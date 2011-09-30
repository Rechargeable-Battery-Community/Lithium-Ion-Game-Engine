/**
 * \file GraphicsDeviceEffectPassGL.cpp
 *
 * \section COPYRIGHT
 *
 * Lithium-Ion Game Engine
 *
 * ---------------------------------------------------------------------
 *
 * Copyright (c) 2011, Don Olmstead
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <Lithium/Graphics/GraphicsDevice.hpp>
#include "EffectPassBinding.hpp"
#include "OpenGLMappings.hpp"
using namespace Lithium;

namespace
{

	GLuint createShader(GLenum type, const GLchar* source, GLint sourceLength)
	{
		// Create the shader
		GLuint id = glCreateShader(type);
		glShaderSource(id, 1, &source, &sourceLength);
		glCompileShader(id);

		// See if compilation was successful
		GLint compiled;
		glGetShaderiv(id, GL_COMPILE_STATUS, &compiled);

		if (compiled == GL_FALSE)
		{
			char infoLog[1024];
			glGetShaderInfoLog(id, 1024, NULL, infoLog);

			printf(infoLog);

			// Cleanup the shader
			glDeleteShader(id);

			return 0;
		}
		else
		{
			return id;
		}
	}

	void bindAttributes(GLuint program, VertexElementUsage::Enum usage, GLint count)
	{
		char attributeName[32];
		GLuint attributeLocation = OpenGLMappings::vertexElement[usage];
		const char* attributeNameFormat =  OpenGLMappings::vertexElementNames[usage];

		for (GLint i = 0; i < count; ++i, ++attributeLocation)
		{
			sprintf(attributeName, attributeNameFormat, i);

			// If the location is present in the shader bind it
			if (glGetAttribLocation(program, attributeName) != -1)
				glBindAttribLocation(program, attributeLocation, attributeName);
		}
	}
}

//---------------------------------------------------------------------

void GraphicsDevice::bindEffectPass(
	EffectPass* effectPass,
	const char* vertexSource,
	std::size_t vertexSourceLength,
	const char* pixelSource,
	std::size_t pixelSourceLength
)
{
	// Create the program object
	GLuint id = glCreateProgram();

	// Attach the shaders
	GLuint vertexShader = createShader(GL_VERTEX_SHADER, vertexSource, vertexSourceLength);
	GLuint pixelShader = createShader(GL_FRAGMENT_SHADER, pixelSource, pixelSourceLength);

	glAttachShader(id, vertexShader);
	glAttachShader(id, pixelShader);

	// Link the program so the attribute locations are present
	glLinkProgram(id);

	// Bind the attribute locations
	bindAttributes(id, VertexElementUsage::Position, 1);
	bindAttributes(id, VertexElementUsage::TextureCoordinate, 2);
	bindAttributes(id, VertexElementUsage::Normal, 1);

	// Link the program with the new attribute locations
	glLinkProgram(id);

	// Delete the shaders
	glDeleteShader(vertexShader);
	glDeleteShader(pixelShader);

	// See if linking was successful
	GLint linked;
	glGetProgramiv(id, GL_LINK_STATUS, &linked);

	if (linked == GL_FALSE)
	{
	
		glDeleteProgram(id);
		id = 0;
	}

	// Create the binding
	EffectPassBinding* binding = new EffectPassBinding();
	binding->id = id;

	effectPass->setDevice(this, binding);

	// \todo REMOVE TESTING
	glUseProgram(id);
	glUniform1i(glGetUniformLocation(id, "texture"), 0);
}

//---------------------------------------------------------------------

void GraphicsDevice::releaseEffectPass(EffectPass* effectPass)
{
	EffectPassBinding* binding = (EffectPassBinding*)effectPass->getResources();

	glDeleteProgram(binding->id);

	// Remove the binding
	delete binding;

	effectPass->setDevice(0, 0);
}

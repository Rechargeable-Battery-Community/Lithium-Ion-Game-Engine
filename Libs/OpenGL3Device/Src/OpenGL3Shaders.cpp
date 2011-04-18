/**
 * \file OpenGL3Shaders.cpp
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
#include "VertexShaderBinding.hpp"
#include "PixelShaderBinding.hpp"
#include "GeometryShaderBinding.hpp"
using namespace Lithium;

namespace
{
	/**
	 * Create the shader object.
	 *
	 * \param type The type of shader to create.
	 * \param stream The stream containing the shader code.
	 * \returns The shader object.
	 */
	GLuint createShader(GLenum type, std::istream& stream)
	{
		// Create the shader object
		GLuint shader = glCreateShader(type);

		// Copy the stream to a buffer
		std::stringstream copy;
		copy << stream.rdbuf();

		// Compile the shader
		const std::string& str = copy.str();
		const char* buffer = str.c_str();

		glShaderSource(shader, 1, &buffer, 0);
		glCompileShader(shader);

		return shader;
	}
}

//---------------------------------------------------------------------

void GraphicsDevice::createVertexShader(VertexShader* shader)
{
	// Create the binding
	VertexShaderBinding* binding = new VertexShaderBinding();
	binding->id = createShader(GL_VERTEX_SHADER, shader->getSource());

	LITHIUM_ASSERT(binding->id != 0, "The VertexShader could not be created");

	// Associate the shader with this device
	shader->setDevice(this, binding);
}

//---------------------------------------------------------------------

void GraphicsDevice::createPixelShader(PixelShader* shader)
{
	// Create the binding
	PixelShaderBinding* binding = new PixelShaderBinding();
	binding->id = createShader(GL_FRAGMENT_SHADER, shader->getSource());

	LITHIUM_ASSERT(binding->id != 0, "The PixelShader could not be created");

	// Associate the shader with this device
	shader->setDevice(this, binding);
}

//---------------------------------------------------------------------

void GraphicsDevice::createGeometryShader(GeometryShader* shader)
{
	// Create the binding
	GeometryShaderBinding* binding = new GeometryShaderBinding();
	binding->id = createShader(GL_GEOMETRY_SHADER, shader->getSource());

	LITHIUM_ASSERT(binding->id != 0, "The GeometryShader could not be created");

	// Associate the shader with this device
	shader->setDevice(this, binding);
}

//---------------------------------------------------------------------

void GraphicsDevice::destroyVertexShader(VertexShader* shader)
{
	// Get the binding
	VertexShaderBinding* binding = static_cast<VertexShaderBinding*>(shader->getBinding());

	// Delete the shader from OpenGL
	glDeleteShader(binding->id);

	// Delete the binding
	delete binding;
}

//---------------------------------------------------------------------

void GraphicsDevice::destroyPixelShader(PixelShader* shader)
{
	// Get the binding
	PixelShaderBinding* binding = static_cast<PixelShaderBinding*>(shader->getBinding());

	// Delete the shader from OpenGL
	glDeleteShader(binding->id);

	// Delete the binding
	delete binding;
}

//---------------------------------------------------------------------

void GraphicsDevice::destroyGeometryShader(GeometryShader* shader)
{
	// Get the binding
	GeometryShaderBinding* binding = static_cast<GeometryShaderBinding*>(shader->getBinding());

	// Delete the shader from OpenGL
	glDeleteShader(binding->id);

	// Delete the binding
	delete binding;
}

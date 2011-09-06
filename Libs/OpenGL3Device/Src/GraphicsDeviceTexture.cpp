/**
 * \file GraphicsDeviceTexture.cpp
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
#include "TextureBinding.hpp"
using namespace Lithium;

namespace
{
	/// Mapping values to OpenGL
	GLenum __surfaceFormatInternal[SurfaceFormat::Size] =
	{
		GL_RGBA // Color
	} ;

	/// Mapping values to OpenGL
	GLenum __surfaceFormat[SurfaceFormat::Size] =
	{
		GL_RGBA // Color
	} ;

	/// Mapping values to OpenGL
	GLenum __surfaceFormatType[SurfaceFormat::Size] =
	{
		GL_UNSIGNED_BYTE // Color
	} ;

	GLenum getError()
	{
		GLenum error = glGetError();

		switch (error)
		{
			case GL_INVALID_ENUM     : printf("GL_INVALID_ENUM");      break;
			case GL_INVALID_VALUE    : printf("GL_INVALID_VALUE");     break;
			case GL_INVALID_OPERATION: printf("GL_INVALID_OPERATION"); break;
			case GL_STACK_OVERFLOW   : printf("GL_STACK_OVERFLOW");    break;
			case GL_STACK_UNDERFLOW  : printf("GL_STACK_UNDERFLOW");   break;
			case GL_OUT_OF_MEMORY    : printf("GL_OUT_OF_MEMORY");     break;
			case GL_TABLE_TOO_LARGE  : printf("GL_TABLE_TOO_LARGE");   break;
		} ;

		return error;
	}

} // end anonymous namespace

//---------------------------------------------------------------------

void GraphicsDevice::bindTexture2D(Texture2D* texture, const void* data)
{
	GLuint id;

	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);
	SurfaceFormat::Enum format = texture->getSurfaceFormat();

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); 
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

	glTexImage2D(
		GL_TEXTURE_2D,
		0,
		__surfaceFormatInternal[format],
		texture->getWidth(),
		texture->getHeight(),
		0,
		__surfaceFormat[format],
		__surfaceFormatType[format],
		data
	);
	
	TextureBinding* binding = new TextureBinding();
	binding->id = id;

	texture->setDevice(this, binding);
}

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

} // end anonymous namespace

//---------------------------------------------------------------------

void GraphicsDevice::bindTexture2D(Texture2D* texture, const void* data, BufferUsage::Enum bufferUsage)
{
	std::int32_t size = texture->getWidth() * texture->getHeight() * 4;

	GLuint id;
	GLuint buffer;

	// Create the texture
	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); 
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

	SurfaceFormat::Enum format = texture->getSurfaceFormat();

	if (bufferUsage == BufferUsage::Static)
	{
		// Copy the data into the texture
		glTexImage2D(
			GL_TEXTURE_2D,                   // Target
			0,                               // Level
			__surfaceFormatInternal[format], // Internal format (color components)
			texture->getWidth(),             // Width
			texture->getHeight(),            // Height
			0,                               // Border
			__surfaceFormat[format],         // Surface format (format of the pixel data)
			__surfaceFormatType[format],     // Surface format type (data-type of pixel data)
			data                             // Data
		);

		// Pixel buffer is unused
		buffer = 0;
	}
	else
	{
		// Create the PBO
		glGenBuffers(1, &buffer);
		glBindBuffer(GL_PIXEL_UNPACK_BUFFER, buffer);

		// Copy the data into the texture
		// If data is null then the space is just reserved
		glBufferData(GL_PIXEL_UNPACK_BUFFER, size, data, GL_DYNAMIC_DRAW);

		glTexImage2D(
			GL_TEXTURE_2D,                   // Target
			0,                               // Level
			__surfaceFormatInternal[format], // Internal format (color components)
			texture->getWidth(),             // Width
			texture->getHeight(),            // Height
			0,                               // Border
			__surfaceFormat[format],         // Surface format (format of the pixel data)
			__surfaceFormatType[format],     // Surface format type (data-type of pixel data)
			0                                // Data
		);

		// Unbind the PBO
		glBindBuffer(GL_PIXEL_UNPACK_BUFFER, 0);
	}

	// Unbind the texture
	glBindTexture(GL_TEXTURE_2D, 0);
	
	// Create the binding
	TextureBinding* binding = new TextureBinding();
	binding->id = id;
	binding->buffer = buffer;

	texture->setDevice(this, binding);
}

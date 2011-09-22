/**
 * \file OpenGL3VertexBuffer.cpp
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
#include <Lithium/Graphics/VertexBuffer.hpp>
#include "VertexBufferBinding.hpp"
using namespace Lithium;

namespace
{
	/// Mapping values to OpenGL
	GLenum __bufferUsage[BufferUsage::Size] =
	{
		GL_STATIC_DRAW,  // Static
		GL_DYNAMIC_DRAW, // Dynamic
		GL_STREAM_DRAW   // Stream
	} ;

} // end anonymous namespace

//---------------------------------------------------------------------

void GraphicsDevice::bindVertexBuffer(VertexBuffer* buffer, const void* data, std::size_t vertexSize)
{
	GLuint id;

	// Create the vertex buffer
	glGenBuffers(1, &id);
	glBindBuffer(GL_ARRAY_BUFFER, id);

	glBufferData(GL_ARRAY_BUFFER, vertexSize * buffer->getVertexCount(), data, __bufferUsage[buffer->getBufferUsage()]);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// Create the binding
	VertexBufferBinding* binding = new VertexBufferBinding();
	binding->id = id;

	// \todo remove
	binding->stride = vertexSize;
	binding->positionOffset = 0;
	binding->texCoordOffset = 16;

	buffer->setDevice(this, binding);
}

//---------------------------------------------------------------------

void GraphicsDevice::releaseVertexBuffer(VertexBuffer* buffer)
{
	VertexBufferBinding* binding = (VertexBufferBinding*)buffer->getResources();

	glDeleteBuffers(1, &binding->id);

	// Remove the binding
	delete binding;

	buffer->setDevice(0, 0);
}

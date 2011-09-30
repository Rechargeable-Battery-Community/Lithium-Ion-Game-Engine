/**
 * \file GraphicsDeviceBuffers.cpp
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
#include "VertexBufferBinding.hpp"
#include "IndexBufferBinding.hpp"
#include "OpenGLMappings.hpp"
using namespace Lithium;

//---------------------------------------------------------------------

void GraphicsDevice::bindVertexBuffer(VertexBuffer* buffer, const void* data, std::size_t vertexSize)
{
	GLuint id;

	// Create the vertex buffer object
	glGenBuffers(1, &id);
	glBindBuffer(GL_ARRAY_BUFFER, id);

	glBufferData(
		GL_ARRAY_BUFFER,
		vertexSize * buffer->getVertexCount(),
		data,
		OpenGLMappings::bufferUsage[buffer->getBufferUsage()]
	);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// Create the binding
	VertexBufferBinding* binding = new VertexBufferBinding();
	binding->id = id;

	const VertexDeclaration& vertexDeclaration = buffer->getVertexDeclaration();
	const std::vector<VertexElement>& elements = vertexDeclaration.getElements();

#if (OPENGL_VERSION >= 3)

	// Create the vertex array object

#else

	std::size_t elementCount = elements.size();

	for (std::size_t i = 0; i < elementCount; ++i)
	{
		VertexElementBinding& elementBinding = binding->elements[i];
		VertexElementUsage::Enum usage = elements[i].getUsage();
		VertexElementFormat::Enum format = elements[i].getFormat();

		elementBinding.index  = OpenGLMappings::vertexElement[usage] + elements[i].getUsageIndex();
		elementBinding.size   = OpenGLMappings::vertexElementSize[format];
		elementBinding.type   = OpenGLMappings::vertexElementFormat[format];
		elementBinding.offset = elements[i].getOffset();
	}

	binding->stride = vertexSize;
	binding->elementCount = elementCount;

#endif

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

//---------------------------------------------------------------------

void GraphicsDevice::bindIndexBuffer(IndexBuffer* buffer, const void* data, std::size_t indexSize)
{
	GLuint id;

	// Create the index buffer object
	glGenBuffers(1, &id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);

	glBufferData(
		GL_ELEMENT_ARRAY_BUFFER,
		indexSize * buffer->getIndexCount(),
		data,
		OpenGLMappings::bufferUsage[buffer->getBufferUsage()]
	);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	// Create the binding
	IndexBufferBinding* binding = new IndexBufferBinding();
	binding->id = id;

	buffer->setDevice(this, binding);
}

//---------------------------------------------------------------------

void GraphicsDevice::releaseIndexBuffer(IndexBuffer* buffer)
{
	IndexBufferBinding* binding = (IndexBufferBinding*)buffer->getResources();

	glDeleteBuffers(1, &binding->id);

	// Remove the binding
	delete binding;

	buffer->setDevice(0, 0);
}

/**
 * \file GraphicsDeviceCommand.cpp
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

#include "GraphicsCommand.hpp"
#include "GLPlatform.hpp"
using namespace Lithium;

namespace
{
	/**
	 * Sets the blend state within OpenGL.
	 *
	 * \param state The blend state information.
	 */
	void setBlendState(const BlendStateBinding* state)
	{
		glBlendEquationSeparate(
			state->colorFunction,
			state->alphaFunction
		);

		glBlendFuncSeparate(
			state->colorSource,
			state->colorDestination,
			state->alphaSource,
			state->alphaDestination
		) ;
	}

	/**
	 * Sets the depth stencil state within OpenGL.
	 *
	 * \param state The depth stencil state information.
	 */
	void setDepthStencilState(const DepthStencilStateBinding* state)
	{

	}

	/**
	 * Sets the rasterizer state within OpenGL.
	 *
	 * \param state The rasterizer state information.
	 */
	void setRasterizerState(const RasterizerStateBinding* state)
	{
		if (state->scissorTestEnabled)
			glEnable(GL_SCISSOR_TEST);
		else
			glDisable(GL_SCISSOR_TEST);

		if (state->cullEnabled)
		{
			glEnable(GL_CULL_FACE);
			glCullFace(state->cullFace);
			glFrontFace(state->frontFace);
		}
		else
		{
			glDisable(GL_CULL_FACE);
		}

		glEnable(GL_POLYGON_OFFSET_FILL);
		glPolygonMode(GL_FRONT_AND_BACK, state->fillMode);
		glPolygonOffset(state->depthScale, state->depthBias);
	}

	void setTexture(const TextureBinding* texture)
	{
		glBindTexture(GL_TEXTURE_2D, texture->id);
	}

#define BUFFER_OFFSET(i) ((char*)NULL + (i))

	void setVertexBuffer(const VertexBufferBinding* buffer)
	{
		glBindBuffer(GL_ARRAY_BUFFER, buffer->id);

		for (int i = 0; i < buffer->elementCount; ++i)
		{
			const VertexElementBinding& element = buffer->elements[i];

			glEnableVertexAttribArray(element.index);
			glVertexAttribPointer(
				element.index,
				element.size,
				element.type,
				GL_FALSE,
				buffer->stride,
				BUFFER_OFFSET(element.offset)
			);
		}
	}

	void setIndexBuffer(const IndexBufferBinding* buffer)
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer->id);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, 0);
	}

} // end anonymous namespace

//---------------------------------------------------------------------

void Lithium::executeCommand(const GraphicsCommand& command)
{
	setBlendState(command.blendState);
	setDepthStencilState(command.depthStencilState);
	setRasterizerState(command.rasterizerState);
	setTexture(command.texture);

	setVertexBuffer(command.vertexBuffer);
	setIndexBuffer(command.indexBuffer);
}

/**
 * \file OpenGL3Command.cpp
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

#include "OpenGL3Command.hpp"
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

} // end anonymous namespace

//---------------------------------------------------------------------

void Lithium::executeCommand(const GraphicsCommand& command)
{
	setBlendState(command.blendState);
	setDepthStencilState(command.depthStencilState);
	setRasterizerState(command.rasterizerState);
}

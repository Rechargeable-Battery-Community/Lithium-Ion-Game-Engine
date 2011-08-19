/**
 * \file OpenGL3DeviceState.cpp
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
#include "BlendStateBinding.hpp"
using namespace Lithium;

namespace
{
	/// Mapping BlendFunction values to OpenGL
	GLenum __blendFunctionMapping[BlendFunction::Size] =
	{
		GL_FUNC_ADD,              // Add
		GL_MAX,                   // Max
		GL_MIN,                   // Min
		GL_FUNC_REVERSE_SUBTRACT, // ReverseSubtract
		GL_FUNC_SUBTRACT          // Subtract
	} ;

	/// Mapping Blend values to OpenGL
	GLenum __blendMapping[Blend::Size] =
	{
		GL_ZERO,                     // Zero
		GL_ONE,                      // One
		GL_SRC_COLOR,                // SourceColor
		GL_ONE_MINUS_SRC_COLOR,      // InverseSourceColor
		GL_SRC_ALPHA,                // SourceAlpha
		GL_ONE_MINUS_SRC_ALPHA,      // InverseSourceAlpha
		GL_DST_ALPHA,                // DestinationAlpha
		GL_ONE_MINUS_DST_ALPHA,      // InverseDestinationAlpha
		GL_CONSTANT_COLOR,           // DestinationColor
		GL_ONE_MINUS_CONSTANT_COLOR, // InverseDestinationColor
		GL_SRC_ALPHA_SATURATE,       // SourceAlphaSaturation
		GL_CONSTANT_COLOR,           // BlendFactor
		GL_ONE_MINUS_CONSTANT_COLOR  // InverseBlendFactor
	} ;

} // end anonymous namespace

//---------------------------------------------------------------------

void GraphicsDevice::bindBlendState(BlendState* state)
{
	BlendStateBinding* binding = new BlendStateBinding();

	binding->alphaFunction = __blendFunctionMapping[state->getAlphaBlendFunction()];
	binding->colorFunction = __blendFunctionMapping[state->getColorBlendFunction()];

	binding->alphaDestination = __blendMapping[state->getAlphaDestinationBlend()];
	binding->alphaSource      = __blendMapping[state->getAlphaSourceBlend()];
	binding->colorDestination = __blendMapping[state->getColorDestinationBlend()];
	binding->colorSource      = __blendMapping[state->getColorSourceBlend()];

	state->setDevice(this, binding);
}

//---------------------------------------------------------------------

void GraphicsDevice::releaseBlendState(BlendState* state)
{
	BlendStateBinding* binding = (BlendStateBinding*)state->getResources();

	delete binding;

	state->setDevice(0, 0);
}

//---------------------------------------------------------------------

void GraphicsDevice::bindDepthStencilState(DepthStencilState* state)
{
	
}

//---------------------------------------------------------------------

void GraphicsDevice::releaseDepthStencilState(DepthStencilState* state)
{

}

//---------------------------------------------------------------------

void GraphicsDevice::bindRasterizerState(RasterizerState* state)
{

}

//---------------------------------------------------------------------

void GraphicsDevice::releaseRasterizerState(RasterizerState* state)
{

}

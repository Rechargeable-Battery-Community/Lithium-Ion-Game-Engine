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
#include "DepthStencilStateBinding.hpp"
#include "RasterizerStateBinding.hpp"
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
	DepthStencilStateBinding* binding = new DepthStencilStateBinding();

	state->setDevice(this, binding);
}

//---------------------------------------------------------------------

void GraphicsDevice::releaseDepthStencilState(DepthStencilState* state)
{
	DepthStencilStateBinding* binding = (DepthStencilStateBinding*)state->getResources();

	delete binding;

	state->setDevice(0, 0);
}

//---------------------------------------------------------------------

void GraphicsDevice::bindRasterizerState(RasterizerState* state)
{
	RasterizerStateBinding* binding = new RasterizerStateBinding();

	binding->scissorTestEnabled = state->isScissorTestEnabled();

	// Set the culling information
	CullMode::Enum cullMode = state->getCullMode();

	binding->cullFace = GL_BACK;

	if (cullMode != CullMode::None)
	{
		binding->cullEnabled = GL_FALSE;
		
		if (cullMode == CullMode::CullClockwiseFace)
			binding->frontFace = GL_CW;
		else
			binding->frontFace = GL_CCW;
	}
	else
	{
		binding->cullEnabled = GL_FALSE;
		binding->frontFace = GL_CCW;
	}

	// Set the polygon information
	binding->fillMode = (state->getFillMode() == FillMode::Solid) ? GL_FILL : GL_LINE;
	binding->depthBias = state->getDepthBias();
	binding->depthScale = state->getSlopeScaleDepthBias();

	state->setDevice(this, binding);
}

//---------------------------------------------------------------------

void GraphicsDevice::releaseRasterizerState(RasterizerState* state)
{
	RasterizerStateBinding* binding = (RasterizerStateBinding*)state->getResources();

	delete binding;

	state->setDevice(0, 0);
}

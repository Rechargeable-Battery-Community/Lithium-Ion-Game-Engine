/**
 * \file GraphicsDeviceState.cpp
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
#include "SamplerStateBinding.hpp"
#include "OpenGLMappings.hpp"
using namespace Lithium;

//---------------------------------------------------------------------

void GraphicsDevice::bindBlendState(BlendState* state)
{
	BlendStateBinding* binding = new BlendStateBinding();
	std::size_t targets = state->getTargetCount();

#if (OPENGL_VERSION >= 4)
	
	for (std::size_t i = 0; i < targets; ++i)
	{
		RenderTargetBlendStateBinding& renderTargetBlendState = binding->renderTargetBlendStates[i];

		renderTargetBlendState.alphaFunction = OpenGLMappings::blendFunction[state->getAlphaBlendFunction(i)];
		renderTargetBlendState.colorFunction = OpenGLMappings::blendFunction[state->getColorBlendFunction(i)];

		renderTargetBlendState.alphaDestination = OpenGLMappings::blend[state->getAlphaDestinationBlend(i)];
		renderTargetBlendState.alphaSource      = OpenGLMappings::blend[state->getAlphaSourceBlend(i)];
		renderTargetBlendState.colorDestination = OpenGLMappings::blend[state->getColorDestinationBlend(i)];
		renderTargetBlendState.colorSource      = OpenGLMappings::blend[state->getColorSourceBlend(i)];

		const ColorWriteChannelFlags& flags = state->getColorMask(i);
		renderTargetBlendState.colorMask.red   = GL_TRUE;
		renderTargetBlendState.colorMask.green = GL_TRUE;
		renderTargetBlendState.colorMask.blue  = GL_TRUE;
		renderTargetBlendState.colorMask.alpha = GL_TRUE;
	}

	binding->targets = targets;

#elif (OPENGL_VERSION == 3)

	binding->alphaFunction = OpenGLMappings::blendFunction[state->getAlphaBlendFunction()];
	binding->colorFunction = OpenGLMappings::blendFunction[state->getColorBlendFunction()];

	binding->alphaDestination = OpenGLMappings::blend[state->getAlphaDestinationBlend()];
	binding->alphaSource      = OpenGLMappings::blend[state->getAlphaSourceBlend()];
	binding->colorDestination = OpenGLMappings::blend[state->getColorDestinationBlend()];
	binding->colorSource      = OpenGLMappings::blend[state->getColorSourceBlend()];

	// Get the individual color masks
	for (std::size_t i = 0; i < targets; ++i)
	{
		RenderTargetColorMaskBinding& colorMask = binding->colorMasks[i];
		const ColorWriteChannelFlags& flags = state->getColorMask(i);

		colorMask.red   = GL_TRUE;
		colorMask.green = GL_TRUE;
		colorMask.blue  = GL_TRUE;
		colorMask.alpha = GL_TRUE;
	}

	binding->targets = targets;

#else

	binding->alphaFunction = OpenGLMappings::blendFunction[state->getAlphaBlendFunction()];
	binding->colorFunction = OpenGLMappings::blendFunction[state->getColorBlendFunction()];

	binding->alphaDestination = OpenGLMappings::blend[state->getAlphaDestinationBlend()];
	binding->alphaSource      = OpenGLMappings::blend[state->getAlphaSourceBlend()];
	binding->colorDestination = OpenGLMappings::blend[state->getColorDestinationBlend()];
	binding->colorSource      = OpenGLMappings::blend[state->getColorSourceBlend()];

	const ColorWriteChannelFlags& flags = state->getColorMask();
	binding->colorMask.red   = flags.is_set(ColorWriteChannel::Red);
	binding->colorMask.green = flags.is_set(ColorWriteChannel::Green);
	binding->colorMask.blue  = flags.is_set(ColorWriteChannel::Blue);
	binding->colorMask.alpha = flags.is_set(ColorWriteChannel::Alpha);

#endif

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

//---------------------------------------------------------------------

void GraphicsDevice::bindSamplerState(SamplerState* state)
{
	SamplerStateBinding* binding = new SamplerStateBinding();

	TextureFilter::Enum filter = state->getFilter();
	binding->minFilter = OpenGLMappings::textureFilterMin[filter];
	binding->magFilter = OpenGLMappings::textureFilterMag[filter];

	binding->addressModeU = OpenGLMappings::textureAddressMode[state->getAddressU()];
	binding->addressModeV = OpenGLMappings::textureAddressMode[state->getAddressV()];
	binding->addressModeW = OpenGLMappings::textureAddressMode[state->getAddressW()];

	state->setDevice(this, binding);
}

//---------------------------------------------------------------------

void GraphicsDevice::releaseSamplerState(SamplerState* state)
{
	SamplerStateBinding* binding = (SamplerStateBinding*)state->getResources();

	delete binding;

	state->setDevice(0, 0);
}

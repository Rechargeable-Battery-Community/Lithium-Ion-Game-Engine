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
#include "SamplerStateBinding.hpp"
using namespace Lithium;

namespace
{
	//----------------------------------------------------------------------
	// Blend state mappings
	//----------------------------------------------------------------------

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

	//----------------------------------------------------------------------
	// Sampler state mappings
	//----------------------------------------------------------------------

	/// Mapping values to OpenGL
	GLenum __textureFilterMappingMin[TextureFilter::Size] =
	{
		GL_LINEAR,                 // Linear
		GL_NEAREST,                // Point
		0,                         // Anisotropic (Enabled through an extension)
		GL_LINEAR_MIPMAP_NEAREST,  // LinearMipPoint
		GL_NEAREST_MIPMAP_LINEAR,  // PointMipLinear
		GL_LINEAR_MIPMAP_LINEAR,   // MinLinearMagPointMipLinear
		GL_LINEAR_MIPMAP_NEAREST,  // MinLinearMagPointMipPoint
		GL_NEAREST_MIPMAP_LINEAR,  // MinPointMagLinearMipLinear
		GL_NEAREST_MIPMAP_NEAREST  // MinPointMagLinearMipPoint
	} ;

	/// Mapping values to OpenGL
	GLenum __textureFilterMappingMag[TextureFilter::Size] =
	{
		GL_LINEAR,                 // Linear
		GL_NEAREST,                // Point
		0,                         // Anisotropic (Enabled through an extension)
		GL_LINEAR_MIPMAP_NEAREST,  // LinearMipPoint
		GL_NEAREST_MIPMAP_LINEAR,  // PointMipLinear
		GL_NEAREST_MIPMAP_LINEAR,  // MinLinearMagPointMipLinear
		GL_NEAREST_MIPMAP_NEAREST, // MinLinearMagPointMipPoint
		GL_LINEAR_MIPMAP_LINEAR,   // MinPointMagLinearMipLinear
		GL_LINEAR_MIPMAP_NEAREST   // MinPointMagLinearMipPoint
	} ;

	/// Mapping values to OpenGL
	GLenum __textureAddressModeMapping[TextureAddressMode::Size] =
	{
		GL_CLAMP_TO_EDGE,   // Clamp
		GL_MIRRORED_REPEAT, // Mirror
		GL_REPEAT           // Wrap
	} ;

} // end anonymous namespace

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
	binding->minFilter = __textureFilterMappingMin[filter];
	binding->magFilter = __textureFilterMappingMag[filter];

	binding->addressModeU = __textureAddressModeMapping[state->getAddressU()];
	binding->addressModeV = __textureAddressModeMapping[state->getAddressV()];
	binding->addressModeW = __textureAddressModeMapping[state->getAddressW()];

	state->setDevice(this, binding);
}

//---------------------------------------------------------------------

void GraphicsDevice::releaseSamplerState(SamplerState* state)
{
	SamplerStateBinding* binding = (SamplerStateBinding*)state->getResources();

	delete binding;

	state->setDevice(0, 0);
}

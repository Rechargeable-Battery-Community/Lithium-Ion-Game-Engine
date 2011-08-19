/**
 * \file OpenGL3Effects.cpp
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
#include "EffectPassBinding.hpp"
#include "VertexShaderBinding.hpp"
#include "PixelShaderBinding.hpp"
#include "GeometryShaderBinding.hpp"
using namespace Lithium;

//---------------------------------------------------------------------

void GraphicsDevice::createEffectPass(EffectPass* effect)
{
	// Create the program
	GLuint program = glCreateProgram();

	// Attach the vertex shader
	const VertexShader* vertexShader = effect->getVertexShader();

	if (vertexShader)
	{
		const VertexShaderBinding* vertexBinding = static_cast<VertexShaderBinding*>(vertexShader->getResources());

		glAttachShader(program, vertexBinding->id);
	}

	// Attach the pixel shader
	const PixelShader* pixelShader = effect->getPixelShader();

	if (pixelShader)
	{
		const PixelShaderBinding* pixelBinding = static_cast<PixelShaderBinding*>(pixelShader->getResources());

		glAttachShader(program, pixelBinding->id);
	}

	// Attach the geometry shader
	const GeometryShader* geometryShader = effect->getGeometryShader();

	if (geometryShader)
	{
		const GeometryShaderBinding* geometryBinding = static_cast<GeometryShaderBinding*>(geometryShader->getResources());

		glAttachShader(program, geometryBinding->id);
	}

	// Link the program
	glLinkProgram(program);

	// Create the binding
	EffectPassBinding* binding = new EffectPassBinding();
	binding->id = program;

	// Associate the effect with this device
	effect->setDevice(this, binding);
}

//---------------------------------------------------------------------

void GraphicsDevice::setEffectPass(EffectPass* effect)
{
	// Get the binding
	EffectPassBinding* binding = static_cast<EffectPassBinding*>(effect->getResources());

	// Use the program
	glUseProgram(binding->id);
}

//---------------------------------------------------------------------

void GraphicsDevice::destroyEffectPass(EffectPass* effect)
{
	// Get the binding
	EffectPassBinding* binding = static_cast<EffectPassBinding*>(effect->getResources());

	// Delete the program object from OpenGL
	glDeleteProgram(binding->id);

	// Delete the binding
	delete binding;
}

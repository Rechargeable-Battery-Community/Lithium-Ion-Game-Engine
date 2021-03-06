/**
 * \file GraphicsDeviceContext.cpp
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

#include <Lithium/Graphics/GraphicsDeviceContext.hpp>
#include "GraphicsCommandList.hpp"
using namespace Lithium;

//---------------------------------------------------------------------

GraphicsDeviceContext::GraphicsDeviceContext(const GraphicsDevice* device)
: _commandList(new GraphicsCommandList())
, _device(device)
, _blendState(0)
{ }

//---------------------------------------------------------------------

GraphicsDeviceContext::~GraphicsDeviceContext()
{
	if (_commandList)
	{
		delete _commandList;
		_commandList = 0;
	}
}

//---------------------------------------------------------------------

void GraphicsDeviceContext::begin()
{
	_commandList->begin();
}

//---------------------------------------------------------------------

void GraphicsDeviceContext::draw()
{
	_commandList->draw();
}

//---------------------------------------------------------------------

void GraphicsDeviceContext::end()
{
	_commandList->end();
}

//---------------------------------------------------------------------

void GraphicsDeviceContext::setBlendState(const BlendState* state)
{
	_blendState = state;

	const BlendStateBinding* binding = (const BlendStateBinding*)state->getResources();
	LITHIUM_ASSERT(binding, "Resource has not been bound");
	LITHIUM_ASSERT(state->getDevice() == _device, "Resource is not bound to this device");

	_commandList->setBlendStateBinding(binding);
}

//---------------------------------------------------------------------

void GraphicsDeviceContext::setDepthStencilState(const DepthStencilState* state)
{
	_depthStencilState = state;

	const DepthStencilStateBinding* binding = (const DepthStencilStateBinding*)state->getResources();
	LITHIUM_ASSERT(binding, "Resource has not been bound");
	LITHIUM_ASSERT(state->getDevice() == _device, "Resource is not bound to this device");

	_commandList->setDepthStencilStateBinding(binding);
}

//---------------------------------------------------------------------

void GraphicsDeviceContext::setRasterizerState(const RasterizerState* state)
{
	_rasterizerState = state;

	const RasterizerStateBinding* binding = (const RasterizerStateBinding*)state->getResources();
	LITHIUM_ASSERT(binding, "Resource has not been bound");
	LITHIUM_ASSERT(state->getDevice() == _device, "Resource is not bound to this device");

	_commandList->setRasterizerStateBinding(binding);
}

//---------------------------------------------------------------------

void GraphicsDeviceContext::setTexture(const Texture2D* texture)
{
	const TextureBinding* binding = (const TextureBinding*)texture->getResources();
	LITHIUM_ASSERT(binding, "Resource has not been bound");
	LITHIUM_ASSERT(texture->getDevice() == _device, "Resource is not bound to this device");

	_commandList->setTextureBinding(binding);
}

//---------------------------------------------------------------------

void GraphicsDeviceContext::setVertexBuffer(const VertexBuffer* buffer)
{
	const VertexBufferBinding* binding = (const VertexBufferBinding*)buffer->getResources();

	_commandList->setVertexBuffer(binding);
}

//---------------------------------------------------------------------

void GraphicsDeviceContext::setIndexBuffer(const IndexBuffer* buffer)
{
	const IndexBufferBinding* binding = (const IndexBufferBinding*)buffer->getResources();

	_commandList->setIndexBuffer(binding);
}

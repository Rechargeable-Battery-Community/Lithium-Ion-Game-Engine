/**
 * \file GraphicsDevice.cpp
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
using namespace Lithium;

//---------------------------------------------------------------------

GraphicsDevice::GraphicsDevice()
: _viewport(0, 0, 0, 0)
{
	_immediateContext = new GraphicsDeviceContext(this);
}

//---------------------------------------------------------------------

GraphicsDevice::~GraphicsDevice()
{
	if (_immediateContext)
	{
		delete _immediateContext;
		_immediateContext = 0;
	}
}

//---------------------------------------------------------------------

void GraphicsDevice::bind(GraphicsResource* resource)
{
	if (resource->isExactly(BlendState::typeOf()))
		bindBlendState(static_cast<BlendState*>(resource));
	else if (resource->isExactly(DepthStencilState::typeOf()))
		bindDepthStencilState(static_cast<DepthStencilState*>(resource));
	else if (resource->isExactly(RasterizerState::typeOf()))
		bindRasterizerState(static_cast<RasterizerState*>(resource));
	else if (resource->isExactly(SamplerState::typeOf()))
		bindSamplerState(static_cast<SamplerState*>(resource));
}

//---------------------------------------------------------------------

void GraphicsDevice::release(GraphicsResource* resource)
{
	if (resource->isExactly(BlendState::typeOf()))
		releaseBlendState(static_cast<BlendState*>(resource));
	else if (resource->isExactly(DepthStencilState::typeOf()))
		releaseDepthStencilState(static_cast<DepthStencilState*>(resource));
	else if (resource->isExactly(RasterizerState::typeOf()))
		releaseRasterizerState(static_cast<RasterizerState*>(resource));
	else if (resource->isExactly(SamplerState::typeOf()))
		releaseSamplerState(static_cast<SamplerState*>(resource));
}

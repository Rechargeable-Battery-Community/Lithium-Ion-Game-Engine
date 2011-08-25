/**
 * \file BlendState.cpp
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

#include <Lithium/Graphics/BlendState.hpp>
using namespace Lithium;

LITHIUM_IMPLEMENT_TYPE_INFO(Lithium, BlendState, GraphicsResource);

//---------------------------------------------------------------------

BlendState::BlendState()
: _numTargets(1)
{ }

//---------------------------------------------------------------------

BlendState::~BlendState()
{
	release();
}

//---------------------------------------------------------------------

void BlendState::setAlphaBlendFunction(BlendFunction::Enum function, std::size_t i)
{
	// \todo Handle case where already bound
		
	_renderTargetBlendStates[i].alphaBlendFunction = function;

	// Update the number of render targets in use
	updateTargetCount(i);
}

//---------------------------------------------------------------------

void BlendState::setAlphaDestinationBlend(Blend::Enum blend, std::size_t i)
{
	// \todo Handle case where already bound

	_renderTargetBlendStates[i].alphaDestinationBlend = blend;

	// Update the number of render targets in use
	updateTargetCount(i);
}

//---------------------------------------------------------------------

void BlendState::setAlphaSourceBlend(Blend::Enum blend, std::size_t i)
{
	// \todo Handle case where already bound

	_renderTargetBlendStates[i].alphaSourceBlend = blend;

	// Update the number of render targets in use
	updateTargetCount(i);
}

//---------------------------------------------------------------------

void BlendState::setColorBlendFunction(BlendFunction::Enum function, std::size_t i)
{
	// \todo Handle case where already bound

	_renderTargetBlendStates[i].colorBlendFunction = function;

	// Update the number of render targets in use
	updateTargetCount(i);
}

//---------------------------------------------------------------------

void BlendState::setColorDestinationBlend(Blend::Enum blend, std::size_t i)
{
	// \todo Handle case where already bound

	_renderTargetBlendStates[i].colorDestinationBlend = blend;

	// Update the number of render targets in use
	updateTargetCount(i);
}

//---------------------------------------------------------------------

void BlendState::setColorSourceBlend(Blend::Enum blend, std::size_t i)
{
	// \todo Handle case where already bound

	_renderTargetBlendStates[i].colorSourceBlend = blend;

	// Update the number of render targets in use
	updateTargetCount(i);
}

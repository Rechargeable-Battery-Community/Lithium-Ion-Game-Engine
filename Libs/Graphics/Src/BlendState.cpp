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
: _alphaBlendFunction(BlendFunction::Add)
, _colorBlendFunction(BlendFunction::Add)
, _alphaDestinationBlend(Blend::One)
, _alphaSourceBlend(Blend::One)
, _colorDestinationBlend(Blend::One)
, _colorSourceBlend(Blend::One)
{ }

//---------------------------------------------------------------------

BlendState::~BlendState()
{
	release();
}

//---------------------------------------------------------------------

void BlendState::setAlphaBlendFunction(BlendFunction::Enum function)
{
	// \todo Handle case where already bound

	_alphaBlendFunction = function;
}

//---------------------------------------------------------------------

void BlendState::setAlphaDestinationBlend(Blend::Enum blend)
{
	// \todo Handle case where already bound

	_alphaDestinationBlend = blend;
}

//---------------------------------------------------------------------

void BlendState::setAlphaSourceBlend(Blend::Enum blend)
{
	// \todo Handle case where already bound

	_alphaSourceBlend = blend;
}

//---------------------------------------------------------------------

void BlendState::setColorBlendFunction(BlendFunction::Enum function)
{
	// \todo Handle case where already bound

	_colorBlendFunction = function;
}

//---------------------------------------------------------------------

void BlendState::setColorDestinationBlend(Blend::Enum blend)
{
	// \todo Handle case where already bound

	_colorDestinationBlend = blend;
}

//---------------------------------------------------------------------

void BlendState::setColorSourceBlend(Blend::Enum blend)
{
	// \todo Handle case where already bound

	_colorSourceBlend = blend;
}

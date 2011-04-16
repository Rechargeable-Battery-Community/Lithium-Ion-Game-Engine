/**
 * \file MouseState.cpp
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

#include "LithiumApplicationPCH.hpp"
#include <Lithium/Input/MouseState.hpp>
using namespace Lithium;

//----------------------------------------------------------------------

MouseState::MouseState()
: _xPosition(0)
, _yPosition(0)
{
	for (std::int32_t i = 0; i < MouseButtons::Size; ++i)
		_buttonStates[i] = ButtonState::Released;
}

//----------------------------------------------------------------------

MouseState::MouseState(const MouseState& copy)
: _xPosition(copy._xPosition)
, _yPosition(copy._yPosition)
{
	for (std::int32_t i = 0; i < MouseButtons::Size; ++i)
		_buttonStates[i] = copy._buttonStates[i];
}

//----------------------------------------------------------------------

MouseState& MouseState::operator= (const MouseState& copy)
{
	_xPosition = copy._xPosition;
	_yPosition = copy._yPosition;

	for (std::int32_t i = 0; i < MouseButtons::Size; ++i)
		_buttonStates[i] = copy._buttonStates[i];

	return *this;
}

//----------------------------------------------------------------------

bool MouseState::operator== (const MouseState& compare) const
{
	if ((_xPosition != compare._xPosition) || (_yPosition != compare._yPosition))
		return false;

	for (std::int32_t i = 0; i < MouseButtons::Size; ++i)
		if (_buttonStates[i] != compare._buttonStates[i])
			return false;

	return true;
}

//----------------------------------------------------------------------

bool MouseState::operator!= (const MouseState& compare) const
{
	if ((_xPosition != compare._xPosition) || (_yPosition != compare._yPosition))
		return true;

	for (std::int32_t i = 0; i < MouseButtons::Size; ++i)
		if (_buttonStates[i] != compare._buttonStates[i])
			return true;

	return false;
}

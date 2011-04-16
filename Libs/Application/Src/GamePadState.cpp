/**
 * \file GamePadState.cpp
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
#include <Lithium/Input/GamePadState.hpp>
using namespace Lithium;

//----------------------------------------------------------------------

GamePadState::GamePadState()
: _connected(false)
, _packetNumber(0)
, _leftTrigger(0.0f)
, _rightTrigger(0.0f)
, _leftThumbstick(0.0f, 0.0f)
, _rightThumbstick(0.0f, 0.0f)
{ }

//----------------------------------------------------------------------

GamePadState::GamePadState(const GamePadState& copy)
: _connected(copy._connected)
, _packetNumber(copy._packetNumber)
, _leftTrigger(copy._leftTrigger)
, _rightTrigger(copy._rightTrigger)
, _leftThumbstick(copy._leftThumbstick)
, _rightThumbstick(copy._rightThumbstick)
{ }

//----------------------------------------------------------------------

GamePadState& GamePadState::operator= (const GamePadState& copy)
{
	_connected = copy._connected;
	_packetNumber = copy._packetNumber;

	_leftTrigger  = copy._leftTrigger;
	_rightTrigger = copy._rightTrigger;

	_leftThumbstick  = copy._leftThumbstick;
	_rightThumbstick = copy._rightThumbstick;

	return *this;
}

/**
 * \file KeyboardState.cpp
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
#include <Lithium/Input/KeyboardState.hpp>
using namespace Lithium;

//----------------------------------------------------------------------

KeyboardState::KeyboardState()
{
	for (std::size_t i = 0; i < Keys::Size; ++i)
		_keyStates[i] = KeyState::Up;
}

//----------------------------------------------------------------------

KeyboardState::KeyboardState(const KeyboardState& copy)
{
	for (std::size_t i = 0; i < Keys::Size; ++i)
		_keyStates[i] = copy._keyStates[i];
}

//----------------------------------------------------------------------

KeyboardState& KeyboardState::operator= (const KeyboardState& copy)
{
	for (std::size_t i = 0; i < Keys::Size; ++i)
		_keyStates[i] = copy._keyStates[i];

	return *this;
}

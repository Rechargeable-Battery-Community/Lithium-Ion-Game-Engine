/**
 * \file Keyboard.cpp
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
#include <Lithium/Input/Keyboard.hpp>
#include <Lithium/Application/Game.hpp>
using namespace Lithium;

namespace
{
	/// The current state of the keyboard
	KeyboardState __keyboardState;

} // end namespace

//----------------------------------------------------------------------

const KeyboardState& Keyboard::getState()
{
	return __keyboardState;
}

//----------------------------------------------------------------------

void Game::onKeyChange(Keys::Enum key, KeyState::Enum state)
{
	__keyboardState[key] = state;
}

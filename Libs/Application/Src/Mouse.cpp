/**
 * \file Mouse.cpp
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
#include <Lithium/Input/Mouse.hpp>
#include <Lithium/Application/Game.hpp>
using namespace Lithium;

namespace
{
	/// The current state of the mouse
	MouseState __mouseState;

} // end namespace

//----------------------------------------------------------------------

const MouseState& Mouse::getState()
{
	return __mouseState;
}

//----------------------------------------------------------------------

void Game::onMouseMove(std::int32_t x, std::int32_t y)
{
	__mouseState.setCursorPosition(x, y);
}

//----------------------------------------------------------------------

void Game::onMouseClick(MouseButtons::Enum button, ButtonState::Enum state)
{
	__mouseState[button] = state;
}

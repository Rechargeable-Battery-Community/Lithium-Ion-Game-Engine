/**
 * \file Keyboard.hpp
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

#ifndef LITHIUM_KEYBOARD_HPP_INCLUDED
#define LITHIUM_KEYBOARD_HPP_INCLUDED

#include <Lithium/Input/KeyboardState.hpp>

namespace Lithium
{
	/**
	 * Allows retrieval of keystrokes from a keyboard input device.
	 *
	 * \author Don Olmstead
	 * \version 0.1
	 */
	namespace Keyboard
	{
		/**
		 * Gets the current keyboard state.
		 *
		 * \returns The current keyboard state.
		 */
		const KeyboardState& getState();

	} // end namespace Keyboard

} // end namespace Lithium

#endif // end LITHIUM_KEYBOARD_HPP_INCLUDED

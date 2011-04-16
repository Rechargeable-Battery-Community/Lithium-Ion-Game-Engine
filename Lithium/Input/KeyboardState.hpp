/**
 * \file KeyboardState.hpp
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

#ifndef LITHIUM_KEYBOARD_STATE_HPP_INCLUDED
#define LITHIUM_KEYBOARD_STATE_HPP_INCLUDED

#include <Lithium/System/Includes.hpp>
#include <Lithium/Input/Keys.hpp>
#include <Lithium/Input/KeyState.hpp>

namespace Lithium
{
	//----------------------------------------------------------------------
	// Forward declaration
	//----------------------------------------------------------------------

	class Game;

	/**
	 * Represents a state of keystrokes recorded by a keyboard input device.
	 *
	 * \author Don Olmstead
	 * \version 0.1
	 */
	class KeyboardState
	{
		//----------------------------------------------------------------------
		// Construction
		//----------------------------------------------------------------------

		public:

			/**
			 * Creates an instance of the KeyboardState class.
			 */
			KeyboardState();

			/**
			 * Initializes an instance of the KeyboardState class.
			 *
			 * \param copy The instance to copy.
			 */
			KeyboardState(const KeyboardState& copy);

		//----------------------------------------------------------------------
		// Assignment
		//----------------------------------------------------------------------

		public:

			/**
			 * Copies the values from the given instance.
			 *
			 * \param copy The instance to copy.
			 */
			KeyboardState& operator= (const KeyboardState& copy);

		//----------------------------------------------------------------------
		// Array operator
		//----------------------------------------------------------------------

		public:

			inline KeyState::Enum operator[] (Keys::Enum key) const
			{
				LITHIUM_ASSERT((key >= 0) && (key < Keys::Size - 1), "Invalid key");

				return _keyStates[key];
			}

		private:

			inline KeyState::Enum& operator[] (Keys::Enum key)
			{
				return _keyStates[key];
			}

		//----------------------------------------------------------------------
		// Methods
		//----------------------------------------------------------------------

		public:

			inline bool isKeyUp(Keys::Enum key) const
			{
				LITHIUM_ASSERT((key >= 0) && (key < Keys::Size - 1), "Invalid key");

				return _keyStates[key] == KeyState::Up;
			}

			inline bool isKeyDown(Keys::Enum key) const
			{
				LITHIUM_ASSERT((key >= 0) && (key < Keys::Size - 1), "Invalid key");

				return _keyStates[key] == KeyState::Down;
			}

		private:

			friend class Game;

			KeyState::Enum _keyStates[Keys::Size];

	} ; // end class KeyboardState

} // end namespace Lithium

#endif // LITHIUM_KEYBOARD_STATE_HPP_INCLUDED

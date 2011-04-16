/**
 * \file MouseState.hpp
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

#ifndef LITHIUM_MOUSE_STATE_HPP_INCLUDED
#define LITHIUM_MOUSE_STATE_HPP_INCLUDED

#include <Lithium/System/Includes.hpp>
#include <Lithium/Input/MouseButtons.hpp>
#include <Lithium/Input/ButtonState.hpp>

namespace Lithium
{
	//----------------------------------------------------------------------
	// Forward declaration
	//----------------------------------------------------------------------

	class Game;

	/**
	 * Represents the state of a mouse input device.
	 *
	 * \author Don Olmstead
	 * \version 0.1
	 */
	class MouseState
	{
		//----------------------------------------------------------------------
		// Construction
		//----------------------------------------------------------------------

		public:

			/**
			 * Creates an instance of the MouseState class.
			 */
			MouseState();

			/**
			 * Initializes an instance of the MouseState class.
			 *
			 * \param copy The instance to copy.
			 */
			MouseState(const MouseState& copy);

		//----------------------------------------------------------------------
		// Assignment
		//----------------------------------------------------------------------

		public:

			/**
			 * Copies the values from the given instance.
			 *
			 * \param copy The instance to copy.
			 */
			MouseState& operator= (const MouseState& copy);

		//----------------------------------------------------------------------
		// Comparison
		//----------------------------------------------------------------------

		public:

			/**
			 * Checks if two MouseState instances are equal.
			 *
			 * \param compare The instance to compare with.
			 * \returns \b true if the instances are equal; \b false otherwise.
			 */
			bool operator== (const MouseState& compare) const;

			/**
			 * Checks if two MouseState instances are not equal.
			 *
			 * \param compare The instance to compare with.
			 * \returns \b true if the instances are not equal; \b false otherwise.
			 */
			bool operator!= (const MouseState& compare) const;

		//----------------------------------------------------------------------
		// Array operator
		//----------------------------------------------------------------------

		public:

			inline ButtonState::Enum operator[] (MouseButtons::Enum button) const
			{
				return _buttonStates[button];
			}

		private:

			inline ButtonState::Enum& operator[] (MouseButtons::Enum button)
			{
				return _buttonStates[button];
			}

		//----------------------------------------------------------------------
		// Properties
		//----------------------------------------------------------------------

		public:

			/**
			 * Gets the horizontal position of the mouse cursor.
			 *
			 * \returns The horizontal position of the mouse cursor.
			 */
			inline std::uint32_t getXPosition() const
			{
				return _xPosition;
			}

			/**
			 * Gets the vertical position of the mouse cursor.
			 *
			 * \returns The vertical position of the mouse cursor.
			 */
			inline std::uint32_t getYPosition() const
			{
				return _yPosition;
			}

			/**
			 * Gets the state of the left mouse button.
			 *
			 * \returns The state of the left mouse button.
			 */
			inline ButtonState::Enum getLeftButton() const
			{
				return _buttonStates[MouseButtons::Left];
			}

			/**
			 * Gets the state of the middle mouse button.
			 *
			 * \returns The state of the middle mouse button.
			 */
			inline ButtonState::Enum getMiddleButton() const
			{
				return _buttonStates[MouseButtons::Middle];
			}

			/**
			 * Gets the state of the right mouse button.
			 *
			 * \returns The state of the right mouse button.
			 */
			inline ButtonState::Enum getRightButton() const
			{
				return _buttonStates[MouseButtons::Right];
			}

		private:

			/**
			 * Sets the position of the mouse cursor.
			 *
			 * \param x The horizontal position of the mouse cursor.
			 * \param y The vertical position of the mouse cursor.
			 */
			inline void setCursorPosition(std::int32_t x, std::int32_t y)
			{
				_xPosition = x;
				_yPosition = y;
			}

		//----------------------------------------------------------------------
		// Member variables
		//----------------------------------------------------------------------

		private:

			friend class Game;

			/// The horizontal position of the mouse cursor
			std::int32_t _xPosition;
			/// The vertical position of the mouse cursor
			std::int32_t _yPosition;
			/// The state of the mouse buttons
			ButtonState::Enum _buttonStates[MouseButtons::Size];

	} ; // end class MouseState

} // end namespace Lithium

#endif // end LITHIUM_MOUSE_STATE_HPP_INCLUDED

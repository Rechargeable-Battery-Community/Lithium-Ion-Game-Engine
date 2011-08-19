/**
 * \file GamePadState.hpp
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

#ifndef LITHIUM_GAME_PAD_STATE_HPP_INCLUDED
#define LITHIUM_GAME_PAD_STATE_HPP_INCLUDED

#include <Lithium/System/Includes.hpp>
#include <Lithium/Mathematics/Vector.hpp>
#include <Lithium/Input/Buttons.hpp>
#include <Lithium/Input/ButtonState.hpp>

namespace Lithium
{
	//----------------------------------------------------------------------
	// Forward declaration
	//----------------------------------------------------------------------

	class Game;

	/**
	 * Represents information about the state of an Xbox 360 Controller.
	 *
	 * \author Don Olmstead
	 * \version 0.1
	 */
	class GamePadState
	{
		//----------------------------------------------------------------------
		// Construction
		//----------------------------------------------------------------------

		public:

			/**
			 * Creates an instance of the GamePadState class.
			 */
			GamePadState();

			/**
			 * Initializes an instance of the GamePadState class.
			 *
			 * \param copy The instance to copy.
			 */
			GamePadState(const GamePadState& copy);

		//----------------------------------------------------------------------
		// Assignment
		//----------------------------------------------------------------------

		public:

			/**
			 * Copies the values from the given instance.
			 *
			 * \param copy The instance to copy.
			 */
			GamePadState& operator= (const GamePadState& copy);

		//----------------------------------------------------------------------
		// Properties
		//----------------------------------------------------------------------

		public:

			inline bool isConnected() const
			{
				return _connected;
			}

			inline const Vector2f& getLeftThumbstick() const
			{
				return _leftThumbstick;
			}

			inline const Vector2f& getRightThumbstick() const
			{
				return _rightThumbstick;
			}

			inline float getLeftTrigger() const
			{
				return _leftTrigger;
			}

			inline float getRightTrigger() const
			{
				return _rightTrigger;
			}

		private:

			inline std::int32_t getPacketNumber() const
			{
				return _packetNumber;
			}

			inline void setLeftThumbstick(float x, float y)
			{
				_leftThumbstick.set_values(x, y);
			}

			inline void setRightThumbstick(float x, float y)
			{
				_rightThumbstick.set_values(x, y);
			}

			inline void setLeftTrigger(float value)
			{
				_leftTrigger = value;
			}

			inline void setRightTrigger(float value)
			{
				_rightTrigger = value;
			}

		//----------------------------------------------------------------------
		// Methods
		//----------------------------------------------------------------------

		public:

			inline bool isButtonUp(Buttons::Enum button) const
			{
				return !_buttonFlags.is_set(button);
			}

			inline bool isButtonDown(Buttons::Enum button) const
			{
				return _buttonFlags.is_set(button);
			}

			inline std::uint16_t getButtonFlags() const
			{
				return _buttonFlags;
			}

		private:

			inline void setButtonFlags(std::uint16_t flags)
			{
				_buttonFlags.set_values(flags);
			}

		//----------------------------------------------------------------------
		// Member variables
		//----------------------------------------------------------------------

		private:

			friend class Game;

			bool _connected;
			std::int32_t _packetNumber;
			float _leftTrigger;
			float _rightTrigger;
			Vector2f _leftThumbstick;
			Vector2f _rightThumbstick;
			ButtonFlags _buttonFlags;

	} ; // end class GamePadState

} // end namespace Lithium

#endif // end LITHIUM_GAME_PAD_STATE_HPP_INCLUDED

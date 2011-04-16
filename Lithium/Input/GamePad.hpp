/**
 * \file GamePad.hpp
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

#ifndef LITHIUM_GAME_PAD_HPP_INCLUDED
#define LITHIUM_GAME_PAD_HPP_INCLUDED

#include <Lithium/System/PlayerIndex.hpp>
#include <Lithium/Input/GamePadState.hpp>

namespace Lithium
{
	/**
	 * Allows retrieval of user interaction with an Xbox 360 controller.
	 *
	 * \author Don Olmstead
	 * \version 0.1
	 */
	namespace GamePad
	{
		/**
		 * Gets the current state of a game pad controller.
		 *
		 * \returns The current state of a game pad controller.
		 */
		const GamePadState& getState(PlayerIndex::Enum player);

		/**
		 * Sets the virbration motor speeds of an Xbox 360 controller.
		 *
		 * \param leftMotor The speed of the low-frequency left motor.
		 * \param rightMoto The speed of the high-frequency right motor.
		 */
		void setVibration(PlayerIndex::Enum player, const float leftMotor, const float rightMotor);

	} // end namespace GamePad

} // end namespace Lithium

#endif // end LITHIUM_GAME_PAD_HPP_INCLUDED

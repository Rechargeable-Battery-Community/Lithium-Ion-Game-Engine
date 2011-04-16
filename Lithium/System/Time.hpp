/**
 * \file Time.hpp
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

#ifndef LITHIUM_TIME_HPP_INCLUDED
#define LITHIUM_TIME_HPP_INCLUDED

#include <Lithium/System/Includes.hpp>

namespace Lithium
{
	// Forward declaration
	class Game;

	class Time
	{
		public:

			/**
			 * Gets the total amount of time since the game started.
			 *
			 * The time is expressed in seconds.
			 *
			 * \returns The total amount of time since the game started.
			 */
			inline static float getTime()
			{
				return _totalTime;
			}

			/**
			 * Gets the time in seconds since the last frame.
			 *
			 * The time is expressed in seconds.
			 *
			 * \returns The time in seconds since the last frame.
			 */
			inline static float getDeltaTime()
			{
				return _deltaTime;
			}

			/**
			 * Gets the delta time after smoothing is applied.
			 *
			 * The time is expressed in seconds.
			 *
			 * \returns The delta time after smoothing is applied.
			 */
			inline static float getSmoothedDeltaTime()
			{
				return _smoothedDeltaTime;
			}
			
		private:

			friend class Game;

			/// The total amount to time since the game started
			static float _totalTime;
			/// The time in seconds since the last frame.
			static float _deltaTime;
			/// The delta time after smoothing is applied
			static float _smoothedDeltaTime;

			/**
			 * Creates an instance of the Time class.
			 */
			Time() 
			{ }

			static void initialize();

			/**
			 * Updates the values held in the Time class.
			 */
			static void update();

			/**
			 * Gets the current time.
			 *
			 * Querying the time is dependent on the underlying operating
			 * system.
			 *
			 * \returns The current time.
			 */
			static float getCurrentTime();

	} ; // end class Time

} // end namespace Lithium

#endif // end LITHIUM_TIME_HPP_INCLUDED

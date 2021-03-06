/**
 * \file KeyState.hpp
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

#ifndef LITHIUM_KEY_STATE_HPP_INCLUDED
#define LITHIUM_KEY_STATE_HPP_INCLUDED

namespace Lithium
{
	/**
	 * Identifies the state of a keyboard key.
	 *
	 * \author Don Olmstead
	 * \version 0.1
	 */
	namespace KeyState
	{
		/// An enumerated type
		enum Enum
		{
			/// Key is released
			Up,
			/// Key is pressed
			Down,
			/// The number of enumerations
			Size

		} ; // end enum Enum

	} // end namespace KeyState

} // end namespace Lithium

#endif // end LITHIUM_KEY_STATE_HPP_INCLUDED

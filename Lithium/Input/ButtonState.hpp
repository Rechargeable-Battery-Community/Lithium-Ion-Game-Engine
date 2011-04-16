/**
 * \file ButtonState.hpp
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

#ifndef LITHIUM_BUTTON_STATE_HPP_INCLUDED
#define LITHIUM_BUTTON_STATE_HPP_INCLUDED

namespace Lithium
{
	/**
	 * Identifies the state of a button.
	 *
	 * \author Don Olmstead
	 * \version 0.1
	 */
	namespace ButtonState
	{
		/// An enumerated type
		enum Enum
		{
			/// The button is released
			Released,
			/// The button is pressed
			Pressed,
			/// The number of enumerations
			Size

		} ; // end enum Enum

	} // end namespace ButtonState

} // end namespace Lithium

#endif // end LITHIUM_BUTTON_STATE_HPP_INCLUDED

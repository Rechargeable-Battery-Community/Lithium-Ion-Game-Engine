/**
 * \file MouseButtons.hpp
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

#ifndef LITHIUM_MOUSE_BUTTONS_HPP_INCLUDED
#define LITHIUM_MOUSE_BUTTONS_HPP_INCLUDED

namespace Lithium
{
	/**
	 * Identifies a particular button on a mouse.
	 *
	 * \author Don Olmstead
	 * \version 0.1
	 */
	namespace MouseButtons
	{
		/// An enumerated type
		enum Enum
		{
			/// Left mouse button
			Left,
			/// Middle mouse button
			Middle,
			/// Right mouse button
			Right,
			/// An additional mouse button
			X1,
			/// An additional mouse button
			X2,
			/// The number of enumerations
			Size

		} ; // end enum Enum

	} // end namespace MouseButtons

} // end namespace Lithium

#endif // end LITHIUM_MOUSE_BUTTONS_HPP_INCLUDED

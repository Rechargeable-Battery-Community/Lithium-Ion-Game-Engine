/**
 * \file PlayerIndex.hpp
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

#ifndef LITHIUM_PLAYER_INDEX_HPP_INCLUDED
#define LITHIUM_PLAYER_INDEX_HPP_INCLUDED

namespace Lithium
{
	/**
	 * Specifies the game controller associated with a player.
	 *
	 * \author Don Olmstead
	 * \version 0.1
	 */
	namespace PlayerIndex
	{
		/// An enumerated type
		enum Enum
		{
			/// The first controller
			One,
			/// The second controller
			Two,
			/// The third controller
			Three,
			/// The fourth controller
			Four,
			/// The number of enumerations
			Size

		} ; // end enum Enum

	} // end namespace PlayerIndex

} // end namespace Lithium

#endif // end LITHIUM_PLAYER_INDEX_HPP_INCLUDED

/**
 * \file BlendFunction.hpp
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

#ifndef LITHIUM_BLEND_FUNCTION_HPP_INCLUDED
#define LITHIUM_BLEND_FUNCTION_HPP_INCLUDED

namespace Lithium
{
	/**
	 * Defines how to combine a source color with the destination color.
	 *
	 * \author Don Olmstead
	 * \version 0.1
	 */
	namespace BlendFunction
	{
		/// An enumerated type
		enum Enum
		{
			/**
			 * The result is the destination added to the source.
			 * 
			 * Result = (Source Color * Source Blend) + (Destination Color * Destination Blend)
			 */
			Add,
			/**
			 * The result is the maximum of the source and destination.
			 *
			 * Result = max((Source Color * Source Blend), (Destination Color * Destination Blend))
			 */
			Max,
			/**
			 * The result is the minimum of the source and destination.
			 *
			 * Result = min((Source Color * Source Blend), (Destination Color * Destination Blend))
			 */
			Min,
			/**
			 * The result is the source subtracted from the destination.
			 *
			 * Result = (Destination Color * Destination Blend) ? (Source Color * Source Blend)
			 */
			ReverseSubtract,	
			/**
			 * The result is the destination subtracted from the source.
			 *
			 * Result = (Source Color * Source Blend) ? (Destination Color * Destination Blend)
			 */
			Subtract,
			/// The number of enumerations
			Size

		} ; // end enum Enum

	} // end namespace BlendFunction

} // end namespace Lithium

#endif // end LITHIUM_BLEND_FUNCTION_HPP_INCLUDED

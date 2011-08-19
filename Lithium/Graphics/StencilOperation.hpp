/**
 * \file StencilOperation.hpp
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

#ifndef LITHIUM_STENCIL_OPERATION_HPP_INCLUDED
#define LITHIUM_STENCIL_OPERATION_HPP_INCLUDED

namespace Lithium
{
	namespace StencilOperation
	{
		/// An enumerated type
		enum Enum
		{
			/// Decrements the stencil-buffer entry, wrapping to the maximum value if the new value is less than 0
			Decrement,
			/// Decrements the stencil-buffer entry, clamping to 0
			DecrementSaturation,
			/// Increments the stencil-buffer entry, wrapping to 0 if the new value exceeds the maximum value
			Increment,
			/// Increments the stencil-buffer entry, clamping to the maximum value
			IncrementSaturation,
			/// Inverts the bits in the stencil-buffer entry
			Invert,
			/// Does not update the stencil-buffer entry. This is the default value
			Keep,
			/// Replaces the stencil-buffer entry with a reference value
			Replace,
			/// Sets the stencil-buffer entry to 0
			Zero,
			/// The number of enumerations
			Size

		} ; // end enum Enum

	} // end namespace StencilOperation

} // end namespace Lithium

#endif // end LITHIUM_STENCIL_OPERATION_HPP_INCLUDED

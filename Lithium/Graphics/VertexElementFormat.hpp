/**
 * \file VertexElementFormat.hpp
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

#ifndef LITHIUM_VERTEX_ELEMENT_FORMAT_HPP_INCLUDED
#define LITHIUM_VERTEX_ELEMENT_FORMAT_HPP_INCLUDED

namespace Lithium
{
	/**
	 * Defines vertex element formats.
	 *
	 * \author Don Olmstead
	 * \version 0.1
	 */
	namespace VertexElementFormat
	{
		/// An enumerated type
		enum Enum
		{
			/// Single-component, 32-bit floating-point element
			Scalar,
			/// Two-component, 32-bit floating-point, element
			Vector2,
			/// Three-component, 32-bit floating point, element
			Vector3,
			/// Four-component, 32-bit floating point, element
			Vector4,
			/// The number of enumerations
			Size

		} ; // end enum Enum

	} // end namespace VertexElementFormat

} // end namespace Lithium

#endif // end LITHIUM_VERTEX_ELEMENT_FORMAT_HPP_INCLUDED

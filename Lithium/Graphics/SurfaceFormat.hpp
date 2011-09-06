/**
 * \file SurfaceFormat.hpp
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

#ifndef LITHIUM_SURFACE_FORMAT_HPP_INCLUDED
#define LITHIUM_SURFACE_FORMAT_HPP_INCLUDED

namespace Lithium
{
	/**
	 * Defines various types of surface formats.
	 *
	 * \author Don Olmstead
	 * \version 0.1
	 */
	namespace SurfaceFormat
	{
		/// An enumerated type
		enum Enum
		{
			/**
			 * 32-bit ARGB pixel format with alpha, using 8 bits per channel.
			 */
			Color,
			/// The number of enumerations
			Size

		} ; // end enum Enum

	} // end namespace SurfaceFormat

} // end namespace Lithium

#endif // end LITHIUM_SURFACE_FORMAT_HPP_INCLUDED

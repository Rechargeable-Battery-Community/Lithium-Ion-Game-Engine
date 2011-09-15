/**
 * \file BufferUsage.hpp
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

#ifndef LITHIUM_BUFFER_USAGE_HPP_INCLUDED
#define LITHIUM_BUFFER_USAGE_HPP_INCLUDED

namespace Lithium
{
	/**
	 * Defines the expected usage of a buffer.
	 *
	 * \author Don Olmstead
	 * \version 0.1
	 */
	namespace BufferUsage
	{
		/// An enumerated type
		enum Enum
		{
			/**
			 * Contents of the buffer will not change.
			 *
			 * Reading and writing the contents is disabled.
			 */
			Static,
			/**
			 * Contents of the buffer will change.
			 *
			 * The buffer can be read and written to.
			 */
			Dynamic,
			/**
			 * Contents of the buffer will change frequently.
			 *
			 * The buffer will be written to each time it is accessed.
			 */
			Stream,
			/// The number of enumerations
			Size

		} ; // end enum Enum

	} // end namespace BufferUsage

} // end namespace Lithium

#endif // end LITHIUM_BUFFER_USAGE_HPP_INCLUDED

/**
 * \file HttpMethod.hpp
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

#ifndef LITHIUM_HTTP_METHOD_HPP_INCLUDED
#define LITHIUM_HTTP_METHOD_HPP_INCLUDED

namespace Lithium
{
	namespace HttpMethod
	{
		/// An enumerated type
		enum Enum
		{
			/// Requests a representation of the specified resource.
			Get,
			/// Submits data to be processed to the identified resource.
			Post,
			/// Uploads a representation of the specified resource.
			Put,
			/// Deletes the specified resource.
			Delete,
			/// The number of enumerations.
			Size

		} ; // end enum Enum

	} // end namespace HttpMethod

} // end namespace Lithium

#endif // end LITHIUM_HTTP_METHOD_HPP_INCLUDED

/**
 * \file CompareFunction.hpp
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

#ifndef LITHIUM_COMPARE_FUNCTION_HPP_INCLUDED
#define LITHIUM_COMPARE_FUNCTION_HPP_INCLUDED

namespace Lithium
{
	/**
	 * Defines comparison functions for alpha, stencil, or depth-buffer tests.
	 *
	 * \author Don Olmstead
	 * \version 0.1
	 */
	namespace CompareFunction
	{
		/// An enumerated type
		enum Enum
		{
			/// Always pass the test
			Always,
			/// Accept the new pixel if its value is equal to the value of the current pixel
			Equal,
			/// Accept the new pixel if its value is greater than the value of the current pixel
			Greater,
			/// Accept the new pixel if its value is greater than or equal to the value of the current pixel
			GreaterEqual,
			/// Accept the new pixel if its value is less than the value of the current pixel
			Less,
			/// Accept the new pixel if its value is less than or equal to the value of the current pixel
			LessEqual,
			/// Always fail the test
			Never,
			/// Accept the new pixel if its value does not equal the value of the current pixel
			NotEqual,
			/// The number of enumerations
			Size

		} ; // end enum Enum

	} // end namespace CompareFunction

} // end namespace Lithium

#endif // end LITHIUM_COMPARE_FUNCTION_HPP_INCLUDED

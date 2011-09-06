/**
 * \file TextureFilter.hpp
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

#ifndef LITHIUM_TEXTURE_FILTER_HPP_INCLUDED
#define LITHIUM_TEXTURE_FILTER_HPP_INCLUDED

namespace Lithium
{
	/**
	 * Defines filtering types during texture sampling.
	 *
	 * \author Don Olmstead
	 * \version 0.1
	 */
	namespace TextureFilter
	{
		/// An enumerated type
		enum Enum
		{
			/// Use linear filtering
			Linear,
			/// Use point filtering
			Point,
			/// Use anisotropic filtering
			Anisotropic,
			/**
			 * Use linear filtering to shrink or expand, and point filtering between mipmap levels
			 */
			LinearMipPoint,
			/**
			 * Use point filtering to shrink (minify) or expand (magnify), and linear filtering between mipmap levels
			 */
			PointMipLinear,
			/**
			 * Use linear filtering to shrink, point filtering to expand, and linear filtering between mipmap levels
			 */
			MinLinearMagPointMipLinear,
			/**
			 * Use linear filtering to shrink, point filtering to expand, and point filtering between mipmap levels
			 */
			MinLinearMagPointMipPoint,
			/**
			 * Use point filtering to shrink, linear filtering to expand, and linear filtering between mipmap levels
			 */
			MinPointMagLinearMipLinear,
			/**
			 * Use point filtering to shrink, linear filtering to expand, and point filtering between mipmap levels.
			 */
			MinPointMagLinearMipPoint,
			/// The number of enumerations
			Size

		} ; // end enum Enum

	} // end namespace TextureFilter

} // end namespace Lithium

#endif // end LITHIUM_TEXTURE_FILTER_HPP_INCLUDED

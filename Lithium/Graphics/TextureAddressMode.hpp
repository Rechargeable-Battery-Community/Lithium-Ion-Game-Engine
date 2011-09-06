/**
 * \file TextureAddressMode.hpp
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

#ifndef LITHIUM_TEXTURE_ADDRESS_MODE_HPP_INCLUDED
#define LITHIUM_TEXTURE_ADDRESS_MODE_HPP_INCLUDED

namespace Lithium
{
	/**
	 * Defines modes for addressing texels using texture coordinates.
	 *
	 * These modes refer to coordinates outside the typical range of 0.0 to 1.0.
	 *
	 * \author Don Olmstead
	 * \version 0.1
	 */
	namespace TextureAddressMode
	{
		/// An enumerated type
		enum Enum
		{
			/**
			 * Texture coordinates outside the range are set to 0.0, or 1.0.
			 */
			Clamp,
			/**
			 * Tiles the texture, but flips it at every integer junction.
			 *
			 * As an example, coordinates between 0 and 1 are addressed normally;
			 * coordinates between 1 and 2 is flipped; coordinates between 2 and 3
			 * are addressed normally.
			 */
			Mirror,
			/**
			 * Tiles the texture at every integer junction.
			 */
			Wrap,
			/// The number of enumerations
			Size

		} ; // end enum Enum

	} // end namespace TextureAddressMode

} // end namespace Lithium

#endif // end LITHIUM_TEXTURE_ADDRESS_MODE_HPP_INCLUDED

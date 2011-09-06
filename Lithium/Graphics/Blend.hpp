/**
 * \file Blend.hpp
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

#ifndef LITHIUM_BLEND_HPP_INCLUDED
#define LITHIUM_BLEND_HPP_INCLUDED

namespace Lithium
{
	/**
	 * Defines color blending factors.
	 *
	 * \author Don Olmstead
	 * \version 0.1
	 */
	namespace Blend
	{
		/// An enumerated type
		enum Enum
		{
			/**
			 * Each component of the color is multiplied by (0, 0, 0, 0).
			 */
			Zero,
			/**
			 * Each component of the color is multiplied by (1, 1, 1, 1).
			 */
			One,
			/**
			 * Each component of the color is multiplied by the source color.
			 *
			 * This can be represented as (Rs, Gs, Bs, As), where R, G, B, and A
			 * respectively stand for the red, green, blue, and alpha source values.
			 */
			SourceColor,
			/**
			 * Each component of the color is multiplied by the inverse of the source color.
			 *
			 * This can be represented as (1 ? Rs, 1 ? Gs, 1 ? Bs, 1 ? As) where R, G, B, and A
			 * respectively stand for the red, green, blue, and alpha destination values.
			 */
			InverseSourceColor,
			/**
			 * Each component of the color is multiplied by the alpha value of the source.
			 *
			 * This can be represented as (As, As, As, As), where As is the alpha source value.
			 */
			SourceAlpha,
			/**
			 * Each component of the color is multiplied by the inverse of the alpha value of the source.
			 *
			 * This can be represented as (1 ? As, 1 ? As, 1 ? As, 1 ? As), where As is the alpha destination value.
			 */
			InverseSourceAlpha,
			/**
			 * Each component of the color is multiplied by the alpha value of the destination.
			 *
			 * This can be represented as (Ad, Ad, Ad, Ad), where Ad is the destination alpha value.
			 */
			DestinationAlpha,
			/**
			 * Each component of the color is multiplied by the inverse of the alpha value of the destination.
			 *
			 * This can be represented as (1 ? Ad, 1 ? Ad, 1 ? Ad, 1 ? Ad), where Ad is the alpha destination value.
			 */
			InverseDestinationAlpha,
			/**
			 * Each component color is multiplied by the destination color.
			 *
			 * This can be represented as (Rd, Gd, Bd, Ad), where R, G, B, and A
			 * respectively stand for red, green, blue, and alpha destination values.
			 */
			DestinationColor,
			/**
			 * Each component of the color is multiplied by the inverse of the destination color.
			 *
			 * This can be represented as (1 ? Rd, 1 ? Gd, 1 ? Bd, 1 ? Ad), where Rd, Gd, Bd, and Ad
			 * respectively stand for the red, green, blue, and alpha destination values.
			 */
			InverseDestinationColor,
			/**
			 * Each component of the color is multiplied by either the alpha of the source color, or the inverse of the alpha of the source color, whichever is greater.
			 *
			 * This can be represented as (f, f, f, 1), where f = min(A, 1 ? Ad).
			 */
			SourceAlphaSaturation,
			/**
			 * Each component of the color is multiplied by a constant set in BlendFactor.
			 */
			BlendFactor,
			/**
			 * Each component of the color is multiplied by the inverse of a constant set in BlendFactor.
			 */
			InverseBlendFactor,
			/// The number of enumerations
			Size

		} ; // end enum Enum

	} // end namespace Blend

} // end namespace Lithium

#endif // end LITHIUM_BLEND_HPP_INCLUDED

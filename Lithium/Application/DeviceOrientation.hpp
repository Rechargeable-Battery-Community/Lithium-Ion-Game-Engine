/**
 * \file DeviceOrientation.hpp
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

#ifndef LITHIUM_DEVICE_ORIENTATION_HPP_INCLUDED
#define LITHIUM_DEVICE_ORIENTATION_HPP_INCLUDED

namespace Lithium
{
	/**
	 * Defines the display orientation.
	 *
	 * Only applicable for development on a mobile device.
	 *
	 * \author Don Olmstead
	 * \version 0.1
	 */
	namespace DeviceOrientation
	{
		/// An enumerated type
		enum Enum
		{
			/// The default display orientation
			Default,
			/**
			 * The display is rotated counterclockwise 90 degrees into a landscape orientation.
			 *
			 * In landscape mode the width is greater than the height.
			 */
			 LandscapeLeft,
			/**
			 * The display is rotated clockwise 90 degrees into a landscape orientation.
			 *
			 * In landscape mode the width is greater than the height.
			 */
			 LandscapeRight,
			 /**
			  * The orientation is a portrait.
			  *
			  * In portrait mode the height is greater than the width.
			  */
			 Portrait,
			 /// The number of enumerations.
			 Size

		} ; // end enum Enum

	} // end namespace DeviceOrientation

} // end namespace Lithium

#endif // end LITHIUM_DEVICE_ORIENTATION_HPP_INCLUDED

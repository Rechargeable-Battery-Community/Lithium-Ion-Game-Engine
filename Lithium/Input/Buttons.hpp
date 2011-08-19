/**
 * \file Buttons.hpp
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

#ifndef LITHIUM_BUTTONS_HPP_INCLUDED
#define LITHIUM_BUTTONS_HPP_INCLUDED

#include <rtl/flags.hpp>

namespace Lithium
{
	/**
	 * Enumerates input device buttons.
	 *
	 * \author Don Olmstead
	 * \version 0.1
	 */
	namespace Buttons
	{
		/// An enumerated type
		enum Enum
		{
			//----------------------------------------------------------------------
			// D-pad
			//----------------------------------------------------------------------

			/// Directional pad up
			DPadUp,
			/// Directional pad left
			DPadLeft,
			/// Directional pad right
			DPadRight,
			/// Directional pad down
			DPadDown,

			//----------------------------------------------------------------------
			// Start/Back
			//----------------------------------------------------------------------

			/// START button
			Start,
			/// BACK button
			Back,

			//----------------------------------------------------------------------
			// Thumbstick
			//----------------------------------------------------------------------

			/// Left stick button
			LeftStick,
			/// Right stick button
			RightStick,

			//----------------------------------------------------------------------
			// Shoulder
			//----------------------------------------------------------------------

			/// Left bumper (shoulder) button
			LeftShoulder,
			/// Right bumper (shoulder) button
			RightShoulder,

			//----------------------------------------------------------------------
			// Action
			//----------------------------------------------------------------------

			/// A button
			A = 11,
			/// B button
			B,
			/// X button
			X,
			/// Y button
			Y,

			//----------------------------------------------------------------------
			// Count
			//----------------------------------------------------------------------

			/// The number of enumerations
			Size

		} ; // end enum Enum

		struct Names
		{
			/// DPadUp flag
			std::uint32_t DPadUp:1;
			/// DPadDown flag
			std::uint32_t DPadDown:1;
			/// DPadLeft flag
			std::uint32_t DPadLeft:1;
			/// DPadRight flag
			std::uint32_t DPadRight:1;
			/// Start flag
			std::uint32_t Start:1;
			/// Back flag
			std::uint32_t Back:1;
			/// LeftThumb flag
			std::uint32_t LeftThumb:1;
			/// RightThumb flag
			std::uint32_t RightThumb:1;
			/// LeftShoulder flag
			std::uint32_t LeftShoulder:1;
			/// RightShoulder flag
			std::uint32_t RightShoulder:1;
			/// Unused
			std::uint32_t UnusedFlag1:1;
			/// Unused
			std::uint32_t UnusedFlag2:1;
			/// A flag
			std::uint32_t AFlag:1;
			/// B flag
			std::uint32_t BFlag:1;
			/// X flag
			std::uint32_t XFlag:1;
			/// Y flag
			std::uint32_t YFlag:1;

		} ; // end struct Names

	} // end namespace Buttons

	/// Flag enumeration
	typedef rtl::flag_set<Buttons::Enum, Buttons::Size, Buttons::Names> ButtonFlags;

} // end namespace Lithium

#endif // end LITHIUM_BUTTONS_HPP_INCLUDED

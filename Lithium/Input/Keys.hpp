/**
 * \file Keys.hpp
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

#ifndef LITHIUM_KEYS_HPP_INCLUDED
#define LITHIUM_KEYS_HPP_INCLUDED

namespace Lithium
{
	/**
	 * Identifies a particular key on a keyboard.
	 *
	 * \author Don Olmstead
	 * \version 0.1
	 */
	namespace Keys
	{
		/// An enumerated type
		enum Enum
		{
			//----------------------------------------------------------------------
			// Function keys
			//----------------------------------------------------------------------

			/// F1 key
			F1,
			/// F2 key
			F2,
			/// F3 key
			F3,
			/// F4 key
			F4,
			/// F5 key
			F5,
			/// F6 key
			F6,
			/// F7 key
			F7,
			/// F8 key
			F8,
			/// F9 key
			F9,
			/// F10 key
			F10,
			/// F11 key
			F11,
			/// F12 key
			F12,
			/// F13 key
			F13,
			/// F14 key
			F14,
			/// F15 key
			F15,
			/// F16 key
			F16,
			/// F17 key
			F17,
			/// F18 key
			F18,
			/// F19 key
			F19,
			/// F20 key
			F20,
			/// F21 key
			F21,
			/// F22 key
			F22,
			/// F23 key
			F23,
			/// F24 key
			F24,

			//----------------------------------------------------------------------
			// ASCII keys
			//----------------------------------------------------------------------

			/// Tab key
			Tab,
			/// Caps lock
			CapsLock,
			/// Backspace key
			Back,
			/// Enter key
			Enter,
			/// A key
			A,
			/// B key
			B,
			/// C key
			C,
			/// D key
			D,
			/// B key
			E,
			/// B key
			F,
			/// B key
			G,
			/// B key
			H,
			/// B key
			I,
			/// B key
			J,
			/// B key
			K,
			/// B key
			L,
			/// B key
			M,
			/// B key
			N,
			/// B key
			O,
			/// B key
			P,
			/// B key
			Q,
			/// B key
			R,
			/// B key
			S,
			/// B key
			T,
			/// B key
			U,
			/// B key
			V,
			/// B key
			W,
			/// B key
			X,
			/// B key
			Y,
			/// B key
			Z,
			/// Space key
			Space,
			/// Left ALT key
			LeftAlt,
			/// Left CTRL key
			LeftControl,
			/// Left SHIFT key
			LeftShift,
			/// Left Windows key
			LeftWindows,
			/// Right ALT key
			RightAlt,
			/// Right CTRL key
			RightControl,
			/// Right SHIFT key
			RightShift,
			/// Right Windows key
			RightWindows,

			//----------------------------------------------------------------------
			// Other keys
			//----------------------------------------------------------------------

			/// ESC key
			Escape,
			/// PRINT SCREEN key
			PrintScreen,
			/// SCROLL LOCK key
			Scroll,
			/// PAUSE key
			Pause,
			/// INS key
			Insert,
			/// DEL key
			Delete,
			/// HOME key
			Home,
			/// END key
			End,
			/// PAGE UP key
			PageUp,
			/// PAGE DOWN key
			PageDown,

			//----------------------------------------------------------------------
			// Arrow keys
			//----------------------------------------------------------------------

			/// Left arrow key
			Left,
			/// Up arrow key
			Up,
			/// Right arrow key
			Right,
			/// Down arrow key
			Down,

			//----------------------------------------------------------------------
			// Numpad
			//----------------------------------------------------------------------

			/// Numeric keypad 0 key
			NumPad0,
			/// Numeric keypad 1 key
			NumPad1,
			/// Numeric keypad 2 key
			NumPad2,
			/// Numeric keypad 3 key
			NumPad3,
			/// Numeric keypad 4 key
			NumPad4,
			/// Numeric keypad 5 key
			NumPad5,
			/// Numeric keypad 6 key
			NumPad6,
			/// Numeric keypad 7 key
			NumPad7,
			/// Numeric keypad 8 key
			NumPad8,
			/// Numeric keypad 9 key
			NumPad9,
			/// Multiply key
			Multiply,
			/// Add key
			Add,
			/// Separator key
			Separator,
			/// Subtract key
			Subtract,
			/// Decimal key
			Decimal,

			/// The number of enumerations
			Size

		} ; // end enum Enum

	} // end namespace Keys

} // end namespace Lithium

#endif // end LITHIUM_KEYS_HPP_INCLUDED

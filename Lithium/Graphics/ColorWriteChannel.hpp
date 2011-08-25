/**
 * \file ColorWriteChannel.hpp
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

#ifndef LITHIUM_COLOR_WRITE_CHANNEL_HPP_INCLUDED
#define LITHIUM_COLOR_WRITE_CHANNEL_HPP_INCLUDED

#include <Lithium/System/Includes.hpp>

namespace Lithium
{
	/**
	 * Defines the color channels that can be written to.
	 *
	 * \author Don Olmstead
	 * \version 0.1
	 */
	namespace ColorWriteChannel
	{
		/// An enumerated type
		enum Enum
		{
			/// The red channel
			Red,
			/// The green channel
			Green,
			/// The blue channel
			Blue,
			/// The alpha channel
			Alpha,
			/// The number of enumerations
			Size

		} ; // end enum Enum

		/// All channels enabled
		const std::uint8_t All = (1 << Red) | (1 << Green) | (1 << Blue) | (1 << Alpha);

		/// Debugging information
		struct Names
		{
			/// Red flag
			std::uint32_t Red:1;
			/// Green flag
			std::uint32_t Green:1;
			/// Blue flag
			std::uint32_t Blue:1;
			/// Alpha flag
			std::uint32_t Alpha:1;

		} ; // end struct Names

	} // end namespace ColorWriteChannels

	/// Flag enumeration
	typedef rtl::flag_set<ColorWriteChannel::Enum, ColorWriteChannel::Size, ColorWriteChannel::Names> ColorWriteChannelFlags;

} // end namespace Lithium

#endif // end LITHIUM_COLOR_WRITE_CHANNEL_HPP_INCLUDED

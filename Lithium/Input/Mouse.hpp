/**
 * \file Mouse.hpp
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

#ifndef LITHIUM_MOUSE_HPP_INCLUDED
#define LITHIUM_MOUSE_HPP_INCLUDED

#include <Lithium/Input/MouseState.hpp>

namespace Lithium
{
	/**
	 * Allows retrieval of position and button clicks from a mouse.
	 *
	 * \author Don Olmstead
	 * \version 0.1
	 */
	namespace Mouse
	{
		const MouseState& getState();

		void setPosition(std::uint32_t x, std::uint32_t y);

	} ; // end namespace Mouse

} // end namespace Lithium

#endif // end LITHIUM_MOUSE_HPP_INCLUDED

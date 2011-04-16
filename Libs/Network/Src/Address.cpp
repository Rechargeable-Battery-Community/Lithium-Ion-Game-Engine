/**
 * \file Address.cpp
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

#include "LithiumNetworkPCH.hpp"
#include <Lithium/Network/IPAddress.hpp>
using namespace Lithium;

//---------------------------------------------------------------------

void IPAddress::toDotDecimal(std::uint8_t& a, std::uint8_t& b, std::uint8_t& c, std::uint8_t& d) const
{
	a =  _address >> 24;
	b = (_address & 0x00FF0000) >> 16;
	c = (_address & 0x0000FF00) >>  8;
	d =  _address & 0x000000FF;
}

//---------------------------------------------------------------------

std::ostream& operator<< (std::ostream& output, const IPAddress& address)
{
	std::uint8_t a, b, c, d;

	address.toDotDecimal(a, b, c, d);

	output
		<< (std::uint32_t)a << "." 
		<< (std::uint32_t)b << "." 
		<< (std::uint32_t)c << "."
		<< (std::uint32_t)d;

	return output;
}

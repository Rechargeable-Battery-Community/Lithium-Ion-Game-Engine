/**
 * \file Includes.hpp
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

#ifndef LITHIUM_SYSTEM_INCLUDES_HPP
#define LITHIUM_SYSTEM_INCLUDES_HPP

//----------------------------------------------------------------------
// STL includes
//----------------------------------------------------------------------

#include <cstdint>
#include <cstddef>

#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <fstream>

//----------------------------------------------------------------------
// TR1 includes
//----------------------------------------------------------------------

#include <regex>
#include <array>

//----------------------------------------------------------------------
// Debug macro
//----------------------------------------------------------------------

#include <Lithium/System/Debug.hpp>

//----------------------------------------------------------------------
// RTL includes
//----------------------------------------------------------------------

#include <rtl/flags.hpp>
#include <rtl/reflection.hpp>

//----------------------------------------------------------------------
// Min/Max
//----------------------------------------------------------------------

template <typename T>
inline T min(const T& a, const T& b)
{
	return (a < b) ? a : b;
}

template <typename T>
inline T max(const T& a, const T& b)
{
	return (a > b) ? a : b;
}

#endif // end LITHIUM_SYSTEM_INCLUDES_HPP

/**
 * \file LithiumCoreLIB.hpp
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

#ifndef LITHIUM_CORE_LIB_HPP_INCLUDED
#define LITHIUM_CORE_LIB_HPP_INCLUDED

// For the DLL library
#if defined(LITHIUM_CORE_DLL_EXPORT)
#define LITHIUM_CORE_ITEM __declspec(dllexport)

// For a client of the DLL library
#elif defined(LITHIUM_CORE_DLL_IMPORT)
#define LITHIUM_CORE_ITEM __declspec(dllimport)

// For the state library
#else
#define LITHIUM_CORE_ITEM

#endif

#endif // end LITHIUM_CORE_LIB_HPP_INCLUDED

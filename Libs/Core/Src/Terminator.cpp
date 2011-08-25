/**
 * \file Terminator.cpp
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

#include "LithiumCorePCH.hpp"
#include <Lithium/System/Terminator.hpp>
using namespace Lithium;

namespace
{
	/// The maximum number of terminators
	const std::size_t __maxTerminators = 128;
	/// The individual terminators
	Terminator::TermFunction __terminators[__maxTerminators];
	/// The number of terminators
	std::size_t __terminatorCount = 0;

} // end namespace

//---------------------------------------------------------------------

void Terminator::addTerminator(Terminator::TermFunction term)
{
	LITHIUM_ASSERT(__terminatorCount < __maxTerminators, "Too many terminators. Modify the maximum elements");

	__terminators[__terminatorCount++] = term;
}

//---------------------------------------------------------------------

void Terminator::execute()
{
	for (std::size_t i = 0; i < __terminatorCount; ++i)
		__terminators[i]();
}

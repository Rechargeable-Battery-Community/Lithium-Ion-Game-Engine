/**
 * \file Initializer.cpp
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
#include <Lithium/System/Initializer.hpp>
using namespace Lithium;

namespace
{
	/// The maximum number of initializers
	const std::size_t __maxInitializers = 128;
	/// The individual initializers
	Initializer::InitFunction __initializers[__maxInitializers];
	/// The number of initializers
	std::size_t __initializerCount = 0;

} // end namespace

//---------------------------------------------------------------------

void Initializer::addInitializer(Initializer::InitFunction init)
{
	LITHIUM_ASSERT(__initializerCount < __maxInitializers, "Too many initialzers. Modify the maximum elements");

	__initializers[__initializerCount++] = init;
}

//---------------------------------------------------------------------

void Initializer::execute()
{
	for (std::size_t i = 0; i < __initializerCount; ++i)
		__initializers[i]();
}

/**
 * \file Initializer.hpp
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

#ifndef LITHIUM_INITIALIZER_HPP_INCLUDED
#define LITHIUM_INITIALIZER_HPP_INCLUDED

#include <Lithium/LithiumCoreLIB.hpp>
#include <Lithium/System/Includes.hpp>

namespace Lithium
{
	namespace Initializer
	{
		typedef void (*InitFunction)();

		/**
		 * Adds an initialization function to execute.
		 *
		 * \param init The initialization function to execute.
		 */
		LITHIUM_CORE_ITEM void addInitializer(InitFunction init);

		/**
		 * Executes the initialization functions.
		 */
		LITHIUM_CORE_ITEM void execute();

	} // end namespace Initializer

} // end namespace Lithium

#define LITHIUM_DECLARE_INITIALIZE \
	public: \
		static bool registerInitialize(); \
		static void initialize(); \
	private: \
		static bool _initializeRegistered;

#define LITHIUM_IMPLEMENT_INITIALIZE(classname) \
	bool classname::_initializeRegistered = false; \
	bool classname::registerInitialize() \
	{ \
		if (!_initializeRegistered) \
		{ \
			Initializer::addInitializer(classname::initialize); \
			_initializeRegistered = true; \
		} \
		return _initializeRegistered; \
	}

#define LITHIUM_REGISTER_INITIALIZE(classname) \
	namespace \
	{ \
		bool __initializeRegistered_##classname = classname::registerInitialize(); \
	}

#endif // end LITHIUM_INITIALIZER_HPP_INCLUDED

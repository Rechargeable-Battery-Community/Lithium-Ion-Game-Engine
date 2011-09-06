/**
 * \file Terminator.hpp
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

#ifndef LITHIUM_TERMINATOR_HPP_INCLUDED
#define LITHIUM_TERMINATOR_HPP_INCLUDED

#include <Lithium/LithiumCoreLIB.hpp>
#include <Lithium/System/Includes.hpp>

namespace Lithium
{
	namespace Terminator
	{
		typedef void (*TermFunction)();

		LITHIUM_CORE_ITEM void addTerminator(TermFunction term);

		LITHIUM_CORE_ITEM void execute();

	} // end namespace Terminator

} // end namespace Lithium

#define LITHIUM_DECLARE_TERMINATE \
	public: \
		static bool registerTerminate(); \
		static void terminate(); \
	private: \
		static bool _terminateRegistered;

#define LITHIUM_IMPLEMENT_TERMINATE(classname) \
	bool classname::_terminateRegistered = false; \
	bool classname::registerTerminate() \
	{ \
		if (!_terminateRegistered) \
		{ \
			Terminator::addTerminator(classname::terminate); \
			_terminateRegistered = true; \
		} \
		return _terminateRegistered; \
	}

#define LITHIUM_REGISTER_TERMINATE(classname) \
	namespace \
	{ \
		bool __terminateRegistered_##classname = classname::registerTerminate(); \
	}

#endif // end LITHIUM_TERMINATOR_HPP_INCLUDED

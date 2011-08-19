/**
 * \file OpenGL3CommandList.cpp
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

#include "OpenGL3CommandList.hpp"
using namespace Lithium;

//---------------------------------------------------------------------

GraphicsCommandList::GraphicsCommandList()
: _finished(true)
, _currentCommand(0)
{ }

//---------------------------------------------------------------------

void GraphicsCommandList::begin()
{
	LITHIUM_ASSERT(_finished, "Command building has not finished");

	_finished = false;
	_currentCommand = 0;
}

//---------------------------------------------------------------------

void GraphicsCommandList::draw()
{
	LITHIUM_ASSERT(!_finished, "Command building has not started");

	++_currentCommand;
}

//---------------------------------------------------------------------

void GraphicsCommandList::end()
{
	LITHIUM_ASSERT(!_finished, "Command building has not started");

	_finished = true;
}

//---------------------------------------------------------------------

void GraphicsCommandList::setBlendStateBinding(const BlendStateBinding* binding)
{
	LITHIUM_ASSERT(!_finished, "Command building has not started");

	_commands[_currentCommand].blendState = binding;
}

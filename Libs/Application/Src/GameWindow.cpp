/**
 * \file GameWindow.cpp
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

#include "LithiumApplicationPCH.hpp"
#include <Lithium/Application/GameWindow.hpp>
using namespace Lithium;

//----------------------------------------------------------------------

GameWindow::GameWindow(const std::string& title, std::int32_t width, std::int32_t height, bool resizeable)
: _handle(0)
, _deviceOrientation(DeviceOrientation::Default)
, _width(width)
, _height(height)
, _resizeable(resizeable)
, _fullscreen(false)
, _title(title)
{ 
	initialize();
}

//----------------------------------------------------------------------

GameWindow::GameWindow(const std::string& title, std::int32_t width, std::int32_t height)
: _handle(0)
, _deviceOrientation(DeviceOrientation::Default)
, _width(width)
, _height(height)
, _resizeable(false)
, _fullscreen(true)
, _title(title)
{
	initialize();
}

//---------------------------------------------------------------------

void GameWindow::initialize()
{
	// Create the window
	createWindow();

	// Create the rendering context
	createContext();
}

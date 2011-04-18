/**
 * \file Time.cpp
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
#include <Lithium/System/Time.hpp>
using namespace Lithium;

float Time::_totalTime = 0.0f;
float Time::_deltaTime = 0.0f;
float Time::_smoothedDeltaTime = 0.0f;

//---------------------------------------------------------------------

void Time::update()
{
	// Get the current time
	float current = getCurrentTime();

	// Compute the delta time
	_deltaTime = current - _totalTime;

	// Set the current time
	_totalTime = current;
}
/**
 * \file Time_Windows.cpp
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

#include "../LithiumCorePCH.hpp"
#include <Lithium/System/Time.hpp>
#include "PlatformWindows.hpp"
using namespace Lithium;

namespace
{
	float __timerResolution;
	std::int64_t __startTime;

} // end namespace

//---------------------------------------------------------------------

void Time::initialize()
{
	std::int64_t frequency;

	if (QueryPerformanceFrequency((LARGE_INTEGER*)&frequency))
	{
		__timerResolution = 1.0f / (float)frequency;

		// Get the starting time
		QueryPerformanceCounter((LARGE_INTEGER*)&__startTime);
	}
	else
	{
		assert(false && "High precision timer not available");
	}
}

//---------------------------------------------------------------------

float Time::getCurrentTime()
{
	std::int64_t current;

	QueryPerformanceCounter((LARGE_INTEGER*)&current);

	return (float)(current - __startTime) * __timerResolution;
}

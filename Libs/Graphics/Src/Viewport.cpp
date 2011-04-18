/**
 * \file Viewport.cpp
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

#include <Lithium/Graphics/Viewport.hpp>
using namespace Lithium;

//---------------------------------------------------------------------

Viewport::Viewport(std::int32_t x, std::int32_t y, std::int32_t width, std::int32_t height)
: _x(x)
, _y(y)
, _width(width)
, _height(height)
, _minDepth(0.0f)
, _maxDepth(1.0f)
{ }

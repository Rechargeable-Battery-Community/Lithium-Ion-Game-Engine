/**
 * \file VertexElement.cpp
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

#include <Lithium/Graphics/VertexElement.hpp>
using namespace Lithium;

//---------------------------------------------------------------------

VertexElement::VertexElement()
: _offset(0)
, _format(VertexElementFormat::Vector4)
, _usage(VertexElementUsage::Position)
, _usageIndex(0)
{ }

//---------------------------------------------------------------------

VertexElement::VertexElement(
	std::int32_t offset,
	VertexElementFormat::Enum format,
	VertexElementUsage::Enum usage,
	std::int32_t usageIndex
)
: _offset(offset)
, _format(format)
, _usage(usage)
, _usageIndex(usageIndex)
{ }

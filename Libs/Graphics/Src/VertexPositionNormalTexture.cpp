/**
 * \file VertexPositionNormalTexture.cpp
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

#include <Lithium/VertexDefinitions/VertexPositionNormalTexture.hpp>
using namespace Lithium;

namespace
{
	/// Vertex declaration for VertexPositionTexture
	VertexDeclaration __vertexDeclaration;
}

//---------------------------------------------------------------------

const VertexDeclaration& VertexPositionNormalTexture::getVertexDeclaration()
{
	std::vector<VertexElement>& elements = __vertexDeclaration.getElements();

	if (elements.size() == 0)
	{
		std::int32_t offset = 0;
		elements.push_back(VertexElement(offset, VertexElementFormat::Vector3, VertexElementUsage::Position));
		offset += sizeof(Vector3f);
		elements.push_back(VertexElement(offset, VertexElementFormat::Vector3, VertexElementUsage::Normal));
		offset += sizeof(Vector3f);
		elements.push_back(VertexElement(offset, VertexElementFormat::Vector2, VertexElementUsage::TextureCoordinate));
	}

	return __vertexDeclaration;
}

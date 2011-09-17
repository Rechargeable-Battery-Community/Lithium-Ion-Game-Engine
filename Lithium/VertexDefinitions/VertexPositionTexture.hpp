/**
 * \file VertexPositionTexture.hpp
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

#ifndef LITHIUM_VERTEX_POSITION_TEXTURE_HPP_INCLUDED
#define LITHIUM_VERTEX_POSITION_TEXTURE_HPP_INCLUDED

#include <Lithium/Graphics/VertexDeclaration.hpp>
#include <Lithium/Mathematics/Vector.hpp>

namespace Lithium
{
	/**
	 * Describes a vertex format that contains position and one set of texture coordinates.
	 *
	 * \author Don Olmstead
	 * \version 0.1
	 */
	struct VertexPositionTexture
	{
		/// The position
		Vector3f position;
		/// The texture coordinate
		Vector2f textureCoordinate;

		/**
		 * Gets the vertex declaration, which defines per-vertex data.
		 *
		 * \returns The vertex declaration, which defines per-vertex data.
		 */
		static const VertexDeclaration& getVertexDeclaration();

	} ; // end struct VertexPositionTexture

} // end namespace Lithium

#endif // end LITHIUM_VERTEX_POSITION_TEXTURE_HPP_INCLUDED

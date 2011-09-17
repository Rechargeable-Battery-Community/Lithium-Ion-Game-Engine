/**
 * \file VertexBuffer.hpp
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

#ifndef LITHIUM_VERTEX_BUFFER_HPP_INCLUDED
#define LITHIUM_VERTEX_BUFFER_HPP_INCLUDED

#include <Lithium/Graphics/GraphicsResource.hpp>
#include <Lithium/Graphics/VertexDeclaration.hpp>

namespace Lithium
{
	class VertexBuffer : public GraphicsResource
	{
		//----------------------------------------------------------------------
		// Construction
		//----------------------------------------------------------------------

		public:

			template <typename VertexType>
			VertexBuffer(GraphicsDevice* device, const VertexType* data, std::int32_t vertexCount, BufferUsage::Enum bufferUsage = BufferUsage::Static)
			: _vertexCount(vertexCount)
			, _vertexDeclaration(VertexType::getVertexDeclaration())
			{
				device->bindVertexBuffer(this, (const void*)data, bufferUsage);
			}

		//----------------------------------------------------------------------
		// Properties
		//----------------------------------------------------------------------

		public:

			/**
			 * Gets the number of vertices.
			 *
			 * \returns The number of vertices.
			 */
			inline std::int32_t getVertexCount() const
			{
				return _vertexCount;
			}

			/**
			 * Gets the vertex declaration, which defines per-vertex data.
			 *
			 * \returns The vertex declaration, which defines per-vertex data.
			 */
			inline const VertexDeclaration& getVertexDeclaration() const
			{
				return _vertexDeclaration;
			}

		//----------------------------------------------------------------------
		// Member variables
		//----------------------------------------------------------------------
	
		private:

			/// The number of vertices
			std::int32_t _vertexCount;
			/// The vertex declaration
			const VertexDeclaration& _vertexDeclaration;

	} ; // end class VertexBuffer

} // end namespace Lithium

#endif // end LITHIUM_VERTEX_BUFFER_HPP_INCLUDED

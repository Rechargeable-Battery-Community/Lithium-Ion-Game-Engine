/**
 * \file IndexBuffer.hpp
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

#ifndef LITHIUM_INDEX_BUFFER_HPP_INCLUDED
#define LITHIUM_INDEX_BUFFER_HPP_INCLUDED

#include <Lithium/Graphics/GraphicsResource.hpp>
#include <Lithium/Graphics/BufferUsage.hpp>
#include <Lithium/Graphics/IndexElementSize.hpp>

namespace Lithium
{
	class IndexBuffer : public GraphicsResource
	{
		//----------------------------------------------------------------------
		// Construction
		//----------------------------------------------------------------------

		public:

			/**
			 * Initializes an instance of the IndexBuffer class.
			 *
			 * \param device The device to bind to.
			 * \param data The index data.
			 * \param indexCount The number of indices.
			 * \param bufferUsage The buffer behavior.
			 */
			IndexBuffer(
				GraphicsDevice* device,
				const std::uint16_t* data,
				std::size_t indexCount,
				BufferUsage::Enum bufferUsage = BufferUsage::Static
			);

			/**
			 * Initializes an instance of the IndexBuffer class.
			 *
			 * \param device The device to bind to.
			 * \param data The index data.
			 * \param indexCount The number of indices.
			 * \param bufferUsage The buffer behavior.
			 */
			IndexBuffer(
				GraphicsDevice* device,
				const std::uint32_t* data,
				std::size_t indexCount,
				BufferUsage::Enum bufferUsage = BufferUsage::Static
			);

		//----------------------------------------------------------------------
		// Properties
		//----------------------------------------------------------------------

		public:

			/**
			 * Gets the number of indices.
			 *
			 * \returns The number of indices.
			 */
			inline std::size_t getIndexCount() const
			{
				return _indexCount;
			}

			/**
			 * Gets the size of the indices.
			 *
			 * \returns The size of the indices.
			 */
			inline IndexElementSize::Enum getIndexElementSize() const
			{
				return _indexElementSize;
			}

			/**
			 * Gets the behavior of the buffer.
			 *
			 * \returns The behavior of the buffer.
			 */
			inline BufferUsage::Enum getBufferUsage() const
			{
				return _bufferUsage;
			}

		//----------------------------------------------------------------------
		// Member variables
		//----------------------------------------------------------------------

		private:

			/// The number of indices
			std::size_t _indexCount;
			/// The size of the indices
			IndexElementSize::Enum _indexElementSize;
			/// The behavior of the buffer
			BufferUsage::Enum _bufferUsage;

	} ; // end class IndexBuffer

} // end namespace Lithium

#endif // end LITHIUM_INDEX_BUFFER_HPP_INCLUDED

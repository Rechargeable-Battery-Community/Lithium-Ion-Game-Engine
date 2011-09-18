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

#ifndef LITHIUM_VERTEX_ELEMENT_HPP_INCLUDED
#define LITHIUM_VERTEX_ELEMENT_HPP_INCLUDED

#include <Lithium/System/Includes.hpp>
#include <Lithium/Graphics/VertexElementFormat.hpp>
#include <Lithium/Graphics/VertexElementUsage.hpp>

namespace Lithium
{
	class VertexElement
	{
		//----------------------------------------------------------------------
		// Construction
		//----------------------------------------------------------------------

		public:

			/**
			 * Creates an instance of the VertexElement class.
			 */
			VertexElement();

			/**
			 * Initializes an instance of the VertexElement class.
			 *
			 * \param offset Offset from the start of the stream to the start of the vertex data.
			 * \param format One of several predefined types that define the vertex data size.
			 * \param usage The intended use of the vertex data.
			 * \param usageIndex Modifies the usage data to allow the user to specify multiple usage types.
			 */
			VertexElement(
				std::int32_t offset,
				VertexElementFormat::Enum format,
				VertexElementUsage::Enum usage,
				std::int32_t usageIndex = 0
			);

		//----------------------------------------------------------------------
		// Properties
		//----------------------------------------------------------------------

		public:

			inline std::int32_t getOffset() const
			{
				return _offset;
			}

			inline void setOffset(std::int32_t value)
			{
				_offset = value;
			}

			inline VertexElementFormat::Enum getFormat() const
			{
				return _format;
			}

			inline void setFormat(VertexElementFormat::Enum value)
			{
				_format = value;
			}

			inline VertexElementUsage::Enum getUsage() const
			{
				return _usage;
			}

			inline void setUsage(VertexElementUsage::Enum value)
			{
				_usage = value;
			}

			inline std::int32_t getUsageIndex() const
			{
				return _usageIndex;
			}

			inline void setUsageIndex(std::int32_t value)
			{
				_usageIndex = value;
			}

		//----------------------------------------------------------------------
		// Member variables
		//----------------------------------------------------------------------
	
		private:

			std::int32_t _offset;
			VertexElementFormat::Enum _format;
			VertexElementUsage::Enum _usage;
			std::int32_t _usageIndex;

	} ; // end class VertexElement

} // end namespace Lithium

#endif // end LITHIUM_VERTEX_ELEMENT_HPP_INCLUDED

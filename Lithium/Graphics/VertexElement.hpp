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

namespace Lithium
{
	class VertexElement
	{
		//----------------------------------------------------------------------
		// Construction
		//----------------------------------------------------------------------

		public:

			VertexElement();

			VertexElement(std::int32_t offset, VertexElementFormat::Enum format);

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

		//----------------------------------------------------------------------
		// Member variables
		//----------------------------------------------------------------------
	
		private:

			std::int32_t _offset;
			VertexElementFormat::Enum _format;

	} ; // end class VertexElement

} // end namespace Lithium

#endif // end LITHIUM_VERTEX_ELEMENT_HPP_INCLUDED

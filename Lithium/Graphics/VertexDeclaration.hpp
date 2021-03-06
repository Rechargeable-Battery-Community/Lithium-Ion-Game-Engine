/**
 * \file VertexDeclaration.hpp
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

#ifndef LITHIUM_VERTEX_DECLARATION_HPP_INCLUDED
#define LITHIUM_VERTEX_DECLARATION_HPP_INCLUDED

#include <Lithium/Graphics/VertexElement.hpp>

namespace Lithium
{
	class VertexDeclaration
	{
		//----------------------------------------------------------------------
		// Construction
		//----------------------------------------------------------------------

		public:

			VertexDeclaration();

		//----------------------------------------------------------------------
		// Properties
		//----------------------------------------------------------------------

		public:

			inline const std::vector<VertexElement>& getElements() const
			{
				return _elements;
			}

			inline std::vector<VertexElement>& getElements()
			{
				return _elements;
			}


		//----------------------------------------------------------------------
		// Member variables
		//----------------------------------------------------------------------

		private:

			std::vector<VertexElement> _elements;

	} ; // end class VertexDeclaration

} // end namespace Lithium

#endif // end LITHIUM_VERTEX_DECLARATION_HPP_INCLUDED

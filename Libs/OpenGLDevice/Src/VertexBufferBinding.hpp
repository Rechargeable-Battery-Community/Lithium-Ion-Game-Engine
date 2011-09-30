/**
 * \file VertexBufferBinding.hpp
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

#ifndef LITHIUM_VERTEX_BUFFER_BINDING_HPP_INCLUDED
#define LITHIUM_VERTEX_BUFFER_BINDING_HPP_INCLUDED

#include "GLPlatform.hpp"

namespace Lithium
{
#if (OPENGL_VERSION <= 2)

	/**
	 * Represents the binding of a VertexElement to OpenGL.
	 *
	 * Specifies the parameters for the glVertexAttribPointer. This
	 * is not needed for OpenGL 3.x or greater as the Vertex Array Object
	 * handles this functionality.
	 */
	struct VertexElementBinding
	{
		/// The index of the element
		GLuint index;
		/// The number of components.
		GLint size;
		/// The data type
		GLenum type;
		/// The offset to the data
		GLsizei offset;
	} ;

#endif
	
	/**
	 * Represents the binding of an VertexBuffer to OpenGL.
	 *
	 * \author Don Olmstead
	 * \version 0.1
	 */
	struct VertexBufferBinding
	{
		GLuint id;


	#if (OPENGL_VERSION >= 3)

	#else
		
		/// The number of elements
		GLsizei elementCount;
		/// The stride between elements
		GLsizei stride;
		/// The individual elements
		VertexElementBinding elements[16];

	#endif
	} ; // end struct VertexBufferBinding

} // end namespace Lithium

#endif // end LITHIUM_VERTEX_BUFFER_BINDING_HPP_INCLUDED

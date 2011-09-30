/**
 * \file TextureBinding.hpp
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

#ifndef LITHIUM_TEXTURE_BINDING_HPP_INCLUDED
#define LITHIUM_TEXTURE_BINDING_HPP_INCLUDED

#include "GLPlatform.hpp"

namespace Lithium
{
	/**
	 * Represents the binding of a Texture to OpenGL.
	 *
	 * \author Don Olmstead
	 * \version 0.1
	 */
	struct TextureBinding
	{
		/// The identifier for the texture
		GLuint id;
		/**
		 * Identifier for the pixel buffer object.
		 *
		 * Used when streaming to and from the texture. This is
		 * not present if the buffer usage is static.
		 */
		GLuint buffer;
	} ;

} // end namespace Lithium

#endif // end LITHIUM_TEXTURE_BINDING_HPP_INCLUDED

/**
 * \file OpenGLMappings.hpp
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

#ifndef LITHIUM_OPENGL_MAPPINGS_HPP_INCLUDED
#define LITHIUM_OPENGL_MAPPINGS_HPP_INCLUDED

#include "GLPlatform.hpp"
#include <Lithium/Graphics/Blend.hpp>
#include <Lithium/Graphics/BlendFunction.hpp>
#include <Lithium/Graphics/BufferUsage.hpp>
#include <Lithium/Graphics/IndexElementSize.hpp>
#include <Lithium/Graphics/TextureAddressMode.hpp>
#include <Lithium/Graphics/TextureFilter.hpp>
#include <Lithium/Graphics/VertexElementFormat.hpp>
#include <Lithium/Graphics/VertexElementUsage.hpp>

namespace Lithium
{
	/**
	 * Contains mappings between enumerations and OpenGL values.
	 *
	 * \author Don Olmstead
	 * \version 0.1
	 */
	struct OpenGLMappings
	{
		//----------------------------------------------------------------------
		// BlendState mappings
		//----------------------------------------------------------------------

		/// Maps the Blend enumeration
		static GLenum blend[Blend::Size];

		/// Maps the BlendFunction enumeration
		static GLenum blendFunction[BlendFunction::Size];

		//----------------------------------------------------------------------
		// DepthStencilState mappings
		//----------------------------------------------------------------------

		//----------------------------------------------------------------------
		// SamplerState mappings
		//----------------------------------------------------------------------

		/// Maps the TextureAdressMode enumeration
		static GLenum textureAddressMode[TextureAddressMode::Size];

		/// Maps the TextureFilter enumeration for minification
		static GLenum textureFilterMin[TextureFilter::Size];

		/// Maps the TextureFilter enumeration for magnification
		static GLenum textureFilterMag[TextureFilter::Size];

		//----------------------------------------------------------------------
		// Buffer mappings
		//----------------------------------------------------------------------

		/// Maps the BufferUsage enumeration
		static GLenum bufferUsage[BufferUsage::Size];

		/// Maps the IndexElementSize enumeration
		static GLenum indexElementSize[IndexElementSize::Size];

		//----------------------------------------------------------------------
		// VertexBuffer mappings
		//----------------------------------------------------------------------
		
		/// Maps the vertex attribute locations for different usages.
		static GLuint vertexElement[VertexElementUsage::Size];

		/**
		 * Naming scheme for vertex element usage.
		 *
		 * Used to bind attribute names in the effects.
		 *
		 * Contains a format string used by sprintf.
		 */
		static const char* vertexElementNames[VertexElementUsage::Size];

		/// Maps the format of vertex elements.
		static GLenum vertexElementFormat[VertexElementFormat::Size];

		/// Maps the size of vertex element formats.
		static GLint vertexElementSize[VertexElementFormat::Size];

	} ; // end struct OpenGLMappings

} // end namespace Lithium

#endif // end LITHIUM_OPENGL_MAPPINGS_HPP_INCLUDED

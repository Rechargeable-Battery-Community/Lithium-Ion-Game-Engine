/**
 * \file RasterizerStateBinding.hpp
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

#ifndef LITHIUM_RASTERIZER_STATE_BINDING_HPP_INCLUDED
#define LITHIUM_RASTERIZER_STATE_BINDING_HPP_INCLUDED

#include "GLPlatform.hpp"

namespace Lithium
{
	/**
	 * Represents the binding of a RasterizerState to OpenGL.
	 *
	 * OpenGL doesn't actually bind a RasterizerState. This binding is
	 * emulated to keep parity with DirectX.
	 *
	 * \author Don Olmstead
	 * \version 0.1
	 */
	struct RasterizerStateBinding
	{
		/// Whether scissor testing is enabled
		GLboolean scissorTestEnabled;
		/// Whether culling is enabled
		GLboolean cullEnabled;
		/// The face to cull
		GLenum cullFace;
		/// The orientation of front facing polygons
		GLenum frontFace;
		/// How a polygon is filled during rendering
		GLenum fillMode;
		/// The depth scale for polygons
		GLfloat depthScale;
		/// The depth bias for polygons
		GLfloat depthBias;

	} ; // end struct RasterizerStateBinding

} // end namespace Lithium

#endif // end LITHIUM_RASTERIZER_STATE_BINDING_HPP_INCLUDED

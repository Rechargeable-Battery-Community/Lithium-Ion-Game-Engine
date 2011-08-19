/**
 * \file BlendStateBinding.hpp
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

#ifndef LITHIUM_BLEND_STATE_BINDING_HPP_INCLUDED
#define LITHIUM_BLEND_STATE_BINDING_HPP_INCLUDED

#include "GLPlatform.hpp"

namespace Lithium
{
	/**
	 * Represents the binding of a BlendState to OpenGL.
	 *
	 * OpenGL doesn't actually bind a BlendState. This binding is
	 * emulated to keep parity with DirectX.
	 *
	 * \author Don Olmstead
	 * \version 0.1
	 */
	struct BlendStateBinding
	{
		/// The arithmetic operation when blending alpha values.
		GLenum alphaFunction;
		/// The arithemtic operation when blending color values.
		GLenum colorFunction;
		/// The alpha blend factor for the destination alpha.
		GLenum alphaDestination;
		/// The alpha blend factor.
		GLenum alphaSource;
		/// The blend factor for the destination color.
		GLenum colorDestination;
		/// The blend factor for the source color.
		GLenum colorSource;

	} ; // end struct BlendStateBinding

} // end namespace Lithium

#endif // end LITHIUM_BLEND_STATE_BINDING_HPP_INCLUDED

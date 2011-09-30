/**
 * \file SamplerStateBinding.hpp
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

#ifndef LITHIUM_SAMPLER_STATE_BINDING_HPP_INCLUDED
#define LITHIUM_SAMPLER_STATE_BINDING_HPP_INCLUDED

#include "GLPlatform.hpp"

namespace Lithium
{
	/**
	 * Represents the binding of a SamplerStateBinding to OpenGL.
	 *
	 * OpenGL doesn't actually bind a SamplerStateBinding. This binding is
	 * emulated to keep parity with DirectX.
	 *
	 * \author Don Olmstead
	 * \version 0.1
	 */
	struct SamplerStateBinding
	{
		/// The type of filtering during minification
		GLenum minFilter;
		/// The type of filtering during magnification
		GLenum magFilter;
		/// The address mode for the the u coordinate
		GLenum addressModeU;
		/// The address mode for the the v coordinate
		GLenum addressModeV;
		/// The address mode for the the w coordinate
		GLenum addressModeW;

	} ; // end struct SamplerStateBinding

} // end namespace Lithium

#endif // end LITHIUM_SAMPLER_STATE_BINDING_HPP_INCLUDED

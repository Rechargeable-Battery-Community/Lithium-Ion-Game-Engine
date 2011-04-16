/**
 * \file GraphicsContextGL_Windows.hpp
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

#ifndef LITHIUM_GRAPHICS_CONTEXT_GL_HPP_INCLUDED
#define LITHIUM_GRAPHICS_CONTEXT_GL_HPP_INCLUDED

#include "GLPlatformWindows.hpp"

namespace Lithium
{
	class GraphicsContext
	{
		public:

			/// The rendering context
			HGLRC _render;
			/// The device context
			HDC _device;

	} ; // end struct GraphicsContext

	namespace GraphicsAPI
	{
		/**
		 * Initializes the graphics API.
		 */
		void initialize();

	} // end namespace GraphicsAPI

} // end namespace Lithium

#endif // end LITHIUM_GRAPHICS_CONTEXT_GL_HPP_INCLUDED

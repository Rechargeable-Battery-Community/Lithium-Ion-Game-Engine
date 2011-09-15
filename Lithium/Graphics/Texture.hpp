/**
 * \file Texture.hpp
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

#ifndef LITHIUM_TEXTURE_HPP_INCLUDED
#define LITHIUM_TEXTURE_HPP_INCLUDED

#include <Lithium/Graphics/GraphicsResource.hpp>
#include <Lithium/Graphics/SurfaceFormat.hpp>

namespace Lithium
{
	class Texture : public GraphicsResource
	{
		protected:

			/**
			 * Creates an instance of the Texture class.
			 *
			 * \param format The format of the texture data.
			 */
			Texture(SurfaceFormat::Enum format);

			/**
			 * Destroys an instance of the Texture class.
			 */
			~Texture();

		public:

			/**
			 * Gets the format of the texture data.
			 *
			 * \returns The format of the texture data.
			 */
			inline SurfaceFormat::Enum getSurfaceFormat() const
			{
				return _surfaceFormat;
			}

		private:

			/// The format of the texture data
			SurfaceFormat::Enum _surfaceFormat;

	} ; // end class Texture

} // end namespace Lithium

#endif // end LITHIUM_TEXTURE_HPP_INCLUDED

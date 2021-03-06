/**
 * \file Texture2D.hpp
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

#ifndef LITHIUM_TEXTURE_2D_HPP_INCLUDED
#define LITHIUM_TEXTURE_2D_HPP_INCLUDED

#include <Lithium/Graphics/Texture.hpp>
#include <Lithium/Graphics/BufferUsage.hpp>

namespace Lithium
{
	class Texture2D : public Texture
	{
		public:

			/**
			 * Initializes an instance of the Texture2D class.
			 *
			 * \param device The GraphicsDevice to bind to.
			 * \param width The width of the texture.
			 * \param height The height of the texture.
			 * \param data The texture data.
			 * \param bufferUsage Description of how the buffer will be used.
			 */
			Texture2D(GraphicsDevice* device, std::int32_t width, std::int32_t height, const void* data = 0, BufferUsage::Enum bufferUsage = BufferUsage::Dynamic);

		//----------------------------------------------------------------------
		// Properties
		//----------------------------------------------------------------------

		public:

			/**
			 * Gets the width of the texture.
			 *
			 * \returns The width of the texture.
			 */
			inline std::int32_t getWidth() const
			{
				return _width;
			}

			/**
			 * Gets the height of the texture.
			 *
			 * \returns The height of the texture.
			 */
			inline std::int32_t getHeight() const
			{
				return _height;
			}

		//----------------------------------------------------------------------
		// Methods
		//----------------------------------------------------------------------

		public:

			void setData(const void* data);

			void setData(const void* data, std::int32_t x, std::int32_t y, std::int32_t width, std::int32_t height);

		//----------------------------------------------------------------------
		// Member variables
		//----------------------------------------------------------------------

		private:

			/// The width of the texture
			std::int32_t _width;
			/// The height of the texture
			std::int32_t _height;

	} ; // end class Texture2D

} // end namespace Lithium

#endif // end LITHIUM_TEXTURE_2D_HPP_INCLUDED

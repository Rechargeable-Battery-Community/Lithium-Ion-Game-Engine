/**
 * \file GraphicsDevice.hpp
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

#ifndef LITHIUM_GRAPHICS_DEVICE_HPP_INCLUDED
#define LITHIUM_GRAPHICS_DEVICE_HPP_INCLUDED

#include <Lithium/Graphics/EffectPass.hpp>
#include <Lithium/Graphics/Viewport.hpp>

namespace Lithium
{
	struct VertexShaderBinding;
	struct PixelShaderBinding;
	struct GeometryShaderBinding;

	class GraphicsDevice
	{
		public:

			/**
			 * Creates an instance of the GraphicsDevice class.
			 */
			GraphicsDevice();

		public:

			void clear();

			void setEffectPass(EffectPass* effect);

			inline const Viewport& getViewport() const
			{
				return _viewport;
			}

			void setViewport(const Viewport& viewport);

		//private:

			void createVertexShader(VertexShader* shader);
			void createPixelShader(PixelShader* shader);
			void createGeometryShader(GeometryShader* shader);

			void destroyVertexShader(VertexShader* shader);
			void destroyPixelShader(PixelShader* shader);
			void destroyGeometryShader(GeometryShader* shader);

			void createEffectPass(EffectPass* effect);
			void destroyEffectPass(EffectPass* effect);

			Viewport _viewport;

	} ; // end class GraphicsDevice

} // end namespace Lithium

#endif // end LITHIUM_GRAPHICS_DEVICE_HPP_INCLUDED

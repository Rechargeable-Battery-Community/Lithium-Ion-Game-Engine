/**
 * \file EffectPass.hpp
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

#ifndef LITHIUM_EFFECT_PASS_HPP_INCLUDED
#define LITHIUM_EFFECT_PASS_HPP_INCLUDED

#include <Lithium/Graphics/VertexShader.hpp>
#include <Lithium/Graphics/PixelShader.hpp>
#include <Lithium/Graphics/GeometryShader.hpp>

namespace Lithium
{
	class EffectPass : public GraphicsResource
	{
		public:

			/**
			 * Creates an instance of the EffectPass class.
			 */
			EffectPass();

		public:

			inline const VertexShader* getVertexShader() const
			{
				return _vertexShader;
			}

			void setVertexShader(VertexShader* shader);

			inline const PixelShader* getPixelShader() const
			{
				return _pixelShader;
			}

			void setPixelShader(PixelShader* shader);

			inline const GeometryShader* getGeometryShader() const
			{
				return _geometryShader;
			}

			void setGeometryShader(GeometryShader* shader);
				
		private:

			/// The vertex shader associated with the pass
			VertexShader* _vertexShader;
			/// The pixel shader associated with the pass
			PixelShader* _pixelShader;
			/// The geometry shader associated with the pass
			GeometryShader* _geometryShader;

	} ; // end class EffectPass

} // end namespace Lithium

#endif // end LITHIUM_EFFECT_PASS_HPP_INCLUDED

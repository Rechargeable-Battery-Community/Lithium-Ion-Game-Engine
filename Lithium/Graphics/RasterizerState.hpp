/**
 * \file RasterizerState.hpp
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

#ifndef LITHIUM_RASTERIZER_STATE_HPP_INCLUDED
#define LITHIUM_RASTERIZER_STATE_HPP_INCLUDED

#include <Lithium/Graphics/GraphicsResource.hpp>
#include <Lithium/Graphics/CullMode.hpp>
#include <Lithium/Graphics/FillMode.hpp>

namespace Lithium
{
	class RasterizerState : public GraphicsResource
	{
		LITHIUM_DECLARE_TYPE_INFO;

		//----------------------------------------------------------------------
		// Construction/Destruction
		//----------------------------------------------------------------------

		public:

			/**
			 * Creates an instance of the RasterizerState class.
			 */
			RasterizerState();

			/**
			 * Destroys an instance of the RasterizerState class.
			 */
			virtual ~RasterizerState();

		//----------------------------------------------------------------------
		// Properties
		//----------------------------------------------------------------------

		public:

			/**
			 * Gets whether scissor testing is enabled.
			 *
			 * \returns \b true \b if scissor testing is enabled; \b false \b otherwise.
			 */
			inline bool isScissorTestEnabled() const
			{
				return _scissorTestEnabled;
			}

			/**
			 * Sets whether scissor testing is enabled.
			 *
			 * \param value Whether scissor testing is enabled.
			 */
			void setScissorTestEnabled(bool value);

			/**
			 * Gets the condition for culling polygons.
			 *
			 * \returns The condition for culling polygons.
			 */
			inline CullMode::Enum getCullMode() const
			{
				return _cullMode;
			}

			/**
			 * Sets the condition for culling polygons.
			 *
			 * \param mode The condition for culling polygons.
			 */
			void setCullMode(CullMode::Enum mode);

			/**
			 * Gets how a polygon is filled during rendering.
			 *
			 * \returns How a polygon is filled during rendering.
			 */
			inline FillMode::Enum getFillMode() const
			{
				return _fillMode;
			}

			/**
			 * Sets how a polygon is filled during rendering.
			 *
			 * \param mode How a polygon is filled during rendering.
			 */
			void setFillMode(FillMode::Enum mode);

			/**
			 * Gets the depth bias for polygons.
			 *
			 * The bias is applied to the depth of a primitive to alleviate
			 * depth testing problems for primitives of similar depth.
			 *
			 * \returns The depth bias for polygons.
			 */
			inline float getDepthBias() const
			{
				return _depthBias;
			}

			/**
			 * Sets the depth bias for polygons.
			 *
			 * The bias is applied to the depth of a primitive to alleviate
			 * depth testing problems for primitives of similar depth.
			 *
			 * \param bias The depth bias for polygons.
			 */
			void setDepthBias(float bias);

			/**
			 * Gets the bias value that uses the slope of a polygon.
			 *
			 * This bias value is applied to coplanar primitives to
			 * reduce aliasing and other rendering artifacts caused by z-fighting.
			 *
			 * \returns The bias value that uses the slope of a polygon.
			 */
			inline float getSlopeScaleDepthBias() const
			{
				return _slopeScaleDepthBias;
			}

			/**
			 * Sets the bias value that uses the slope of a polygon.
			 *
			 * This bias value is applied to coplanar primitives to
			 * reduce aliasing and other rendering artifacts caused by z-fighting.
			 *
			 * \param bias The bias value that uses the slope of a polygon.
			 */
			void setSlopeScaleDepthBias(float bias);

		//----------------------------------------------------------------------
		// Member variables
		//----------------------------------------------------------------------

		private:

			/// Whether scissor testing is enabled
			bool _scissorTestEnabled;
			/// The condition for culling polygons
			CullMode::Enum _cullMode;
			/// How a polygon is filled during rendering
			FillMode::Enum _fillMode;	
			/// The depth bias for polygons
			float _depthBias;
			/// The bias value that uses the slope of a polygon
			float _slopeScaleDepthBias;

	} ; // end class RasterizerState

} // end namespace Lithium

#endif // end LITHIUM_RASTERIZER_STATE_HPP_INCLUDED

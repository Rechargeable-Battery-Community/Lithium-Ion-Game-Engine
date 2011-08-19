/**
 * \file BlendState.hpp
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

#ifndef LITHIUM_BLEND_STATE_HPP_INCLUDED
#define LITHIUM_BLEND_STATE_HPP_INCLUDED

#include <Lithium/Graphics/GraphicsResource.hpp>
#include <Lithium/Graphics/Blend.hpp>
#include <Lithium/Graphics/BlendFunction.hpp>

namespace Lithium
{
	/**
	 * Contains blend state for the device.
	 *
	 * \author Don Olmstead
	 * \version 0.1
	 */
	class BlendState : public GraphicsResource
	{
		LITHIUM_DECLARE_TYPE_INFO;

		//----------------------------------------------------------------------
		// Construction/Destruction
		//----------------------------------------------------------------------

		public:

			/**
			 * Creates an instance of the BlendState class.
			 */
			BlendState();

			/**
			 * Destroys an instance of the BlendState class.
			 */
			virtual ~BlendState();

		//----------------------------------------------------------------------
		// Properties
		//----------------------------------------------------------------------

		public:

			/**
			 * Retrieves the arithmetic operation when blending alpha values.
			 *
			 * \returns The arithmetic operation when blending alpha values.
			 */
			inline BlendFunction::Enum getAlphaBlendFunction() const
			{
				return _alphaBlendFunction;
			}

			/**
			 * Sets the arithmetic operation when blending alpha values.
			 *
			 * \param function The arithmetic operation when blending alpha values.
			 */
			void setAlphaBlendFunction(BlendFunction::Enum function);

			/**
			 * Retrieves the blend factor for the destination alpha.
			 *
			 * Contains the percentage of the destination alpha included in the blended result.
			 *
			 * \returns The blend factor for the destination alpha.
			 */
			inline Blend::Enum getAlphaDestinationBlend() const
			{
				return _alphaDestinationBlend;
			}

			/**
			 * Sets the blend factor for the destination alpha.
			 *
			 * Contains the percentage of the destination alpha included in the blended result.
			 *
			 * \param blend The blend factor for the destination alpha.
			 */
			void setAlphaDestinationBlend(Blend::Enum blend);

			/**
			 * Retrieves the alpha blend factor.
			 *
			 * \returns The alpha blend factor.
			 */
			inline Blend::Enum getAlphaSourceBlend() const
			{
				return _alphaSourceBlend;
			}

			/**
			 * Sets the alpha blend factor.
			 *
			 * \param blend The alpha blend factor.
			 */
			void setAlphaSourceBlend(Blend::Enum blend);

			/**
			 * Gets the arithmetic operation when blending color values.
			 *
			 * \returns The arithmetic operation when blending color values.
			 */
			inline BlendFunction::Enum getColorBlendFunction() const
			{
				return _colorBlendFunction;
			}

			/**
			 * Sets the arithmetic operation when blending color values.
			 *
			 * \param function The arithmetic operation when blending color values.
			 */
			void setColorBlendFunction(BlendFunction::Enum function);

			/**
			 * Gets the blend factor for the destination color.
			 *
			 * \returns The blend factor for the destination color.
			 */
			inline Blend::Enum getColorDestinationBlend() const
			{
				return _colorDestinationBlend;
			}

			/**
			 * Sets the blend factor for the destination color.
			 *
			 * \param blend The blend factor for the destination color.
			 */
			void setColorDestinationBlend(Blend::Enum blend);

			/**
			 * Gets the blend factor for the source color.
			 *
			 * \returns The blend factor for the source color.
			 */
			inline Blend::Enum getColorSourceBlend() const
			{
				return _colorSourceBlend;
			}

			/**
			 * Sets the blend factor for the source color.
			 *
			 * \param blend The blend factor for the source color.
			 */
			void setColorSourceBlend(Blend::Enum blend);

		//----------------------------------------------------------------------
		// Member variables
		//----------------------------------------------------------------------

		private:

			/// The four-component (RGBA) blend factor for alpha blending.

			/// The arithmetic operation when blending alpha values
			BlendFunction::Enum _alphaBlendFunction;
			/// The arithemtic operation when blending color values
			BlendFunction::Enum _colorBlendFunction;
			/// The alpha blend factor for the destination alpha
			Blend::Enum _alphaDestinationBlend;
			/// The alpha blend factor
			Blend::Enum _alphaSourceBlend;
			/// The blend factor for the destination color
			Blend::Enum _colorDestinationBlend;
			/// The blend factor for the source color
			Blend::Enum _colorSourceBlend;

	} ; // end class BlendState

} // end namespace Lithium

#endif // end LITHIUM_BLEND_STATE_HPP_INCLUDED

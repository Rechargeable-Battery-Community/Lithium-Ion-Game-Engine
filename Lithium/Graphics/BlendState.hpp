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
#include <Lithium/Graphics/ColorWriteChannel.hpp>

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
			 * \param i The index of the target.
			 * \returns The arithmetic operation when blending alpha values.
			 */
			inline BlendFunction::Enum getAlphaBlendFunction(std::size_t i = 0) const
			{
				return _renderTargetBlendStates[i].alphaBlendFunction;
			}

			/**
			 * Sets the arithmetic operation when blending alpha values.
			 *
			 * \param function The arithmetic operation when blending alpha values.
			 * \param i The index of the target.
			 */
			void setAlphaBlendFunction(BlendFunction::Enum function, std::size_t i = 0);

			/**
			 * Retrieves the blend factor for the destination alpha.
			 *
			 * Contains the percentage of the destination alpha included in the blended result.
			 *
			 * \param i The index of the target.
			 * \returns The blend factor for the destination alpha.
			 */
			inline Blend::Enum getAlphaDestinationBlend(std::size_t i = 0) const
			{
				return _renderTargetBlendStates[i].alphaDestinationBlend;
			}

			/**
			 * Sets the blend factor for the destination alpha.
			 *
			 * Contains the percentage of the destination alpha included in the blended result.
			 *
			 * \param blend The blend factor for the destination alpha.
			 * \param i The index of the target.
			 */
			void setAlphaDestinationBlend(Blend::Enum blend, std::size_t i = 0);

			/**
			 * Retrieves the alpha blend factor.
			 *
			 * \param i The index of the target.
			 * \returns The alpha blend factor.
			 */
			inline Blend::Enum getAlphaSourceBlend(std::size_t i = 0) const
			{
				return _renderTargetBlendStates[i].alphaSourceBlend;
			}

			/**
			 * Sets the alpha blend factor.
			 *
			 * \param i The index of the target.
			 * \param blend The alpha blend factor.
			 */
			void setAlphaSourceBlend(Blend::Enum blend, std::size_t i = 0);

			/**
			 * Gets the arithmetic operation when blending color values.
			 *
			 * \param i The index of the target.
			 * \returns The arithmetic operation when blending color values.
			 */
			inline BlendFunction::Enum getColorBlendFunction(std::size_t i = 0) const
			{
				return _renderTargetBlendStates[i].colorBlendFunction;
			}

			/**
			 * Sets the arithmetic operation when blending color values.
			 *
			 * \param function The arithmetic operation when blending color values.
			 * \param i The index of the target.
			 */
			void setColorBlendFunction(BlendFunction::Enum function, std::size_t i = 0);

			/**
			 * Gets the blend factor for the destination color.
			 *
			 * \param i The index of the target.
			 * \returns The blend factor for the destination color.
			 */
			inline Blend::Enum getColorDestinationBlend(std::size_t i = 0) const
			{
				return _renderTargetBlendStates[i].colorDestinationBlend;
			}

			/**
			 * Sets the blend factor for the destination color.
			 *
			 * \param blend The blend factor for the destination color.
			 * \param i The index of the target.
			 */
			void setColorDestinationBlend(Blend::Enum blend, std::size_t i = 0);

			/**
			 * Gets the blend factor for the source color.
			 *
			 * \param i The index of the target.
			 * \returns The blend factor for the source color.
			 */
			inline Blend::Enum getColorSourceBlend(std::size_t i = 0) const
			{
				return _renderTargetBlendStates[i].colorSourceBlend;
			}

			/**
			 * Sets the blend factor for the source color.
			 *
			 * \param blend The blend factor for the source color.
			 * \param i The index of the target.
			 */
			void setColorSourceBlend(Blend::Enum blend, std::size_t i = 0);

			/**
			 * The number of render targets available.
			 *
			 * DirectX 10.1/11 set this to a maximum of 8.
			 *
			 * \returns The number of render targets available.
			 */
			inline static std::size_t getAvailableTargetCount()
			{
				return __availableTargets;
			}

		//----------------------------------------------------------------------
		// Methods
		//----------------------------------------------------------------------

		private:

			/**
			 * Updates the number of targets in use.
			 *
			 * \param i The target index.
			 */
			inline void updateTargetCount(std::size_t i)
			{
				_numTargets = max(_numTargets, i + 1);
			}

		//----------------------------------------------------------------------
		// Member variables
		//----------------------------------------------------------------------

		private:

			/**
			 * The number of render targets available.
			 *
			 * DirectX 10.1/11 set this to a maximum of 8.
			 */
			static const std::size_t __availableTargets = 8;

			/**
			 * Per render target blending state.
			 *
			 * OpenGL 4.x and DirectX 10.1/11 hardware supports separate blending
			 * per render target. OpenGL 3.x and Direct 10 hardware only support
			 * separate color masks. OpenGL ES 2.x hardware applies the same
			 * blending to all targets.
			 *
			 * If the underlying GraphicsDevice does not support the functionality
			 * it is ignored by the renderer.
			 */
			struct RenderTargetBlendState
			{
				/// The arithmetic operation when blending alpha values
				BlendFunction::Enum alphaBlendFunction;
				/// The arithemtic operation when blending color values
				BlendFunction::Enum colorBlendFunction;
				/// The alpha blend factor for the destination alpha
				Blend::Enum alphaDestinationBlend;
				/// The alpha blend factor
				Blend::Enum alphaSourceBlend;
				/// The blend factor for the destination color
				Blend::Enum colorDestinationBlend;
				/// The blend factor for the source color
				Blend::Enum colorSourceBlend;
				/// The color channels to write to
				ColorWriteChannelFlags colorWriteChannelFlags;

				/**
				 * Creates an instance of the RenderTargetBlendState struct.
				 */
				RenderTargetBlendState::RenderTargetBlendState()
				: alphaBlendFunction(BlendFunction::Add)
				, colorBlendFunction(BlendFunction::Add)
				, alphaDestinationBlend(Blend::One)
				, alphaSourceBlend(Blend::One)
				, colorDestinationBlend(Blend::One)
				, colorSourceBlend(Blend::One)
				, colorWriteChannelFlags(ColorWriteChannel::All)
				{ }
			} ;

			/// An array of RenderTargetBlendStates
			typedef std::tr1::array<RenderTargetBlendState, __availableTargets> RenderTargetBlendStateArray;

			/**
			 * The number of render targets in use.
			 *
			 * The number of render targets specified is set to the
			 * largest value targeted when setting the state.
			 */
			std::size_t _numTargets;
			/**
			 * The four-component (RGBA) blend factor for alpha blending.
			 *
			 * The blend factor is only applicable to OpenGL ES 2.x hardware.
			 */

			/// The blend state for individual targets
			RenderTargetBlendStateArray _renderTargetBlendStates;

	} ; // end class BlendState

} // end namespace Lithium

#endif // end LITHIUM_BLEND_STATE_HPP_INCLUDED

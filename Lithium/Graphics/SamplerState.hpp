/**
 * \file SamplerState.hpp
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

#ifndef LITHIUM_SAMPLER_STATE_HPP_INCLUDED
#define LITHIUM_SAMPLER_STATE_HPP_INCLUDED

#include <Lithium/Graphics/GraphicsResource.hpp>
#include <Lithium/Graphics/TextureAddressMode.hpp>
#include <Lithium/Graphics/TextureFilter.hpp>

namespace Lithium
{
	/**
	 * Contains state which determines how to sample texture data.
	 *
	 * \author Don Olmstead
	 * \version 0.1
	 */
	class SamplerState : public GraphicsResource
	{
		LITHIUM_DECLARE_TYPE_INFO;

		//----------------------------------------------------------------------
		// Construction/Destruction
		//----------------------------------------------------------------------

		public:

			/**
			 * Creates an instance of the SamplerState class.
			 */
			SamplerState();

			/**
			 * Destroys an instance of the SamplerState class.
			 */
			~SamplerState();

		//----------------------------------------------------------------------
		// Properties
		//----------------------------------------------------------------------

		public:

			/**
			 * Gets the type of filtering during sampling.
			 *
			 * \returns The type of filtering during sampling.
			 */
			inline TextureFilter::Enum getFilter() const
			{
				return _textureFilter;
			}

			/**
			 * Sets the type of filtering during sampling.
			 *
			 * \param filter The type of filtering during sampling.
			 */
			void setFilter(TextureFilter::Enum filter);

			/**
			 * Gets the address mode for the u coordinate.
			 *
			 * \returns The address mode for the u coordinate.
			 */
			inline TextureAddressMode::Enum getAddressU() const
			{
				return _addressModeU;
			}

			/**
			 * Sets the address mode for the u coordinate.
			 *
			 * \param mode The address mode for the u coordinate.
			 */
			void setAddressU(TextureAddressMode::Enum mode);

			/**
			 * Gets the address mode for the v coordinate.
			 *
			 * \returns The address mode for the v coordinate.
			 */
			inline TextureAddressMode::Enum getAddressV() const
			{
				return _addressModeV;
			}

			/**
			 * Sets the address mode for the v coordinate.
			 *
			 * \param mode The address mode for the v coordinate.
			 */
			void setAddressV(TextureAddressMode::Enum mode);

			/**
			 * Gets the address mode for the w coordinate.
			 *
			 * \returns The address mode for the w coordinate.
			 */
			inline TextureAddressMode::Enum getAddressW() const
			{
				return _addressModeU;
			}

			/**
			 * Sets the address mode for the w coordinate.
			 *
			 * \param mode The address mode for the w coordinate.
			 */
			void setAddressW(TextureAddressMode::Enum mode);

		private:

			/// The type of filtering during sampling
			TextureFilter::Enum _textureFilter;
			/// The address mode for the u coordinate
			TextureAddressMode::Enum _addressModeU;
			/// The address mode for the v coordinate
			TextureAddressMode::Enum _addressModeV;
			/// The address mode for the w coordinate
			TextureAddressMode::Enum _addressModeW;

	} ; // end class SamplerState

} // end namespace Lithium

#endif // end LITHIUM_SAMPLER_STATE_HPP_INCLUDED

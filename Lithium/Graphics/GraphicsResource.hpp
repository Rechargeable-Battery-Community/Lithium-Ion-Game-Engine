/**
 * \file GraphicsResource.hpp
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

#ifndef LITHIUM_GRAPHICS_RESOURCE_HPP_INCLUDED
#define LITHIUM_GRAPHICS_RESOURCE_HPP_INCLUDED

#include <Lithium/System/Object.hpp>

namespace Lithium
{
	//----------------------------------------------------------------------
	// Forward declarations
	//----------------------------------------------------------------------

	class GraphicsDevice;
	class GraphicsDeviceContext;

	class GraphicsResource : public Object
	{
		LITHIUM_DECLARE_TYPE_INFO;

		protected:

			/**
			 * Creates an instance of the GraphicsResource class.
			 */
			GraphicsResource();

		public:

			/**
			 * Destroys an instance of the GraphicsResource class.
			 */
			virtual ~GraphicsResource();

		public:

			inline bool isBound() const
			{
				return _device != 0;
			}

			inline const GraphicsDevice* getDevice() const
			{
				return _device;
			}

		protected:

			/**
			 * Remove the device binding.
			 *
			 * Makes a call into the graphics device to remove any
			 * allocated resources.
			 */
			void release();

		private:

			/**
			 * Creates the device binding.
			 *
			 * This call is made by the GraphicsDevice during binding.
			 *
			 * \param device The graphics device to bind to.
			 * \param resources The graphics resources.
			 */
			void setDevice(GraphicsDevice* device, void* resources);

			/**
			 * Gets the resources bound to the device.
			 *
			 * \returns The resources bound to the device.
			 */
			inline void* getResources() const
			{
				return _binding;
			}

		private:

			friend class GraphicsDevice;
			friend class GraphicsDeviceContext;

			/// The associated graphics device.
			GraphicsDevice* _device;
			/// The resources bound to the device.
			void* _binding;

	} ; // end class GraphicsResource

} // end namespace Lithium

#endif // end LITHIUM_GRAPHICS_RESOURCE_HPP_INCLUDED

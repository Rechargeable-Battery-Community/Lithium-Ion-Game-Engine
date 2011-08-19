/**
 * \file GraphicsDeviceContext.hpp
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

#ifndef LITHIUM_GRAPHICS_DEVICE_CONTEXT_HPP_INCLUDED
#define LITHIUM_GRAPHICS_DEVICE_CONTEXT_HPP_INCLUDED

#include <Lithium/Graphics/BlendState.hpp>

namespace Lithium
{
	//----------------------------------------------------------------------
	// Forward declaration
	//----------------------------------------------------------------------

	class GraphicsDevice;
	class GraphicsCommandList;

	/**
	 * The graphics rendering context.
	 *
	 * \author Don Olmstead
	 * \version 0.1
	 */
	class GraphicsDeviceContext
	{
		//----------------------------------------------------------------------
		// Construction/Destruction
		//----------------------------------------------------------------------

		private:

			/**
			 * Initializes an instance of the GraphicsDeviceContext class.
			 *
			 * \param device The associated GraphicsDevice.
			 */
			GraphicsDeviceContext(const GraphicsDevice* device);

			/**
			 * Destroys an instance of the GraphicsDeviceContext class.
			 */
			~GraphicsDeviceContext();

		//----------------------------------------------------------------------
		// Properties
		//----------------------------------------------------------------------

		public:

			/**
			 * Retrieves the associated GraphicsDevice.
			 *
			 * \returns The associated GraphicsDevice.
			 */
			inline const GraphicsDevice* getDevice() const
			{
				return _device;
			}

			/**
			 * Retrieves the current BlendState.
			 *
			 * \returns The current BlendState.
			 */
			inline const BlendState* getBlendState() const
			{
				return _blendState;
			}

		private:

			/**
			 * Retrieves the list of GraphicsCommands.
			 *
			 * \returns The list of GraphicsCommands.
			 */
			inline const GraphicsCommandList* getCommandList() const
			{
				return _commandList;
			}

		//----------------------------------------------------------------------
		// Rendering methods
		//----------------------------------------------------------------------

		public:

			/**
			 * Begin rendering.
			 *
			 * Starts collection of GraphicsCommands.
			 */
			void begin();

			/**
			 * Draw the specified geometry.
			 *
			 * Finishes the current GraphicsCommand and begins collection
			 * of the next.
			 */
			void draw();

			/**
			 * Ends rendering.
			 *
			 * Stops collection of GraphicsCommands. The commands
			 * can now be rendererd.
			 */
			void end();

		//----------------------------------------------------------------------
		// Render state methods
		//----------------------------------------------------------------------

		public:

			/**
			 * Sets the current BlendState used for rendering.
			 *
			 * \param state The BlendState to use.
			 */
			void setBlendState(const BlendState* state);

			/**
			 * Sets the current DepthStencilState used for rendering.
			 *
			 * \param state The DepthStencilState to use.
			 */
			void setDepthStencilState();

			/**
			 * Sets the current RasterizerState used for rendering.
			 *
			 * \param state The RasterizerState to use.
			 */
			void setRasterizerState();

		//----------------------------------------------------------------------
		// Member variables
		//----------------------------------------------------------------------

		private:

			friend class GraphicsDevice;

			/// A list of GraphicsCommands to execute
			GraphicsCommandList* _commandList;
			/// The associated GraphicsDevice
			const GraphicsDevice* _device;
			/// The current BlendState
			const BlendState* _blendState;

	} ; // end class GraphicsDeviceContext

} // end namespace Lithium

#endif // end LITHIUM_GRAPHICS_DEVICE_CONTEXT_HPP_INCLUDED

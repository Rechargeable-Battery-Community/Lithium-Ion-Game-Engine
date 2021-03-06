/**
 * \file GraphicsCommandList.hpp
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

#ifndef LITHIUM_OPENGL3_COMMAND_LIST_HPP_INCLUDED
#define LITHIUM_OPENGL3_COMMAND_LIST_HPP_INCLUDED

#include <Lithium/Graphics/GraphicsDevice.hpp>
#include "GraphicsCommand.hpp"

namespace Lithium
{
	class GraphicsCommandList
	{
		//----------------------------------------------------------------------
		// Construction
		//----------------------------------------------------------------------

		private:

			GraphicsCommandList();

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
		// Properties
		//----------------------------------------------------------------------

		public:

			/**
			 * Queries whether commands are still being generated.
			 *
			 * A CommandList should not be submitted until all commands
			 * have been generated.
			 *
			 * \returns Whether commands are still being generated.
			 */
			inline bool isFinished() const
			{
				return _finished;
			}

		//----------------------------------------------------------------------
		// Element access
		//----------------------------------------------------------------------

		public:

			/**
			 * Gets the number of GraphicsCommands in the list.
			 *
			 * \returns The number of GraphicsCommands in the list.
			 */
			inline std::int32_t getCommandCount() const
			{
				return _currentCommand;
			}

			/**
			 * Gets the GraphicsCommand at the specified index.
			 *
			 * \param i The index of the GraphicsCommand.
			 * \returns The GraphicsCommand at the specified index.
			 */
			inline const GraphicsCommand& operator[] (std::size_t i) const
			{
				return _commands[i];
			}


		//----------------------------------------------------------------------
		// Render state methods
		//----------------------------------------------------------------------

		public:

			/**
			 * Sets the BlendStateBinding to use.
			 *
			 * \param state The BlendStateBinding to use.
			 */
			void setBlendStateBinding(const BlendStateBinding* state);

			/**
			 * Sets the DepthStencilStateBinding to use.
			 *
			 * \param state The DepthStencilStateBinding to use.
			 */
			void setDepthStencilStateBinding(const DepthStencilStateBinding* state);

			/**
			 * Sets the RasterizerStateBinding to use.
			 *
			 * \param state The RasterizerStateBinding to use.
			 */
			void setRasterizerStateBinding(const RasterizerStateBinding* state);

			void setTextureBinding(const TextureBinding* texture);

		//----------------------------------------------------------------------
		// Buffer methods
		//----------------------------------------------------------------------

		public:

			void setVertexBuffer(const VertexBufferBinding* buffer);

			void setIndexBuffer(const IndexBufferBinding* buffer);

		//----------------------------------------------------------------------
		// Member variables
		//----------------------------------------------------------------------

		private:

			friend class GraphicsDeviceContext;

			/// The maximum number of commands
			static const std::size_t __maxCommands = 256;

			/// An array of GraphicsCommands
			typedef std::tr1::array<GraphicsCommand, __maxCommands> GraphicsCommandArray;

			/// Whether commands are still being generated
			bool _finished;
			/// The index of the current command being generated
			std::size_t _currentCommand;
			/// The GraphicsCommands to execute
			GraphicsCommandArray _commands;

	} ; // end class GraphicsCommandList

} // end namespace Lithium

#endif // end LITHIUM_GRAPHICS_COMMAND_LIST_HPP_INCLUDED

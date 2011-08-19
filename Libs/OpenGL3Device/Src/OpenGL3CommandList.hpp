/**
 * \file OpenGL3CommandList.hpp
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
#include "OpenGL3Command.hpp"

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
			inline const GraphicsCommand& operator[] (std::int32_t i) const
			{
				LITHIUM_ASSERT((i >= 0) && (i < _currentCommand), "Invalid index");

				return _commands[i];
			}


		//----------------------------------------------------------------------
		// Render state methods
		//----------------------------------------------------------------------

		public:

			/**
			 * Sets the BlendStateBinding to use.
			 *
			 * \param blendState The BlendStateBinding to use.
			 */
			void setBlendStateBinding(const BlendStateBinding* binding);

		//----------------------------------------------------------------------
		// Member variables
		//----------------------------------------------------------------------

		private:

			friend class GraphicsDeviceContext;

			/// The maximum number of commands
			static const std::int32_t __maxCommands = 256;

			/// Whether commands are still being generated
			bool _finished;
			/// The index of the current command being generated
			std::int32_t _currentCommand;
			/// The GraphicsCommands to execute
			GraphicsCommand _commands[__maxCommands];

	} ; // end class GraphicsCommandList

} // end namespace Lithium

#endif // end LITHIUM_OPENGL3_COMMAND_LIST_HPP_INCLUDED

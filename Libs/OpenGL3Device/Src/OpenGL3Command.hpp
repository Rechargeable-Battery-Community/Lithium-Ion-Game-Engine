/**
 * \file OpenGL3Command.hpp
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

#ifndef LITHIUM_OPNEGL3_COMMAND_HPP_INCLUDED
#define LITHIUM_OPENGL3_COMMAND_HPP_INCLUDED

#include "BlendStateBinding.hpp"
#include "DepthStencilStateBinding.hpp"
#include "RasterizerStateBinding.hpp"

namespace Lithium
{
	/**
	 * Contains the infomation to execute a draw call.
	 *
	 * \todo Make this a dynamic structure to reduce state changes. Refactor
	 * into something more robust. Currently just using the bindings to make calls.
	 *
	 * \author Don Olmstead
	 * \version 0.1
	 */
	struct GraphicsCommand
	{
		//----------------------------------------------------------------------
		// Render State
		//----------------------------------------------------------------------

		/// The BlendState to use
		const BlendStateBinding* blendState;
		/// The DepthStencilState to use
		const DepthStencilStateBinding* depthStencilState;
		/// The RasterizerState to use
		const RasterizerStateBinding* rasterizerState;
	} ;

	/**
	 * Executes the GraphicsCommand.
	 */
	void executeCommand(const GraphicsCommand& command);

} // end namespace Lithium

#endif // end LITHIUM_OPENGL_COMMAND_HPP_INCLUDED

/**
 * \file OpenGL3Command.cpp
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

#include "OpenGL3Command.hpp"
#include "GLPlatform.hpp"
using namespace Lithium;

namespace
{
	void setBlendState(const BlendStateBinding* binding)
	{
		glBlendEquationSeparate(
			binding->colorFunction,
			binding->alphaFunction
		);

		glBlendFuncSeparate(
			binding->colorSource,
			binding->colorDestination,
			binding->alphaSource,
			binding->alphaDestination
		) ;
	}

} // end anonymous namespace

//---------------------------------------------------------------------

void Lithium::executeCommand(const GraphicsCommand& command)
{
	setBlendState(command.blendState);
}

/**
 * \file GraphicsDevice.cpp
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

#include <Lithium/Graphics/GraphicsDevice.hpp>
#include "GLPlatform.hpp"
#include "GraphicsCommandList.hpp"
using namespace Lithium;

//---------------------------------------------------------------------

void GraphicsDevice::clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT); // Clear required buffers
}

//---------------------------------------------------------------------

void GraphicsDevice::setClearColor(float r, float g, float b)
{
	glClearColor(r, g, b, 1.0f);
}

//---------------------------------------------------------------------

void GraphicsDevice::setViewport(const Viewport& viewport)
{
	_viewport = viewport;

	// Set the viewport
	const std::int32_t x = _viewport.getX();
	const std::int32_t y = _viewport.getY();
	const std::int32_t width = _viewport.getWidth();
	const std::int32_t height = _viewport.getHeight();

	glViewport(x, y, width, height);
	glScissor(x, y, width, height);

	// Set the depth
	glDepthRange(_viewport.getMinDepth(), _viewport.getMaxDepth());
}

//---------------------------------------------------------------------

void GraphicsDevice::execute(const GraphicsDeviceContext* context)
{
	const GraphicsCommandList* commands = context->getCommandList();
	LITHIUM_ASSERT(commands->isFinished(), "Command generation has not completed");

	const std::int32_t count = commands->getCommandCount();

	for (std::int32_t i = 0; i < count; ++i)
		executeCommand((*commands)[i]);
}

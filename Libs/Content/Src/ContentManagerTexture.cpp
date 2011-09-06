/**
 * \file ContentManagerTexture.cpp
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

#include <Lithium/Content/ContentManager.hpp>
#include "stb_image.h"
using namespace Lithium;

//---------------------------------------------------------------------

Texture2D* ContentManager::loadTexture2D(const std::string& path)
{
	Texture2DMap::const_iterator itr = _loadedTexture2Ds.find(path);
	Texture2D* texture;

	if (itr != _loadedTexture2Ds.end())
	{
		texture = itr->second;
	}
	else
	{
		std::int32_t width, height, bytesPerPixel;
		std::uint8_t* imageData = stbi_load(path.c_str(), &width, &height, &bytesPerPixel, 4);

		texture = new Texture2D(_gameServiceLocator.getGraphicsDevice(), width, height, imageData);

		_loadedTexture2Ds[path] = texture;
	}

	return texture;
}

/**
 * \file Viewport.hpp
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

#ifndef LITHIUM_VIEWPORT_HPP_INCLUDED
#define LITHIUM_VIEWPORT_HPP_INCLUDED

#include <Lithium/System/Includes.hpp>

namespace Lithium
{
	class Viewport
	{
		public:

			Viewport(std::int32_t x, std::int32_t y, std::int32_t width, std::int32_t height);

			inline std::int32_t getX() const
			{
				return _x;
			}

			inline std::int32_t getY() const
			{
				return _y;
			}

			inline std::int32_t getWidth() const
			{
				return _width;
			}

			inline std::int32_t getHeight() const
			{
				return _height;
			}

			inline void setX(std::int32_t x)
			{
				_x = x;
			}

			inline void setY(std::int32_t y)
			{
				_y = y;
			}

			inline void setWidth(std::int32_t width)
			{
				_width = width;
			}

			inline void setHeight(std::int32_t height)
			{
				_height = height;
			}

			inline float getAspectRatio() const
			{
				return (float)_width / (float)_height;
			}

			inline float getMinDepth() const
			{
				return _minDepth;
			}

			inline float getMaxDepth() const
			{
				return _maxDepth;
			}

			inline void setMinDepth(float minDepth)
			{
				_minDepth = minDepth;
			}

			inline void setMaxDepth(float maxDepth)
			{
				_maxDepth = maxDepth;
			}

		private:

			std::int32_t _x;
			std::int32_t _y;
			std::int32_t _width;
			std::int32_t _height;
			float _minDepth;
			float _maxDepth;

	} ; // end class Viewport

} // end namespace Lithium

#endif // end LITHIUM_VIEWPORT_HPP_INCLUDED

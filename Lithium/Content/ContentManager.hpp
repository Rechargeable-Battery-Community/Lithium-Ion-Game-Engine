/**
 * \file ContentManager.hpp
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

#ifndef LITHIUM_CONTENT_MANAGER_HPP_INCLUDED
#define LITHIUM_CONTENT_MANAGER_HPP_INCLUDED

#include <Lithium/Content/GameServiceLocator.hpp>
#include <Lithium/Graphics/Texture2D.hpp>

namespace Lithium
{
	class ContentManager
	{
		//----------------------------------------------------------------------
		// Construction
		//----------------------------------------------------------------------

		public:

			/**
			 * Initializes an instance of the ContentManager.
			 *
			 * \param locator Contains the devices to bind to.
			 */
			ContentManager(const GameServiceLocator& locator);

			/**
			 * Loads the Texture2D resource.
			 *
			 * \param path The path to the resource.
			 */
			Texture2D* loadTexture2D(const std::string& path);

		private:

			typedef std::tr1::unordered_map<std::string, Texture2D*> Texture2DMap;

			/// The services associated with the manager
			GameServiceLocator _gameServiceLocator;
			/// The Texture2D resources loaded by the manager
			Texture2DMap _loadedTexture2Ds;

	} ; // end class ContentManager

} // end namespace Lithium

#endif // end LITHIUM_CONTENT_MANAGER_HPP_INCLUDED

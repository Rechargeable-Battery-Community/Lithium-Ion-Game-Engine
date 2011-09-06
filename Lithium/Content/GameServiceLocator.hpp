/**
 * \file GameServiceLocator.hpp
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

#ifndef LITHIUM_GAME_SERVICE_LOCATOR_HPP_INCLUDED
#define LITHIUM_GAME_SERVICE_LOCATOR_HPP_INCLUDED

#include <Lithium/Graphics/GraphicsDevice.hpp>

namespace Lithium
{
	class GameServiceLocator
	{
		//----------------------------------------------------------------------
		// Construction
		//----------------------------------------------------------------------

		public:

			/**
			 * Creates an instance of the GameServiceLocator class.
			 */
			GameServiceLocator();

		//----------------------------------------------------------------------
		// Properties
		//----------------------------------------------------------------------

		public:

			/**
			 * Gets the associated GraphicsDevice.
			 *
			 * \returns The associated GraphicsDevice.
			 */
			inline GraphicsDevice* getGraphicsDevice() const
			{
				return _graphicsDevice;
			}

			/**
			 * Sets the associated GraphicsDevice.
			 *
			 * \param device The associated GraphicsDevice.
			 */
			inline void setGraphicsDevice(GraphicsDevice* device)
			{
				_graphicsDevice = device;
			}

		//----------------------------------------------------------------------
		// Member variables
		//----------------------------------------------------------------------

		private:

			/// The associated GraphicsDevice
			GraphicsDevice* _graphicsDevice;

	} ; // end class GameServiceLocator

} // end namespace Lithium

#endif // end LITHIUM_GAME_SERVICE_LOCATOR_HPP_INCLUDED

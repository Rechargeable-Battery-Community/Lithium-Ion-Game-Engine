/**
 * \file GameWindow.hpp
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

#ifndef LITHIUM_GAME_WINDOW_HPP_INCLUDED
#define LITHIUM_GAME_WINDOW_HPP_INCLUDED

#include <Lithium/System/Includes.hpp>
#include <Lithium/Application/DeviceOrientation.hpp>

namespace Lithium
{
	//----------------------------------------------------------------------
	// Forward declaration
	//----------------------------------------------------------------------

	class Game;
	class GraphicsContext;

	/**
	 * The system window associated with a Game.
	 *
	 * \author Don Olmstead
	 * \version 0.1
	 */
	class GameWindow
	{
		//----------------------------------------------------------------------
		// Construction
		//----------------------------------------------------------------------

		private:

			/**
			 * Creates an instance of the GameWindow class.
			 *
			 * \param title The title of the window.
			 * \param width The width of the window.
			 * \param height The height of the window.
			 * \param resizeable Whether the window is resizeable.
			 */
			GameWindow(const std::string& title, std::int32_t width, std::int32_t height, bool resizeable);

			/**
			 * Creates an instance of the GameWindow class.
			 *
			 * The window is opened in fullscreen mode.
			 *
			 * \param title The title of the window.
			 * \param width The width of the window.
			 * \param height The height of the window.
			 */
			GameWindow(const std::string& title, std::int32_t width, std::int32_t height);

		public:

			/**
			 * Destroys an instance of the GameWindow class.
			 */
			~GameWindow();

		//----------------------------------------------------------------------
		// Properties
		//----------------------------------------------------------------------

		public:

			/**
			 * Retrieves the handle to the window.
			 *
			 * \returns The handle to the window.
			 */
			inline std::int32_t getHandle() const
			{
				return _handle;
			}

			/**
			 * Gets the current display orientation.
			 *
			 * Reflects the physical orientation of the device in the user's hand.
			 *
			 * \returns The current display orientation.
			 */
			inline DeviceOrientation::Enum getDeviceOrientation() const
			{
				return _deviceOrientation;
			}

			/**
			 * Retrieves the width of the window.
			 *
			 * \returns The width of the window.
			 */
			inline std::int32_t getWidth() const
			{
				return _width;
			}

			/**
			 * Retrieves the height of the window.
			 *
			 * \returns The height of the window.
			 */
			inline std::int32_t getHeight() const
			{
				return _height;
			}

			/**
			 * Retrieves the title of the window.
			 *
			 * \returns The title of the window.
			 */
			inline const std::string& getTitle() const
			{
				return _title;
			}

			/**
			 * Sets the title of the window.
			 *
			 * \param title The title of the window.
			 */
			void setTitle(const std::string& title);

		//----------------------------------------------------------------------
		// Methods
		//----------------------------------------------------------------------

		private:

			/**
			 * Initialize the window.
			 */
			void initialize();

			/**
			 * Creates the window.
			 */
			void createWindow();

			/**
			 * Shows the window.
			 */
			void showWindow();

			/**
			 * Hides the window.
			 */
			void hideWindow();

			/**
			 * Creates the graphics rendering context.
			 */
			void createContext();

			/**
			 * Deletes the graphics rendering context.
			 */
			void deleteContext();

			/**
			 * Makes the graphics rendering context current.
			 */
			void makeContextCurrent();

			/**
			 * Swaps the buffers of the window.
			 */
			void swapBuffers();

		//----------------------------------------------------------------------
		// Member variables
		//----------------------------------------------------------------------

		private:

			friend class Game;

			/// The handle to the window
			std::int32_t _handle;
			/// The graphics context
			GraphicsContext* _context;
			/// The display orientation
			DeviceOrientation::Enum _deviceOrientation;
			/// The width of the window
			std::int32_t _width;
			/// The height of the window
			std::int32_t _height;
			/// Whether the window is resizeable
			bool _resizeable;
			/// Whether the window is in fullscreen
			bool _fullscreen;
			/// The title of the window
			std::string _title;

	} ; // end class GameWindow

} // end namespace Lithium

#endif // end LITHIUM_GAME_WINDOW_HPP_INCLUDED

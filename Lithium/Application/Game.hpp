/**
 * \file Game.hpp
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

#ifndef LITHIUM_GAME_HPP_INCLUDED
#define LITHIUM_GAME_HPP_INCLUDED

#include <Lithium/System/Includes.hpp>
#include <Lithium/Application/GameWindow.hpp>
#include <Lithium/Input/ButtonState.hpp>
#include <Lithium/Input/MouseButtons.hpp>
#include <Lithium/Input/Keys.hpp>
#include <Lithium/Input/KeyState.hpp>

namespace Lithium
{
	class Game
	{
		public:

			/**
			 * Creates an instance of the Game class.
			 */
			Game();

			/**
			 * Destroys an instance of the Game class.
			 */
			~Game();

			/**
			 * Initializes the Game class.
			 */
			void initialize();

			void terminate();

			void update();

			void draw();

			inline std::int32_t getWindow() const
			{
				return _window;
			}

			/// The instance of the Game class
			static Game* instance;

			static std::int32_t main(std::int32_t, char**);

			void onMouseMove(std::int32_t x, std::int32_t y);
			void onMouseClick(MouseButtons::Enum button, ButtonState::Enum state);
			void onKeyChange(Keys::Enum key, KeyState::Enum state);
			void updateGamePads();

		private:

			/// The handle to the window
			std::int32_t _window;
			/// The width of the window
			std::int32_t _windowWidth;
			/// The height of the window
			std::int32_t _windowHeight;
			/// Whether the window is fullscreen
			bool _fullScreen;
			/// Whether the window is resizeable
			bool _resizeable;

			GameWindow* _gameWindow;

			std::int32_t createWindow();

	} ; // end class Game
}

#endif // end LITHIUM_GAME_HPP_INCLUDED

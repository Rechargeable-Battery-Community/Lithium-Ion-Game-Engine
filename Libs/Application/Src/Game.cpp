/**
 * \file Game.cpp
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

#include "LithiumApplicationPCH.hpp"
#include <Lithium/Application/Game.hpp>
#include <Lithium/System/Time.hpp>

#include <Lithium/Network/Dns.hpp>
#include <Lithium/Network/Socket.hpp>
#include <Lithium/Web/HttpRequest.hpp>
#include <Lithium/Web/WebRequest.hpp>
#include <Lithium/Application/HttpServer.hpp>
#include <Lithium/Input/GamePad.hpp>
using namespace Lithium;

#include <sstream>

Game* Game::instance = 0;

TcpSocket __socket;
HttpServer* __server;

//---------------------------------------------------------------------

Game::Game()
: _window(0)
, _windowWidth(640)
, _windowHeight(480)
, _fullScreen(false)
, _resizeable(true)
, _gameWindow(0)
{ }

//---------------------------------------------------------------------

Game::~Game()
{
	if (_gameWindow)
		delete _gameWindow;
}

//---------------------------------------------------------------------

void Game::initialize()
{
	Time::initialize();

	// \todo REMOVE
	__server = new HttpServer(8001);
}

//---------------------------------------------------------------------

void Game::terminate()
{

}

//---------------------------------------------------------------------

void Game::update()
{
	Time::update();
	updateGamePads();

	// \todo REMOVE
	__server->update();
}

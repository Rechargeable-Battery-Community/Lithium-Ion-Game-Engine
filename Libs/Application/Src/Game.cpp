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
#include <Lithium/Web/HttpServer.hpp>
#include <Lithium/Input/GamePad.hpp>

#include <Lithium/Graphics/EffectPass.hpp>
#include "GLPlatform.hpp"
using namespace Lithium;

Game* Game::instance = 0;

TcpSocket __socket;
HttpServer* __server;

EffectPass* __effectPass;
VertexShader* __vertexShader;
PixelShader* __pixelShader;

BlendState* __blendState;

//---------------------------------------------------------------------

Game::Game()
: _graphicsDevice(0)
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
	// Initialize the timer
	Time::initialize();

	// Create the graphics device
	_graphicsDevice = new GraphicsDevice();

	// Set the viewport
	Viewport viewport(0, 0, _gameWindow->getWidth(), _gameWindow->getHeight());
	_graphicsDevice->setViewport(viewport);

	__blendState = new BlendState();
	_graphicsDevice->bind(__blendState);
	/*
	__vertexShader = new VertexShader();
	__pixelShader = new PixelShader();

	_graphicsDevice->createVertexShader(__vertexShader);
	_graphicsDevice->createPixelShader(__pixelShader);
	
	__effectPass = new EffectPass();
	__effectPass->setVertexShader(__vertexShader);
	__effectPass->setPixelShader(__pixelShader);

	_graphicsDevice->createEffectPass(__effectPass);
	*/

	// \todo REMOVE
	__server = new HttpServer(8001);
}

//---------------------------------------------------------------------

void Game::terminate()
{
	delete __blendState;
}

//---------------------------------------------------------------------

void Game::update()
{
	Time::update();
	updateGamePads();

	// \todo REMOVE
	__server->update();
}

//---------------------------------------------------------------------

void Game::draw()
{
	_graphicsDevice->clear();

	GraphicsDeviceContext* context = _graphicsDevice->getContext();
	context->begin();
	context->setBlendState(__blendState);
	context->draw();
	context->end();
	_graphicsDevice->execute(context);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-8.0, 8.0, -6.0, 6.0, 0.0, 100.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, 1.0f);
	glBegin(GL_QUADS);
		glVertex3f( 0.5f,  0.5f, 0.0f);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(-0.5f,  0.5f, 0.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(-1.0f, -0.5f, 0.0f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f( 1.0f, -0.5f, 0.0f);
		glColor3f(1.0f, 1.0f, 0.0f);
	glEnd();
}

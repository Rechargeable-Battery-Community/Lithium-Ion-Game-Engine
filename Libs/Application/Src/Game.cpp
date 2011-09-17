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
#include <Lithium/Graphics/VertexBuffer.hpp>
#include <Lithium/VertexDefinitions/VertexPositionTexture.hpp>
#include "GLPlatform.hpp"
using namespace Lithium;

Game* Game::instance = 0;

TcpSocket __socket;
HttpServer* __server;

EffectPass* __effectPass;
VertexShader* __vertexShader;
PixelShader* __pixelShader;

BlendState* __blendState;
DepthStencilState* __depthStencilState;
RasterizerState* __rasterizerState;
Texture2D* __texture;
VertexBuffer* __vertexBuffer;

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
	if (_graphicsDevice)
		delete _graphicsDevice;
	if (_contentManager)
		delete _contentManager;
}

//---------------------------------------------------------------------

void Game::initialize()
{
	// Initialize the timer
	Time::initialize();

	// Create the graphics device
	_graphicsDevice = new GraphicsDevice();
	_graphicsDevice->setClearColor(0.4f, 0.6f, 0.9f);

	GameServiceLocator locator;
	locator.setGraphicsDevice(_graphicsDevice);

	_contentManager = new ContentManager(locator);

	__texture = _contentManager->loadTexture2D("textures/Crate.bmp");

	// Set the viewport
	Viewport viewport(0, 0, _gameWindow->getWidth(), _gameWindow->getHeight());
	_graphicsDevice->setViewport(viewport);

	__blendState = new BlendState();
	_graphicsDevice->bind(__blendState);

	__depthStencilState = new DepthStencilState();
	_graphicsDevice->bind(__depthStencilState);

	__rasterizerState = new RasterizerState();
	_graphicsDevice->bind(__rasterizerState);

	VertexPositionTexture vertices[4];
	vertices[0].position.set_values(-1.0f,  1.0f, 0.0f);
	vertices[1].position.set_values( 1.0f,  1.0f, 0.0f);
	vertices[2].position.set_values( 1.0f, -1.0f, 0.0f);
	vertices[3].position.set_values(-1.0f, -1.0f, 0.0f);

	vertices[0].textureCoordinate.set_values(0.0f, 0.0f);
	vertices[1].textureCoordinate.set_values(1.0f, 0.0f);
	vertices[2].textureCoordinate.set_values(1.0f, 1.0f);
	vertices[3].textureCoordinate.set_values(0.0f, 1.0f);

	__vertexBuffer = new VertexBuffer(_graphicsDevice, vertices, 4);
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
	delete __depthStencilState;
	delete __rasterizerState;
	delete __texture;
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
	context->setDepthStencilState(__depthStencilState);
	context->setRasterizerState(__rasterizerState);
	context->setTexture(__texture);
	context->draw();
	context->end();
	_graphicsDevice->execute(context);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glFrustum(-8.0, 8.0, -6.0, 6.0, 0.0, 100.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.0f,0.0f,1.0f);
	glRotatef(45.0f, 0.0f, 1.0f, 0.0f);

	glBegin(GL_QUADS);
		// Front Face
		glNormal3f( 0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f,  0.5f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 0.5f, -0.5f,  0.5f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 0.5f,  0.5f,  0.5f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f,  0.5f,  0.5f);
		// Back Face
		glNormal3f( 0.0f, 0.0f,-1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.5f, -0.5f, -0.5f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.5f,  0.5f, -0.5f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 0.5f,  0.5f, -0.5f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 0.5f, -0.5f, -0.5f);
		// Top Face
		glNormal3f( 0.0f, 1.0f, 0.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f,  0.5f, -0.5f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f,  0.5f,  0.5f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 0.5f,  0.5f,  0.5f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 0.5f,  0.5f, -0.5f);
		// Bottom Face
		glNormal3f( 0.0f,-1.0f, 0.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.5f, -0.5f, -0.5f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 0.5f, -0.5f, -0.5f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 0.5f, -0.5f,  0.5f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.5f, -0.5f,  0.5f);
		// Right face
		glNormal3f( 1.0f, 0.0f, 0.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 0.5f, -0.5f, -0.5f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 0.5f,  0.5f, -0.5f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 0.5f,  0.5f,  0.5f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 0.5f, -0.5f,  0.5f);
		// Left Face
		glNormal3f(-1.0f, 0.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, -0.5f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.5f, -0.5f,  0.5f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.5f,  0.5f,  0.5f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f,  0.5f, -0.5f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);
}

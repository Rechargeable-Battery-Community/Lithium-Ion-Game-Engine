
#include <Lithium/Web/HttpServer.hpp>
#include <Lithium/Web/HttpRequest.hpp>
/**
 * \file HttpServer.cpp
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

#include <Lithium/Web/HttpResponse.hpp>
#include <Lithium/Input/GamePad.hpp>
using namespace Lithium;

#include "json/value.h"
#include "json/reader.h"
#include "json/writer.h"

//---------------------------------------------------------------------

HttpServer::HttpServer(std::int16_t port)
{
	_socket.listen(port);
	
	// Add the regular expressions
	mapMethod(std::tr1::regex("/GamePad/(\\d)/*"), &HttpServer::getGamePad);
	mapMethod(std::tr1::regex("/image/\\S+.(png|jpeg|jpg|gif|bmp)$"), &HttpServer::getImage);\
	mapMethod(std::tr1::regex("/script/\\S+.js$"), &HttpServer::getScript);
	mapMethod(std::tr1::regex("/css/\\S+.css$"), &HttpServer::getStyleSheet);
	mapMethod(std::tr1::regex("/"), &HttpServer::getIndex);
}

//---------------------------------------------------------------------

void HttpServer::update()
{
	// Check for a connection
	TcpSocket connection = _socket.accept();

	if (connection.isBound())
	{
		// Receive the request
		std::stringstream requestStream;
		connection.receive(requestStream);

		HttpRequest request(requestStream);

		const std::string& resource = request.getResource();

		const std::int32_t size = _responseMap.size();

		for (std::int32_t i = 0; i < size; ++i)
		{
			std::match_results<std::string::const_iterator> match;
			
			if (std::tr1::regex_match(resource, match, _responseMap[i].first))
			{
				ResponseMethod method = _responseMap[i].second;

				(this->*method)(request, connection, match);

				return;
			}
		}
	}
}

//---------------------------------------------------------------------

void HttpServer::sendResponse(TcpSocket& connection, const HttpResponse& response)
{
	std::stringstream send;
	response.write(send);

	connection.send(send);
}

//---------------------------------------------------------------------

void HttpServer::mapMethod(const std::tr1::regex& expression, ResponseMethod method)
{
	std::pair<std::tr1::regex, ResponseMethod> p(expression, method);

	_responseMap.push_back(p);
}

//---------------------------------------------------------------------

void HttpServer::getIndex(HttpRequest& request, TcpSocket& connection, const std::tr1::match_results<std::string::const_iterator>& match)
{
	std::ifstream index("html/index.html");

	if (index.is_open())
	{
		HttpResponse response(HttpStatus::Ok);
		response.getBody() << index.rdbuf();

		response.addField("Content-Type", "text/html");

		sendResponse(connection, response);
	}
	else
	{

	}
}

//---------------------------------------------------------------------

void HttpServer::getImage(HttpRequest& request, TcpSocket& connection, const std::tr1::match_results<std::string::const_iterator>& match)
{
	const std::string& filename = match[0];
	std::ifstream image("html" + filename, std::ios::in | std::ios::binary);

	if (image.is_open())
	{
		HttpResponse response(HttpStatus::Ok);
		response.getBody() << image.rdbuf();

		response.addField("Content-Type", "image/png");

		sendResponse(connection, response);
	}
	else
	{
		// Send 403
	}
}

//---------------------------------------------------------------------

void HttpServer::getScript(HttpRequest& request, TcpSocket& connection, const std::tr1::match_results<std::string::const_iterator>& match)
{
	const std::string filename = match[0];
	std::ifstream script("html" + filename);

	if (script.is_open())
	{
		HttpResponse response(HttpStatus::Ok);
		response.getBody() << script.rdbuf();

		response.addField("Content-Type", "application/javascript");

		sendResponse(connection, response);
	}
	else
	{

	}
}

//---------------------------------------------------------------------

void HttpServer::getStyleSheet(HttpRequest& request, TcpSocket& connection, const std::tr1::match_results<std::string::const_iterator>& match)
{
	const std::string filename = match[0];
	std::ifstream script("html" + filename);

	if (script.is_open())
	{
		HttpResponse response(HttpStatus::Ok);
		response.getBody() << script.rdbuf();

		response.addField("Content-Type", "text/css");

		sendResponse(connection, response);
	}
	else
	{

	}
}

//---------------------------------------------------------------------

void HttpServer::getGamePad(HttpRequest& request, TcpSocket& connection, const std::tr1::match_results<std::string::const_iterator>& match)
{
	// Get the index
	const std::string& indexStr = match[1];
	const std::int32_t index = (std::int32_t)(indexStr[0] - '0');

	if ((index >= 0) && (index < PlayerIndex::Size))
	{
		// Get the game pad
		const PlayerIndex::Enum player = (PlayerIndex::Enum)index;
		const GamePadState& gamePad = GamePad::getState(player);

		// Create the response
		HttpResponse response(HttpStatus::Ok);

		if (request.getMethod() == HttpMethod::Post)
		{
			// Get the request
			Json::Value root;

			request.getBody() >> root;

			// Set the motors
			float leftMotor = root["leftMotor"].asDouble();
			float rightMotor = root["rightMotor"].asDouble();

			GamePad::setVibration(player, leftMotor, rightMotor);
		}
		else
		{
			// Serialize the state
			Json::Value root;

			root["isConnected"] = gamePad.isConnected();
			root["buttons"] = 7;
			root["leftTrigger"] = gamePad.getLeftTrigger();
			root["rightTrigger"] = gamePad.getRightTrigger();

			// \todo Generalize serialization
			const Vector2f&  leftThumbstick = gamePad.getLeftThumbstick();
			root["leftThumbstick"]["x"] = (float)leftThumbstick.x();
			root["leftThumbstick"]["y"] = (float)leftThumbstick.y();

			const Vector2f& rightThumbstick = gamePad.getRightThumbstick();
			root["rightThumbstick"]["x"] = (float)rightThumbstick.x();
			root["rightThumbstick"]["y"] = (float)rightThumbstick.y();

			// Add the json to the response
			response.getBody() << root;

			response.addField("Content-Type", "application/json");
		}

		// Send the response
		sendResponse(connection, response);
	}
	else
	{
		// Return a 404 page

	}
}

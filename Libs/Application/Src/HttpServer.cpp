#include "LithiumApplicationPCH.hpp"
#include <Lithium/Application/HttpServer.hpp>
#include <Lithium/Web/HttpRequest.hpp>
#include <Lithium/Web/HttpResponse.hpp>
#include <Lithium/Input/GamePad.hpp>
using namespace Lithium;

#include <sstream>
#include <fstream>

//---------------------------------------------------------------------

HttpServer::HttpServer(std::int16_t port)
{
	_socket.listen(port);
	
	// Add the regular expressions
	mapMethod(std::tr1::regex("/GamePad/(\\d)/*"), &HttpServer::getGamePad);
	mapMethod(std::tr1::regex("/image/\\w+.(png|jpeg|jpg|bmp)"), &HttpServer::getImage);\
	mapMethod(std::tr1::regex("/script/\\w+.js"), &HttpServer::getScript);
	mapMethod(std::tr1::regex("/css/\\w+.css"), &HttpServer::getStyleSheet);
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

void HttpServer::getIndex(const HttpRequest& request, TcpSocket& connection, const std::tr1::match_results<std::string::const_iterator>& match)
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

void HttpServer::getImage(const HttpRequest& request, TcpSocket& connection, const std::tr1::match_results<std::string::const_iterator>& match)
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

void HttpServer::getScript(const HttpRequest& request, TcpSocket& connection, const std::tr1::match_results<std::string::const_iterator>& match)
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

void HttpServer::getStyleSheet(const HttpRequest& request, TcpSocket& connection, const std::tr1::match_results<std::string::const_iterator>& match)
{

}

//---------------------------------------------------------------------

void HttpServer::getGamePad(const HttpRequest& request, TcpSocket& connection, const std::tr1::match_results<std::string::const_iterator>& match)
{
	// Get the index
	const std::string& indexStr = match[1];
	const std::int32_t index = (std::int32_t)(indexStr[0] - '0');

	if ((index >= 0) && (index < PlayerIndex::Size))
	{
		// Get the game pad
		const PlayerIndex::Enum player = (PlayerIndex::Enum)index;
		const GamePadState& gamePad = GamePad::getState(player);

		// Serialize the state
		// \todo Generalize serialization
		const Vector2f&  leftThumbstick = gamePad.getLeftThumbstick();
		const Vector2f& rightThumbstick = gamePad.getRightThumbstick();
		std::string connected = (gamePad.isConnected()) ? "true" : "false";

		// Send the response
		HttpResponse response(HttpStatus::Ok);

		response.getBody()
			<< "{\n"
			<< "\t\"isConnected\": "  << connected << ",\n"
			<< "\t\"buttons\": 7,\n"
			<< "\t\"leftTrigger\": "  << gamePad.getLeftTrigger()  << ",\n"
			<< "\t\"rightTrigger\": " << gamePad.getRightTrigger() << ",\n"
			<< "\t\"leftThumbstick\":  { \"x\": " <<  leftThumbstick.x() << ", \"y\": " <<  leftThumbstick.y() << " },\n"
			<< "\t\"rightThumbstick\": { \"x\": " << rightThumbstick.x() << ", \"y\": " << rightThumbstick.y() << " } \n"
			<< "}";

		response.addField("Content-Type", "application/json");
		sendResponse(connection, response);
	}
	else
	{
		// Return a 404 page

	}
}

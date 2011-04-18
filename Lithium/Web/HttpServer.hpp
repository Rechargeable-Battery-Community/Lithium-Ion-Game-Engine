/**
 * \file HttpServer.hpp
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

#ifndef LITHIUM_HTTP_SERVER_HPP_INCLUDED
#define LITHIUM_HTTP_SERVER_HPP_INCLUDED

#include <Lithium/Web/HttpRequest.hpp>
#include <Lithium/Web/HttpResponse.hpp>
#include <Lithium/Network/TcpSocket.hpp>

namespace Lithium
{
	class HttpServer
	{
		public:

			HttpServer(std::int16_t port);


		//----------------------------------------------------------------------
		// Handle connections
		//----------------------------------------------------------------------

		public:

			void update();

		private:

			void sendResponse(TcpSocket& connection, const HttpResponse& response);

		//----------------------------------------------------------------------
		// Input views
		//----------------------------------------------------------------------

		public:



		//----------------------------------------------------------------------
		// Member variables
		//----------------------------------------------------------------------

		private:

			static const int __bufferSize = 1024;

			TcpSocket _socket;
			IPAddress _connection;

			typedef void (HttpServer::*ResponseMethod)(HttpRequest&, TcpSocket& connection, const std::tr1::match_results<std::string::const_iterator>&);
			std::vector<std::pair<std::tr1::regex, ResponseMethod> > _responseMap;

			void getIndex(HttpRequest& request, TcpSocket& connection, const std::tr1::match_results<std::string::const_iterator>& match);
			void getImage(HttpRequest& request, TcpSocket& connection, const std::tr1::match_results<std::string::const_iterator>& match);
			void getScript(HttpRequest& request, TcpSocket& connection, const std::tr1::match_results<std::string::const_iterator>& match);
			void getStyleSheet(HttpRequest& request, TcpSocket& connection, const std::tr1::match_results<std::string::const_iterator>& match);
			void getGamePad(HttpRequest& request, TcpSocket& connection, const std::tr1::match_results<std::string::const_iterator>& match);

			void mapMethod(const std::tr1::regex& expression, ResponseMethod method);

	} ; // end class HttpServer

} // end namespace Lithium

#endif // end LITHIUM_HTTP_SERVER_HPP_INCLUDED

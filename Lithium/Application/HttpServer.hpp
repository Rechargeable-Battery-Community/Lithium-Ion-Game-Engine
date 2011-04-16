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

			typedef void (HttpServer::*ResponseMethod)(const HttpRequest&, TcpSocket& connection, const std::tr1::match_results<std::string::const_iterator>&);
			std::vector<std::pair<std::tr1::regex, ResponseMethod> > _responseMap;

			void getIndex(const HttpRequest& request, TcpSocket& connection, const std::tr1::match_results<std::string::const_iterator>& match);
			void getImage(const HttpRequest& request, TcpSocket& connection, const std::tr1::match_results<std::string::const_iterator>& match);
			void getScript(const HttpRequest& request, TcpSocket& connection, const std::tr1::match_results<std::string::const_iterator>& match);
			void getStyleSheet(const HttpRequest& request, TcpSocket& connection, const std::tr1::match_results<std::string::const_iterator>& match);
			void getGamePad(const HttpRequest& request, TcpSocket& connection, const std::tr1::match_results<std::string::const_iterator>& match);

			void mapMethod(const std::tr1::regex& expression, ResponseMethod method);

	} ; // end class HttpServer

} // end namespace Lithium

#endif // end LITHIUM_HTTP_SERVER_HPP_INCLUDED

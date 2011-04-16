/**
 * \file HttpListenerContext.hpp
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

#ifndef LITHIUM_HTTP_LISTENER_CONTEXT_HPP_INCLUDED
#define LITHIUM_HTTP_LISTENER_CONTEXT_HPP_INCLUDED

#include <Lithium/Network/Socket.hpp>
#include <Lithium/Web/HttpRequest.hpp>
#include <Lithium/Web/HttpResponse.hpp>

namespace Lithium
{
	class HttpListener;

	class HttpListenerContext
	{
		private:

			HttpListenerContext();

		public:

			inline bool isConnected() const
			{
				return true;
			}

			const HttpRequest& getRequest() const
			{
				return _request;
			}

			HttpResponse& getResponse()
			{
				return _response;
			}

			const HttpResponse& getResponse() const
			{
				return _response;
			}

		private:

			HttpRequest& getRequest()
			{
				return _request;
			}

		public:

			void close();

		private:

			Socket _socket;
			HttpRequest _request;
			HttpResponse _response;

	} ; // end class HttpListenerContext

} // end namespace Lithium

#endif // end LITHIUM_HTTP_LISTENER_CONTEXT_HPP_INCLUDED

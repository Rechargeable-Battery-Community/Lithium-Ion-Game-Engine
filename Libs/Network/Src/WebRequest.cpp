/**
 * \file WebRequest.cpp
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

#include "LithiumNetworkPCH.hpp"
#include <Lithium/Web/WebRequest.hpp>
#include <Lithium/Network/Dns.hpp>
#include <Lithium/Network/TcpSocket.hpp>
using namespace Lithium;

//---------------------------------------------------------------------

WebRequest::WebRequest(const std::string& host, const std::string& path)
: _host(host)
, _path(path)
, _requestMade(false)
{ }

//---------------------------------------------------------------------

const HttpResponse& WebRequest::getResponse() const
{
	if (!_requestMade)
	{
		// Get the IP address associated with the host
		std::vector<IPAddress> addresses = Dns::getHostAddresses(_host);

		// Attempt to connect to the host
		TcpSocket socket;
		socket.setBlocking(true);

		const std::int32_t size = addresses.size();

		for (std::int32_t i = 0; i < size; ++i)
		{
			socket.connect(addresses[i], 80);

			if (socket.isBound())
				break;
		}

		if (socket.isBound())
		{
			// Send the request
			HttpRequest request(HttpMethod::Get, _path);
			request.setHostname(_host);

			std::stringstream requestStream;
			request.write(requestStream);

			socket.send(requestStream);

			// Receive the response
			std::stringstream responseStream;			
			socket.receive(responseStream);

			HttpResponse response(responseStream);
			HttpStatus::Enum status = response.getStatus();
		}

		_requestMade = true;
	}

	return _response;
}

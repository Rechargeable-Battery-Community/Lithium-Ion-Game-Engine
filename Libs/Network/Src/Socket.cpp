/**
 * \file Socket.cpp
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
#include <Lithium/Network/Socket.hpp>
#include "NetworkPlatform.hpp"
using namespace Lithium;

LITHIUM_IMPLEMENT_INITIALIZE(Socket);
LITHIUM_REGISTER_INITIALIZE(Socket);
LITHIUM_IMPLEMENT_TERMINATE(Socket);
LITHIUM_REGISTER_TERMINATE(Socket);

//---------------------------------------------------------------------

Socket::Socket()
: _socket(0)
, _port(0)
, _blocking(false)
{ }

//---------------------------------------------------------------------

Socket::Socket(std::int32_t socket, std::int16_t port)
: _socket(socket)
, _port(port)
{ }

//---------------------------------------------------------------------

Socket::~Socket()
{
	close();
}

//---------------------------------------------------------------------

std::int32_t Socket::create(ProtocolType::Enum protocol)
{
	_socket = (protocol == ProtocolType::Tcp)
		? ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)
		: ::socket(AF_INET, SOCK_DGRAM,  IPPROTO_UDP);

	if (_socket <= 0)
	{
		_socket = 0;
		
		return -1;
	}
	else
	{
		// Set the blocking mode
		setBlocking(_blocking);

		return 0;
	}
}

//---------------------------------------------------------------------

std::int32_t Socket::bind(ProtocolType::Enum protocol, std::int16_t port)
{
	if (create(protocol) == 0)
	{
		// Bind to the port
		sockaddr_in address;
		address.sin_family = AF_INET;
		address.sin_addr.s_addr = INADDR_ANY;
		address.sin_port = htons(port);

		if (::bind(_socket, (const sockaddr*)&address, sizeof(sockaddr_in)) == 0)
		{
			_port = port;

			return 0;
		}
	}

	// An error has occurred
	close();

	return -1;
}

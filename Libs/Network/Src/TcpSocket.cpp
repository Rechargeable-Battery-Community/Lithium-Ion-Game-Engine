/**
 * \file TcpSocket.cpp
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
#include <Lithium/Network/TcpSocket.hpp>
#include "NetworkPlatform.hpp"
using namespace Lithium;

//---------------------------------------------------------------------

TcpSocket::TcpSocket()
{ }

//---------------------------------------------------------------------

TcpSocket::TcpSocket(std::int32_t socket, std::int16_t port)
: Socket(socket, port)
{ }

//---------------------------------------------------------------------

TcpSocket TcpSocket::accept()
{
	if (isBound())
	{
		const std::int32_t connection = ::accept(getHandle(), 0, 0);

		if (connection != INVALID_SOCKET)
			return TcpSocket(connection, getPort());
	}

	// No connection was made
	return TcpSocket();
}

//---------------------------------------------------------------------

void TcpSocket::connect(const IPAddress& destination, std::int16_t port)
{
	if (isBound())
		return;

	// Create the socket
	if (create(ProtocolType::Tcp) == 0)
	{
		// Connect to the server
		sockaddr_in address;
		address.sin_family = AF_INET;
		address.sin_addr.s_addr = htonl(destination.getAddress());
		address.sin_port = htons(port);

		if (::connect(getHandle(), (const sockaddr*)&address, sizeof(sockaddr_in)) == 0)
		{
			setPort(port);
			return;
		}
	}

	// An error has occurred
	close();
}

//---------------------------------------------------------------------

void TcpSocket::listen(std::int16_t port, std::int32_t backlog)
{
	if (isBound())
		return;

	// Bind to the port
	if (bind(ProtocolType::Tcp, port) == 0)
	{
		// Begin listening
		if (::listen(getHandle(), backlog) == 0)
			return;
	}

	// An error has occurred
	close();
}

//---------------------------------------------------------------------

std::int32_t TcpSocket::send(const void* data, std::int32_t size)
{
	if (!isBound())
		return 0;

	const std::int32_t sent = ::send(getHandle(), (const char*)data, size, 0);

	return (sent > 0) ? sent : 0;
}

//---------------------------------------------------------------------

std::int32_t TcpSocket::send(const std::stringstream& data)
{
	if (!isBound())
		return 0;

	const std::string& str = data.str();
	const char* buffer = str.c_str();
	std::int32_t totalSent = 0;
	std::int32_t left = str.size();

	while (true)
	{
		const std::int32_t sent = ::send(getHandle(), (const char*)buffer, left, 0);

		if (sent == -1)
			break;

		buffer += sent;
		totalSent += sent;
		left -= sent;

		if (left == 0)
			break;
	}

	return totalSent;
}

//---------------------------------------------------------------------

std::int32_t TcpSocket::receive(void* data, std::int32_t size)
{
	if (!isBound())
		return 0;

	const std::int32_t received = ::recv(getHandle(), (char*)data, size, 0);

	return (received > 0) ? received : 0;
}

//---------------------------------------------------------------------

std::int32_t TcpSocket::receive(std::stringstream& data)
{
	if (!isBound())
		return 0;

	const std::int32_t bufferSize = 5120;
	char buffer[bufferSize];
	std::int32_t totalReceived = 0;

	while (true)
	{
		const std::int32_t received = ::recv(getHandle(), buffer, bufferSize, 0);

		if (received <= 0)
			break;

		data.write(buffer, received);
		totalReceived += received;
	}

	return totalReceived;
}

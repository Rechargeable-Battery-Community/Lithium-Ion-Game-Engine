/**
 * \file Dns.cpp
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
#include <Lithium/Network/Dns.hpp>
#include "NetworkPlatformWindows.hpp"
#include <ws2tcpip.h>
using namespace Lithium;

//---------------------------------------------------------------------

std::string Dns::getHostName()
{
	// The largest buffer size that gethostname can handle is 256
	const int bufferSize = 256;
	char buffer[bufferSize];

	return gethostname(buffer, bufferSize) == 0
		? std::string(buffer)
		: std::string();
}

//---------------------------------------------------------------------

std::vector<IPAddress> Dns::getHostAddresses(const std::string& host)
{
	struct addrinfo* hostInfo;

	// Attempt to get the host address
	// If getaddrinfo returns 0 then the host was found
	if (getaddrinfo(host.c_str(), "http", 0, &hostInfo) != 0)
		return std::vector<IPAddress>();

	std::vector<IPAddress> addresses;

	// Iterate over the addresses
	const struct addrinfo* itr = hostInfo;

	for (; itr != 0; itr = itr->ai_next)
	{
		// Get the address info
		const struct sockaddr_in* sock = (sockaddr_in*)hostInfo->ai_addr;
		const std::uint32_t ip = ntohl(sock->sin_addr.s_addr);

		addresses.push_back(IPAddress(ip));
	}

	// Free the structure
	freeaddrinfo(hostInfo);

	return addresses;
}

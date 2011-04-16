
#include "../LithiumNetworkPCH.hpp"
#include <Lithium/Network/Socket.hpp>
#include "NetworkPlatformWindows.hpp"
using namespace Lithium;

//---------------------------------------------------------------------

void Socket::initialize()
{
	WSADATA data;
	WSAStartup(MAKEWORD(2, 2), &data);
}

//---------------------------------------------------------------------

void Socket::terminate()
{
	WSACleanup();
}

//---------------------------------------------------------------------

void Socket::close()
{
	if (_socket != 0)
	{
		closesocket(_socket);
		_socket = 0;
		_port = 0;
	}
}

//---------------------------------------------------------------------

void Socket::setBlocking(bool blocking)
{
	if (_socket != 0)
	{
		DWORD param = (blocking) ? 0 : 1;

		if (ioctlsocket(_socket, FIONBIO, &param) != 0)
			return;
	}
	
	_blocking = blocking;
}

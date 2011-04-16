/**
 * \file TcpSocket.hpp
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

#ifndef LITHIUM_TCP_SOCKET_HPP_INCLUDED
#define LITHIUM_TCP_SOCKET_HPP_INCLUDED

#include <Lithium/Network/Socket.hpp>

namespace Lithium
{
	class TcpSocket : public Socket
	{
		public:

			/**
			 * Creates an instance of the TcpSocket class.
			 */
			TcpSocket();

		private:

			TcpSocket(std::int32_t socket, std::int16_t port);

		public:

			TcpSocket accept();

			void connect(const IPAddress& address, std::int16_t port);

			void listen(std::int16_t port, std::int32_t backlog = 10);

			std::int32_t send(const void* data, std::int32_t size);
			std::int32_t send(const std::stringstream& data);

			std::int32_t receive(void* data, std::int32_t size);
			std::int32_t receive(std::stringstream& data);

	} ; // end class TcpSocket

} // end namespace Lithium

#endif // end LITHIUM_TCP_SOCKET_HPP_INCLUDED

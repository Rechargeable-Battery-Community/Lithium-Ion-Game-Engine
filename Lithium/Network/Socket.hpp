/**
 * \file Socket.hpp
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

#ifndef LITHIUM_SOCKET_HPP_INCLUDED
#define LITHIUM_SOCKET_HPP_INCLUDED

#include <Lithium/System/Initializer.hpp>
#include <Lithium/System/Terminator.hpp>
#include <Lithium/Network/IPAddress.hpp>
#include <Lithium/Network/ProtocolType.hpp>

namespace Lithium
{
	class Socket
	{
		LITHIUM_DECLARE_INITIALIZE;
		LITHIUM_DECLARE_TERMINATE;

		protected:

			/**
			 * Creates an instance of the Socket class.
			 */
			Socket();

			/**
			 * Initializes an instance of the Socket class.
			 *
			 * \param socket The handle to the socket.
			 * \param port The port the socket is using.
			 */
			Socket(std::int32_t socket, std::int16_t port);

		public:

			/**
			 * Destroys an instance of the Socket class.
			 */
			virtual ~Socket();

		public:

			inline bool isBound() const
			{
				return _socket != 0;
			}

			inline std::int16_t getPort() const
			{
				return _port;
			}

			inline bool isBlocking() const
			{
				return _blocking;
			}

			void setBlocking(bool blocking);

		protected:

			inline std::int32_t getHandle() const
			{
				return _socket;
			}

			inline void setPort(std::int16_t port)
			{
				_port = port;
			}

		public:

			void close();


		protected:

			std::int32_t create(ProtocolType::Enum type);

			std::int32_t bind(ProtocolType::Enum type, std::int16_t port);

		private:

			std::int32_t _socket;
			std::int16_t _port;
			bool _blocking;

	} ; // end class Socket

} // end namespace Lithium

#endif // end LITHIUM_SOCKET_HPP_INCLUDED

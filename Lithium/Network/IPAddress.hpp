/**
 * \file IPAddress.hpp
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

#ifndef LITHIUM_IP_ADDRESS_HPP_INCLUDED
#define LITHIUM_IP_ADDRESS_HPP_INCLUDED

#include <Lithium/System/Includes.hpp>

namespace Lithium
{
	class IPAddress
	{
		public:

			/**
			 * Creates an instance of the IPAddress class.
			 *
			 * The address is initially set to the loopback address, 127.0.0.1.
			 */
			IPAddress()
			: _address(fromDotDecimal(127, 0, 0, 1))
			{ }

			/**
			 * Initializes an instance of the IPAddress class.
			 *
			 * The IP address is in the form a.b.c.d.
			 *
			 * \param a The first octal of the IP address.
			 * \param b The second octal of the IP address.
			 * \param c The third octal of the IP address.
			 * \param d The fourth octal of the IP address.
			 */
			IPAddress(std::uint8_t a, std::uint8_t b, std::uint8_t c, std::uint8_t d)
			: _address(fromDotDecimal(a, b, c, d))
			{ }

			/**
			 * Initializes an instance of the IPAddress class.
			 *
			 * \param address The IP address.
			 */
			IPAddress(std::int32_t address)
			: _address(address)
			{ }

			/**
			 * Initializes an instance of the IPAddress class.
			 *
			 * \param copy The instance to copy.
			 */
			IPAddress(const IPAddress& copy)
			: _address(copy._address)
			{ }

			IPAddress& operator= (const IPAddress& copy)
			{
				_address = copy._address;

				return *this;
			}

		public:

			inline bool operator== (const IPAddress& compare) const
			{
				return _address == compare._address;
			}

			inline bool operator != (const IPAddress& compare) const
			{
				return _address != compare._address;
			}

		public:

			inline bool isLoopback() const
			{
				return (_address >> 24) == 127;
			}

			/**
			 * Retrieves the IP address.
			 *
			 * \returns the IP address.
			 */
			inline std::uint32_t getAddress() const
			{
				return _address;
			}

			inline void setAddress(std::uint32_t address)
			{
				_address = address;
			}

			void setAddress(std::uint8_t a, std::uint8_t b, std::uint8_t c, std::uint8_t d)
			{
				_address = fromDotDecimal(a, b, c, d);
			}

			void toDotDecimal(std::uint8_t& a, std::uint8_t& b, std::uint8_t& c, std::uint8_t& d) const;

		private:

			/**
			 * Creates an IP address from dot-decimal notation.
			 *
			 * \param a The first octal of the IP address.
			 * \param b The second octal of the IP address.
			 * \param c The third octal of the IP address.
			 * \param d The fourth octal of the IP address.
			 */
			inline static std::int32_t fromDotDecimal(std::uint8_t a, std::uint8_t b, std::int8_t c, std::int8_t d)
			{
				return (a << 24) | (b << 16) | (c << 8) | d;
			}

		private:

			/// The IP address
			std::int32_t _address;

	} ; // end class IPAddress

} // end namespace Lithium


std::ostream& operator<< (std::ostream& output, const Lithium::IPAddress& address);

#endif // end LITHIUM_IP_ADDRESS_HPP_INCLUDED

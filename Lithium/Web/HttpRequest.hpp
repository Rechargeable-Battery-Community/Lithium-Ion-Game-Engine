/**
 * \file HttpRequest.hpp
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

#ifndef LITHIUM_HTTP_REQUEST_HPP_INCLUDED
#define LITHIUM_HTTP_REQUEST_HPP_INCLUDED

#include <Lithium/System/Includes.hpp>
#include <Lithium/Web/HttpMethod.hpp>

namespace Lithium
{
	class WebRequest;

	class HttpRequest
	{
		public:

			HttpRequest(const HttpMethod::Enum method, const std::string& resource = "/");
			HttpRequest(std::stringstream& stream);

		private:

			HttpRequest();

		public:

			inline HttpMethod::Enum getMethod() const
			{
				return _method;
			}

			void setHostname(const std::string& host)
			{
				_hostname = host;
			}

			inline const std::string& getHostname() const
			{
				return _hostname;
			}

			inline const std::string& getResource() const
			{
				return _resource;
			}

		public:

			const std::string& getField(const std::string& name) const;

			void addField(const std::string& name, const std::string& value);

			void write(std::ostream& output) const;

			std::stringstream& getBody()
			{
				return _body;
			}

		private:

			friend class WebRequest;

			HttpMethod::Enum _method;
			std::string _hostname;
			std::string _resource;
			std::map<std::string, std::string> _fields;
			std::stringstream _body;

			static std::string __invalidField;

	} ; // end class HttpRequest

} // end namespace Lithium

#endif // end LITHIUM_HTTP_REQUEST_HPP_INCLUDED

/**
 * \file HttpResponse.hpp
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

#ifndef LITHIUM_HTTP_RESPONSE_HPP_INCLUDED
#define LITHIUM_HTTP_RESPONSE_HPP_INCLUDED

#include <Lithium/System/Includes.hpp>
#include <Lithium/Web/HttpStatus.hpp>

namespace Lithium
{
	class WebRequest;

	class HttpResponse
	{
		public:

			HttpResponse(const HttpStatus::Enum status);
			HttpResponse(std::stringstream& stream);

		private:

			HttpResponse() : _status(HttpStatus::Ok) { }

		public:

			inline HttpStatus::Enum getStatus() const
			{
				return _status;
			}

			std::stringstream& getBody()
			{
				return _body;
			}

		public:

			const std::string& getField(const std::string& name) const;

			void addField(const std::string& name, const std::string& value);

			void write(std::ostream& output) const;

		private:

			friend class WebRequest;

			HttpStatus::Enum _status;
			std::map<std::string, std::string> _fields;
			std::stringstream _body;

			static std::string __invalidField;

	} ; // end class HttpResponse

} // end namespace Lithium

#endif // end LITHIUM_HTTP_RESPONSE_HPP_INCLUDED

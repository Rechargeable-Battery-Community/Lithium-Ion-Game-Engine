/**
 * \file HttpRequest.cpp
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
#include <Lithium/Web/HttpRequest.hpp>
using namespace Lithium;

std::string HttpRequest::__invalidField;

//---------------------------------------------------------------------

HttpRequest::HttpRequest()
{ }

//---------------------------------------------------------------------

HttpRequest::HttpRequest(const HttpMethod::Enum method, const std::string& resource)
: _method(method)
, _resource(resource)
{ }

//---------------------------------------------------------------------

const std::string& HttpRequest::getField(const std::string& name) const
{
	std::map<std::string, std::string>::const_iterator itr = _fields.find(name);
	std::map<std::string, std::string>::const_iterator end = _fields.end();

	return (itr != end) ? itr->second : __invalidField;
}

//---------------------------------------------------------------------

void HttpRequest::addField(const std::string& name, const std::string& value)
{
	// See if the value is the hostname
	if (name == "Hostname")
	{
		_hostname = value;
	}
	else
	{
		// Add to the map
		std::pair<std::string, std::string> p(name, value);

		_fields.insert(p);
	}
}

//---------------------------------------------------------------------

void HttpRequest::write(std::ostream& output) const
{
	// Output the request line
	switch (_method)
	{
		case HttpMethod::Get   : output << "GET";    break;
		case HttpMethod::Post  : output << "POST";   break;
		case HttpMethod::Put   : output << "PUT";    break;
		case HttpMethod::Delete: output << "DELETE"; break;
	}

	output << " " << _resource << " HTTP/1.1\r\n";

	// Output the hostname
	output << "Host: " << _hostname << "\r\n";

	// Output the other fields
	std::map<std::string, std::string>::const_iterator itr = _fields.begin();
	std::map<std::string, std::string>::const_iterator end = _fields.end();

	for (; itr != end; ++itr)
		output << itr->first << ": " << itr->second << "\r\n";

	// If there is additional content (POST data) output the total size

	// Output a blank line
	output << "\r\n";

	// Output any additional content

}

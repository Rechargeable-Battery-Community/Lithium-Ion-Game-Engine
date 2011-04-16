/**
 * \file HttpResponse.cpp
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
#include <Lithium/Web/HttpResponse.hpp>
using namespace Lithium;

std::string HttpResponse::__invalidField;

//---------------------------------------------------------------------

HttpResponse::HttpResponse(const HttpStatus::Enum status)
: _status(status)
{ }

//---------------------------------------------------------------------

const std::string& HttpResponse::getField(const std::string& name) const
{
	std::map<std::string, std::string>::const_iterator itr = _fields.find(name);
	std::map<std::string, std::string>::const_iterator end = _fields.end();

	return (itr != end) ? itr->second : __invalidField;
}

//---------------------------------------------------------------------

void HttpResponse::addField(const std::string& name, const std::string& value)
{
	// Add to the map
	std::pair<std::string, std::string> p(name, value);

	_fields.insert(p);
}

//---------------------------------------------------------------------

void HttpResponse::write(std::ostream& output) const
{
	// Output the server status
	output << "HTTP/1.1 ";

	switch (_status)
	{
		case HttpStatus::Ok: output << "200 OK"; break;
	}

	output << "\r\n";

	// Output the other fields
	std::map<std::string, std::string>::const_iterator itr = _fields.begin();
	std::map<std::string, std::string>::const_iterator end = _fields.end();

	for (; itr != end; ++itr)
		output << itr->first << ": " << itr->second << "\r\n";

	// Output a blank line
	output << "\r\n";

	// Write the body
	output << _body.str();
}

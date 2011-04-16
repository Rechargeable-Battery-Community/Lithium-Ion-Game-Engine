/**
 * \file HttpParsing.cpp
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
#include <Lithium/Web/HttpResponse.hpp>
using namespace Lithium;

namespace
{
	std::string getLine(std::istream& input)
	{
		char prevChar;
		char currChar;
		std::stringstream buffer;

		input.get(prevChar);

		while (!input.eof())
		{
			input.get(currChar);

			if ((prevChar == '\r') && (currChar == '\n'))
				break;

			buffer << prevChar;
			prevChar = currChar;
		}

		return buffer.str();
	}

	void copyBody(std::istream& input, std::ostream& output)
	{
		// Get the number of bytes left
		const std::streamoff currPos = input.tellg();
		input.seekg(0, std::ios::end);
		const std::streamoff lastPos = input.tellg();
		const std::streamoff size = lastPos - currPos;

		// Return to the starting position
		input.seekg(currPos, std::ios::beg); 

		// Read in the rest of the stream
		char* buffer = new char[size];

		input.read(buffer, size);

		// Write to the stream
		output.write(buffer, size);

		// Cleanup the buffer
		delete[] buffer;
	}
}

//---------------------------------------------------------------------

HttpRequest::HttpRequest(std::stringstream& stream)
{
	// Get the request line
	std::string requestLine = getLine(stream);

	// Match the method and the resource
	const std::tr1::regex requestPattern("(GET|POST|PUT|DELETE)\\s+(/\\S*)\\s+(HTTP|http)/1.[0,1]");
	std::tr1::match_results<std::string::const_iterator> requestResult;

	if (std::tr1::regex_match(requestLine, requestResult, requestPattern))
	{
		const std::string& methodString = requestResult[1];

		_method =
			(methodString == "GET" ) ? HttpMethod::Get  :
			(methodString == "POST") ? HttpMethod::Post :
			(methodString == "PUT" ) ? HttpMethod::Put  : HttpMethod::Delete;

		_resource = requestResult[2];

		// Get each individual field
		while (true)
		{
			std::string field = getLine(stream);

			// The last line of the header is \r\n
			// This will have a size of zero when read.
			if (field.size() == 0)
				break;

		}

		// Get the message body
		copyBody(stream, _body);
	}
}

//---------------------------------------------------------------------

HttpResponse::HttpResponse(std::stringstream& stream)
{
	// Get the response line
	std::string responseLine = getLine(stream);

	// Match the status code
	const std::tr1::regex responsePattern("(HTTP|http)/1.[0,1]\\s+(\\d\\d\\d)\\s+\\w+");
	std::tr1::match_results<std::string::const_iterator> responseResult;

	if (std::tr1::regex_match(responseLine, responseResult, responsePattern))
	{
		const std::string& statusString = responseResult[2];

		_status =
			(statusString == "200") ? HttpStatus::Ok : HttpStatus::NotFound;

		// Get each indvidual field
		while (true)
		{
			std::string field = getLine(stream);

			// The last line of the header is \r\n
			// This will have a size of zero when read.
			if (field.size() == 0)
				break;
		}
	
		// Get the message body
		copyBody(stream, _body);
	}
}

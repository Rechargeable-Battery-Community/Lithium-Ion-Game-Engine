/**
 * \file WebRequest.hpp
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

#ifndef LITHIUM_WEB_REQUEST_HPP_INCLUDED
#define LITHIUM_WEB_REQUEST_HPP_INCLUDED

#include <Lithium/Web/HttpRequest.hpp>
#include <Lithium/Web/HttpResponse.hpp>

namespace Lithium
{
	class WebRequest
	{
		public:

			WebRequest(const std::string& host, const std::string& path);

			inline HttpRequest& getRequest()
			{
				return _request;
			}

			inline const HttpRequest& getRequest() const
			{
				return _request;
			}

			const HttpResponse& getResponse() const;

		private:

			/// The host to connect to
			std::string _host;
			/// The path to the resource
			std::string _path;
			/// Whether the request has been made
			mutable bool _requestMade;
			/// The request to make
			HttpRequest _request;
			/// The response from the server
			mutable HttpResponse _response;

	} ; // end class WebRequest

} // end namespace Lithium

#endif // end LITHIUM_WEB_REQUEST_HPP_INCLUDED

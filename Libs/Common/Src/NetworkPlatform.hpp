#ifndef LITHIUM_NETWORK_PLATFORM_HPP_INCLUDED
#define LITHIUM_NETWORK_PLATFORM_HPP_INCLUDED

//----------------------------------------------------------------------
// Windows platform
//----------------------------------------------------------------------

#if defined(_WIN32) || defined(WIN32)

#include "NetworkPlatformWindows.hpp"

//----------------------------------------------------------------------
// OS X platform 
//----------------------------------------------------------------------

#elif defined(__APPLE__)

//----------------------------------------------------------------------
// Linux platform
//----------------------------------------------------------------------

#else

#endif

#endif // end LITHIUM_NETWORK_PLATFORM_HPP_INCLUDED

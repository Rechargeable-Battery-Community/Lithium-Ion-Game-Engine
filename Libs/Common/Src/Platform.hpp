#ifndef LITHIUM_PLATFORM_HPP_INCLUDED
#define LITHIUM_PLATFORM_HPP_INCLUDED

//----------------------------------------------------------------------
// Windows platform
//----------------------------------------------------------------------

#if defined(_WIN32) || defined(WIN32)

#include "PlatformWindows.hpp"

//----------------------------------------------------------------------
// OS X platform 
//----------------------------------------------------------------------

#elif defined(__APPLE__)

//----------------------------------------------------------------------
// Linux platform
//----------------------------------------------------------------------

#else

#endif

#endif // end LITHIUM_PLATFORM_HPP_INCLUDED

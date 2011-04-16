#ifndef LITHIUM_GL_PLATFORM_HPP_INCLUDED
#define LITHIUM_GL_PLATFORM_HPP_INCLUDED

//----------------------------------------------------------------------
// Windows platform
//----------------------------------------------------------------------

#if defined(_WIN32) || defined(WIN32)

#include "GLPlatformWindows.hpp"

//----------------------------------------------------------------------
// OS X platform 
//----------------------------------------------------------------------

#elif defined(__APPLE__)

//----------------------------------------------------------------------
// Linux platform
//----------------------------------------------------------------------

#else

#endif

#endif // end LITHIUM_GL_PLATFORM_HPP_INCLUDED

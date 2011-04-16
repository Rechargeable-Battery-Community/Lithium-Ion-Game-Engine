#ifndef LITHIUM_PLATFORM_WINDOWS_HPP_INCLUDED
#define LITHIUM_PLATFORM_WINDOWS_HPP_INCLUDED

//----------------------------------------------------------------------
// Windows Includes
//----------------------------------------------------------------------

#define WINVER 0x0500
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>

/// Classname for the application
#define LITHIUM_WINDOW_CLASS_NAME "Lithium Application 0.1"

//----------------------------------------------------------------------
// Input
//----------------------------------------------------------------------

#include <XInput.h>

#endif // end LITHIUM_PLATFORM_WINDOWS_HPP_INCLUDED

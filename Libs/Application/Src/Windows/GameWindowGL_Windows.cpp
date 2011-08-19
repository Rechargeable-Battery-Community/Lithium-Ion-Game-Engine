/**
 * \file GameWindowGL_Windows.cpp
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

#include "../LithiumApplicationPCH.hpp"
#include <Lithium/Application/GameWindow.hpp>
#include "GraphicsContextGL_Windows.hpp"
using namespace Lithium;

//---------------------------------------------------------------------

void GameWindow::createContext()
{
	// Create the pixel format
	PIXELFORMATDESCRIPTOR pfd;
    ZeroMemory(&pfd, sizeof(pfd));
    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 24;
    pfd.cStencilBits = 8;
    pfd.iLayerType = PFD_MAIN_PLANE;

	// Get device context
	HWND handle = (HWND)IntToPtr(_handle);
	HDC hDC = GetDC(handle);

	// Create the temporary context
	// This has to be created in order to create the 3.2 context
    hDC = GetDC(handle);
    int pixelFormat = ChoosePixelFormat(hDC, &pfd);

    SetPixelFormat(hDC, pixelFormat, &pfd);
    HGLRC tempContext = wglCreateContext(hDC);
    wglMakeCurrent(hDC, tempContext);

	// Create the GL context
	int attributes[] = 
	{
		WGL_CONTEXT_MAJOR_VERSION_ARB, LITHIUM_GL_MAJOR_VERSION,
		WGL_CONTEXT_MINOR_VERSION_ARB, LITHIUM_GL_MINOR_VERSION,
		WGL_CONTEXT_FLAGS_ARB, 0,//WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB,
		0
	};

	PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB = NULL;
	wglCreateContextAttribsARB = (PFNWGLCREATECONTEXTATTRIBSARBPROC) wglGetProcAddress("wglCreateContextAttribsARB");

	HGLRC hRC;

	if (wglCreateContextAttribsARB)
		hRC = wglCreateContextAttribsARB(hDC, 0, attributes);

	// Initialize the API
	wglMakeCurrent(hDC, hRC);
	GraphicsAPI::initialize();
	wglMakeCurrent(0, 0);

	// Delete the temporary context
	wglDeleteContext(tempContext);

	// Create the graphics context
	_context = new GraphicsContext();
	_context->_device = hDC;
	_context->_render = hRC;
}

//---------------------------------------------------------------------

void GameWindow::deleteContext()
{
	// Delete the context from OpenGL
	wglMakeCurrent(_context->_device, 0);
	wglDeleteContext(_context->_render);

	// Release the device context
	HWND handle = (HWND)IntToPtr(_handle);
	ReleaseDC(handle, _context->_device);

	delete _context;
	_context = 0;
}

//---------------------------------------------------------------------

void GameWindow::makeContextCurrent()
{
	wglMakeCurrent(_context->_device, _context->_render);
}

//---------------------------------------------------------------------

void GameWindow::swapBuffers()
{
	SwapBuffers(_context->_device);
}

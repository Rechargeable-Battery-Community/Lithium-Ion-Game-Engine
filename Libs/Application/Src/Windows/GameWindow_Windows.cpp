/**
 * \file GameWindow_Windows.cpp
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
#include "PlatformWindows.hpp"
using namespace Lithium;

//---------------------------------------------------------------------

GameWindow::~GameWindow()
{
	// Delete the graphics contest
	deleteContext();

	// Destroy the window
	HWND handle = (HWND)IntToPtr(_handle);

	DestroyWindow(handle);
}

//---------------------------------------------------------------------

void GameWindow::createWindow()
{
	// Set the window styles
	DWORD dwStyle   = WS_VISIBLE;
	DWORD dwExStyle = WS_EX_APPWINDOW;

	if (_fullscreen)
	{
		dwStyle |= WS_POPUP;
	}
	else
	{
		dwStyle |= WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX;

		if (_resizeable)
		{
			dwStyle   |= WS_MAXIMIZEBOX | WS_SIZEBOX;
			dwExStyle |= WS_EX_WINDOWEDGE;
		}
	}

	// Get the window size
	RECT rect;
	rect.left   = 0;
	rect.right  = _width - 1;
	rect.top    = 0;
	rect.bottom = _height - 1;

	AdjustWindowRectEx(&rect, dwStyle, FALSE, dwExStyle);

	std::int32_t fullWidth  = rect.right - rect.left + 1;
	std::int32_t fullHeight = rect.bottom + rect.top + 1;

	// Get the working area
	RECT wa;

	if (_fullscreen)
	{
		wa.left = 0;
		wa.top  = 0;
	}
	else
	{
		SystemParametersInfo(SPI_GETWORKAREA, 0, &wa, 0);
	}

	// Create the window
	HWND handle = CreateWindowExA
	(
		dwExStyle,
		LITHIUM_WINDOW_CLASS_NAME,
		_title.c_str(),
		dwStyle,
		wa.left, wa.top,
		fullWidth,
		fullHeight,
		0,
		0,
		0,
		0
	);

	// Set the window handle
	_handle = PtrToInt(handle);
}

//---------------------------------------------------------------------

void GameWindow::showWindow()
{
	HWND handle = (HWND)IntToPtr(_handle);

	ShowWindow(handle, SW_SHOW);
}

//---------------------------------------------------------------------

void GameWindow::hideWindow()
{
	HWND handle = (HWND)IntToPtr(_handle);

	ShowWindow(handle, SW_HIDE);
}

//---------------------------------------------------------------------

void GameWindow::setTitle(const std::string& title)
{
	_title = title;

	HWND handle = (HWND)IntToPtr(_handle);

	// Update the window title
	SetWindowText(handle, title.c_str());
}

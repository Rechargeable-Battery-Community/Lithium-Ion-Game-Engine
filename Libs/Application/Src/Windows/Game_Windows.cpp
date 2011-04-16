/**
 * \file Game_Windows.cpp
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
#include <Lithium/Application/Game.hpp>
#include <Lithium/System/Initializer.hpp>
#include <Lithium/System/Terminator.hpp>
#include "PlatformWindows.hpp"
using namespace Lithium;

namespace
{
	/// Maps the virtual key codes to the Keys enumeration
	const std::int32_t __keyboardMapping[] =
	{
		-1, // 0x00
		-1, // 0x01 Left mouse button
		-1, // 0x02 Right mouse button
		-1, // 0x03 Control-break processing
		-1, // 0x04 Middle mouse button (three-button mouse)
		-1, // 0x05 X1 mouse button
		-1, // 0x06 X2 mouse button
		-1, // 0x07 Undefined
		Keys::Back, // 0x08 BACKSPACE key
		Keys::Tab, // 0x09 TAB key
		-1, // 0x0A Reserved
		-1, // 0x0B Reserved
		-1, // 0x0C CLEAR key
		Keys::Enter, // 0x0D ENTER key
		-1, // 0x0E Undefined
		-1, // 0x0F Undefined
		Keys::LeftShift, // 0x10 SHIFT key
		Keys::LeftControl, // 0x11 CTRL key
		Keys::LeftAlt, // 0x12 ALT key
		Keys::Pause, // 0x13 PAUSE key
		Keys::CapsLock, // 0x14 CAPS LOCK key
		-1, // 0x15 IME Kana mode /IME Hangul mode
		-1, // 0x16 Undefined
		-1, // 0x17 IME Junja mode
		-1, // 0x18 IME final mode
		-1, // 0x19 IME Hanja mode
		-1, // 0x1A Undefined
		Keys::Escape, // 0x1B ESC key
		-1, // 0x1C IME convert
		-1, // 0x1D IME nonconvert
		-1, // 0x1E IME accept
		-1, // 0x1F IME mode change request
		Keys::Space, // 0x20 SPACEBAR
		Keys::PageUp, // 0x21 PAGE UP key
		Keys::PageDown, // 0x22 PAGE DOWN key
		Keys::End, // 0x23 END key
		Keys::Home, // 0x24 HOME key
		Keys::Left, // 0x25 LEFT ARROW key
		Keys::Up, // 0x26 UP ARROW key
		Keys::Right, // 0x27 RIGHT ARROW key
		Keys::Down, // 0x28 DOWN ARROW key
		-1, // 0x29 SELECT key
		-1, // 0x2A PRINT key
		-1, // 0x2B EXECUTE key
		-1, // 0x2C PRINT SCREEN key
		Keys::Insert, // 0x2D INS key
		Keys::Delete, // 0x2E DEL key
		-1, // 0x2F HELP key
		-1, // 0x30 0 key
		-1, // 0x31 1 key
		-1, // 0x32 2 key
		-1, // 0x33 3 key
		-1, // 0x34 4 key
		-1, // 0x35 5 key
		-1, // 0x36 6 key
		-1, // 0x37 7 key
		-1, // 0x38 8 key
		-1, // 0x39 9 key
		-1, // 0x3A Undefined
		-1, // 0x3B Undefined
		-1, // 0x3C Undefined
		-1, // 0x3D Undefined
		-1, // 0x3E Undefined
		-1, // 0x3F Undefined
		-1, // 0x40 Undefined
		Keys::A, // 0x41 A key
		Keys::B, // 0x42 B key
		Keys::C, // 0x43 C key
		Keys::D, // 0x44 D key
		Keys::E, // 0x45 E key
		Keys::F, // 0x46 F key
		Keys::G, // 0x47 G key
		Keys::H, // 0x48 H key
		Keys::I, // 0x49 I key
		Keys::J, // 0x4A J key
		Keys::K, // 0x4B K key
		Keys::L, // 0x4C L key
		Keys::M, // 0x4D M key
		Keys::N, // 0x4E N key
		Keys::O, // 0x4F O key
		Keys::P, // 0x50 P key
		Keys::Q, // 0x51 Q key
		Keys::R, // 0x52 R key
		Keys::S, // 0x53 S key
		Keys::T, // 0x54 T key
		Keys::U, // 0x55 U key
		Keys::V, // 0x56 V key
		Keys::W, // 0x57 W key
		Keys::X, // 0x58 X key
		Keys::Y, // 0x59 Y key
		Keys::Z, // 0x5A Z key
		Keys::LeftWindows, // 0x5B Left Windows key (Natural keyboard)
		Keys::RightWindows, // 0x5C Right Windows key (Natural keyboard)
		-1, // 0x5D Applications key (Natural keyboard)
		-1, // 0x5E Reserved
		-1, // 0x5F Computer Sleep key
		-1, // 0x60 Numeric keypad 0 key
		-1, // 0x61 Numeric keypad 1 key
		-1, // 0x62 Numeric keypad 2 key
		-1, // 0x63 Numeric keypad 3 key
		-1, // 0x64 Numeric keypad 4 key
		-1, // 0x65 Numeric keypad 5 key
		-1, // 0x66 Numeric keypad 6 key
		-1, // 0x67 Numeric keypad 7 key
		-1, // 0x68 Numeric keypad 8 key
		-1, // 0x69 Numeric keypad 9 key
		-1, // 0x6A Multiply key
		-1, // 0x6B Add key
		-1, // 0x6C Separator key
		-1, // 0x6D Subtract key
		-1, // 0x6E Decimal key
		-1, // 0x6F Divide key
		Keys::F1, // 0x70 F1 key
		Keys::F2, // 0x71 F2 key
		Keys::F3, // 0x72 F3 key
		Keys::F4, // 0x73 F4 key
		Keys::F5, // 0x74 F5 key
		Keys::F6, // 0x75 F6 key
		Keys::F7, // 0x76 F7 key
		Keys::F8, // 0x77 F8 key
		Keys::F9, // 0x78 F9 key
		Keys::F10, // 0x79 F10 key
		Keys::F11, // 0x7A F11 key
		Keys::F12, // 0x7B F12 key
		-1, // 0x7C F13 key
		-1, // 0x7D F14 key
		-1, // 0x7E F15 key
		-1, // 0x7F F16 key
		-1, // 0x80 F17 key
		-1, // 0x81 F18 key
		-1, // 0x82 F19 key
		-1, // 0x83 F20 key
		-1, // 0x84 F21 key
		-1, // 0x85 F22 key
		-1, // 0x86 F23 key
		-1, // 0x87 F24 key
		-1, // 0x88 Unassigned
		-1, // 0x89 Unassigned
		-1, // 0x8A Unassigned
		-1, // 0x8B Unassigned
		-1, // 0x8C Unassigned
		-1, // 0x8D Unassigned
		-1, // 0x8E Unassigned
		-1, // 0x8F Unassigned
		-1, // 0x90 NUM LOCK key
		-1, // 0x91 SCROLL LOCK key
		-1, // 0x92 OEM specific
		-1, // 0x93 OEM specific
		-1, // 0x94 OEM specific
		-1, // 0x95 OEM specific
		-1, // 0x96 OEM specific
		-1, // 0x97 Unassigned
		-1, // 0x98 Unassigned
		-1, // 0x99 Unassigned
		-1, // 0x9A Unassigned
		-1, // 0x9B Unassigned
		-1, // 0x9C Unassigned
		-1, // 0x9D Unassigned
		-1, // 0x9E Unassigned
		-1, // 0x9F Unassigned
		Keys::LeftShift, // 0xA0 Left SHIFT key
		Keys::RightShift, // 0xA1 Right SHIFT key
		Keys::LeftControl, // 0xA2 Left CONTROL key
		Keys::RightControl, // 0xA3 Right CONTROL key
		-1, // 0xA4 Left MENU key
		-1, // 0xA5 Right MENU key
		-1, // 0xA6 Browser Back key
		-1, // 0xA7 Browser Forward key
		-1, // 0xA8 Browser Refresh key
		-1, // 0xA9 Browser Stop key
		-1, // 0xAA Browser Search key
		-1, // 0xAB Browser Favorites key
		-1, // 0xAC Browser Start and Home key
		-1, // 0xAD Volume Mute key
		-1, // 0xAE Volume Down key
		-1, // 0xAF Volume Up key
		-1, // 0xB0 Next Track key
		-1, // 0xB1 Previous Track key
		-1, // 0xB2 Stop Media key
		-1, // 0xB3 Play/Pause Media key
		-1, // 0xB4 Start Mail key
		-1, // 0xB5 Select Media key
		-1, // 0xB6 Start Application 1 key
		-1, // 0xB7 Start Application 2 key
		-1, // 0xB8 Reserved
		-1, // 0xB9 Reserved
		-1, // 0xBA Used for miscellaneous characters; it can vary by keyboard. For the US standard keyboard, the ';:' key
		-1, // 0xBB For any country/region, the '+' key
		-1, // 0xBC For any country/region, the ',' key
		-1, // 0xBD For any country/region, the '-' key
		-1, // 0xBE For any country/region, the '.' key
		-1, // 0xBF Used for miscellaneous characters; it can vary by keyboard. For the US standard keyboard, the '/?' key
		-1, // 0xC0 Used for miscellaneous characters; it can vary by keyboard. For the US standard keyboard, the '`~' key
		-1, // 0xC1 Reserved
		-1, // 0xC2 Reserved
		-1, // 0xC3 Reserved
		-1, // 0xC4 Reserved
		-1, // 0xC5 Reserved
		-1, // 0xC6 Reserved
		-1, // 0xC7 Reserved
		-1, // 0xC8 Reserved
		-1, // 0xC9 Reserved
		-1, // 0xCA Reserved
		-1, // 0xCB Reserved
		-1, // 0xCC Reserved
		-1, // 0xCD Reserved
		-1, // 0xCE Reserved
		-1, // 0xCF Reserved
		-1, // 0xD1 Reserved
		-1, // 0xD2 Reserved
		-1, // 0xD3 Reserved
		-1, // 0xD4 Reserved
		-1, // 0xD5 Reserved
		-1, // 0xD6 Reserved
		-1, // 0xD7 Reserved
		-1, // 0xD8 Unassigned
		-1, // 0xD9 Unassigned
		-1, // 0xDA Unassigned
		-1, // 0xDB Used for miscellaneous characters; it can vary by keyboard.
		-1, // 0xDC Used for miscellaneous characters; it can vary by keyboard. For the US standard keyboard, the '\|' key
		-1, // 0xDD Used for miscellaneous characters; it can vary by keyboard. For the US standard keyboard, the ']}' key
		-1, // 0xDE Used for miscellaneous characters; it can vary by keyboard. For the US standard keyboard, the 'single-quote/double-quote' key
		-1, // 0xDF Used for miscellaneous characters; it can vary by keyboard.
		-1, // 0xE0 Reserved
		-1, // 0xE1 OEM specific
		-1, // 0xE2 Either the angle bracket key or the backslash key on the RT 102-key keyboard
		-1, // 0xE3 OEM specific
		-1, // 0xE4 OEM specific
		-1, // 0xE5 IME PROCESS key
		-1, // 0xE6 OEM specific
		-1, // 0xE7 Used to pass Unicode characters as if they were keystrokes. The VK_PACKET key is the low word of a 32-bit Virtual Key value used for non-keyboard input methods. For more information, see Remark in KEYBDINPUT, SendInput, WM_KEYDOWN, and WM_KEYUP
		-1, // 0xE8 Unassigned
		-1, // 0xE9 OEM specific
		-1, // 0xEA OEM specific
		-1, // 0xEB OEM specific
		-1, // 0xEC OEM specific
		-1, // 0xED OEM specific
		-1, // 0xEE OEM specific
		-1, // 0xEF OEM specific
		-1, // 0xF0 OEM specific
		-1, // 0xF1 OEM specific
		-1, // 0xF2 OEM specific
		-1, // 0xF3 OEM specific
		-1, // 0xF4 OEM specific
		-1, // 0xF5 OEM specific
		-1, // 0xF6 Attn key
		-1, // 0xF7 CrSel key
		-1, // 0xF8 ExSel key
		-1, // 0xF9 Erase EOF key
		-1, // 0xFA Play key
		-1, // 0xFB Zoom key
		-1, // 0xFC Reserved
		-1, // 0xFD PA1 key
		-1, // 0xFE Clear key
	} ;

} // end annoynmous namespace

//---------------------------------------------------------------------

LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	Game* instance = Game::instance;

	switch (msg)
	{
		case WM_MOUSEMOVE:
		{
			std::int32_t xPos = (std::int32_t)(LOWORD(lParam));
			std::int32_t yPos = (std::int32_t)(HIWORD(lParam));

			instance->onMouseMove(xPos, yPos);

			return 0;
		}

		case WM_LBUTTONDOWN:
		{
			instance->onMouseClick(MouseButtons::Left, ButtonState::Pressed);
			
			return 0;
		}

		case WM_LBUTTONUP:
		{
			instance->onMouseClick(MouseButtons::Left, ButtonState::Released);

			return 0;
		}

		case WM_MBUTTONDOWN:
		{
			instance->onMouseClick(MouseButtons::Middle, ButtonState::Pressed);
			
			return 0;
		}

		case WM_MBUTTONUP:
		{
			instance->onMouseClick(MouseButtons::Middle, ButtonState::Released);

			return 0;
		}

		case WM_RBUTTONDOWN:
		{
			instance->onMouseClick(MouseButtons::Right, ButtonState::Pressed);
			
			return 0;
		}

		case WM_RBUTTONUP:
		{
			instance->onMouseClick(MouseButtons::Right, ButtonState::Released);

			return 0;
		}

		case WM_KEYDOWN:
		{
			std::int32_t key = __keyboardMapping[wParam];

			if (key != -1)
				instance->onKeyChange((Keys::Enum)key, KeyState::Down);

			return 0;
		}

		case WM_KEYUP:
		{
			std::int32_t key = __keyboardMapping[wParam];

			if (key != -1)
				instance->onKeyChange((Keys::Enum)key, KeyState::Up);

			return 0;
		}

		case WM_DESTROY:
		{
			PostQuitMessage(0);
			return 0;
		}
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

//---------------------------------------------------------------------

std::int32_t Game::main(std::int32_t, char**)
{
	// Register window class
	WNDCLASSEXA wc;
	wc.cbSize        = sizeof(WNDCLASSEX);
	wc.style         = CS_CLASSDC;
	wc.lpfnWndProc   = MsgProc;
	wc.cbClsExtra    = 0;
	wc.cbWndExtra    = 0;
	wc.hInstance     = GetModuleHandle(0);
	wc.hIcon         = LoadIcon(0, IDI_APPLICATION);
	wc.hCursor       = LoadCursor(0, IDC_ARROW);
	wc.hbrBackground = 0;
	wc.lpszMenuName  = 0;
	wc.lpszClassName = LITHIUM_WINDOW_CLASS_NAME;
	wc.hIconSm       = 0;

	RegisterClassExA(&wc);

	// Call the precreate method
	// instance->onPrecreate();	

	// Create the window
	instance->_gameWindow = new GameWindow("Lithium Application", 640, 480, false);

	// Call the initialize method
	instance->initialize();

	// Show the window
	instance->_gameWindow->showWindow();
	instance->_gameWindow->makeContextCurrent();

	// Start the message pump
	MSG msg = {0};

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			instance->update();
			instance->draw();
			instance->_gameWindow->swapBuffers();
		}
	}

	// Call the termination method
	instance->terminate();

	return 0;
}

//---------------------------------------------------------------------

int main()
//INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, INT)
{
	// Call the initializers
	Initializer::execute();

	Game::instance = new Game();

	std::int32_t returnCode = Game::main(0, 0);

	delete Game::instance;

	// Call the terminators
	Terminator::execute();

	return returnCode;
}

#include "GLPlatform.hpp"

// REMOVE LATER
void Game::draw()
{
	glClearColor(0.4f, 0.6f, 0.9f, 1.0f);
	glViewport(0, 0, _windowWidth, _windowHeight); // Set the viewport size to fill the window
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT); // Clear required buffers
}

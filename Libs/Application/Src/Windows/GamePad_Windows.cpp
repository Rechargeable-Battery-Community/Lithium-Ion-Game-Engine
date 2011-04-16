/**
 * \file GamePad_Windows.cpp
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
#include <Lithium/Input/GamePad.hpp>
#include <Lithium/Application/Game.hpp>
#include "PlatformWindows.hpp"
using namespace Lithium;

namespace
{
	/// The current state of the controllers
	GamePadState __gamePadState[PlayerIndex::Size];

} // end anonymous namespace

//----------------------------------------------------------------------

const GamePadState& GamePad::getState(PlayerIndex::Enum player)
{
	LITHIUM_ASSERT((player >= 0) && (player < PlayerIndex::Size), "Invalid player index");

	return __gamePadState[player];
}

//----------------------------------------------------------------------

void GamePad::setVibration(PlayerIndex::Enum player, const float leftMotor, const float rightMotor)
{
	XINPUT_VIBRATION vibration;
	ZeroMemory(&vibration, sizeof(XINPUT_VIBRATION));
	vibration.wLeftMotorSpeed  = (std::uint16_t)(leftMotor  * 65535.0f);
	vibration.wRightMotorSpeed = (std::uint16_t)(rightMotor * 65535.0f);

	XInputSetState(player, &vibration);
}

//----------------------------------------------------------------------

void Game::updateGamePads()
{
	DWORD result;

	for (DWORD i = 0; i < PlayerIndex::Size; ++i)
	{
		XINPUT_STATE state;
		ZeroMemory(&state, sizeof(XINPUT_STATE));

		// Get the state of the controller
		result = XInputGetState(i, &state);

		// Get the gamepad
		GamePadState& gamePad = __gamePadState[i];

		if (result == ERROR_SUCCESS)
		{
			gamePad._connected = true;

			// See if the packet number has changed
			if (gamePad.getPacketNumber() != state.dwPacketNumber)
			{
				// Set the trigger
				gamePad.setLeftTrigger((float)state.Gamepad.bLeftTrigger / 255.0f);
				gamePad.setRightTrigger((float)state.Gamepad.bRightTrigger / 255.0f);
				
				// Set the left thumbstick
				const float leftThumbX = (float)state.Gamepad.sThumbLX / 32767.0f;
				const float leftThumbY = (float)state.Gamepad.sThumbLY / 32767.0f;
				gamePad.setLeftThumbstick(leftThumbX, leftThumbY);

				// Set the right thumbstick
				const float rightThumbX = (float)state.Gamepad.sThumbRX / 32767.0f;
				const float rightThumbY = (float)state.Gamepad.sThumbRY / 32767.0f;
				gamePad.setRightThumbstick(rightThumbX, rightThumbY);

				// Set the buttons
				gamePad.setButtonFlags(state.Gamepad.wButtons);
			}
		}
		else
		{
			// Zero out the values
			gamePad._connected = false;
			gamePad._packetNumber = 0;

			// Set the trigger
			gamePad.setLeftTrigger(0.0f);
			gamePad.setRightTrigger(0.0f);

			// Set the thumbsticks
			gamePad.setLeftThumbstick(0.0f, 0.0f);
			gamePad.setRightThumbstick(0.0f, 0.0f);

			// Set the buttons
			gamePad.setButtonFlags(0);
		}
	}
}

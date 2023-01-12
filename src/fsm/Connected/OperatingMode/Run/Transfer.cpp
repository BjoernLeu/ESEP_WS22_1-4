/*
 * Transfer.cpp
 *
 *  Created on: Dec 22, 2022
 *      Author: daniel
 */

#include "Transfer.h"

Transfer::Transfer() {}

Transfer::~Transfer() {}

void Transfer::entry()
{
	std::cout << "Transfer entry" << std::endl;
	if(data->IdleTransferFesto1())
	{

		/// Hier muss noch eine passende Pulse message gefunden werden die wir senden sollen
		// if (MsgSendPulse(coid, -1, static_cast<int>(/*Hier muss die Pulse message rein*/), 0) == -1) {
		// 	perror("MsgSendPulse failed");
		// }
	}
	else if(data->IdleTransferFesto1())
	{

		/// Hier muss noch eine passende Pulse message gefunden werden die wir senden sollen
		// if (MsgSendPulse(coid, -1, static_cast<int>(/*hier muss die pulse message rein.*/), 0) == -1) {
		// 	perror("MsgSendPulse failed");
		// }
	}
	else
	{
		std::cout << "Error! \nNo Idle Transfer variable was set!" << std::endl;
	}
}

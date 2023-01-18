/*
 * Actions.cpp
 *
 * @author Björn Leuendorf
 * @author Johannes Oehlers
 */

#include "Actions.h"

Actions::Actions() {}
Actions::~Actions() {}

/**
* @brief Turns on the given light
*
* @param light GEREEN, YELLOW, RED, Q1, Q2, START_LED or RESET_LED
*/
void Actions::lightOn(int light){
	switch(light){
	case 1:
    	// std::cout << "green-on" << std::endl;
		if (MsgSendPulse(ContextData::coid, -1, static_cast<int>(LIGHT_GREEN_ON), 0) == -1) {
			perror("MsgSendPulse failed");
		}
		break;
	case 2:
    	// std::cout << "yellow-on" << std::endl;
		if (MsgSendPulse(ContextData::coid, -1, static_cast<int>(LIGHT_YELLOW_ON), 0) == -1) {
			perror("MsgSendPulse failed");
		}
		break;
	case 3:
		// std::cout << "red-on" << std::endl;
		if (MsgSendPulse(ContextData::coid, -1, static_cast<int>(LIGHT_RED_ON), 0) == -1) {
			perror("MsgSendPulse failed");
		}
		break;
	case 4:
    	// std::cout << "q1-on" << std::endl;
		ContextData::q1On = true;
		if (MsgSendPulse(ContextData::coid, -1, static_cast<int>(LIGHT_Q1_ON), 0) == -1) {
			perror("MsgSendPulse failed");
		}
		break;
	case 5:
    	// std::cout << "q2-on" << std::endl;
		ContextData::q2On = true;
		if (MsgSendPulse(ContextData::coid, -1, static_cast<int>(LIGHT_Q2_ON), 0) == -1) {
				perror("MsgSendPulse failed");
		}
		break;
	case 6:
		// std::cout << "start-on" << std::endl;
		if (MsgSendPulse(ContextData::coid, -1, static_cast<int>(LED_START_ON), 0) == -1) {
			perror("MsgSendPulse failed");
		}
		break;
	case 7:
		// std::cout << "start-on" << std::endl;
		if (MsgSendPulse(ContextData::coid, -1, static_cast<int>(LED_RESET_ON), 0) == -1) {
			perror("MsgSendPulse failed");
		}
		break;
	}
}
/**
* @brief Turns off the given light
*
* @param light GEREEN, YELLOW, RED, Q1, Q2, START_LED or RESET_LED
*/
void Actions::lightOff(int light){
	switch(light){
	case 1:
    	// std::cout << "green-off" << std::endl;
		if (MsgSendPulse(ContextData::coid, -1, static_cast<int>(LIGHT_GREEN_OFF), 0) == -1) {
			perror("MsgSendPulse failed");
		}
		break;
	case 2:
    	// std::cout << "yellow-off" << std::endl;
		if (MsgSendPulse(ContextData::coid, -1, static_cast<int>(LIGHT_YELLOW_OFF), 0) == -1) {
			perror("MsgSendPulse failed");
		}
		break;
	case 3:
		// std::cout << "red-off" << std::endl;
		if (MsgSendPulse(ContextData::coid, -1, static_cast<int>(LIGHT_RED_OFF), 0) == -1) {
			perror("MsgSendPulse failed");
		}
		break;
	case 4:
    	// std::cout << "q1-off" << std::endl;
		ContextData::q1On = false;
		if (MsgSendPulse(ContextData::coid, -1, static_cast<int>(LIGHT_Q1_OFF), 0) == -1) {
			perror("MsgSendPulse failed");
		}
		break;
	case 5:
    	// std::cout << "q2-off" << std::endl;
		ContextData::q2On = false;
		if (MsgSendPulse(ContextData::coid, -1, static_cast<int>(LIGHT_Q2_OFF), 0) == -1) {
			perror("MsgSendPulse failed");
		}
		break;
	case 6:
		// std::cout << "start-on" << std::endl;
		if (MsgSendPulse(ContextData::coid, -1, static_cast<int>(LED_START_OFF), 0) == -1) {
			perror("MsgSendPulse failed");
		}
		break;
	case 7:
		// std::cout << "start-on" << std::endl;
		if (MsgSendPulse(ContextData::coid, -1, static_cast<int>(LED_RESET_OFF), 0) == -1) {
			perror("MsgSendPulse failed");
		}
		break;
	}
}
/**
* @brief Starts a new Thread to let the given light blink at the given speed
*
* @param light GEREEN, YELLOW, RED, Q1, Q2, START_LED or RESET_LED
* @param speed SLOW or FAST
*/
void Actions::blinkingOn(int light, int speed){
	// std::cout << "entered blinkingOn: " << light << ", " << speed << std::endl;
	switch(light){
	case 1:
		ContextData::blinkGreen = true;
		// std::cout << "blinkGreen: " << ContextData::blinkGreen << std::endl;
		break;
	case 2:
		ContextData::blinkYellow = true;
		// std::cout << "blinkYellow: " << ContextData::blinkYellow << std::endl;
		break;
	case 3:
		ContextData::blinkRed = true;
		break;
	case 4:
		ContextData::blinkQ1 = true;
		break;
	case 5:
		ContextData::blinkQ2 = true;
		break;
	case 6:
		ContextData::blinkStart = true;
		break;
	case 7:
		ContextData::blinkReset = true;
		break;
	}

 	std::thread b (&Actions::blinking, this, light, speed);
	b.detach();
}

/**
* @brief Helper-Method for blinkingOn()
*
* @param light GEREEN, YELLOW, RED, Q1, Q2, START_LED or RESET_LED
* @param speed SLOW or FAST
*/
void Actions::blinking(int light, int speed){
	switch(light){
	case 1:
		while (true) {
			if (MsgSendPulse(ContextData::coid, -1, static_cast<int>(LIGHT_GREEN_ON), 0) == -1) {
				perror("MsgSendPulse failed");
			}
			usleep(speed);
			if (MsgSendPulse(ContextData::coid, -1, static_cast<int>(LIGHT_GREEN_OFF), 0) == -1) {
				perror("MsgSendPulse failed");
			}
			usleep(speed);
			if(!ContextData::blinkGreen){break;}
		}
		break;
	case 2:
		while (true) {
			if (MsgSendPulse(ContextData::coid, -1, static_cast<int>(LIGHT_YELLOW_ON), 0) == -1) {
				perror("MsgSendPulse failed");
			}
			usleep(speed);
			if (MsgSendPulse(ContextData::coid, -1, static_cast<int>(LIGHT_YELLOW_OFF), 0) == -1) {
				perror("MsgSendPulse failed");
			}
			usleep(speed);
			if(!ContextData::blinkYellow){break;}
		}
		break;
	case 3:
		while (true) {
			if (MsgSendPulse(ContextData::coid, -1, static_cast<int>(LIGHT_RED_ON), 0) == -1) {
				perror("MsgSendPulse failed");
			}
			usleep(speed);
			if (MsgSendPulse(ContextData::coid, -1, static_cast<int>(LIGHT_RED_OFF), 0) == -1) {
				perror("MsgSendPulse failed");
			}
			usleep(speed);
			if(!ContextData::blinkRed){break;}
		}
		break;
	case 4:
		while(true) {
			if (MsgSendPulse(ContextData::coid, -1, static_cast<int>(LIGHT_Q1_ON), 0) == -1) {
				perror("MsgSendPulse failed");
			}
			usleep(speed);
			if(ContextData::q1On){
				break;
			}
			if (MsgSendPulse(ContextData::coid, -1, static_cast<int>(LIGHT_Q1_OFF), 0) == -1) {
				perror("MsgSendPulse failed");
			}
			usleep(speed);
			if(!ContextData::blinkQ1){break;}
		}
		break;
	case 5:
		while(true) {
			if (MsgSendPulse(ContextData::coid, -1, static_cast<int>(LIGHT_Q2_ON), 0) == -1) {
				perror("MsgSendPulse failed");
			}
			usleep(speed);
			if(ContextData::q2On){
				break;
			}
			if (MsgSendPulse(ContextData::coid, -1, static_cast<int>(LIGHT_Q2_OFF), 0) == -1) {
				perror("MsgSendPulse failed");
			}
			usleep(speed);
			if(!ContextData::blinkQ2){break;}
		}
		break;
	case 6:
		while(true) {
			if (MsgSendPulse(ContextData::coid, -1, static_cast<int>(LED_START_ON), 0) == -1) {
				perror("MsgSendPulse failed");
			}
			usleep(speed);
			if (MsgSendPulse(ContextData::coid, -1, static_cast<int>(LED_START_OFF), 0) == -1) {
				perror("MsgSendPulse failed");
			}
			usleep(speed);
			if(!ContextData::blinkStart){break;}
		}
		break;
	case 7:
		while(true) {
			if (MsgSendPulse(ContextData::coid, -1, static_cast<int>(LED_RESET_ON), 0) == -1) {
				perror("MsgSendPulse failed");
			}
			usleep(speed);
			if (MsgSendPulse(ContextData::coid, -1, static_cast<int>(LED_RESET_OFF), 0) == -1) {
				perror("MsgSendPulse failed");
			}
			usleep(speed);
			if(!ContextData::blinkReset){break;}
		}
		break;
	}
}

/**
* @brief Stops the blinking of the given light
*
* @param light GEREEN, YELLOW, RED, Q1, Q2, START_LED, RESET_LED or ALL
*/
void Actions::blinkingOff(int light){
	switch(light){
	case 1:
		ContextData::blinkGreen = false;
		break;
	case 2:
		ContextData::blinkYellow = false;
		break;
	case 3:
		ContextData::blinkRed = false;
		break;
	case 4:
		ContextData::blinkQ1 = false;
		break;
	case 5:
		ContextData::blinkQ2 = false;
		break;
	case 6:
		ContextData::blinkStart = false;
		break;
	case 7:
		ContextData::blinkReset = false;
		break;
	case 8:
		ContextData::blinkGreen = false;
		ContextData::blinkYellow = false;
		ContextData::blinkRed = false;
		ContextData::blinkQ1 = false;
		ContextData::blinkQ2 = false;
		ContextData::blinkStart = false;
		ContextData::blinkReset = false;
		break;
	}
}

/**
* @brief Starts a new Thread to let the given light blink
		at the given speed for a given time
*
* @param light GEREEN, YELLOW, RED, Q1, Q2, START_LED or RESET_LED
* @param speed SLOW or FAST
* @param seconds double seconds
*/
 void Actions::blinkingOn(int light, int speed, int seconds){
 	// std::cout << "entered blinkingOn: " << light << ", " << speed << ", " << seconds << std::endl;
 	std::thread tB (&Actions::timeBlinking, this, light, speed, seconds);
	tB.detach();
}

void Actions::timeBlinking(int light, int speed, int seconds){
	auto now = std::chrono::system_clock::now();
	auto prev = std::chrono::system_clock::now();
 	
	// std::cout << "In timeBlinking" << std::endl;
	switch(light){
	case 1:
		while (true) {
			now = std::chrono::system_clock::now();
			if (MsgSendPulse(ContextData::coid, -1, static_cast<int>(LIGHT_GREEN_ON), 0) == -1) {
				perror("MsgSendPulse failed");
			}
			usleep(speed);
			if (MsgSendPulse(ContextData::coid, -1, static_cast<int>(LIGHT_GREEN_OFF), 0) == -1) {
				perror("MsgSendPulse failed");
			}
			usleep(speed);
			std::chrono::duration<double> elapsed_seconds = now-prev;
			if(elapsed_seconds > std::chrono::seconds(seconds))
			{
				if (MsgSendPulse(ContextData::coid, -1, static_cast<int>(LIGHT_GREEN_OFF), 0) == -1) {
					perror("MsgSendPulse failed");
				}
				break;
			}
		}
		break;
	case 2:
		while (true) {
			now = std::chrono::system_clock::now();
			if (MsgSendPulse(ContextData::coid, -1, static_cast<int>(LIGHT_YELLOW_ON), 0) == -1) {
				perror("MsgSendPulse failed");
			}
			usleep(speed);
			if (MsgSendPulse(ContextData::coid, -1, static_cast<int>(LIGHT_YELLOW_OFF), 0) == -1) {
				perror("MsgSendPulse failed");
			}
			usleep(speed);
			std::chrono::duration<double> elapsed_seconds = now-prev;
			if(elapsed_seconds > std::chrono::seconds(seconds))
			{
				if (MsgSendPulse(ContextData::coid, -1, static_cast<int>(LIGHT_YELLOW_OFF), 0) == -1) {
					perror("MsgSendPulse failed");
				}
				break;
			}
		}
		break;
	case 3:
		while (true) {
			now = std::chrono::system_clock::now();
			if (MsgSendPulse(ContextData::coid, -1, static_cast<int>(LIGHT_RED_ON), 0) == -1) {
				perror("MsgSendPulse failed");
			}
			usleep(speed);
			if (MsgSendPulse(ContextData::coid, -1, static_cast<int>(LIGHT_RED_OFF), 0) == -1) {
				perror("MsgSendPulse failed");
			}
			usleep(speed);
			std::chrono::duration<double> elapsed_seconds = now-prev;
			if(elapsed_seconds > std::chrono::seconds(seconds))
			{
				if (MsgSendPulse(ContextData::coid, -1, static_cast<int>(LIGHT_RED_OFF), 0) == -1) {
					perror("MsgSendPulse failed");
				}
				break;
			}
		}
		break;
	case 4:
		while(true) {
			now = std::chrono::system_clock::now();
			if (MsgSendPulse(ContextData::coid, -1, static_cast<int>(LIGHT_Q1_ON), 0) == -1) {
				perror("MsgSendPulse failed");
			}
			usleep(speed);
			if (MsgSendPulse(ContextData::coid, -1, static_cast<int>(LIGHT_Q1_OFF), 0) == -1) {
				perror("MsgSendPulse failed");
			}
			usleep(speed);
			std::chrono::duration<double> elapsed_seconds = now-prev;
			if(elapsed_seconds > std::chrono::seconds(seconds))
			{
				if(ContextData::q1On){
					break;
				}
				if (MsgSendPulse(ContextData::coid, -1, static_cast<int>(LIGHT_Q1_OFF), 0) == -1) {
					perror("MsgSendPulse failed");
				}
				break;
			}
		}
		break;
	case 5:
		while(true) {
			now = std::chrono::system_clock::now();
			if (MsgSendPulse(ContextData::coid, -1, static_cast<int>(LIGHT_Q2_ON), 0) == -1) {
				perror("MsgSendPulse failed");
			}
			usleep(speed);
			if (MsgSendPulse(ContextData::coid, -1, static_cast<int>(LIGHT_Q2_OFF), 0) == -1) {
				perror("MsgSendPulse failed");
			}
			usleep(speed);
			std::chrono::duration<double> elapsed_seconds = now-prev;
			if(elapsed_seconds > std::chrono::seconds(seconds))
			{
				if(ContextData::q2On){
					break;
				}
				if (MsgSendPulse(ContextData::coid, -1, static_cast<int>(LIGHT_Q2_OFF), 0) == -1) {
					perror("MsgSendPulse failed");
				}
				break;
			}
		}
		break;
	case 6:
		while(true) {
			now = std::chrono::system_clock::now();
			if (MsgSendPulse(ContextData::coid, -1, static_cast<int>(LED_START_ON), 0) == -1) {
				perror("MsgSendPulse failed");
			}
			usleep(speed);
			if (MsgSendPulse(ContextData::coid, -1, static_cast<int>(LED_START_OFF), 0) == -1) {
				perror("MsgSendPulse failed");
			}
			usleep(speed);
			std::chrono::duration<double> elapsed_seconds = now-prev;
			if(elapsed_seconds > std::chrono::seconds(seconds))
			{
				if (MsgSendPulse(ContextData::coid, -1, static_cast<int>(LED_START_OFF), 0) == -1) {
					perror("MsgSendPulse failed");
				}
				break;
			}
		}
		break;
	case 7:
		while(true) {
			now = std::chrono::system_clock::now();
			if (MsgSendPulse(ContextData::coid, -1, static_cast<int>(LED_RESET_ON), 0) == -1) {
				perror("MsgSendPulse failed");
			}
			usleep(speed);
			if (MsgSendPulse(ContextData::coid, -1, static_cast<int>(LED_RESET_OFF), 0) == -1) {
				perror("MsgSendPulse failed");
			}
			usleep(speed);
			std::chrono::duration<double> elapsed_seconds = now-prev;
			if(elapsed_seconds > std::chrono::seconds(seconds))
			{
				if (MsgSendPulse(ContextData::coid, -1, static_cast<int>(LED_RESET_OFF), 0) == -1) {
					perror("MsgSendPulse failed");
				}
				break;
			}
		}
		break;
	}
}

int Actions::sendMQTT()
{
	printf("Initialize Connection");
	fflush(stdout);
    MQTTClient client;
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
    MQTTClient_message pubmsg = MQTTClient_message_initializer;
    MQTTClient_deliveryToken token;
    int rc;

    //Create Client
    if ((rc = MQTTClient_create(&client, ADDRESS, CLIENTID,
        MQTTCLIENT_PERSISTENCE_NONE, NULL)) != MQTTCLIENT_SUCCESS)
    {
         printf("Failed to create client, return code %d\n", rc);
         exit(EXIT_FAILURE);
    } else 
    {
	    printf("Client created");
    }

    conn_opts.keepAliveInterval = 20;
    conn_opts.cleansession = 1;
    if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS)
    {
        printf("Failed to connect, return code %d\n", rc);
        exit(EXIT_FAILURE);
    } else 
    {
	    printf("Connection Initialized");
    }

    //publish this nonsense 
    char payload[20] = "Hello World!";
    pubmsg.payload = payload;
    pubmsg.payloadlen = (int)strlen(payload);
    pubmsg.qos = QOS;
    pubmsg.retained = 0;
    if ((rc = MQTTClient_publishMessage(client, TOPIC, &pubmsg, &token)) != MQTTCLIENT_SUCCESS)
    {
         printf("Failed to publish message, return code %d\n", rc);
         exit(EXIT_FAILURE);
    }

    printf("Waiting for up to %d seconds for publication of %s\n"
            "on topic %s for client with ClientID: %s\n",
            (int)(TIMEOUT/1000), PAYLOAD, TOPIC, CLIENTID);
    rc = MQTTClient_waitForCompletion(client, token, TIMEOUT);
    printf("Message with delivery token %d delivered\n", token);

    //selfdestroy by disconnect
    if ((rc = MQTTClient_disconnect(client, 10000)) != MQTTCLIENT_SUCCESS)
    	printf("Failed to disconnect, return code %d\n", rc);
    MQTTClient_destroy(&client);
	return rc;
}


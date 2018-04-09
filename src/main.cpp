#include <mbed.h>
#include <EthernetInterface.h>
#include <rtos.h>
#include <C12832.h>
#include <string>
#include "communications.h"
#include "components.h"

AssignmentBoard board;

//[name] These are the IDs of all the different LEDs.
char *name[] = {"red","green","blue"};

LED led[] =
{
    LED(board.K64F_RED_LED),
    LED(board.K64F_GREEN_LED),
    LED(board.K64F_BLUE_LED),
};

/**
 * @brief Sets an LED.
 */
void setLED(char *which, char *state)
{
    //Check which LED to set.
    for(int id = 0; id < 3; id++)
    {
        /* test for name match */
        if(strcmp(which, name[id])==0)
        {
            //Turn the LED on.
            if(strcmp(state,"on") == 0)
            {
                led[id].on();
                printf("led %d at %d \n", id, 0);
            }
            //Turn the LED off.
            if(strcmp(state,"off") == 0)
            {
                led[id].off();
                printf("led %d at %d \n", id, 1);
            }
            
            //Exit loop.
            break;
        }
    }
}

int main()
{
    Reciever reciever;

    MessageProcessor messageProcessor;

    while(1)
    {
        //Recieve the message.
        char* msg = (char*)reciever.getMessage().c_str();

        //Deocde the message.
        messageProcessor.decodeMessage(msg);

        //Do something with the message.
        setLED(
            (char*)messageProcessor.getKey().c_str(),
            (char*)messageProcessor.getValue().c_str()
        );
    }
}

#include <mbed.h>
#include <EthernetInterface.h>
#include <rtos.h>
#include <C12832.h>
#include <string>
#include "communications.h"

DigitalOut LED[] = { /* initialise to 1==off */
    DigitalOut(LED_RED,1),
    DigitalOut(LED_GREEN,1),
    DigitalOut(LED_BLUE,1)
};

char *name[] = {"red","green","blue"};

void setLED(char *which, char *state)
{
    int id;
    int logic;
    for( id=0 ; id<3 ; id++) {
        /* test for name match */
        if( strcmp(which, name[id])==0 ) break; /* exit loop with current id */
    }
    if( strcmp(state,"on")==0 )logic=0;
    if( strcmp(state,"off")==0 )logic=1;
    LED[id].write(logic);
    printf("led %d at %d \n", id, logic);
}

int main()
{
    Reciever reciever;
    MessageProcessor messageProcessor;

    while(1)
    {
        //Retrieve the message and decode it.
        messageProcessor.decodeMessage(reciever.getMessage());

        //Use the message to set the value of an LED.
        setLED(
            (char*)messageProcessor.getKey().c_str(),
            (char*)messageProcessor.getValue().c_str()
        );
    }
}

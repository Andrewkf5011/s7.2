#include <mbed.h>
#include <EthernetInterface.h>
#include <rtos.h>
#include <C12832.h>
#include <string>
#include "communications.h"

//[buffer] A buffer made of 1l bytes, where the
//recieved messages are stored.
char buffer[1024];

//[name] These are the IDs of all the different LEDs.
char *name[] = {"red","green","blue"};

//[LED] These are all the different LEDs.
DigitalOut LED[] =
{
    /* initialise to 1==off */
    DigitalOut(LED_RED,1),
    DigitalOut(LED_GREEN,1),
    DigitalOut(LED_BLUE,1)
};


/**
 * @brief Sets an LED.
 */
void setLED(char *which, char *state)
{
    //[id] The ID of the LED.
    int id;

    //[logic] The state to set the LED.
    int logic;

    //Check which LED to set.
    for(id=0; id<3; id++)
    {
        /* test for name match */
        if(strcmp(which, name[id])==0)
        {
            break; /* exit loop with current id */
        }
    }

    //Turn the LED on.
    if(strcmp(state,"on") == 0)
    {
        logic = 0;
    }
    //Turn the LED off.
    if(strcmp(state,"off") == 0)
    {
        logic = 1;
    }

    //Set the state of the LED.
    LED[id].write(logic);

    printf("led %d at %d \n", id, logic);
}

/**
 * @brief Processes a message in the format:
 *        key:value\n
 */
void process_message(char *buffer)
{
    //[key] The object to be used. (found at the beginning of the line).
    char *key = buffer;
    //printf("Key: %s\n", key);

    // find ':' seperator */
    char *value = strchr(buffer,':');
    //printf("Value: %s\n", value);

    /* mark end of key string */
    *value = '\0';
    //printf("Value_a: %s\n", value);

    /* move to start of value part */
    value += 1;
    //printf("Value_b: %s\n", value);

    /* find end of line */
    char *eol = strchr(value, '\n');
    //printf("EOL %s\n", eol);

    *eol = '\0';
    //printf("EOL_a %s\n", eol);

    //printf("Final Key: %s\n", key);
    //printf("Final Value: %s\n", value);
    //Set the LED using the key and the value.
    setLED(key, value);
}

int main()
{
    Reciever reciever;
    Processor processor;

    while(1)
    {
        char* msg = (char*)reciever.getMessage().c_str();

        process_message(msg);
    }
}

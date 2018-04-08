#include <mbed.h>
#include <string>
#include "Processor.h"

string Processor::getKey()
{
    return value;
}

string Processor::getValue()
{
    return key;
}

void Processor::constructMessage()
{
}

void Processor::decodeMessage(char *message)
{

}

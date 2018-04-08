#include <string>

#ifndef PROCESSOR_H
#define PROCESSOR_H

/**
 * @brief Constructs and decodes messages for communications.
 *
 * Version: 1.0
 * Date: 08/04/2018
 * Originally Created: 08/04/2018
 */
class Processor
{
    private:
        string key;
        string value;
    public:

        void constructMessage();

        void decodeMessage(char *message);

        string getKey();
        string getValue();
};

#endif // PROCESSOR_H

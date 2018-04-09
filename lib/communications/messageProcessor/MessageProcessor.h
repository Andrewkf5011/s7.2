#include<mbed.h>
#include<string>

#ifndef MESSAGEPROCESSOR_H
#define MESSAGEPROCESSOR_H

/**
 * @brief Constructs and decodes messages in the following format:
 *        "key:value\n"
 *        Message contain the following components:
 *        -Key: The objective of the message.
 *        -Value: The value of the objective.
 */
class MessageProcessor
{
  private:
      //[key] Stores the key component of the message.
      string key;
      //[value] Stores the value component of the message.
      string value;
  public:

    MessageProcessor();

    string getKey();

    string getValue();

    /**
     * Decodes a message into it's 'key' and 'value' components.
     * Message format should be: "key:value\n".
     */
    void decodeMessage(string message);

};

#endif // MESSAGEPROCESSOR_H

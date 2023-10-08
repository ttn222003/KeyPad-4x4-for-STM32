#include "main.h"
#include "KeyPad_4x4.h"

KeyPad_4x4_t keypad1; // This create keypad, and you can create how many keypad you want

int main(void)
{
    while(1)
    {
        keypad1.button = readButton(); // This function read the value of keypad
        // The value return is uint8_t type
        
        // Process the value
        // Delay. I recommend the delay value around 150 - 200
    }
}
#include "utils.h"
#include "gpio.h"

int main (int argc, char *argv[])
{
    // Check if the program is running as root
    if (getuid() != 0)
    {
        std::cout << "Error: This program needs to be run as root to run it." << std::endl;
        return -1;
    }

    int res = 0;

    res = pinExport(499);
    if (!res)
        std::cout << "Pin 499 exported" << std::endl;
    
    res = pinMode(499, OUTPUT);
    if (!res)
        std::cout << "Pin 499 set to output" << std::endl;

    while (1)
    {
        res = digitalWrite(499, HIGH);
        if (!res)
            std::cout << "Pin 499 set to HIGH" << std::endl;

        sleep(1);

        res = digitalWrite(499, LOW);
        if (!res)
            std::cout << "Pin 499 set to LOW" << std::endl;

        sleep(1);
    }

    res = pinUnexport(499);

    if (res)
        std::cout << "Pin 499 unexported" << std::endl;

    return 0;
}
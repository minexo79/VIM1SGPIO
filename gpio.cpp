#include "gpio.h"

int len = 0;
char buf[MAX_BUF] = {};

int pinExport(int pin)
{
    std::fstream iofile;
    iofile.open(SYSFS_GPIO_DIR "/export", std::ios::out);
    
    if (iofile.fail())
    {
        std::cout << "Error: Unable to open export file." << std::endl;
        return -1;
    }

    len = snprintf(buf, sizeof(buf) / sizeof(char), "%d", pin);
    iofile.write(buf, len);
    iofile.close();
 
    return 0;
}

int pinUnexport(int pin)
{
    std::fstream iofile;
    iofile.open(SYSFS_GPIO_DIR "/unexport", std::ios::out);
    
    if (iofile.fail())
    {
        std::cout << "Error: Unable to open export file." << std::endl;
        return -1;
    }

    len = snprintf(buf, sizeof(buf) / sizeof(char), "%d", pin);
    iofile.write(buf, len);
    iofile.close();
 
    return 0;
}

int pinMode(int pin, std::string mode)
{
    std::fstream iofile;
    // combine the path and the pin number
    std::string path = SYSFS_GPIO_DIR "/gpio" + std::to_string(pin) + "/direction";
    iofile.open(path, std::ios::out);
    
    if (iofile.fail())
    {
        std::cout << "Error: Unable to open direction file." << std::endl;
        return -1;
    }

    iofile << mode;
    iofile.close();
 
    return 0;
}

// int digitalRead(int pin);

int digitalWrite(int pin, int value)
{
    std::fstream iofile;
    // combine the path and the pin number
    std::string path = SYSFS_GPIO_DIR "/gpio" + std::to_string(pin) + "/value";
    iofile.open(path, std::ios::out);
    
    if (iofile.fail())
    {
        std::cout << "Error: Unable to open value file." << std::endl;
        return -1;
    }

    iofile << value;
    iofile.close();
 
    return 0;
}
#include <iostream>
#include <fstream>
#include <string>

extern "C"
{
    #include <fcntl.h>
    #include <errno.h>
    #include <unistd.h>
}

#define MAX_BUF 256
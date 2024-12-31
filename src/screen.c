#include <stdio.h>
#include <string.h>
#include "../headers/screen.h"

void screen(const char *input)
{
    printf("User wrote: %s\n", input);
    /*
        Wanted to split up the files and make it more organized.
        Thinking of using a windows library like WinAPI (literally #include <windows.h>)
        but im thinking if we want to add a UI later on it might be better to use GLFW (OpenGL Framwork)
    */
}
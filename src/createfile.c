#include <stdio.h>
#include "../headers/createfile.h"

void createfile(FILE *settings, char *filename, char *filecontents)
{
    settings = fopen(filename, "w");

    fprintf(settings, filecontents);
    fclose(settings);

    settings = fopen(filename, "r"); // Reopening for use in main.c
    if (settings == NULL)
    {
        printf("Unable to reopen");
    }
}
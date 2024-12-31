#include <stdio.h>
#include <string.h>
#include "../headers/uiserver.h"

void isValidChamp(const char *input) // Is Valid Champion
{
    FILE *champs = fopen("champions.txt", "r");
    if (champs == NULL)
    {
        perror("Error opening file");
        return;
    }
    char buffer[256], c[256];

    while (fgets(buffer, sizeof(buffer), champs))
    {
        buffer[strcspn(buffer, "\n")] = 0;

        if (strcmp(buffer, input) == 0)
        {
            printf("%s IS AS MATCH TO %s\n", input, buffer);
        }
    }

    /*if (c == NULL)
    {
        printf("Champion not found in Iostream");
    }*/

    fclose(champs);
}
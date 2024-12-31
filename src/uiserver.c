#include <stdio.h>
#include <string.h>
#include "../headers/uiserver.h"

int isValidChamp(const char *input)
{
    FILE *champs;
    champs = fopen("../../config/champions.txt", "r");
    if (champs == NULL)
    {
        perror("Error opening file");
        return 0;
    }
    char buffer[256], c[256];
    while (fgets(buffer, sizeof(buffer), champs))
    {
        buffer[strcspn(buffer, "\n")] = 0;
        if (strcmp(buffer, input) == 0)
        {
            printf("%s IS AS MATCH TO %s\n", input, buffer);
            return 1;
        }
    }
    fclose(champs);
    return 0;
}
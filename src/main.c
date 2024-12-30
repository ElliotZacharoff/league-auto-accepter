#include <stdio.h>
#include <string.h>
#include "../headers/screen.h"
#include "../headers/tokenize.h"
#include "../headers/createfile.h"

int main()
{
    FILE *settings;
    char FILE_NAME[256] = "settings.txt";
    char INITIAL_FILE_CONTENTS[256] = "Bans: \nChampions: \n";
    if (settings == NULL)
    {
        createfile(settings, FILE_NAME, INITIAL_FILE_CONTENTS);
    }

    settings = fopen(FILE_NAME, "r");

    char buffer[256], b[256], c[256];

    while (fscanf(settings, "%[^\n]\n", buffer) != EOF)
    {
        buffer[strcspn(buffer, "\n")] = '\0';

        if (strncmp(buffer, "Bans: ", 6) == 0) // 3rd param means everything after index 6 of the line
        {
            strcpy(b, buffer + 6);
        }
        else if (strncmp(buffer, "Champions: ", 11) == 0) // Same but with index 11
        {
            strcpy(c, buffer + 11);
        }
    }
    fclose(settings);

    struct Token champions[5], bans[5];
    char t[2] = {',', '\0'};

    // This is gonna correspond with the ranking so use this to loop through the champs/bans
    int rankBans = tokenize(bans, t, b);
    int rankChampions = tokenize(champions, t, c);

    printf("BANS:\n");
    for (int i = 0; i < rankBans; i++)
    {
        printf("Champ (ban): %s, Priority: %d\n", bans[i].name, bans[i].priorityRanking);
    }

    printf("\nCHAMPIONS:\n");
    for (int i = 0; i < rankChampions; i++)
    {
        printf("Champ: %s, Priority: %d\n", champions[i].name, champions[i].priorityRanking);
    }

    return 0;
}
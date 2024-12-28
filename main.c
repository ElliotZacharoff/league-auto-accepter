#include <stdio.h>
#include <string.h>
#include <stdbool.h>
//go get candy
/*struct Ban
{
    int ranking;
    char[256] name;
};

struct Champion
{
    int ranking;
    char[256]
}*/

int main()
{
    FILE *persisted;
    FILE *settings;

    settings = fopen("settings.txt", "r");
    if (settings == NULL)
    {
        // Error
        settings = fopen("settings.txt", "w");
        /* Code inbetween
        Bans: [up to 4 chapmions]
        Champions: [up to 9 champions]
        */

        fprintf(settings, "Bans: \nChampions: ");
        fclose(settings);
    }

    char buffer[256];

    char b[6] = "Bans: ";
    char c[12] = "Champions: ";

    char bans[256];
    char champions[256];

    while (fscanf(settings, "%[^\n]\n", buffer) != EOF)
    {
        buffer[strcspn(buffer, "\n")] = '\0';

        if (strncmp(buffer, b, strlen(b)) == 0)
        {
            strcpy(bans, buffer);
        }
        else if (strncmp(buffer, c, strlen(c)) == 0)
        {
            strcpy(champions, buffer);
        }
    }
    printf("B: %s\n", bans);
    printf("C: %s\n", champions);

    fclose(settings);
    return 0;
}

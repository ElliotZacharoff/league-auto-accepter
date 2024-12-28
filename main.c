#include <stdio.h>
#include <string.h>

/*struct Ban // Will use later for determining ranking and also selecting champion
{
    int ranking;
    char[256] name;
};

struct Champion
{
    int ranking;
    char[256] name;
}*/

int main()
{
    FILE *persisted;
    FILE *settings;

    settings = fopen("settings.txt", "r");
    if (settings == NULL)
    {
        settings = fopen("settings.txt", "w");
        /* Code inbetween
        Bans: [up to 4 chapmions]
        Champions: [up to 9 champions]
        */

        fprintf(settings, "Bans: \nChampions: ");
        fclose(settings);

        settings = fopen("settings.txt", "r"); // REOPENNNNN (sat with this for an hour before giving up and asking the gpt)
        if (settings == NULL)
        {
            printf("Unable to reopen");
            return 1;
        }
    }
    char buffer[256];

    char bans[256] = "";
    char champions[256] = "";

    while (fscanf(settings, "%[^\n]\n", buffer) != EOF) // still no clue tf the "%[^\n]\n" does but we ball
    {
        buffer[strcspn(buffer, "\n")] = '\0';

        if (strncmp(buffer, "Bans: ", 6) == 0) // 3rd param meaning everything after index 6
        {
            strcpy(bans, buffer + 6);
        }
        else if (strncmp(buffer, "Champions: ", 11) == 0) // After index 11
        {
            strcpy(champions, buffer + 11);
        }
    }
    fclose(settings);

    int rankBans = 1;
    int rankChampions = 1;

    // Split bans by ','
    printf("Bans:\n");
    char *token = strtok(bans, ",");
    while (token != NULL)
    {
        printf("- %s [ranking: %d]\n", token, rankBans);
        token = strtok(NULL, ",");
        rankBans += 1;
    }

    // Split champions by ','
    printf("Champions:\n");
    token = strtok(champions, ",");
    while (token != NULL)
    {
        printf("- %s [ranking: %d]\n", token, rankChampions);
        token = strtok(NULL, ",");
        rankChampions += 1;
    }

    return 0;
}
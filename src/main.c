#include <stdio.h>
#include <string.h>
#include "../headers/screen.h"

struct Ban // Will use later for determining ranking and also selecting champion
{
    int priorityRanking;
    char name[256];
};

struct Champion
{
    int priorityRanking;
    char name[256];
};

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

    struct Champion champs[5];
    struct Ban bans_[5];

    int rankBans = 1;
    int rankChampions = 1;

    // Split bans by ','
    char *token = strtok(bans, ",");
    while (token != NULL && rankBans <= 5)
    {
        strcpy(bans_[rankBans - 1].name, token);
        bans_[rankBans - 1].priorityRanking = rankBans;
        token = strtok(NULL, ",");
        rankBans++;
    }

    // Split champions by ','
    token = strtok(champions, ",");
    while (token != NULL && rankChampions <= 5)
    {
        strcpy(champs[rankChampions - 1].name, token);
        champs[rankChampions - 1].priorityRanking = rankChampions;
        token = strtok(NULL, ",");
        rankChampions++;
    }
    printf("BANS:\n");
    for (int i = 0; i < rankBans - 1; i++)
    {
        printf("Champ (ban): %s, Ranking: %d\n", bans_[i].name, bans_[i].priorityRanking);
    }
    printf("CHAMPIONS:\n");
    for (int i = 0; i < rankChampions - 1; i++)
    {
        printf("Champ: %s, Ranking: %d\n", champs[i].name, champs[i].priorityRanking);
    }
    // screen(); Test
    return 0;
}
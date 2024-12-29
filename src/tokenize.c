#include <stdio.h>
#include <string.h>
#include "../headers/tokenize.h"

int tokenize(struct Token *tokens, const char *t, char *data)
{
    int ranking = 0;

    char *token = strtok(data, t);
    while (token != NULL && ranking <= 5)
    {
        strcpy(tokens[ranking].name, token);
        tokens[ranking].priorityRanking = ranking + 1;
        token = strtok(NULL, t);
        ranking++;
    }

    return ranking;
}
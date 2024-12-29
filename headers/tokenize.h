#ifndef TOKENIZE_H
#define TOKENIZE_H

struct Token
{
    int priorityRanking;
    char name[256];
};

// int cause we need to know what the ranking for a thing is
int tokenize(struct Token *tokens, const char *t, char *data);

#endif // TOKENIZE_H
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX 9

typedef struct
{
    string name;
    int vote;
} candidate;

candidate candidates[MAX];

bool votes(string votename, int cand);
void winner(int tc);

int main(int argc, string argv[])
{
    // ask for no of candidates
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 0;
    }

    int total_candidate = argc - 1;
    if (total_candidate > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 1;
    }

    for (int i = 0; i < total_candidate; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].vote = 0;
    }

    int voter_count = get_int("Number of voters: ");
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");
        // calculate votes
        votes(name, total_candidate);
    }
    winner(total_candidate);
}

bool votes(string votename, int cand)
{
    bool found = false;
    int vote = 0;
    for (int i = 0; i < cand; i++)
    {
        if (strcmp(votename, candidates[i].name) == 0)
        {
            found = true;
            vote = candidates[i].vote += 1;
            return true;
        }
    }
    if (found == false)
    {
        printf("Invalid vote\n");
    }

    return false;
}

void winner(int tc)
{
    int highest_votes = 0;
    for (int i = 0; i < tc; i++)
    {
        if (candidates[i].vote > highest_votes)
        {
            highest_votes = candidates[i].vote;
        }
    }
    for (int i = 0; i < tc; i++)
    {
        if (candidates[i].vote == highest_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}

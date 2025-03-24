#include <cs50.h>
#include <stdio.h>

void print_rows(int tr, int b);

int main(void)
{
    // ask for the height of pyramid
    int n;
    do
    {
        n = get_int("What's the height of the pyramid : ");
    }
    while (n < 1);

    // print the pyramid
    for (int i = 0; i < n; i++)
    {
        // no of rows
        print_rows(n, i + 1);
    }
}

void print_rows(int tr, int b)
{
    for (int td = 0; td < tr - b; td++)
    {
        printf(" ");
    }
    for (int i = 0; i < b; i++)
    {
        printf("#");
    }
    printf("\n");
}

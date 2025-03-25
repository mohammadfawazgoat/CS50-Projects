#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cipher(string key, string text);

int main(int argc, string argv[])
{
    // get the key
    string key = argv[1];

    // validate the key
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    int digits = 0;
    for (int i = 0; i < strlen(key); i++)
    {
        for (int x = i + 1; x < strlen(key); x++)
        {
            if (tolower(key[i]) == tolower(key[x]))
            {
                printf("Key must not contain repeated characters\n");
                return 1;
            }
        }
        if (isalpha(key[i]))
        {
            digits++;
        }
    }
    if (digits != 26)
    {
        printf("key must contain 26 characters\n");
        return 1;
    }

    // get plaintext
    string plaintext = get_string("Plaintext: ");

    // encipher the text
    cipher(key, plaintext);

    // print
}

void cipher(string key, string text)
{
    printf("ciphertext: ");
    int cipher;

    for (int i = 0; i < strlen(text); i++)
    {

        if (isupper(text[i]))
        {

            cipher = key[text[i] - 'A'];
            cipher = toupper(cipher);
        }
        if (islower(text[i]))
        {
            cipher = toupper(key[text[i] - 'a']) + 32;
        }
        if (!isalpha(text[i]))
        {
            cipher = text[i];
        }

        printf("%c", cipher);
    }
    printf("\n");
}

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int alphabet_size = 26;
void cipher(int key, string text);

int main(int argc, string argv[])
{
    // get the key

    string key = argv[1];
    // check if agrc c is 2 or not
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // check for digits
    for (int i = 0, len = strlen(key); i < len; i++)
    {
        if (!isdigit(key[i]))
        {
            return 1;
        }
    }
    // convert string to int
    int keyint = atoi(key);

    // take plaintext
    string plaintext = get_string("Plaintext: ");

    // convert it into encipher and printf
    cipher(keyint, plaintext);
}
void cipher(int key, string text)
{
    printf("Ciphertext: ");
    int cipher;

    for (int i = 0, len = strlen(text); i < len; i++)
    {

        // cipher the capital letters
        if (isupper(text[i]))
        {
            cipher = (text[i] - 'A' + key) % alphabet_size + 'A';
        }
        // cipher the lower letters
        if (islower(text[i]))
        {
            cipher = (text[i] - 'a' + key) % alphabet_size + 'a';
        }
        // leave if not a letter
        if (!isalpha(text[i]))
        {
            cipher = text[i];
        }
        printf("%c", cipher);
    }
    printf("\n");
}

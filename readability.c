#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
const float first_multiplier = 0.0588;
const float second_multiplier = 0.296;
const float subtractor = 15.8;
const float avg = 100;

int main(void)
{
    // promt the user for a sentence

    string sentence = get_string("Sentence : ");

    // check the no. of letters,words,sentences

    float word = count_words(sentence);
    float totalwords = word + 1;

    // put it in coleman liau index
    // 0.0588(l) - 0.296(s)-15.8
    // l is average no. of letters per 100 words. s is average no. of sentences per 100 words
    float l = count_letters(sentence) * avg / totalwords;
    float s = count_sentences(sentence) * avg / totalwords;

    float liau = first_multiplier * l - second_multiplier * s - subtractor;
    int rounded_score = round(liau);

    // print whether the sentence is before grade 1,grade 1,''''''''''''''grade 16 or grade 16+
    if (rounded_score < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (rounded_score > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", rounded_score);
    }
}

int count_letters(string text)
{
    int letter_count = 0;

    int i;
    for (i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letter_count += 1;
        }
    }

    return letter_count;
}

int count_words(string text)
{
    int word_count = 0;
    int i;
    for (i = 0; i < strlen(text); i++)
    {
        if (isblank(text[i]))
        {
            word_count += 1;
        }
    }

    return word_count;
}

int count_sentences(string text)
{
    int sentence_count = 0;
    int i;
    for (i = 0; i < strlen(text); i++)
    {
        if (text[i] == '?' || text[i] == '!' || text[i] == '.')
        {
            sentence_count += 1;
        }
    }
    return sentence_count;
}

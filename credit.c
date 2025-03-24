#include <cs50.h>
#include <stdio.h>

long checksum(long number);
long digits(long no);

int main(void)
{
    // promt the user for card number
    long card_number;
    do
    {
        card_number = get_long("Whats the Card number : ");
    }
    while (card_number < 0);

    // check cardsum
    long sum = checksum(card_number);

    // check mastercard, visa, AE, or invalid
    long dd = digits(card_number);
    if (sum % 10 == 0 && dd == 16 &&
        (card_number / 100000000000000 == (51) || card_number / 100000000000000 == (52) ||
         card_number / 100000000000000 == (53) || card_number / 100000000000000 == (54) ||
         card_number / 100000000000000 == (55)))
    {
        printf("MASTERCARD\n");
    }
    else if (sum % 10 == 0 && dd == 15 &&
             (card_number / 10000000000000 == (34) || card_number / 10000000000000 == (37)))
    {
        printf("AMEX\n");
    }
    else if (sum % 10 == 0 && (dd == 16 || dd == 13) &&
             (card_number / 1000000000000000 == (4) || card_number / 1000000000000 == (4)))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

long checksum(long number)
{
    long no = number;
    long fvalue = 0;
    long x;
    for (x = 0; number > 0; x++)
    {
        long last = number % 10;
        fvalue += last;
        number = number / 100;
    }

    number = no / 10;
    long add = 0;
    long dig = 0;
    long first = 0;
    long ss = 0;
    long value = 0;
    long i;
    for (i = 0; number > 0; i++)
    {

        long digit = number % 10;
        digit = digit * 2;
        if (digit > 9)
        {
            dig = digit % 10;
            first = digit / 10;
            ss = dig + first;
            add += ss;
        }
        else
        {
            value += digit;
        }

        number = number / 100;
    }

    long total = value + add + fvalue;

    return total;
}

long digits(long no)
{
    long i;
    for (i = 0; no > 0; i++)
    {
        no = no / 10;
    }
    return i;
}

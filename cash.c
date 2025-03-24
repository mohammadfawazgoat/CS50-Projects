#include <cs50.h>
#include <stdio.h>

int calculate_coins(int coin_value, int cash);

int main(void)
{
    int quarter_value = 25;
    int dimes_value = 10;
    int nickels_value = 5;
    int pennies_value = 1;
    // promt the user for cash
    int cash;
    do
    {
        cash = get_int("Change owed :");
    }
    while (cash < 0);

    // calculate the no. of quarters req.
    int quarter = calculate_coins(quarter_value, cash);
    // substract that from cash
    cash = cash - (quarter * 25);

    // calculate the no. of dimes req.
    int dimes = calculate_coins(dimes_value, cash);
    // subtract from cash
    cash = cash - (dimes * 10);

    // calculate the no. of nickels req.
    int nickels = calculate_coins(nickels_value, cash);
    // sub. that from cash
    cash = cash - (nickels * 5);

    // calculate the no. of pennies req.
    int pennies = calculate_coins(pennies_value, cash);
    // sub. that from cash
    cash = cash - (pennies * 1);

    // sum
    int sum = quarter + dimes + nickels + pennies;
    // print sum
    printf("%i\n", sum);
}

int calculate_coins(int coin_value, int cash)
{
    int coin;
    for (coin = 0; cash >= coin_value; coin++)
    {
        cash = cash - coin_value;
    }
    return coin;
}

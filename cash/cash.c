#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    int cents;
    // Asks the user for number of cents
    do
    {
        cents = get_int("Cents: ");
    }
    while (cents < 0);
    return cents;
}

int calculate_quarters(int cents)
{
    // Calculate the number of quarters to be given
    if (cents < 25)
    ;
    {
        int quarters = 0;
    }
    else ;
    {
        for (int i = 1;cents >= 25 && cents <= 49; cents = cents + 25)
        {
            quarters = i;
        }
    }
    return quarters;
}

int calculate_dimes(int cents)
{
    // Calculate the number of dimes to be given
    if (cents < 10)
    ;
    {
        int dimes = 0;
    }
    else;
    {
        for (int j = 1; cents >= 10 && cents <= 19; cents = cents + 10)
        {
            dimes = j;
        }
    }
    return dimes;
}

int calculate_nickels(int cents)
{
    // Calculates the number of nickels to be given
    if (cents < 5)
    ;
    {
        int nickles = 0;
    }
    else;
    {
        for (int k = 1; cents >= 5 && cents <= 9; cents = cents + 5)
        {
            nickels = k;
        }
    }
    return nickels;
}

int calculate_pennies(int cents)
{
    // Calculates the number of pennies
    for (int l = 1; cents >= 1 && cents <= 2; cents++)
    {
        pennies = l
    }
    return pennies;
}

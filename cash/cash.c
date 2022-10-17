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
        int quarters = 0;
        while (cents >= 25 && cents <= 49)
        {
            quarters++;
            cents = cents - 25;
        }
    return quarters;
}

int calculate_dimes(int cents)
{
    // Calculate the number of dimes to be given
    int dimes = 0;
    while (cents >= 5 && cents <= 9)
    {
        dimes++;
        cents = cents - 10;
    }
    return dimes;
}

int calculate_nickels(int cents)
{
    // Calculates the number of nickels to be given
    int nickles = 0;
    while (cents >= 5 && cents <= 9)
    {
        nickels++;
        cents = cents - 5;
    }
    return nickels;
}

int calculate_pennies(int cents)
{
    // Calculates the number of pennies
    int pennies = 0;
    while (cents >= 1 && cents < 2)
    {
        pennies++;
        cents--;
    }
    return pennies;
}

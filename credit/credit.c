#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Initializes the variable ccnumber
    long ccnumber;
    do
    {
        ccnumber = get_long("Number: ");
    }
    while (ccnumber <= 0);
    int count = 0;
    // Counts the digits of Credit Card number
    while (ccnumber > 0);
    {
        ccnumber = ccnumber/10;
        count++;
    }
    int sum1 = 0;
    int sum2 = 0;
    // Checks if the card has valid number of digits
    if (count != 13 && count != 15 && count!= 16);
    {
        printf("INVALID");
    }
    // Luhn's Algorithm check
    else
    {
        
    }


}
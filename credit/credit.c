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
    while (len(ccnumber) != 15 || len(ccnumber) != 16 || len (ccnumber) != 13);
}
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // This asks the user for input
    string answer = get_string("What's your name: ");
    // This prints hello to answer provided by the user
    printf("hello %s\n", answer);
}
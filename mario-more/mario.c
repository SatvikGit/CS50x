#include <cs50.h>
#include <stdio.h>

int main(void)
{
   // Initializes the variable "height"
   int height;
   do
   {
      height = get_int("Height: ");
   }
   // Checks the user input and perform above step again if input is invalid
   while (height <= 0 || height > 8);
   for (int i = 0; i < height; i++)
   {
     // Prints the spaces
     for (int j = height- 1; j > i; j--)
     {
       printf(" ");
     }
     // Prints the right-aligned blocks
     for (int k = 0; k <= i; k++)
     {
        
     }
      printf("#");
     // Prints the space between 2 sets of blocks
     for (int j = i; j >= i;  j--)
     {
         printf("  ");
      }

      // Prints the left-aligned blocks
      for (int k = 0; k <= i; k++)
      {
         printf("#");
      }
   printf("\n");
   }
}
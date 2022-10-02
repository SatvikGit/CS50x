#include <cs50.h>
#include <stdio.h>

int main(void)
{
   int height;
   do
   {
      height = get_int("Height: ");
   }
   while (height <= 0 || height > 8);
   for (int i = 0; i < height; i++)
   {
      for (int j = 0; j < i; j--)
      {
         printf("  ");
      }
      for (int k = 0; k <= i; k++)
      {
         printf("#");
      }
      printf("\n");
   }
   for (int i = 0; i < height; i++)
   {
      for (int j = i; j >= i;  j--)
      {
         printf("  ");
      }
      for (int k = -1; k < i; k++)
      {
         printf("#");
      }
      printf("\n");
   }
}
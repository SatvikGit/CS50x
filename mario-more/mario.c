#include <cs50.h>
#include <stdio.h>

int main(void)
{
   int height;
   do
   {
      height = get_int("Height : ");
   }
   while (height <= 0);
   for (int i = 0; i < height; i++)
   {
      for (int j = 0; j <= i; j++)
      {
         printf("#");
      }
      printf("\n");
   }
   do
   {
      height = get_int("Height : ");
   }
}
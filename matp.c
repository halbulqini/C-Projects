#include <stdio.h>
#include <stdlib.h>

void main ()
{
    int m1, n1, m2, n2, i, j, k;

   printf("Enter the number of rows of the first matrix\n");
   scanf("%d", &m1);
   printf("Enter the number of columns of the first matrix\n");
   scanf("%d", &n1);

   printf("Enter the number of rows of the second matrix\n");
   scanf("%d", &m2);
   printf("Enter the number of columns of the second matrix\n");
   scanf("%d", &n2);

   if (n1!=m2)
   {
       printf("Error in Entry");

   }
   else
   {

   float first[m1][n1], second[m2][n2], res[m1][n2];
   float sum=0;

   printf("Enter the elements of first matrix\n");

   for (i = 0; i < m1; i++)
      for (j = 0; j < n1; j++)
         scanf("%f", &first[i][j]);

   printf("Enter the elements of second matrix\n");

   for (i = 0; i < m2; i++)
      for (j = 0 ; j < n2; j++)
         scanf("%f", &second[i][j]);

   printf("The result of multiplication \n");

   for (i = 0; i < m1; i++)
   {

      for (j = 0 ; j < n2; j++)
     {
        for (k = 0 ; k < n1; k++)
        {
            sum += first [i][k] * second [k][j];
        }
        res[i][j]=sum;
        sum=0;
        printf("%f\t", res[i][j]);
     }
      printf("\n");
    }
   }
}


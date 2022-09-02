/* Program for Solution of 2-D STEADY STATE
HEAT CONDUCTION without heat generation (Laplace Equation) */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    float T[10][10], temp[10][10], err[10][10];
    float Teast, Twest, Tnorth, Tsouth, maxerr;
    int row,column,nodex,nodey,i,iter,conv;
    do
    {
        printf("Enter the grid size ( <= 10 * 10)\n");
        scanf("%d %d",&nodex,&nodey);
    }while((nodex >10||nodex<0)||(nodey >10||nodey<0));
    printf("Enter the Boundary Conditions (Left, right, above and under):\n");
    scanf("%f %f %f %f", &Teast, &Twest, &Tnorth, &Tsouth);
    for(row=0;row<nodey;row++)
        for(column=0;column<nodex;column++)
            T[row][column]=0;
    for(row=0;row<nodey;row++)
    {
        temp[row][0] = T[row][0]= Teast;  //Left boundary condition
        temp[row][nodex-1]=T[row][nodex-1]=Twest;//right boundary condition
    }
    for(column=1;column<nodex-1;column++)
    {
        temp[0][column] = T[0][column]=Tnorth;//above boundary condition
        temp[nodey-1][column] = T[nodey-1][column]=Tsouth;//below boundary condition
    }

    printf(" Enter the allowed error and maximum number of iterations : ");
    scanf("%f %f",&maxerr,&iter);
    for(i=1;i<=iter;i++)
    {
        conv=1;
        for(row=1;row<nodey-1;row++)
            for(column=1;column< nodex-1;column++)
                temp[row][column]=(T[row-1][column]+T[row+1][column]+T[row][column+1]+T[row][column-1])/4;

        printf("The temperature values after iteration %d are:\n",i);
        for(row=0;row<nodey;row++)
            {
                for(column=0;column< nodex;column++)
                {
                printf("%f \t",temp[row][column]);//display the value after the calculation
                err[row][column]=fabs((temp[row][column]-T[row][column])/temp[row][column]);
                }
            printf("\n");
            }

        for(row=0;row<nodey-1;row++)
            for(column=0;column< nodex-1;column++)
        {
            if (err[row][column] >= maxerr) conv= 0;
        }
        if (conv ==1)
        {
            printf (" Convergence achieved \n");
            printf (" The temperature distribution across the region is :\n");
            for(row=0;row<nodey;row++)
            {
                for(column=0;column< nodex;column++)
                {
                    printf("%f \t",temp[row][column]);//display the final values
                }
            printf("\n");
            }
        exit (1);
        }
        for(row=1;row<nodey-1;row++)
            for(column=1;column< nodex-1;column++)
        {
            T[row][column]=temp[row][column];
        }
    }
    printf ("No convergence");
    return 1;
    }


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float a,b,c,d,imag_part,real_part,x1,x2;

    printf("enter the coefficient a \n");
    scanf("%f", &a);

    printf("enter the coefficient b \n");
    scanf("%f", &b);

    printf("enter the coefficient c \n");
    scanf("%f", &c);

    d=(b*b)-(4.0*a*c) ;


    if(d>0.0){

    x1=(-b+sqrt(d))/(2*a);

    x2=(b-sqrt(d))/(2*a);

   printf("x1= %f \n",x1);
   printf("x2= %f \n",x2);}

    else if (d <0.0){
    real_part=-b/(2.0*a);
    imag_part=(sqrt(abs(d))/(2.0*a));
    printf("x1= %f +i %f \n",real_part, imag_part);
    printf("x2= %f -i %f \n",real_part, imag_part);}

    else if(d==0) {

     x1=-b/(2.0*a);
    printf("x1=x2= %f \n",x1);}

    return 0;
}

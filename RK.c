  #include<stdio.h>
  #include<math.h>
  float f(float x, float y)
  {
  float a;
  a=(-2*y)/(x+10);
  return a;
  }
  int main()
  {
    float x,y, xf,h, yact, yRK, yE, k1,k2,ErrE=0, ErrRK=0;
    printf("Enter the initial independent value (x0) : ");
    scanf("%f",&x);
    printf("Enter the initial dependent value (y0) : ");
    scanf("%f",&y);
    printf("Enter the final independent value(xf) : ");
    scanf("%f",&xf);
    printf("Enter the step h : ");
    scanf("%f",&h);
    yRK=y;

    yE=y;

    printf("\n  x\tyact\t yRK\terrRK(%%)yE\terrEuler(%%)\n");
    printf("%0.3f\t%0.3f\t%0.3f\t%0.3f\t%0.3f\t%0.3f\n",x,y,y,ErrRK,y,ErrE);
    while(x<xf)
    {
        yact=2000*pow(((x+h)+10),-2);
        k1=f(x,yRK);
        k2=f(x+h,yRK+k1*h);
        yRK=yRK+(h/2*(k1+k2));
        ErrRK=fabs((yact-yRK)/yact)*100;

        yE=yE+h*f(x,yE);
        ErrE=fabs((yact-yE)/yact)*100;

        x=x+h;
        printf("%0.3f\t%0.3f\t%0.3f\t%0.3f \t%0.3f \t%0.3f\n",x,yact,yRK,ErrRK,yE,ErrE);
    }
  }

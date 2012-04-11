#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float a = 1000;
    int i;
    float b;
    float f_erg;
    double c =1000;
    double d =10;
    double d_erg;

    for (i=0;i<=10;i++){

    b=pow((float)10,-i);
    d=pow((double)10,-i);

    f_erg=(pow(a+b,2)-pow(a,2)-(2*a*b))/pow(b,2);
    d_erg=(pow(c+d,2)-pow(c,2)-(2*c*d))/pow(d,2);
    printf("b: %f, d: %lf\n",b,d);
    printf("float:%f\n",f_erg);
    printf("double:%lf\n\n",d_erg);

    }

}

#include <stdio.h>
#include <math.h>



void main(void){
  double x,x2=0,alpha=1,alpha2=2,alpha3,pi=3.14159265358979323846,v[6],h;
  x=1;
  while(x2!=x){
    x2=x;
    x=(x*x+2)/(2*x);
  };
  printf("Wurzel 2: %12.12e\n",x);
  while(alpha2!=alpha){
    alpha2=alpha;
    alpha=alpha-((0.5*pi/cos(alpha)+alpha-pi-tan(alpha))/(0.5*pi*tan(alpha)/cos(alpha)-tan(alpha)*tan(alpha)));
  };
  double r;
  r=sqrt(2*(1-cos(alpha)));
  printf("%12.12e\n",r);
}



#include <stdio.h>
#include <math.h>



void main(void){
  double x,x2=0,alpha=1,alpha2=2,alpha3,pi=3.14159265358979323846,v[6],h;
  x=100;
  while(x2!=x){
    x2=x;
    x=((x*x+2)/(2*x));
  };
  printf("Wurzel 2: %12.12e\n",x);
  while(alpha2!=alpha){
    alpha2=alpha;
    for(int i=1;i<=5;i++){
      h=0.1*pow(2,-i); 
      v[i]=((((pi/(2*cos(alpha+h))))+alpha+h-pi-tan(alpha+h))-((pi/(2*cos(alpha)))+alpha-pi-tan(alpha)))/h;
    }
    for(int i=1;i<=4;i++){
      v[i]=((2*v[i+1])-v[i])/1;
    };
    for(int i=1;i<=3;i++){
      v[i]=(4*v[i+1]-v[i])/3;
    };
    for(int i=1;i<=2;i++){
      v[i]=(8*v[i+1]-v[i])/7;
    };
    for(int i=1;i<=1;i++){
      v[i]=(16*v[i+1]-v[i])/15;
    };

    alpha=((pi/(2*cos(alpha)))+pi+tan(alpha))/v[1];
  };
  printf("%lf",alpha);
}



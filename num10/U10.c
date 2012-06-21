#include <stdio.h>
#include <math.h>

void main(void){
  double vt,vs,vr,w,a,b,h,errt,errs,st,ss,sr;
  vt=1;
  vs=1;
  h=0.1;
  st=0;
  ss=0;
  printf("Geschwindigkeit\n");
  printf("Trapez \t\tSimpson \tRichtig \tFehler Trap. \t Fehler Simps\n");
  for(int i=1;i<=5;i++){
    for(int j=0;j<=9;j++){
      //Trapezregel
      a=(i-1)+j*h;
      b=a+h;
      w=(b-a)/2;
      vt+=w*sin(a)+w*sin(b);
      //Simpsonregel
      vs+=(h/6)*(sin(a)+4*sin((a+b)/2)+sin(b));
      st+=w*(vt)+w*(vt);
      ss+=w*(vs)+w*(vs);
      
    }
  vr=-cos(i)+2;
  errt=fabs(fabs(vt)-fabs(vr));
  errs=fabs(fabs(vs)-fabs(vr));
  printf("%12.6e\t%12.6e\t%12.6e\t%12.6e\t%12.6e\n",vt,vs,vr,errt,errs);
  }
  printf("Strecke nach 5\n");
  printf("Trapez\t\tSimpson\t\t Richtig\n");
  printf("%12.6e\t%12.6e\t%12.6e\n",st,ss,-sin(5)+2*5);
}
    
    


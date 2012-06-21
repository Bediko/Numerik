#include <stdio.h>
#include <math.h>

/**
 * Programm zur Berechnung einer Ableitung mit möglichst kleinem Fehler
 */

int main(void){

  double v[6],h,v2[6],err; 
  printf("1. Ordnung\n");
  printf("Näherung \t richtig\t fehler\n");
  for(int i=1;i<=5;i++){
    h=0.1*pow(2,-i); 
    v[i]=(-sin(1+h)+2*(1+h)+sin(1)-2*1)/h;
    v2[i]=-cos(1)+2;
    printf("%d: %12.6e\t %12.6e\t %12.6e\n",i,v[i],v2[i],fabs(fabs(v2[i])-fabs(v[i])));
  }
  printf("2. Ordnung\n");
  printf("Näherung \t richtig\t fehler\n");
  for(int i=1;i<=4;i++){
    v[i]=((2*v[i+1])-v[i])/1;
     printf("%d: %12.6e\t %12.6e\t %12.6e\n",i,v[i],v2[i],fabs(fabs(v2[i])-fabs(v[i])));
  };
  printf("3. Ordnung\n");
  printf("Näherung \t richtig\t fehler\n");
  for(int i=1;i<=3;i++){
    v[i]=(4*v[i+1]-v[i])/3;
     printf("%d: %12.10e\t %12.10e\t %12.10e\n",i,v[i],v2[i],fabs(fabs(v2[i])-fabs(v[i])));
  };
  printf("4. Ordnung\n");
  printf("Näherung \t richtig\t fehler\n");
  for(int i=1;i<=2;i++){
    v[i]=(8*v[i+1]-v[i])/7;
     printf("%d: %12.15e\t %12.15e\t %12.15e\n",i,v[i],v2[i],fabs(fabs(v2[i])-fabs(v[i])));
  };
  printf("5. Ordnung\n");
  printf("Näherung \t richtig\t fehler\n");

  for(int i=1;i<=1;i++){
    v[i]=(16*v[i+1]-v[i])/15;
     printf("%d: %12.15e\t %12.15e\t %12.15e\n",i,v[i],v2[i],fabs(fabs(v2[i])-fabs(v[i])));
  };





  

 
}

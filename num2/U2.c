#include <math.h>
#include <stdio.h>





void main (void){
  float e_neu=1,e_alt=0;
  float x=-20;
  int i=1;
  float term=1;
  do{
    e_alt = e_neu;
    term*=x/i;
    e_neu +=term;
    i++;
  }while(e_neu != e_alt);

  printf("e^-20:\n");
  printf("Taylor:%12.6ef\n",e_neu);
  printf("%d\n",i);
  i=1;
  e_neu=1;
  do{
    e_alt=e_neu;
    term=pow((1+(x/i)),i);
    e_neu=term;
    i++;
  }while(e_neu != e_alt);
  
  printf("lim:%12.6ef\n",e_neu);
  printf("%d\n",i);
  printf("exp-funktion:%12.6elf\n\n",exp(x));
  printf("1/e^20:\n");
  x=20;
  i=1;
  term=1;
  do{
    e_alt = e_neu;
    term*=x/i;
    e_neu +=term;
    i++;
  }while(e_neu != e_alt);
  printf("%12.6ef\n",1/e_neu);
  printf("%12.6elf\n",1/exp(x));

  printf("\n\nAufgabe 3:\n");
  double erg;
  for(i=1;i<=15;i++){
    x=pow(10,-i);
    erg=1-sqrt(1-pow(x,2));
    printf("1: %12.6elf\n",erg);
    erg=(pow(x,2))/(1+sqrt(1-pow(x,2)));
    printf("2: %12.6elf\n\n",erg);
  }
}

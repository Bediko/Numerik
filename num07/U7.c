#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void){
  double y[33];


  for(int i=0;i<=32;i++){
    y[i]=cos((6*i*2*pi)/33)+0.5*sin((4*i*2*pi)/33)+(rand()%5+1)/100;
  }

#include <stdio.h>
#include <math.h>
int n,m;
void printmatrix(double matrix[n][m],double vector[m]){
  for(int i=0; i<=n-1; i++){
    for(int j=0; j<=m-1; j++){
      printf("% 12.6ef ",matrix[i][j]);
    }
    printf("% 12.6ef",vector[i]);
    printf("\n");
  }
  printf("\n");
};

void pivotsuche(double matrix[n][n],double vector[n],int k){
  double pivot,tmp;
  int j,s;
  for(; k<n-1; k++){
    pivot=fabs(matrix[k][k]);
    s=k;
    for(j=k;j<n;j++){
      if(fabs(matrix[j][k])>pivot){
        s=j;
      }
    }
    if(s!=k){
      tmp=vector[k];
      vector[k]=vector[s];
      vector[s]=tmp;
    
    for(j=0;j<n;j++){
      tmp=matrix[k][j];
      matrix[k][j]=matrix[s][j];
      matrix[s][j]=tmp;
    }
    }
  }
};
void calculatex(double matrix[n][n],double vector[n]){
  double x[n], erg;

  for (int i=n-1;i>=0;i--){
    erg=vector[i];
    for(int j=n-1;j>=0;j--){
      if(i!=j)
        erg-=matrix[i][j]*x[j];
    };
  x[i]=erg/matrix[i][i];
  };
  for(int i=0;i<=n-1;i++)
    printf("% 12.6ef\n",x[i]);

  printf("\n");
};

void gauss(double matrix[n][n], double vector[n]){
  double l[n][n];
  for(int k=0; k<n-1; k++){
    pivotsuche(matrix,vector,k);
    for(int i=k+1; i<n; i++)
      l[i][k] = matrix[i][k]/matrix[k][k];
    for(int i=k+1; i<n; i++){
      for(int j=k; j<n; j++)
        matrix[i][j] = matrix[i][j] - l[i][k]*matrix[k][j];
      vector[i]= vector[i] - l[i][k]*vector[k];
    }
  }   
};



int main(void){
  double ma[6][3],mt[3][6],y[6],mm[3][3]={0},x[6],y2[3]={0};

  for(int i=0,j=2048;i<=5;i++,j*=2){
    x[i]=j;
  }
  
  y[0]=6.8820e+00 ;
  y[1]= 2.9064e+01 ;
  y[2]=1.1578e+02;
  y[3]=4.6309e+02;
  y[4]=1.8731e+03 ;
  y[5]=8.2617e+03 ;


  
  for(int i=0;i<6;i++){
    ma[i][0]=1;
    ma[i][1]=log(x[i]);
    ma[i][2]=x[i];
  }
   
  for(int i=0;i<6;i++){
    for(int j=0;j<3;j++){
      mt[j][i]=ma[i][j];
    }
  }
  n=6;
  m=3;
  printf("Ursprungsmatrix\n");
  printmatrix(ma,y);
  n=3;
  m=6;
  printf("Transponiert\n");
  printmatrix(mt,y);

  double sum;
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      mm[i][j]=0;
      for(int k=0;k<6;k++){
        mm[i][j]+=mt[i][k]*ma[k][j];
      }
    }
  }

  for(int i=0;i<3;i++){
      y2[i]=0;
      for(int k=0; k<6;k++){
        y2[i]+=mt[i][k]*y[k];
      }
    
  }
      
  n=3;
  m=3;
  
  printf("Multipliziert\n");
  printmatrix(mm,y2);
  printf("gauss\n");
  gauss(mm,y2);
  printmatrix(mm,y2);
  calculatex(mm,y2);
}
    
  

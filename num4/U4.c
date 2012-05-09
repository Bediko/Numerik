#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int n=4;

void initialize(double matrix[n][n],double vector[n]){
  for(int i=0; i<=n-1; i++){
    for(int j=0; j<=n-1; j++){
      matrix[i][j]=rand()%5;
    }
    vector[i]=rand()%5;
    printf("%1.0f\n",vector[i]);
  }
  printf("\n");
};

void pivotsuche(double matrix[n][n],double vector[n]){
  double pivot,tmp;
  int j,s;
  for(int k=0; k<n-1; k++){
    pivot=fabs(matrix[k][k]);
    s=k;
    for(j=k;j<n-1;j++){
      if(fabs(matrix[j][k])>pivot){
        s=j;
      }
    }
    if(s!=k){
      tmp=vector[k];
      vector[k]=vector[s];
      vector[s]=tmp;
    
    for(j=0;j<n-1;j++){
      tmp=matrix[k][j];
      matrix[k][j]=matrix[s][j];
      matrix[s][j]=tmp;
    }
    }
  }
}


void gauss(double matrix[n][n], double vector[n]){
  double l[n][n];
  pivotsuche(matrix,vector);
  for(int k=0; k<n-1; k++){
    for(int i=k+1; i<n; i++)
      l[i][k] = matrix[i][k]/matrix[k][k];
    for(int i=k+1; i<n; i++){
      for(int j=k; j<n; j++)
        matrix[i][j] = matrix[i][j] - l[i][k]*matrix[k][j];
      vector[i]= vector[i] - l[i][k]*vector[k];
    }
  }   
};



void printmatrix(double matrix[n][n],double vector[n]){
  for(int i=0; i<=n-1; i++){
    for(int j=0; j<=n-1; j++){
      printf("% 3.6f ",matrix[i][j]);
    }
    printf("% 3.6f",vector[i]);
    printf("\n");
  }
  printf("\n");
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
    printf("% 2.6f\n",x[i]);
}


int main(){

double matrix[n][n], vector[n];
   
srand(time(NULL));

initialize(matrix,vector);
printmatrix(matrix,vector);
gauss(matrix,vector);
printmatrix(matrix,vector);
calculatex(matrix,vector);

return 0;
}

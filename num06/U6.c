#include <stdio.h>
#include <math.h>
int n=9;

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
void printmatrix(double matrix[n][n],double vector[n]){
  for(int i=0; i<=n-1; i++){
    for(int j=0; j<=n-1; j++){
      printf("% 12.6ef ",matrix[i][j]);
    }
    printf("% 12.6ef",vector[i]);
    printf("\n");
  }
  printf("\n");
};


int main(){
  double matrix[n][n],matrix2[n][n], vector[n],vector2[n];
  
  
  for(int j=0;j<n;j++){
      matrix[0][j]=pow(-2,j);
      matrix[1][j]=pow(-1.5,j);
      matrix[2][j]=pow(-1,j);
      matrix[3][j]=pow(-0.5,j);
      matrix[4][j]=pow(0,j);
      matrix[5][j]=pow(0.5,j);
      matrix[6][j]=pow(1,j);
      matrix[7][j]=pow(1.5,j);
      matrix[8][j]=pow(2,j);
      matrix2[0][j]=pow(-4,j);
      matrix2[1][j]=pow(-3,j);
      matrix2[2][j]=pow(-2,j);
      matrix2[3][j]=pow(-1,j);
      matrix2[4][j]=pow(0,j);
      matrix2[5][j]=pow(1,j);
      matrix2[6][j]=pow(2,j);
      matrix2[7][j]=pow(3,j);
      matrix2[8][j]=pow(4,j);


  }

  
  vector[0]=exp(-(-2*-2));
  vector[1]=exp(-(-1.5*-1.5)); 
  vector[2]=exp(-(-1*-1));
  vector[3]=exp(-(-0.5*-0.5));
  vector[4]=exp(-0);
  vector[5]=exp(-(0.5*0.5));
  vector[6]=exp(-(1*1));
  vector[7]=exp(-(1.5*1.5));
  vector[8]=exp(-(2*2));
  vector2[0]=exp(-(-4*-4));
  vector2[1]=exp(-(-3*-3));
  vector2[2]=exp(-(-2*-2));
  vector2[3]=exp(-(-1*-1));
  vector2[4]=exp(-0);
  vector2[5]=exp(-(1*1));
  vector2[6]=exp(-(2*2));
  vector2[7]=exp(-(3*3));
  vector2[8]=exp(-(4*4));


  
  gauss(matrix,vector);
  calculatex(matrix,vector);
  gauss(matrix2,vector2);
  calculatex(matrix2,vector2);



  return 0;
}

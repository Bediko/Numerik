#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int N = 8;

void initialise(double matrix[N][N]){
	srand(123456);
	for (int j=0; j<=N-1; j++){
		for(int i=0; i<=N-1;i++){
			if(i==j){
				matrix[j][i] = rand() % 8 + 1;
			}
			else{
				matrix[j][i] = rand() % 9;
				matrix[j][i] /= N;
			}
		}
	}
}

void residium(double matrix[N][N],double b[N],double x[N]){

}

void jacobi(double a[N][N], double x[N], double b[N],int* iter){
	double xold[N],sum,r[N],rsum,xsum,res;
	for(int i=0;i<=N-1;i++)
		xold[i]=1;
	do{
		for(int j=0;j<=N-1;j++){
			sum=0;
			for(int k=0;k<=N-1;k++){
				if(k != j){
					sum+=a[j][k]*xold[k];
				}
			}
			x[j]=(b[j]-sum)/a[j][j];
		}

		for(int i=0;i<=N-1;i++)
			xold[i] = x[i];

		for(int j=0;j<=N-1;j++){
			sum=0;
			for(int k=0;k<=N-1;k++){
					sum+=a[j][k]*x[k];
			}
			r[j]=(b[j]-sum)/a[j][j];
		}

		rsum=0;
		for(int i=0;i<=N-1;i++){
			rsum+=r[i]*r[i];
		}
		xsum=0;
		for(int i=0;i<=N-1;i++){
			xsum+=x[i]*x[i];
		}
		res=rsum/xsum;
		printf("%12.6e\n",res);


		*iter+=1;
	}while(res>=pow(10,-16));

}

void printMatrix(double matrix[N][N]){
	for (int j=0; j<=N-1; j++){
		for(int i=0; i<=N-1;i++){
			printf("%12.6e ",matrix[j][i]);
		}
		printf("\n");
	} 
}

void printVector(double vector[N]){
	for(int i = 0; i<= N-1;i++){
		printf("%12.6e\n",vector[i]);
	}
}

int main (void){
	double matrix[N][N],b[N], x[N];
	int iter=0;
	for(int i=0; i<=N;i++){
		b[i] = rand() % N;
	}

	initialise(matrix);

	printf("\n");
	printf("Ursprungsmatrix:\n");
	printMatrix(matrix);
	printf("\n\n");
	printf("b:\n");
	printVector(b);
	printf("\n\n");
	jacobi(matrix,x,b,&iter);
	printf("x:\n");
	printVector(x);
	printf("\n\n");
	printf("Iterationen: %d\n",iter);
	return 0;
}
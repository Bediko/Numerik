#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int N = 4;

void initialise(double matrix[N][N],double b[N],double x[N]){
	double sum;
	for (int j=0; j<=N-1; j++){
		sum=0;
		for(int i=0; i<=N-1;i++){
			matrix[j][i] = 1.0/((i+1.0)+j);
			sum+=matrix[j][i];
		}
		b[j]=sum;
		x[j]=0.0;
	}
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

double residium(double A[N][N], double b[N],double x[N]){
	double sum=0,rsum=0,xsum=0,r[N],res,Ax[N];
	for(int i=0;i<N;i++){
			Ax[i]=0.0;
			for (int j=0;j<N;j++){
				Ax[i]+=A[i][j]*x[j];
			}
			r[i]=b[i]-Ax[i];
		}

		rsum=0.0;
		for(int i=0;i<N;i++){
			rsum+=r[i]*r[i];
		}
		xsum=0.0;
		for(int i=0;i<N;i++){
			xsum+=x[i]*x[i];
		}
		res=rsum/xsum;
		printf("%12.6e\n",res);
		return res;
}

void cg(double A[N][N], double b[N], double x[N]){
	double xold[N],pold[N],rold[N],tmp,tmp2,Ap[N],a,r[N],B,p[N];
	for(int i=0;i<N;i++){
		tmp=0.0;
		for(int j=0;j<N;j++){
			tmp+=A[i][j]*x[j];
		}
		xold[i]=x[i];
		pold[i]=b[i]-tmp;
		rold[i]=pold[i];
	}
	do{
		for(int i=0;i<N;i++){
			Ap[i]=0.0;
			for (int j=0;j<N;j++){
				Ap[i]+=A[i][j]*pold[j];
			}
		}
		tmp=0.0;
		tmp2=0.0;
		for(int i=0;i<N;i++){
			tmp+=fabs(rold[i]*rold[i]);
			tmp2+=Ap[i]*pold[i];
		}
		a=tmp/tmp2;

		for(int i=0;i<N;i++){
			x[i]=xold[i]+a*pold[i];
		}
		for (int i=0;i<N;i++){
			r[i]=rold[i]-a*Ap[i];
		}
		tmp=0.0;
		tmp2=0.0;
		for(int i=0;i<N;i++){
			tmp+=fabs(r[i]*r[i]);
			tmp2+=fabs(rold[i]*rold[i]);
		}
		B=tmp/tmp2;

		for (int i=0;i<N;i++){
			p[i]=r[i]+B*pold[i];
		}
		printf("x:\n");
		for (int i=0;i<N;i++){
			xold[i]=x[i];
			pold[i]=p[i];
			rold[i]=r[i];
			printf("%lf\n",x[i]);
		}
		printf("--------------------------------\n");
	
	}while(residium(A,b,x)>=pow(10,-16));
		
}

void main(void){
	double matrix[N][N],b[N], x[N];
	initialise(matrix,b,x);
	printf("\n\n");
	printf("A:\n");
	printMatrix(matrix);
	printf("\n\nb:\n");
	printVector(b);
	printf("\n\n");
	cg(matrix,b,x);
	printf("\n\nx:\n");
	printVector(x);
}
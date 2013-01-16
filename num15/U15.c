#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


//3 iterationen: 260 240 0

int M=2;
int N=3;

void initialise(double matrix[M+1][N+M],double x[N+M],double c[N], double b[N],double q[N]){
	
	c[0] = 25.0;
	c[1] = 40.0;
	c[2] = 50.0;

	b[0] = 0.0;
	b[1] = 600.0;
	b[2] = 900.0;
	
	for(int i=0;i<M+N;i++){
		if(i<M)
			x[i]=0;
		else
			x[i]=b[i-M];
	}

	for (int i=0;i<N;i++){
		q[i]=0.0;
	}

	matrix[0][0] = -c[0];
	matrix[0][1] = -c[1];
	matrix[0][2] = -c[2];
	matrix[0][3] = 0.0;
	matrix[0][4] = 0.0;

	matrix[1][0] = 0.0;
	matrix[1][1] = 1.0/3.0;
	matrix[1][2] = 3.0/4.0;
	matrix[1][3] = 1.0;
	matrix[1][4] = 0.0;

	matrix[2][0] = 1.0;
	matrix[2][1] = 2.0/3.0;
	matrix[2][2] = 1.0/4.0;
	matrix[2][3] = 0.0;
	matrix[2][4] = 1.0;	
}

void tableau(double matrix[M+1][N+M],double x[N+M],double c[N], double b[N],double q[N]){
	printf("\t\t|\t\t| %6.6lf \t%6.6lf \t%6.6lf\t | %6.6lf \t%6.6lf\t| \t |\n",c[0],c[1],c[2],0.0,0.0);
	printf("\tZeile\t|\tBV\t|\tM1\t \tM2\t \tM3\t | \tR1\t \t\tR2\t|   \trechts\t         | Quotient\n");
	for(int i=0; i<M+1;i++){
		printf("\t%i\t|\t\t|%6.6lf \t%6.6lf \t%6.6lf\t | %6.6lf \t%6.6lf\t| \t%6.6lf\t |\t%6.6lf\t\n",i,matrix[i][0],matrix[i][1],matrix[i][2],matrix[i][3],matrix[i][4],b[i],q[i]);
	}
	printf("\n\n");

}

void simplex(double matrix[M+1][N+M],double x[N+M],double c[N], double b[N], double q[N]){
	int ps=0,pz=0, redo=0;
	double max=0.0,pe=0.0;
	do{
		redo=0;
		//pivotspalte
		for (int i=0;i<(N+M);i++){
			if(max < fabs(matrix[0][i])){
				max = fabs(matrix[0][i]);
				ps = i;
			}
		}
		//Quotientenvektor
		for (int i=1;i<N;i++){
			if(matrix[i][ps]!=0)
				q[i]=b[i]/matrix[i][ps];
		}
		tableau(matrix,x,c,b,q);
		//Pivotzeile
		double min=1000000;
		for(int i=0;i<M+1;i++){
			if(q[i] > 0.0){
				if(min > q[i]){
					printf("%lf\n",q[i]);
					min=q[i];
					pz=i;
				}
			} 
		}
		//Pivotelement
		pe=matrix[pz][ps];
		printf("pivotzeile:%d Pivotspalte:%d Pivotelement:%lf\n",pz,ps,pe);
		//Pivotzeile durch Pivotelement(Normierung)
		for(int i=0; i<N+M;i++){
			matrix[pz][i]=matrix[pz][i]/pe;
		}
		b[pz]=b[pz]/pe;


		//Berechnung der anderen Zeilen
		double quot;
		for(int i=0;i<M+1;i++){
			if(i==pz)
				continue;
			quot=matrix[i][ps];

			for(int j=0;j<N+M;j++){
				matrix[i][j]=matrix[i][j]-matrix[pz][j]*quot;
			}
			b[i]=b[i]-b[i]*quot;
		}
		tableau(matrix,x,c,b,q);
		

		for(int i=0;i<N+M;i++){
			if(matrix[0][i] <0)
				redo=1;
		}
	}while(redo);
}

void main(void){
	double matrix[M+1][N+M],x[N+M],c[N],b[N],q[N];
	initialise(matrix,x,c,b,q);
	tableau(matrix,x,c,b,q);
	simplex(matrix,x,c,b,q);
}
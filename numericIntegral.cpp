#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 100

void imprimirVector(int vector[MAX], int tamano){
	for(int i=0; i<tamano; i++){
		printf("%i", vector[i]);
	}
}

void imprimirPolinomio(int vector[MAX], int tamano, int tamanoGrados){
	for(int i=0; i<tamano; i++){
		printf("%ix^%i", vector[i], tamanoGrados--);
	}
	printf("%i", vector[tamano]);
}

int calcularfdeX(float fx, int coeficientes[MAX], int tamanoGrados, int grado){
	float calculo = 0;
	
	for(int i=0; i<tamanoGrados+1; i++){
		calculo += pow(fx, grado--) * coeficientes[i];
	}
	
	//printf("f de %f es %f", fx, calculo);
	return calculo;
}

int main(void){
	
	int coeficientes[MAX], signos[MAX];
	int tamanoGrados, conteoGrados, conteoCoeficientes, grado;
	char signo;
	int n;
	float deltax, limiteA, limiteB, calculo;
	
	printf("Ingrese el numero de grados del polinomio: ");
	scanf("%i", &tamanoGrados);
	conteoGrados = tamanoGrados;
	grado = tamanoGrados;
	
	
	for(int i=0; i<=tamanoGrados; i++){
		printf("Ingrese el coeficiente del grado con signo incluido %i: ",conteoGrados--);
		scanf("%i", &coeficientes[i]);
	}
	
	
	//imprimirPolinomio(coeficientes, tamanoGrados, tamanoGrados);
	
	//Pidiendo limites de integracion
	

	printf("Ingrese el limite de integracion A: ");
	scanf("%f", &limiteA);
	printf("Ingrese el limite de integracion B: ");
	scanf("%f", &limiteB);
	
	
	n = 9000;	
	
	deltax = (limiteB-limiteA) / n;
	printf("Deltax = %f", deltax);
	
	//Integrando

	while(limiteA <= limiteB){
		limiteA += deltax;
		calculo += calcularfdeX(limiteA, coeficientes, tamanoGrados, tamanoGrados) * deltax;
	}
	printf("\n%.2f", calculo);
	
	
	
}


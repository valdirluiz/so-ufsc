#include <stdio.h>
#include <stdlib.h>
#include <math.h>

 
#define true 1
#define false 0



int numeroEhPrimo(int numero){
	int raiz = ceil(sqrt(numero));
	for (int i = 3; i <= raiz; i++) {
    	if (numero % i == 0) { 
     		return false;
    	}
  	}
	return true;
}

int calculaDivisores(int numero){
	int teste = 1;
	int result = 0;
	while(teste<=numero){
		if(numero % teste == 0){
			result = result+teste;
		}
		teste = teste+1;
	}
  return result;
}

int  somaDivisoresOtimizado(int numero)
{
	int resultado;
  if(numero%2==0 && numero!=2){
    resultado = calculaDivisores(numero);
  } else if(numeroEhPrimo(numero)){
 		resultado = numero+1;
 	} else{
 		resultado = calculaDivisores(numero);
 	}
 	return resultado;
}

int main(int argc, const char *argv[])
{


    int min = atoi(argv[1]);
    int max = atoi(argv[2]);
    int tamanhoBuffer = max-min+1;


    float buffer[2][tamanhoBuffer];


    int count = 0;

    while (count<tamanhoBuffer) {
      buffer[0][count] = min;

      int dividendo = somaDivisoresOtimizado(min);
      
       
      float resultado = (float) dividendo/min;
      buffer[1][count] = resultado;
      printf("%f\n", resultado);
      
      count=count+1;
      min=min+1;
    }

    //TODO: imprimi





		return 0;
}

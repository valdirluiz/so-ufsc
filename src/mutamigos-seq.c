#include <stdio.h>
#include <stdlib.h>



int  somaDivisores(int numero, int teste)
{
  int result = 0;
	while(teste<=numero){
		if(numero % teste == 0){
			result = result+teste;
		}
		teste = teste+1;
	}
  return result;

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

      int dividendo = somaDivisores(min, 1);
      float resultado = (float) dividendo/min;
      buffer[1][count] = resultado;
      //TODO: popular tabela
      printf("%f\n", resultado);
      count=count+1;
      min=min+1;
    }

    //TODO: imprimi





		return 0;
}

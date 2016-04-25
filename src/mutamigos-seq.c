#include <stdio.h>
#include <stdlib.h>

 

void  somaDivisores(int numero, int teste, int *result)
{
	while(teste<=numero){
		if(numero % teste == 0){
			*result = *result+teste;
		}
		teste = teste+1;
	}
	 
}

int main(int argc, const char *argv[])
{
		int resultado;
		int min = atoi(argv[1]);
        int max = atoi(argv[2]);
        int tamanhoBuffer = max-min+1;


        //TODO: criar funcao para poular buffer com os numeros que precisa ser somados os divisores
        int buffer[tamanhoBuffer][2];
        int colunaNoBuffer = 0;
        while(min<=max){
        	buffer[0][colunaNoBuffer] = min;
        	printf("%d\n", buffer[0][colunaNoBuffer]);
        	min=min+1;
        	colunaNoBuffer=colunaNoBuffer+1;
        }

        //TODO: percorrer buffer e calcular divisores, pode ser em paralelo

        //TODO: verificar numeros no buffer que tem a linha 1 igual e imprimir




 
		return 0;
}
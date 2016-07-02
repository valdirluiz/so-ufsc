#include <stdio.h>
#include <string.h>

FILE *file;
FILE *file_exportacao;
char *file_name;

typedef struct
{
  unsigned int id;
  char nome [256];
  char sexo;
  float salario;

} funcionario_t;


void create_file(){

	file = fopen (file_name, "rb");

	int file_exists;
	if (file==NULL){
 		file_exists=0;
	} else {
		file_exists=1;
		fclose(file);
	}

	if(file_exists==1){
	   file=fopen(file_name,"r+b");
	} else{
	  file=fopen(file_name,"w+b");
	}

	fclose(file);

}

int existe_id(int id){
  file=fopen(file_name,"rb");
  funcionario_t funcionario;
  int existe = 0;
  while(!feof(file)){
    fread(&funcionario,sizeof(funcionario),1,file);
    if(funcionario.id == id){
      existe = 1;
      break;
    }
  }
  return existe;
}

void salvar_funcionario(){
  funcionario_t funcionario;
	printf("Id: ");
  scanf("%i", &funcionario.id);

  if(funcionario.id <= 0){
      printf("Id precisa ser maior que zero.");
      return;
  }

  if(existe_id(funcionario.id) == 1){
      printf("Id %i já esta cadastro no banco de dados.", funcionario.id);
      return;
  }

	printf("Nome: ");
	scanf("%s", funcionario.nome);
	printf("Sexo: ");
	scanf("%s", &funcionario.sexo);
	printf("Salário: ");
	scanf("%f", &funcionario.salario);

	  file = fopen (file_name, "ab");
    fwrite(&funcionario, sizeof(funcionario_t), 1, file);
    fclose(file);
}



void exportar(){

	file=fopen(file_name,"rb");

	printf("Informe o nome do arquivo de exportação: ");
	char file_name_exportacao[200];
  scanf("%s", file_name_exportacao);

	file_exportacao = fopen (file_name_exportacao, "w+a");

	funcionario_t funcionario;

	while(!feof(file)){
		fread(&funcionario,sizeof(funcionario),1,file);
		if(feof(file)) break;
		char buffer[512];
		snprintf(buffer, sizeof(buffer), "Id:%i | Nome:%s | Sexo:%c | Salário:%f \n", funcionario.id, funcionario.nome, funcionario.sexo, funcionario.salario);
		fputs(buffer, file_exportacao);
	}

	fclose(file);
	fclose(file_exportacao);
}

void media() {

  char sexo;
  printf("Informe o sexo: ");
  scanf("%s", &sexo);

  file=fopen(file_name,"rb");
  funcionario_t funcionario;
  int quantidade_funcionarios = 0;
  float montante_salario;

  while(!feof(file)){
    fread(&funcionario,sizeof(funcionario),1,file);
	  if(feof(file)) {
      break;
    }
    if(funcionario.sexo == sexo){
      quantidade_funcionarios++;
      montante_salario+=funcionario.salario;
    }
  }

  if(quantidade_funcionarios>0){
      printf("Média do salário: %f \n", montante_salario/quantidade_funcionarios);
  } else{
      printf("Não foram encontrados funcionários com esse sexo. \n");
  }

  fclose(file);
}

void remover_funcionario(){
  int id;
  printf("Informe o id que deseja remover: ");
  scanf("%d", &id);

    funcionario_t funcionario;
    file = fopen (file_name, "r+b");
    while(!feof(file)){
      fread(&funcionario,sizeof(funcionario),1,file);
      if(funcionario.id == id){
        fseek (file, (sizeof(funcionario)) * -1, SEEK_CUR);
        funcionario.id = 0;
        printf("Funcionário removido \n");
        fwrite(&funcionario, sizeof(funcionario), 1, file);
        fclose(file);
        return;
      }
    }
    printf("Funcionário não encontrado. \n");
}

void compactar(){

  //file=fopen(file_name+"TMP","w+b");

}


int main(int argc, char **argv)
{

	file_name = argv[1];

    create_file();

	int continua = 1;
	int opcao = 0 ;

	do{

	  	printf("Selecione uma opção: \n");
		  printf("1 - Inserir funcionário \n");
    	printf("2 - Remover funcionário \n");
    	printf("3 - Calcular média por sexo \n");
    	printf("4 - Exportar para arquivo texto \n");
    	printf("5 - Compactar base \n");
    	printf("6 - Sair \n");
	  	scanf("%i", &opcao);

        if(opcao!=6)
	    	switch( opcao ) {
    			case 1:
                salvar_funcionario();
                break;
    			case 2:
             		remover_funcionario();
                break;
          case 3:
               	media();
                break;
          case 4:
               	exportar();
                break;
	        case 5:
               	compactar();
                break;
          default:
                printf("Digite um comando válido \n");
           }
	} while(opcao!=6);


}

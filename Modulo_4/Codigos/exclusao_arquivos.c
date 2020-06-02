#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char*argv[]){
	FILE *arq;
	double tempo = 0;
	int exe = 10, size = 0;
	time_t t_ini, t_fim;
	
	// criação de arquivo
	char path[100] = "../Arquivos/exclusao/arquivo_size_";
	strcat(path, argv[1]);
	strcat(path, ".txt");
	
	// percorre as execuções
	for(int i = 0; i < exe; i++){
		// abrindo arquivo
		arq = fopen(path, "w");
		if (arq == NULL){
			printf("Problemas na CRIACAO do arquivo\n");
			return 0;
		}
		
		if(strcmp(argv[1], "5kb") == 0)
			size = 500;
		else if(strcmp(argv[1], "10kb") == 0)
			size = 1000;
		else if(strcmp(argv[1], "100kb") == 0)
			size = 10000;
		else if(strcmp(argv[1], "1mb") == 0)
			size = 100000;
		else if(strcmp(argv[1], "10mb") == 0)
			size = 1000000;
		else if(strcmp(argv[1], "100mb") == 0)
			size = 10000000;
		else if(strcmp(argv[1], "500mb") == 0)
			size = 50000000;
		
		// insere dados no arquivo
		for(int j=0; j < size; j++){
			char str[11] = "";
			strcat(str,"execucao-");
			strcat(str,"\n");
			fputs(str, arq);
		}

		
	  	// fechando arquivo
	  	fclose(arq);
	  	
		// tempo inicial para cada execucao
		t_ini = time(NULL);
		
  		// remove arquivo
		remove(path);
		
		// tempo final para cada execucao
		t_fim = time(NULL);
		
		// verifica a diferenca do tempo inicial com o final 
		// e soma em uma variavel que armazena todos os resultaos
		tempo += difftime(t_fim, t_ini);
  	}
		
	
	// calcula a media dos tempo
	tempo /= exe;

	// mostra o tempo médio final
	printf("Tempo: %f\n",tempo);
	

	return 0;
}

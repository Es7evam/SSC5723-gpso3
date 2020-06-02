#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char*argv[]){
	FILE *arq;
	char *result;
	double tempo = 0;
	int exe = 10;
	time_t t_ini, t_fim;		
	char linha[11];
	
	// criação do nome arquivo
	char path[100] = "../Arquivos/arquivo_size_";
	strcat(path, argv[1]);
	strcat(path, ".txt");
	
	// percorre as execuções
	for(int i = 0; i < exe; i++){
		// tempo inicial para cada execucao
		t_ini = time(NULL);
		
		// abrindo arquivo
		arq = fopen(path, "r");
		if (arq == NULL){
			printf("Problemas na abetura do arquivo\n");
			return 0;
		}  
		
		// leitura dos dados no arquivo
		int j = 1;
		while(!feof(arq)){
			// Lê uma linha (inclusive com o '\n')
      			result = fgets(linha, 11, arq);
			if (result)  // Se foi possível ler
	  			printf("Linha: %d : %s",j, linha);
	  		j++;
		}
	
	  	// fechando arquivo
	  	fclose(arq);
		
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

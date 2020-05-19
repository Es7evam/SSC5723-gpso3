#include <iostream> 
#include <list>
#include <cstring>

using namespace std;

list<string> paginas;
list<string>::iterator it;
int leitura = 0, escrita = 0, op = 0, faltaPagina = 0;

bool leituraPagina(char* value);
void algoritmoLRU(char* value);
	
int main(int argc, char **argv){
	// definição do arquivo a ser lido
	FILE *arquivo;
	char *caminhoArquivo = argv[1];
	int qtdLinha = 20, qtdValue = 14;
	char linha[qtdLinha];
	int tamPagina = 4096, tamMV = 65536, tamMF = 32768;
	int qtdPagina = tamMF / tamPagina;
	
	// abre o arquivo para leitura
	arquivo = fopen(caminhoArquivo, "r");
	
	// percorre o arquivo
	while(fgets(linha, qtdLinha, arquivo) != NULL){
		op++;
		// endereco 
		char value[qtdValue];
		strncpy(value, linha+5,qtdValue);
		// numero processo
		char p[2];
		strncpy(p, linha,2);
		
		// verifica no arquivo um processo novo
		if (linha[3]  == 'C'){
			// falta criar o processo
			
		// indica a instrução a ser executada pela CPU
		}else if (linha[3]  == 'P'){
			// ocorre algo 
		
		// indica a instrução de I/O
		}else if (linha[3]  == 'I'){
			// ocorre algo
		
		// verifica no arquivo se a opcao eh de escrita
		}else if (linha[3]  == 'W'){
			
			if (paginas.size() <= qtdPagina) 
				paginas.push_back(value);
			else{
				algoritmoLRU(value);
				faltaPagina++;
			}
			escrita++;
			
		// verifica no arquivo se a opcao eh de leitura
		}else if (linha[3] == 'R'){
			// verifica se endereco ja existe
			if (leituraPagina(value)){
				cout << "igual"<<endl;
			}else{
				paginas.push_back(value);
			}
			
			leitura++;
		}
	}
	
	// fecha o arquivo 
	fclose(arquivo);
	
	// mostra no terminal algumas informacoes referentes ao simulador
	cout << "\nSimulador Memoria Virtual" << endl;
	cout << "Quantidade total de operações: " << op << endl;
	cout << "Quantidade de escrita: " << escrita << endl;
	cout << "Quantidade de leitura: " << leitura << endl;
	cout << "Quantidade de falta de pagina: " << faltaPagina << endl;
	
	return 0;
}

bool leituraPagina(char* value){
	for(it = paginas.begin(); it != paginas.end(); it++){
		if(*it == value)
			return true;
	}

	return false;
}

void algoritmoLRU(char* value){
	paginas.pop_front();
	paginas.push_back(value);
}

#include "simulador.h"

bool leituraPagina(int value){
	for(auto it : paginas){
		if(it == value){
			return true;
		}
	}

	return false;
}

void algoritmoLRU(int value){
	paginas.pop_front();
	paginas.push_back(value);
}

int main(int argc, char **argv){
	// definição do arquivo a ser lido
	FILE *arquivo;
	char *caminhoArquivo = argv[1];
	int qtdLinha = 20, qtdValue = 14;
	//char linha[qtdLinha];
	int tamPagina = 4096, tamMV = 65536, tamMF = 32768;
	int qtdPagina = tamMF / tamPagina;
	
	// abre o arquivo para leitura
	
	freopen(caminhoArquivo, "r", stdin);
	// percorre o arquivo
	string linha;
	while(getline(cin, linha)){
		stringstream ss(linha);
		string processo, comando;
		ss >> processo >> comando;
		if(comando == "C"){
			int tamanhoProcesso;
			ss >> tamanhoProcesso;
		}
		else{
			long long operacao;
			cout << "Linha: " << linha;
			for(int i=0;i<linha.size();i++){
				if(linha[i] == '(' || linha[i] == ')'){
					linha[i] = ' ';
				} 
			}
			ss >> operacao;
			cout << " : " << operacao << endl;
			if(comando == "P"){

			}
			else if(comando == "I"){

			}
			else if(comando == "W"){
				if (paginas.size() <= qtdPagina) 
					paginas.push_back(operacao);
				else{
					algoritmoLRU(operacao);
					faltaPagina++;
				}
				escrita++;
				
			}else if(comando == "R"){
			// verifica no arquivo se a opcao eh de leitura
				// verifica se endereco ja existe
				if (leituraPagina(operacao)){
					cout << "igual"<<endl;
				}else{
					paginas.push_back(operacao);
				}
				
				leitura++;
			}
		}
	
	}
	
	// fecha o arquivo 
	
	// mostra no terminal algumas informacoes referentes ao simulador
	cout << "\nSimulador Memoria Virtual" << endl;
	cout << "Quantidade total de operações: " << op << endl;
	cout << "Quantidade de escrita: " << escrita << endl;
	cout << "Quantidade de leitura: " << leitura << endl;
	cout << "Quantidade de falta de pagina: " << faltaPagina << endl;
	
	return 0;
}
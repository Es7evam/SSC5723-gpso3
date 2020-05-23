#include "simulador.h"
#include "ManipulaMemoria.hh"

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
	
	Config *config = new Config();
	ManipulaMemoria *memoria = new ManipulaMemoria(*config);

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
			long long endereco;
			string opString;
			cout << "Linha: " << linha;
			for(int i=0;i<linha.size();i++){
				if(linha[i] == '(' || linha[i] == ')'){
					linha[i] = ' ';
				} 
			}
			ss >> opString;
			endereco = strtoull(opString.c_str(), NULL, 2);
			cout << " : " << endereco << endl;
			if(comando == "P"){

			}
			else if(comando == "I"){
				cout << "\nOp. I/O: Processo " << processo << " : Disp.: " << endereco << endl; 

			}
			else if(comando == "W"){
				cout << "\nOp. Escrita: Processo " << processo << " :End.: " << endereco << endl; 
				int pagIdx = memoria->addrToFrame(endereco);
				pair<string, int> virtMemFrame = make_pair(processo, pagIdx);
				
				memoria->insereVirtual(virtMemFrame);
				/*
				// Ignorar 
				if (paginas.size() <= qtdPagina) 
					paginas.push_back(endereco);
				else{
					algoritmoLRU(endereco);
					faltaPagina++;
				}
				escrita++;
				*/
				
			}else if(comando == "R"){
				cout << "\nOp. Leitura: Processo " << processo << " :End.: " << endereco << endl; 
				int pagIdx = memoria->addrToFrame(endereco);
				pair<string, int> virtMemFrame = make_pair(processo, pagIdx);
				
				memoria->insereVirtual(virtMemFrame);

			// verifica no arquivo se a opcao eh de leitura
				// verifica se endereco ja existe

				/*
				if (leituraPagina(endereco)){
					cout << "igual"<<endl;
				}else{
					paginas.push_back(endereco);
				}
				
				leitura++;
				*/
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
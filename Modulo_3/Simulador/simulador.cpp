#include "simulador.h"
#include "ManipulaMemoria.hh"


int main(int argc, char **argv){
	// definição do arquivo a ser lido
	char *caminhoArquivo = argv[1];
	
	Config *config = new Config();
	ManipulaMemoria *memoria = new ManipulaMemoria(*config);

	// abre o arquivo para leitura
	freopen(caminhoArquivo, "r", stdin);
	// percorre o arquivo
	string linha;
	while(getline(cin, linha)){
		op++;
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
			for(int i=0;i<linha.size();i++){
				if(linha[i] == '(' || linha[i] == ')'){
					linha[i] = ' ';
				} 
			}
			ss >> opString;
			endereco = strtoull(opString.c_str(), NULL, 2);

			// Checagem linha/endereco lidos
			#ifdef DEBUG
				cout << "Linha: " << linha;
				cout << " : " << endereco << endl;
			#endif

			if(comando == "P"){

			}
			else if(comando == "I"){
				cout << "Op. I/O: Processo " << processo << " : Disp.: " << endereco << endl; 

			}
			else if(comando == "W"){
				cout << "Op. Escrita: Processo " << processo << " :End.: " << endereco << endl; 
				escrita++;

				// Converte endereço para página
				int pagIdx = memoria->addrToFrame(endereco);
				pair<string, int> virtMemFrame = make_pair(processo, pagIdx);

				
				memoria->acessaVirtual(virtMemFrame);
			}else if(comando == "R"){
				cout << "Op. Leitura: Processo " << processo << " :End.: " << endereco << endl; 
				leitura++;
				int pagIdx = memoria->addrToFrame(endereco);
				pair<string, int> virtMemFrame = make_pair(processo, pagIdx);
				
				memoria->acessaVirtual(virtMemFrame);
			}
		}
		cout << endl;	
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
#include <iostream> 
#include <list>
#include <string>
#include <sstream>
#include <vector>
#include <deque>

using namespace std;

deque<int> paginas;
int leitura = 0, escrita = 0, op = 0, faltaPagina = 0;

bool leituraPagina(int value);
void algoritmoLRU(int value);
	


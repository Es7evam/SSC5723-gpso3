#include "Config.hh"

Config::Config(){
    pageSize = 64; // tamanho página/quadro
    tamanhoEndLogico = 10; //tamanho em bits endereço lógico

    // Tamanhos de memória (em quantidade de páginas)
    tamMemFisica = 2048; 
    tamMaxSecundaria = 1024;
    tamImgProcesso = 256;

    algorithm = "LRU"; // algoritmo utilizado
    // 0 -> LRU
    return;    
}
    
Config::Config(int size, int szEndLogico, int szMemFisica, int szMaxSecundaria, int szImgProcesso, string algorithm){
    pageSize = size; // tamanho página/quadro
    tamanhoEndLogico = szEndLogico; //tamanho em bits endereço lógico
    if(tamanhoEndLogico > 63){
        cout << "Tamanho do endereço lógico muito grande." << endl;
        cout << "O máximo suportado é 63 bits." << endl;
        abort();
    }

    // Tamanhos de memória (em quantidade de páginas)
    tamMemFisica = szMemFisica; 
    tamMaxSecundaria = szMaxSecundaria;
    tamImgProcesso = szImgProcesso;

    algorithm = algorithm; // algoritmo utilizado
   
    return;    
}

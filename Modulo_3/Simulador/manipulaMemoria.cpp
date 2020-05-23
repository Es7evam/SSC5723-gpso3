#include <iostream>
#include <vector>
#include <utility>
#include <random> // random string

#include "Config.hh"
using namespace std;

class ManipulaMemoria {
    public:
    ManipulaMemoria(Config conf);
    bool acessoReal(int frame);
    
    // Recebe pair <processo, endereco> e retorna frame real associada
    // Associa caso ainda não esteja mapeada
    int virtToReal(pair<string, long long> enderecoVirtual);

    vector<string> memoria;
    Config config;

    
    map<pair<string, int>, int> virtTable;
};

// Gera uma string aleatória
string random_string(std::string::size_type length){
    static auto& chrs = "0123456789"
        "abcdefghijklmnopqrstuvwxyz";

    thread_local static std::mt19937 rg{std::random_device{}()};
    thread_local static std::uniform_int_distribution<std::string::size_type> pick(0, sizeof(chrs) - 2);

    std::string s;

    s.reserve(length);

    while(length--)
        s += chrs[pick(rg)];

    return s;
}

ManipulaMemoria::ManipulaMemoria(Config conf){
    config = conf;
    memoria.resize(config.tamMaxSecundaria/config.pageSize);
}

// Simula um acesso ao frame dado na memória real.
bool ManipulaMemoria::acessoReal(int frame){
    cout << "Acesso à memória real, frame: " << frame << endl;
    if(frame >= config.tamMaxSecundaria/config.pageSize){
        cout << "\t |-> Acesso impossível, memória secundária excedida." << endl;
        return false;
    }
    return true;
}

// Converte um endereço de memória virtual de um processo em um frame de memória real.
int ManipulaMemoria::virtToReal(pair<string, long long> enderecoVirtual){
    // transforma em frame
    pair <string, int> frameVirt;
    frameVirt.first = enderecoVirtual.first;
    frameVirt.second = enderecoVirtual.second/config.pageSize;
    cout << frameVirt.first << ": Acesso na página virtual " << frameVirt.second << endl;

    if(virtTable.find(frameVirt) == virtTable.end()){
        // memória virtual não tem essa página mapeada na real
        // insere na memória real.
        // TODO - memoria.push_back(random_string(10));
        virtTable[frameVirt] = memoria.size();
    }

    // se estiver, converte
    int frameReal = virtTable[frameVirt];
    acessoReal(frameReal);
    return frameReal;
}

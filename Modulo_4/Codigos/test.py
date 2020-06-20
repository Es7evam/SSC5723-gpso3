import os
import statistics as stat

def media(lista):
    return sum(lista)/len(lista)


sizes = ['5kb', '10kb', '100kb', '1mb', '10mb', '100mb', '500mb']

for tamanho in sizes:
    Cclocks = []
    Ctimes = []
    Lclocks = []
    Ltimes = []
    Exclocks = []
    Extimes = []

    for it in range(0, 10):
        print("Iteracao", it)
        inputstr = "./criacao_arquivos " + tamanho + " 1> output 2>/dev/null" 
        os.system(inputstr)
        f = open("output")
        currClock = float(f.readline().strip('\n').split(' ').pop())
        currTime = float(f.readline().strip('\n').split(' ').pop())
        Cclocks.append(currClock)
        Ctimes.append(currTime)
        f.close()

        inputstr = "./leitura_arquivos " + tamanho + " 1> output 2>/dev/null"
        os.system(inputstr)
        f = open("output")
        currClock = float(f.readline().strip('\n').split(' ').pop())
        currTime = float(f.readline().strip('\n').split(' ').pop())
        Lclocks.append(currClock)
        Ltimes.append(currTime)
        f.close()

        inputstr = "./exclusao_arquivos " + tamanho + " 1> output 2>/dev/null"
        os.system(inputstr)
        f = open("output")
        currClock = float(f.readline().strip('\n').split(' ').pop())
        currTime = float(f.readline().strip('\n').split(' ').pop())
        Exclocks.append(currClock)
        Extimes.append(currTime)
        f.close()

    print("\n\nTamanho", tamanho)
    print("Criacao\n Tempo medio: ", media(Ctimes))
    print(" Desvio Padrao: ", stat.stdev(Ctimes))
    print("Leitura\n Tempo medio: ", media(Ltimes))
    print(" Desvio Padrao: ", stat.stdev(Ltimes))
    print("Exclusao\n Tempo medio: ", media(Extimes))
    print(" Desvio Padrao: ", stat.stdev(Extimes))
    #print(Cclocks)
    #print(Ctimes)
    #print(Lclocks)
    #print(Ltimes)
    #print(Exclocks)
    #print(Extimes)







#!/bin/bash

make
cp ../Arquivos/bkcp/arquivo_size_$1.txt ../Arquivos/
./exclusao_arquivos $1

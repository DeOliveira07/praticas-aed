#!/bin/bash

# Para cada arquivo .cpp no diretório atual
for file in *.cpp; do
    # Remove extensão .cpp para gerar o nome do executável
    base=$(basename "$file" .cpp)

    # Nome do executável final
    out="test${base}"

    echo "Compilando $file -> $out"

    # Compila usando g++
    g++ -o $out $file

    # Teste de erro na compilação
    if [[ $? -ne 0 ]]; then
        echo "Erro ao compilar $file"
    fi
done

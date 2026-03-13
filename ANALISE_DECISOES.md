# Análise de Tomadas de Decisão - Praticas AED

---

## **LISTA 01** - Fundamentos de Recursão

### 1. **maior.cpp**
**Objetivo:** Encontrar o maior elemento usando recursão

**Tomada de Decisão:**
- ✅ **Recursão Linear**: Reduz o array em 1 elemento a cada chamada `maior(arr, n-1)`
- ✅ **Caso Base**: `n == 1` retorna o primeiro elemento
- ✅ **Comparação no Retorno**: Compara resultado recursivo com elemento atual
- **Complexidade**: O(n), com overhead de pilha recursiva

---

### 2. **reverse.cpp**
**Objetivo:** Inverter uma string recursivamente

**Tomada de Decisão:**
- ✅ **Estratégia Divide & Conquer**: `inverter(s.substr(1)) + s[0]`
- ✅ **Caso Base**: `s.size() <= 1` retorna a string (caso base)
- ✅ **Processamento Pós-Ordem**: Concatena após retorno recursivo
- **Trade-off**: Cria muitas substrings (ineficiente), mas é didático
- **Complexidade**: O(n²) pelo uso de `substr`

---

### 3. **rotate.cpp**
**Objetivo:** Rotacionar array N posições

**Tomada de Decisão:**
- ✅ **Tratamento de Valores Negativos**: `n = (n % tamanho + tamanho) % tamanho`
- ✅ **Mapeamento de Índices**: `i_novo = (i + n) % tamanho`
- ✅ **Array Auxiliar**: Usa espaço extra O(n) para evitar sobrescrita
- ✅ **Modulo para Circularidade**: Permite rotação com wrap-around
- **Complexidade**: O(n) em tempo e espaço

---

## **LISTA 02** - Problemas Clássicos (BFS/DFS)

### 1. **chuva.cpp**
**Objetivo:** Simular água caindo e se espalhando em relevo

**Tomada de Decisão:**
- ✅ **Duas Abordagens**:
  1. **Iterativa com Repetição**: Loop `do-while` até convergência (não há mudanças)
  2. **Recursiva por Direção**: Propaga apenas direita e baixo
- ✅ **Estratégia de Propagação**: Simula física de gravidade
- ✅ **Detecção de Mudanças**: Flag `change` para saber quando parar
- **Complexidade**: O(n·m·k) onde k é iterações até convergência

---

### 2. **contaminacaoo.cpp**
**Objetivo:** Propagar contaminação em matriz (BFS de fato)

**Tomada de Decisão:**
- ✅ **BFS com Fila Manual**: Implementa fila com dois índices `head` e `tail`
- ✅ **4-Conectividade**: Direções: cima, baixo, esquerda, direita
- ✅ **Evita Revisitar**: Marca como 'T' imediatamente (equivale a visitado)
- ✅ **Alternativa DFS**: Também implementa versão recursiva
- **Eficiência**: BFS é O(n·m), ideal para este problema

```cpp
// BFS manual - sem estrutura STL queue
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
```

---

## **LISTA 03** - Estruturas de Dados Básicas

### 1. **pilha01.cpp**
**Objetivo:** Validar parênteses, colchetes, chaves balanceados

**Tomada de Decisão:**
- ✅ **Stack STL**: Usa `stack<char>` da STL
- ✅ **Processamento caractere por caractere**:
  - Abre: push na pilha
  - Fecha: verifica correspondência com topo
- ✅ **Validação Final**: `stack.empty()` garante que todos foram fechados
- **Complexidade**: O(n) em tempo, O(n) em espaço no pior caso

---

### 2. **fila01.cpp**
**Objetivo:** Calcular média móvel de 4 últimos elementos

**Tomada de Decisão:**
- ✅ **Fila Circular**: Usa `ini`, `tam` e `cap` (sem remover elementos)
- ✅ **Otimização O(1) para Média**: Mantém `soma` acumulada
  - Ao desenfileirar: `soma -= itens[ini]`
  - Ao enfileirar: `soma += i`
- ✅ **Circular com Modulo**: `fim = (ini + tam) % cap`
- ✅ **Gerenciamento de Capacidade**: Remove quando `cheia()` antes de inserir
- **Complexidade**: O(1) média, O(n) espaço

---

## **LISTA 04** - Array Busca

### **kth.cpp / kthLeetcode.cpp**
**Objetivo:** Encontrar o K-ésimo maior elemento

**Decisões Potenciais** (não analisado em detalhe, mas mencionado)

---

## **LISTA 05** - Algoritmos de Ordenação

### **ordenacao.h** - Implementações incluídas

#### 1. **Bubble Sort**
```cpp
// Estratégia: Compara vizinhos, troca se desordenado
// Repete até não haver mudanças
while(mudanca > 0) { ... }
```
**Tomada de Decisão:**
- ✅ **Flag de Mudança**: Otimização que para cedo se array fica ordenado
- **Complexidade**: O(n²) no pior caso, O(n) no melhor (array ordenado)

---

#### 2. **Selection Sort**
**Tomada de Decisão:**
- ✅ **Encontra Mínimo**: A cada iteração, encontra menor elemento
- ✅ **Coloca na Posição Certa**: Swap com início não-ordenado
- **Complexidade**: O(n²) sempre (não melhora com dados parcialmente ordenados)

---

#### 3. **Insertion Sort**
**Tomada de Decisão:**
- ✅ **Constrói Incrementalmente**: Assume primeira posição ordenada
- ✅ **Shift para Direita**: Elementos maiores deslocam-se
- **Complexidade**: O(n²) pior caso, O(n) melhor (já ordenado)
- **Uso Prático**: Bom para arrays pequenos ou dados quase ordenados

---

#### 4. **Quick Sort** (versão iterativa com stack)
```cpp
// Usa stack<pair<int,int>> em vez de recursão
// Pivo no meio: array[(inicio + fim) / 2]
```
**Tomada de Decisão:**
- ✅ **Implementação Iterativa**: Evita stack overflow
- ✅ **Pivo Central**: Reduz risco com arrays ordenados
- ✅ **Partição de Hoare**: 2-pointers (`percorreMenores`, `percorreMaiores`)
- **Complexidade**: O(n log n) médio, O(n²) pior caso

---

#### 5. **Merge Sort**
```cpp
// Função merge combina 2 subarrays ordenados
void merge(vector<T> &array, vector<T> &aux, int start, int finish) {
    // Divide e conquista
}
```
**Tomada de Decisão:**
- ✅ **Divide & Conquer**: Divide até tamanho 1, depois merge
- ✅ **Array Auxiliar**: Necessário para merge eficiente
- ✅ **Stable Sort**: Mantém ordem relativa de iguais
- **Complexidade**: O(n log n) garantido
- **Trade-off**: O(n) espaço auxiliar vs garantia de O(n log n)

---

### **main.cpp / colors.cpp / strings.cpp**
- Testes dos algoritmos de ordenação
- Geração de arrays aleatórios
- Benchmarking de diferentes algoritmos

---

## **LISTA 06** - Sem Status (Possivelmente Teoria)

---

## **LISTA 07** - Árvores de Busca

---

## **PRATICA-05** (dentro LISTA02)

**Estruturas Testadas:**
- Ordenação (Bubble, Selection, Insertion)
- Conversão de tipos com strings

---

## **PRATICA-06** - Tabela de Espalhamento (Hash Table)

### **hashtable.h** (Interface Abstrata)
**Tomada de Decisão:**
- ✅ **Template Genérico**: `hashtable<T_key, T_value>`
- ✅ **Função Hash Modular**: `hash_function(key) % capacity`
- ✅ **Tratamento de Limites**: Validação de capacidade > 0
- ✅ **Interface Abstrata**: Define contrato (insert, remove, search, show)

---

### **simple_hashtable.h**
**Tomada de Decisão:**
- ✅ **Encadeamento Separado**: Cada posição tem Lista Ligada
- ✅ **Reduz Colisões**: Múltiplos elementos na mesma posição
- **Complexidade**: O(1 + α) onde α é fator de carga

---

### **full_hashtable.h**
**Tomada de Decisão:**
- ✅ **Endereçamento Aberto**: Procura próximo espaço disponível
- ✅ **Estratégia de Sondagem** (provavelmente linear)
- **Complexidade**: O(1/(1-α)) com fator de carga α

---

### **hashfunc.h / hashfunc.cpp**
**Função Hash (provavelmente polinomial ou DJB2)**

---

### **linkedlist.h / linkedlist.cpp**
**Suporte a Encadeamento Separado**
- Nó com chave, valor e próximo

---

### **cpf.h**
**Validação CPF Custom** - presumivelmente usa hash para verificação

---

## **PRATICA-07** - Árvores AVL e BST

### **bst.h** - Binary Search Tree
**Tomada de Decisão:**
- ✅ **Altura Armazenada**: Cada nó mantém `height` para cálculos rápidos
- ✅ **Função `H(node)`**: Trata `nullptr` como altura 0 (evita segfault)
- ✅ **Validação Recursiva**: Método `validate()` verifica invariantes
- ✅ **Operações Padrão**:
  - `insert`: Ordem O(log n) a O(n)
  - `search`: Idem
  - `predecessor/successor`: Navegação eficiente
  - `sort`: Inorder traversal
- **Complexidade**: O(log n) médio, O(n) pior (árvore degenerada)

---

### **avl.h** - AVL Tree (herda BST)
**Tomada de Decisão:**
- ✅ **Herança de BST**: Aproveita estrutura base
- ✅ **Balanceamento Automático**: `BF(node) = H(left) - H(right)`
- ✅ **Fator de Balanceamento < 2**: Garante altura ~log(n)
- ✅ **Rotações**:
  - `rotateLeft`, `rotateRight`
  - `rebalance`: Aplica rotação apropriada
- ✅ **Detecção Heavy**: `leftHeavy`, `rightHeavy`
- **Complexidade**: O(log n) garantido para todas operações

```cpp
static int BF(Node * node) { 
    return H(node->left) - H(node->right);  // -1, 0, 1
}
static int balanced(Node * node) { 
    return abs(BF(node)) < 2;  // -1 <= BF <= 1
}
```

---

### **bst.cpp / avl.cpp / tree_sort.cpp**
- Implementações dos métodos
- Testes de ordenação usando árvores

---

## **PRATICA-08-09** - Grafos

### **graph.h** - Grafo Direcionado

**Estrutura:**
```cpp
vector<list<pair<int, int>>> adj;  // adj[src] = {(dst, weight), ...}
```

**Tomada de Decisão:**
- ✅ **Lista de Adjacência**: Eficiente para grafos esparsos
- ✅ **Pares (dst, weight)**: Armazena peso das arestas
- ✅ **4-Conectividade Padrão**: `dr[]` e `dc[]` para movimento
- ✅ **Grafos Contíguos**: Vertices 0 até size-1 (sem "buracos")

**Operações Implementadas:**
- `edge(src, dst, w)`: Adiciona aresta
- `degree(vtx)`: Grau de um vértice
- `neighbors(vtx)`: Adjacentes
- `weight(src, dst)`: Peso da aresta
- `isConnected()`: Grafo é conexo?
- `dfs(src)`: Busca em profundidade
- `bfs(src)`: Busca em largura
- `spf(src, dst)`: Caminho mais curto (Dijkstra)
- `has_cycle()`: Detecta ciclos
- `reacheable(src, dst)`: Alcançabilidade

**Buscas:**
- **DFS**: Recursiva com flag visitado
- **BFS**: Com fila manual
- **SPF (Shortest Path)**: Dijkstra com `prev` e `dist`

---

### **domino.cpp / network.cpp**
- Aplicações específicas de grafos

---

## **PRATICA-10, 11, 12** - Programação Dinâmica e Otimização ⭐

### 1. **subsetsum.cpp** - Encontrar Subset com Soma K

**Informação do Dono do Código:**
- "Ordenar pelo maior e depois aproximação"
- "Encontrar uma sequência que a soma dele vai dar um valor k"
- "Dar valor próximo ou igual ao meu valor k"

**Implementações:**

#### **a) Força Bruta (BF)**
```cpp
long total = 1 << array.size();  // 2^N combinações
for (long v = 0; v < total; v++) {
    // Testa cada combinação bits
    int cur_sum = 0;
    for (unsigned i = 0; i < array.size(); i++) {
        subset[i] = v & (1 << i);  // Extrai i-ésimo bit
        if (subset[i]) cur_sum += array[i];
    }
    if (cur_sum == K) return true;
}
```
**Tomada de Decisão:**
- ✅ **Bit Masking**: Cada número de 0 a 2^n representa um subset
- ✅ **Extração de Bits**: `v & (1 << i)` faz OR binário
- **Complexidade**: O(2^n · n)
- **Uso**: Prototipagem, validação, pequenos inputs

---

#### **b) Backtracking (BT)**
```cpp
bool subsetSumBTRec(const vector<int> &array, int n, int k, vector<bool> &subset) {
    if(k == 0) return true;           // Encontrou soma
    if(n < 0) return false;           // Fim do array
    
    subset[n] = false;                // Não inclui
    if(subsetSumBTRec(array, n - 1, k, subset)) return true;
    
    if(array[n] <= k) {               // Pode incluir?
        subset[n] = true;             // Inclui
        if(subsetSumBTRec(array, n - 1, k - array[n], subset)) return true;
        subset[n] = false;            // Backtrack
    }
    
    return false;
}
```
**Tomada de Decisão:**
- ✅ **Poda**: `array[n] <= k` evita busca inútil
- ✅ **2 Ramos**: Incluir ou não incluir
- ✅ **Backtrack**: Restaura estado
- **Complexidade**: O(2^n) pior caso, mas com poda
- **Uso**: Melhor que BF em casos práticos

---

#### **c) Greedy (11)**
```cpp
// Ordena pelo MAIOR
sort(valores.rbegin(), valores.rend());

int soma = 0;
for(auto &[valor, idx] : valores) {
    if(soma + valor <= k) {
        subset[idx] = true;
        soma += valor;
        if(soma == k) return true;  // Parada cedo
    }
}
```
**Tomada de Decisão (Informação do Dono):**
- ✅ **"Ordenar pelo Maior"**: `rbegin(), rend()`
- ✅ **"Depois Aproximação"**: Se atingir soma < k, para
- ✅ **Avidez**: Sempre toma maior disponível
- **Complexidade**: O(n log n) sorting + O(n) busca
- **Limitação**: Não garante encontrar solução ótima
  - Ex: array=[1, 5, 10], k=6 → Greedy pega [5] + nada, Correto é [1, 5]

---

#### **d) Memorização (12)**
```cpp
vector<vector<int>> memo(array.size() + 1, vector<int>(k + 1, -1));

bool subsetSumRecMemo(const vector<int> &array, int n, int k, 
                       vector<bool> &subset, vector<vector<int>> &memo) {
    if (k == 0) return true;
    if (n < 0 || k < 0) return false;
    
    if (memo[n][k] != -1) {
        return memo[n][k] == 1;  // Retorna resultado em cache
    }
    
    // (mesmo backtracking anterior)
    
    memo[n][k] = resultado ? 1 : 0;
    return resultado;
}
```
**Tomada de Decisão:**
- ✅ **Cache 2D**: memo[n][k] armazena resultado para (n, k)
- ✅ **-1 = Desconhecido**: Diferencia cachê vs. não visitado
- ✅ **Espaço-Tempo Trade-off**: O(n·k) espaço, O(n·k) tempo
- **Complexidade**: O(n·k) tempo, O(n·k) espaço
- **Vantagem**: Evita recalcular subproblemas

---

#### **e) Programação Dinâmica (DP)**
```cpp
// TODO - Implementação possivelmente bottom-up
```
**Esperado:**
- Array `dp[i][j]`: É possível fazer soma j com primeiros i elementos?
- Transição: `dp[i][j] = dp[i-1][j] || dp[i-1][j-array[i]]`

---

### 2. **mochila.cpp** - Problema da Mochila Fracionária ⭐⭐⭐

**Informação do Dono:** 
- "A regra de ordenação foi a razão de peso pelo valor"
- "Ordeno pelo maior"
- "Maior razão, escolhido primeiro"

```cpp
float solve(const vector<int> &price, const vector<int> &weight, int k) {
    // Criar pares (preço, peso)
    vector<pair<int,int>> pricesWeights(price.size());
    
    // Ordenar por razão PREÇO/PESO, do MAIOR para o MENOR
    sort(pricesWeights.begin(), pricesWeights.end(), 
         [](const pair<int,int> &a, const pair<int,int> &b){
             return (a.first / a.second) > (b.first / b.second);  // maior primeiro
         });
    
    float totalValue = 0.0, remainWeight = k;
    
    for(auto x : pricesWeights) {
        if(remainWeight <= 0) return totalValue;
        
        if(x.second <= remainWeight) {
            // Cabe inteiro
            totalValue += x.first;
            remainWeight -= x.second;
        } else {
            // Cabe parcial (fracionário)
            float fraction = remainWeight / x.second;
            totalValue += (x.first * fraction);
            remainWeight = 0;
        }
    }
    
    return totalValue;
}
```

**Tomada de Decisão (Greedy Otimizado):**
- ✅ **Razão Valor/Peso**: `a.first / a.second`
  - Maior razão = mais valor por unidade de peso
- ✅ **Ordenação Decrescente**: `rbegin()` equivalente via comparador reverso
- ✅ **Avidez Fracionária**: Pega inteiro quando cabe, depois fracionário
- ✅ **Parada Cedo**: Se mochila cheio, retorna
- **Complexidade**: O(n log n) sorting + O(n) preenchimento
- **Racional**: Sempre melhor ratio → máximo valor
- **Diferença de Subset Sum**:
  - Mochila: Permite pegar fração do item (FRACIONÁRIA)
  - Subset Sum: Tudo ou nada (BOOLEANO)

---

### 3. **stairs.cpp** - Subir Escadas com Memorização

```cpp
class Solution {
    vector<int> memo;
public:
    Solution() : memo(46, -1) {}
    
    int climbStairs(int n) {
        if(n == 1) return 1;         // 1 forma: [1]
        if(n == 2) return 2;         // 2 formas: [1,1] ou [2]
        
        if(this->memo.at(n) != -1) 
            return this->memo.at(n); // Retorna cache
        
        // Fibonacci: f(n) = f(n-1) + f(n-2)
        this->memo.at(n) = climbStairs(n - 1) + climbStairs(n - 2);
        return this->memo.at(n);
    }
};
```

**Tomada de Decisão:**
- ✅ **Padrão Fibonacci**: `f(n) = f(n-1) + f(n-2)`
  - De n degraus, pode vir de n-1 (subir 1) ou n-2 (subir 2)
- ✅ **Memorização**: Array pré-alocado `memo(46, -1)`
- ✅ **Casos Base**: n=1 → 1 forma, n=2 → 2 formas
- **Complexidade**: O(n) tempo (com cache), O(n) espaço
- **Evita**: Exponencial O(2^n) sem memorização

---

### 4. **subseqmax.cpp** - Subsequência de Soma Máxima

```cpp
/* Força Bruta */
int subseqMaxBF(const vector<int> &array, int & ini, int & end) {
    int totalSum = 0;
    
    for(int i = 0; i < array.size(); i++) {
        int soma = 0;
        for(int j = i; j < array.size(); j++) {
            soma += array[j];
            if(soma > totalSum) {
                totalSum = soma;
                ini = i;
                end = j;
            }
        }
    }
    return totalSum;
}
```

**Tomada de Decisão:**
- ✅ **Força Bruta**: Testa todos os subarrays [i, j]
- ✅ **Rastreamento de Índices**: Mantém ini e end da melhor sequência
- **Complexidade**: O(n²)

**Versão Divide & Conquer:**
```cpp
// Encontra subarray max que cruza o meio
int subseqMaxMiddle(const vector<int> &array, int start, int middle, int finish,
                    int & ini, int & end) {
    // Propaga pela esquerda do meio para mín índice
    for (int i = middle - 1; i >= start; i--) {
        sumL += array[i];
        if (sumL > maxL) {
            maxL = sumL;
            ini = i;
        }
    }
    
    // Propaga pela direita do meio para máx índice
    for (int i = middle + 1; i <= finish; i++) {
        sumR += array[i];
        if (sumR > maxR) { ... }
    }
    
    // Combina: ini até middle + maxR
    return maxL + maxR;
}
```

**Tomada de Decisão:**
- ✅ **3 Casos**: Máximo à esquerda, direita, ou atravessando meio
- ✅ **Propaga Meticulosamente**: Explora todos cruzamentos
- **Complexidade**: O(n log n) divide & conquer

**Nota do Dono:**
- "Adaptação do código dele, **menos subseqmaxx**"
  - Significa: Subseqmax é implementação mais simples/menos otimização

---

### 5. **kthlargest.cpp**
**Encontrar K-ésimo maior elemento** (não analisado em profundidade presente, mas mencionado)

---

### 6. **sales_trip.cpp / labirinto.cpp / change.cpp**
**Aplicações DP** (não analisado em profundidade)

---

## **RESUMO GERAL DE ESTRATÉGIAS USADAS**

| Técnica | Pasta/Arquivo | Uso |
|---------|---------------|-----|
| **Recursão Linear** | LISTA01 | maior, reverse |
| **Modulo Circular** | LISTA01 | rotate |
| **Simples BFS/DFS** | LISTA02 | contaminação, chuva |
| **Pilha (Stack)** | LISTA03 | Parenteses |
| **Fila Circular** | LISTA03 | Média móvel |
| **Bubble/Merge/Quick Sort** | LISTA05 | Ordenação |
| **Hash Table** | PRATICA-06 | Busca O(1) |
| **BST/AVL** | PRATICA-07 | Busca O(log n) |
| **Grafos Direcionados** | PRATICA-08-09 | Trajetos, ciclos |
| **Força Bruta** | PRATICA-10 | 2^n exhaustive |
| **Backtracking + Poda** | PRATICA-10 | Subset Sum |
| **Greedy Ordenado** | PRATICA-11 | Mochila fracionária |
| **Memorização** | PRATICA-12 | DP top-down (stairs) |
| **Programação Dinâmica** | PRATICA-10,11,12 | Bottom-up ótimo |

---

## **TOMADAS DE DECISÃO PRINCIPAIS**

### ✅ Quando Usar Cada Técnica

1. **Força Bruta** → Validação, inputs pequenos
2. **Backtracking + Poda** → Quando há restrições que cortam ramos
3. **Greedy** → Otimização local funciona globalmente (ex: Mochila fracionária)
4. **Memorização** → Subproblemas overlapping, top-down
5. **DP Bottom-up** → Sem recorrência, mais eficiente
6. **BST/AVL** → Manutenção ordenada dinâmica
7. **Hash Table** → Busca/Inserção O(1)
8. **Ordenação** → Préprocessamento antes de busca binária/algoritmo greedy

---

## **TRADE-OFFS OBSERVADOS**

| Decisão | Vantagem | Desvantagem |
|---------|----------|------------|
| Array auxiliar (rotate, merge) | Simplicidade | +O(n) espaço |
| BF vs Backtracking | Simples | BF é exponencial |
| Greedy | Rápido | Não sempre ótimo |
| Memorização | Evita recalcular | +O(n·k) espaço |
| Iterativa Quick (vs recursiva) | Sem stack overflow | Mais complexo |
| Circular Queue | Eficiente | Modulo em cada operação |

---

## **Conclusão**

Seu repositório demonstra compreensão progressiva de:
1. **Fundamentação**: Recursão, estruturas básicas
2. **Otimização**: Reconhecer quando aplicar qual técnica
3. **Trade-offs**: Escolher entre espaço/tempo
4. **Aplicações**: Problemas reais de grafos e DP

A progressão LISTA01 → PRATICA-12 mostra entendimento crescente em complexidade.

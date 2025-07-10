# Philosophers

Este repositório contém uma implementação do projeto "Philosophers", baseado no clássico problema dos filósofos, utilizando a linguagem C para explorar conceitos de concorrência, sincronização e gerenciamento de threads.

## Sobre o Projeto

O problema dos filósofos consiste em um grupo de filósofos sentados à mesa, alternando entre pensar e comer. Para comer, cada filósofo precisa de dois garfos, criando desafios de sincronização e possíveis condições de deadlock. Este projeto tem como objetivo resolver esse problema de forma eficiente, aplicando técnicas de programação concorrente.

## Funcionalidades

- Gerenciamento de múltiplas threads para representar cada filósofo.
- Sincronização do acesso aos recursos compartilhados (garfos).
- Prevenção de condições de deadlock e starvation.
- Parâmetros configuráveis para simulação (número de filósofos, tempos de comer/pensar, etc).

## Como Executar

1. Clone o repositório:
   ```bash
   git clone https://github.com/RochtBruno/philosophers.git
   cd philosophers
   ```

2. Compile o projeto:
   ```bash
   make
   ```

3. Execute o programa:
   ```bash
   ./philosophers [número_de_filósofos] [tempo_para_morrer] [tempo_para_comer] [tempo_para_pensar] [opcional: número_de_refeições]
   ```

   Exemplo:
   ```bash
   ./philosophers 5 800 200 200
   ```

## Estrutura do Projeto

- `src/` — Arquivos-fonte principais do projeto
- `include/` — Arquivos de cabeçalho
- `Makefile` — Script de compilação

## Requisitos

- GCC ou outro compilador C compatível
- Make


---

Desenvolvido por [RochtBruno](https://github.com/RochtBruno)

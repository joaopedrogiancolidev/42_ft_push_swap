#!/bin/bash

# Cores
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

echo -e "${BLUE}=== PUSH_SWAP TESTER COM CHECKER_LINUX ===${NC}\n"

# Teste 1: Caso simples (5 números)
echo -e "${YELLOW}1. Teste com 5 números:${NC}"
ARG="4 67 3 87 23"
OPERATIONS=$(./push_swap $ARG | wc -l)
RESULT=$(./push_swap $ARG | ./checker_linux $ARG)
echo -e "Operações: $OPERATIONS | Resultado: $RESULT"

# Teste 2: Já ordenado
echo -e "${YELLOW}2. Teste já ordenado:${NC}"
ARG="1 2 3 4 5"
OPERATIONS=$(./push_swap $ARG | wc -l)
RESULT=$(./push_swap $ARG | ./checker_linux $ARG)
echo -e "Operações: $OPERATIONS | Resultado: $RESULT"

# Teste 3: Ordem inversa
echo -e "${YELLOW}3. Teste ordem inversa:${NC}"
ARG="5 4 3 2 1"
OPERATIONS=$(./push_swap $ARG | wc -l)
RESULT=$(./push_swap $ARG | ./checker_linux $ARG)
echo -e "Operações: $OPERATIONS | Resultado: $RESULT"

# Teste 4: 3 números
echo -e "${YELLOW}4. Teste com 3 números:${NC}"
ARG="2 1 3"
OPERATIONS=$(./push_swap $ARG | wc -l)
RESULT=$(./push_swap $ARG | ./checker_linux $ARG)
echo -e "Operações: $OPERATIONS | Resultado: $RESULT"

# Teste 5: 2 números
echo -e "${YELLOW}5. Teste com 2 números:${NC}"
ARG="2 1"
OPERATIONS=$(./push_swap $ARG | wc -l)
RESULT=$(./push_swap $ARG | ./checker_linux $ARG)
echo -e "Operações: $OPERATIONS | Resultado: $RESULT"

# Teste 6: 10 números aleatórios
echo -e "${YELLOW}6. Teste com 10 números:${NC}"
ARG=$(shuf -i 1-100 -n 10 | tr '\n' ' ')
OPERATIONS=$(./push_swap $ARG | wc -l)
RESULT=$(./push_swap $ARG | ./checker_linux $ARG)
echo -e "Operações: $OPERATIONS | Resultado: $RESULT"

# Teste 7: 100 números aleatórios
echo -e "${YELLOW}7. Teste com 100 números:${NC}"
ARG=$(shuf -i 1-1000 -n 100 | tr '\n' ' ')
OPERATIONS=$(./push_swap $ARG | wc -l)
RESULT=$(./push_swap $ARG | ./checker_linux $ARG)
echo -e "Operações: $OPERATIONS | Resultado: $RESULT"

# Teste 8: 500 números aleatórios
echo -e "${YELLOW}8. Teste com 500 números:${NC}"
ARG=$(shuf -i 1-1000 -n 500 | tr '\n' ' ')
OPERATIONS=$(./push_swap $ARG | wc -l)
RESULT=$(./push_swap $ARG | ./checker_linux $ARG)
echo -e "Operações: $OPERATIONS | Resultado: $RESULT"

# Teste 9: Caso edge - números grandes
echo -e "${YELLOW}9. Teste com números grandes:${NC}"
ARG="2147483647 -2147483648 0 42 -42"
OPERATIONS=$(./push_swap $ARG | wc -l)
RESULT=$(./push_swap $ARG | ./checker_linux $ARG)
echo -e "Operações: $OPERATIONS | Resultado: $RESULT"

# Teste 10: Muitos números pequenos
echo -e "${YELLOW}10. Teste com muitos números pequenos:${NC}"
ARG="2 1 4 3 6 5 8 7 10 9"
OPERATIONS=$(./push_swap $ARG | wc -l)
RESULT=$(./push_swap $ARG | ./checker_linux $ARG)
echo -e "Operações: $OPERATIONS | Resultado: $RESULT"

echo -e "${BLUE}=== FIM DOS TESTES ===${NC}"
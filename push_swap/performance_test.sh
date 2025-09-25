#!/bin/bash

# Cores
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

echo -e "${BLUE}=== TESTE DE PERFORMANCE PUSH_SWAP ===${NC}\n"

# Teste com 100 números (5 vezes)
echo -e "${YELLOW}Performance com 100 números:${NC}"
TOTAL_100=0
OK_100=0
for i in {1..5}; do
    ARG=$(shuf -i 1-1000 -n 100 | tr '\n' ' ')
    OPERATIONS=$(./push_swap $ARG | wc -l)
    RESULT=$(./push_swap $ARG | ./checker_linux $ARG)
    TOTAL_100=$((TOTAL_100 + OPERATIONS))
    
    if [ "$RESULT" == "OK" ]; then
        OK_100=$((OK_100 + 1))
        echo -e "Teste $i: ${GREEN}$RESULT${NC} - $OPERATIONS operações"
    else
        echo -e "Teste $i: ${RED}$RESULT${NC} - $OPERATIONS operações"
    fi
done
AVG_100=$((TOTAL_100 / 5))
echo -e "Média 100 números: $AVG_100 operações | OK: $OK_100/5"

# Teste com 500 números (3 vezes)
echo -e "${YELLOW}Performance com 500 números:${NC}"
TOTAL_500=0
OK_500=0
for i in {1..3}; do
    ARG=$(shuf -i 1-1000 -n 500 | tr '\n' ' ')
    OPERATIONS=$(./push_swap $ARG | wc -l)
    RESULT=$(./push_swap $ARG | ./checker_linux $ARG)
    TOTAL_500=$((TOTAL_500 + OPERATIONS))
    
    if [ "$RESULT" == "OK" ]; then
        OK_500=$((OK_500 + 1))
        echo -e "Teste $i: ${GREEN}$RESULT${NC} - $OPERATIONS operações"
    else
        echo -e "Teste $i: ${RED}$RESULT${NC} - $OPERATIONS operações"
    fi
done
AVG_500=$((TOTAL_500 / 3))
echo -e "Média 500 números: $AVG_500 operações | OK: $OK_500/3"

# Benchmarks de referência
echo -e "${YELLOW}Benchmarks de referência:${NC}"
echo -e "100 números: ${GREEN}< 700${NC} (bom), < 900 (aceitável)"
echo -e "500 números: ${GREEN}< 5500${NC} (bom), < 7000 (aceitável)"
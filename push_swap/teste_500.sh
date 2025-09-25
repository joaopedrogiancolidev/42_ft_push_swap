#!/bin/bash

echo "🎯 TESTE 500 NÚMEROS - CONTAGEM CORRETA"
echo ""

# Gerar 500 números aleatórios
numbers=()
for i in {1..500}; do numbers+=($i); done
for ((i=499; i>0; i--)); do
    j=$((RANDOM % (i+1)))
    temp=${numbers[i]}
    numbers[i]=${numbers[j]}
    numbers[j]=$temp
done

ARG="${numbers[@]}"

echo "Executando push_swap..."
echo ""

# Contar APENAS operações válidas (filtrar debug)
operations=$(./push_swap $ARG | grep -E '^(ra|rb|rr|rra|rrb|rrr|sa|sb|ss|pa|pb)$' | wc -l)

echo "📊 NÚMERO REAL DE OPERAÇÕES: $operations"
echo ""

# Classificação
if [ $operations -le 5500 ]; then
    echo "🎉 NOTA 5/5 (≤ 5500 operações)"
elif [ $operations -le 7000 ]; then
    echo "✅ NOTA 4/5 (≤ 7000 operações)"
elif [ $operations -le 8500 ]; then
    echo "⚠️  NOTA 3/5 (≤ 8500 operações)"
elif [ $operations -le 10000 ]; then
    echo "🔶 NOTA 2/5 (≤ 10000 operações)"
elif [ $operations -le 11500 ]; then
    echo "❌ NOTA 1/5 (≤ 11500 operações)"
else
    echo "💥 NOTA 0/5 (> 11500 operações)"
fi

# Mostrar distribuição de operações
echo ""
echo "🔍 DISTRIBUIÇÃO DAS OPERAÇÕES:"
./push_swap $ARG | grep -E '^(ra|rb|rr|rra|rrb|rrr|sa|sb|ss|pa|pb)$' | sort | uniq -c | sort -nr
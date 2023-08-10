#include <stdio.h>
#include <stdlib.h>

// Funções para converter entre bases numéricas
int decimalParaBinario(int decimal) {
    int binario = 0, digito, expoente = 0;
    
    while (decimal != 0) {
        digito = decimal % 2;
        binario += digito * (1 << expoente);
        decimal /= 2;
        expoente++;
    }
    
    return binario;
}

int decimalParaHexadecimal(int decimal) {
    char hexadecimal[100];
    sprintf(hexadecimal, "%X", decimal);
    return strtol(hexadecimal, NULL, 16);
}

int main() {
    int num1, num2;
    char operador;
    
    printf("Digite a operação (ex: 5 + 3): ");
    scanf("%d %c %d", &num1, &operador, &num2);

    int resultado;
    switch (operador) {
        case '+':
            resultado = num1 + num2;
            break;
        case '-':
            resultado = num1 - num2;
            break;
        case '*':
            resultado = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                resultado = num1 / num2;
            } else {
                printf("Erro: Divisão por zero!\n");
                return 1;
            }
            break;
        default:
            printf("Operador inválido!\n");
            return 1;
    }

    printf("Resultado em decimal: %d\n", resultado);
    printf("Resultado em binário: %d\n", decimalParaBinario(resultado));
    printf("Resultado em hexadecimal: %X\n", decimalParaHexadecimal(resultado));

    return 0;
}

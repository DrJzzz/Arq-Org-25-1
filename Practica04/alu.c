#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define YES "11111111111111111111111111111111\0"
#define NO "00000000000000000000000000000000\0"

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Error: Se deben ingresar 3 cadenas binarias como argumentos\n");
        printf("Dos operandos de 32 bits y un codigo de operacion de 3 bits\n");
        return -1;
    }

    char *op1 = argv[1];
    char *op2 = argv[2];
    char result[33];
    result[32] = '\0';

    int opcode = (int)strtol(argv[3], NULL, 2);

    switch (opcode)
    {
        case 0:
            for (int i = 0; i < 32; i++)
            {
                result[i] = op1[i] & op2[i];
            }
            break;
        case 1:
            for (int i = 0; i < 32; i++)
            {
                result[i] = op1[i] | op2[i];
            }
            break;
        case 2:
            int carry = 0;
            for (int i = 31; i >= 0; i--)
            {
                int bit1 = op1[i] - '0';
                int bit2 = op2[i] - '0';
                int sum = bit1 ^ bit2 ^ carry;
                carry = (bit1 & bit2) | (bit1 & carry) | (bit2 & carry);
                result[i] = sum + '0';
            }
            break;
        case 3:
            int borrow = 0;
            for (int i = 31; i >= 0; i--)
            {
                int bit1 = op1[i] - '0';
                int bit2 = op2[i] - '0';
                int diff = bit1 ^ bit2 ^ borrow;
                borrow = (~bit1 & bit2) | ((~bit1 | bit2) & borrow);
                result[i] = diff + '0';
            }
            break;
        case 4:
            int flag = 0;
            for (int i = 0; i < 32; i++)
            {
                if (op1[i] != op2[i])
                {
                    strcpy(result, NO);
                    flag = 1;
                    break;
                }
            }
            if (!flag) { strcpy(result, YES);}
            break;
        case 5:
            int flag1 = 0;
            for (int i = 0; i < 32; i++)
            {
                if (op1[i] == '0' && op2[i] == '1')
                {
                    strcpy(result, YES);
                    flag1 = 1;
                    break;
                }
                if (op1[i] == '1' && op2[i] == '0')
                {
                    strcpy(result, NO);
                    flag1 = 1;
                    break;
                }
            }
            if (!flag1) { strcpy(result, NO);}
            break;
        default:
            return -1;
    }
    
    printf("Resultado: %s\n", result);
    return 0;
}

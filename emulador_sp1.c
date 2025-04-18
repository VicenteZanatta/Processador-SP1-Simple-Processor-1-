#include <stdio.h>
#include <stdlib.h>

void jmp(int operando, int *pnt);		// 12 desvio incondicional

struct INSTRUCTION{
	int opcode;
	int operand;
};
typedef struct INSTRUCTION inst; 

int main(){
	
	int acc = 0;
	int pc = 0;
	int status = 0;
	int i = 0;
	inst  programa[256];
	int memoria[128];


	short instruction;

	FILE  * file = fopen("teste", "rb");

	/*if((FILE  * file = fopen("teste.bin", "rb")) == NULL)
	{ 	
		printf("ERRO AO ABRIR ARQUIVO");
		return 0;
	}*/
	
	while(fread(&instruction, 2, 1, file) != 0)
	{
		programa[i].opcode = instruction & 0xFF;
		programa[i].operand = instruction >> 8;
		i++;
	}

	
	while(1)
	{ 
		switch (programa[pc].opcode)
		{
			;
			case 0: //LOAD_M
				acc = memoria[programa[pc].operand];
				pc++;
				break;

			case 1: //LOAD_V
				acc = programa[pc].operand;
				pc++;
				break;

			case 2: // STORE
				memoria[programa[pc].operand] = acc;
				pc++;
				break;

			case 3: // ADD
				acc = acc + memoria[programa[pc].operand];
				pc++;
				break;

			case 4: // SUB 
				acc = acc - memoria[programa[pc].operand];
				pc++;
				break;

			case 5: // MUL
				acc = acc * memoria[programa[pc].operand];
				pc++;
				break;

			case 6: //DIV
				acc = acc / memoria[programa[pc].operand];
				pc++;
				break;

			case 7: // INC
				acc++;
				pc++;
				break;

			case 8: // DEC
				acc--;
				pc++;
				break;

			case 9: // AND
				acc = acc && memoria[programa[pc].operand];
				pc = pc++;
				break;

			case 10: // OR
				acc = acc || memoria[programa[pc].operand];
				pc = pc++;
				break;

			case 11: // NOT
				acc = !(acc);
				pc++;
				break;

			case 12: // JMP
				jmp(programa[pc].operand, &pc);
				break;

			case 13: // JZ
				if(acc == 0)
				{ 
					jmp(programa[pc].operand, &pc);
					break;
				}
				pc++;
				break;

			case 14: // JNZ
				if(acc != 0)
				{ 	
					jmp(programa[pc].operand, &pc);
					break;
				}
				pc++;
				break;

			case 15: // JG
				if(acc > 0)
				{ 
					jmp(programa[pc].operand, &pc);
					break;
				}
				pc++;
				break;

			case 16: // JL
				if(acc < 0)
				{ 
					jmp(programa[pc].operand, &pc);
					break;
				}
				pc++;
				break;

			case 17: // JGE
				if(acc >= 0)
				{ 
					jmp(programa[pc].operand, &pc);
					break;
				}
				pc++;
				break;

			case 18: // JLE
				if(acc <= 0)
				{ 
					jmp(programa[pc].operand, &pc);
					break;
				}
				pc++;
				break;

			case 19: // HLT
				
				break;
			
			default:
				printf("OPCODE NAO ENCONTRADO");
				break;
		}
	}
	return 0;
}

void jmp(int operando, int *pnt)
{
	*pnt = operando++;
}

#include <stdio.h>
//#include <stdlib.h>

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

	switch (programa[pc].opcode)
	{
		;
		case 0:
			acc = memoria[programa[pc].operand];
			pc++;
      		break;

    	case 1:
			acc = programa[pc].operand;
			pc++;
      		break;

		case 2:
			memoria[programa[pc].operand] = acc;
			pc++;
      		break;

    	case 3:
			acc = acc + memoria[programa[pc].operand];
			pc++;
      		break;

		case 4:
			acc = acc - memoria[programa[pc].operand];
			pc++;
      		break;

    	case 5:
			acc = acc * memoria[programa[pc].operand];
			pc++;
      		break;

		case 6:
			acc = acc / memoria[programa[pc].operand];
			pc++;
      		break;

    	case 7:
			acc++;
			pc++;
      		break;

		case 8:
			acc--;
			pc++;
      		break;

    	case 9:
			acc = acc && memoria[programa[pc].operand];
			pc = pc++;
      		break;

		case 10:
			acc = acc || memoria[programa[pc].operand];
			pc = pc++;
      		break;

    	case 11:
			acc = !(acc);
			pc++;
      		break;

		case 12:
			jmp(programa[pc].operand, &pc);
      		break;

    	case 13:
			if(acc == 0)
			{ 
				jmp(programa[pc].operand, &pc);
				break;
			}
			pc++;
      		break;

		case 14:
			if(acc != 0)
			{ 	
				jmp(programa[pc].operand, &pc);
				break;
			}
			pc++;
      		break;

    	case 15:
			if(acc > 0)
			{ 
				jmp(programa[pc].operand, &pc);
				break;
			}
			pc++;
      		break;

		case 16:
			if(acc < 0)
			{ 
				jmp(programa[pc].operand, &pc);
				break;
			}
			pc++;
      		break;

    	case 17:
			if(acc >= 0)
			{ 
				jmp(programa[pc].operand, &pc);
				break;
			}
			pc++;
      		break;

		case 18:
			if(acc <= 0)
			{ 
				jmp(programa[pc].operand, &pc);
				break;
			}
			pc++;
      		break;

    	case 19:
			
			break;
		
		default:
			printf("OPCODE NAO ENCONTRADO");
			break;
	}
	return 0;
}

void jmp(int operando, int *pnt)
{
	*pnt = operando++;
}

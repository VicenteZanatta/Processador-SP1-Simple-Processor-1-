#include <stdio.h>
//#include <stdlib.h>

void jmp(int operando);		// 12 desvio incondicional
void jz(int operando);		// 13 desvio acc == 0
void jnz(int operando);		// 14 '' acc != 0
void jg(int operando);		// 15 '' acc > 0 
void jl(int operando);		// 16 '' acc < 0
void jge(int operando);		// 17 '' acc >= 0 
void jle(int operando);		// 18 '' acc <= 0
void hlt();					// 19 fim do programa 

struct INSTRUCTION{
	int opcode;
	int operand;
};
typedef struct INSTRUCTION inst;

int acc = 0;

int main(){

	int pc = 0;
	int status = 0;
	int i = 0;
	inst  programa[256];
	int memoria[128];
	
	short instruction;

	FILE  * file = fopen("teste.bin", "rb");

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
      		break;

    	case 1:
			acc = memoria[programa[pc].operand];
      		break;

		case 2:
			memoria[programa[pc].operand] = acc;
      		break;

    	case 3:
			acc = acc + memoria[programa[pc].operand];
      		break;

		case 4:
			acc = acc - memoria[programa[pc].operand];
      		break;

    	case 5:
			acc = acc * memoria[programa[pc].operand];
      		break;

		case 6:
			acc = acc / memoria[programa[pc].operand];
      		break;

    	case 7:
			acc++;
      		break;

		case 8:
			acc--;
      		break;

    	case 9:
			acc = acc && memoria[programa[pc].operand];
      		break;

		case 10:
			acc = acc || memoria[programa[pc].operand];
      		break;

    	case 11:
			acc = !(acc);
      		break;

		case 12:
			jmp(programa[pc].operand);
      		break;

    	case 13:
			jz(programa[pc].operand);
      		break;

		case 14:
			jnz(programa[pc].operand);
      		break;

    	case 15:
			jg(programa[pc].operand);
      		break;

		case 16:
			jl(programa[pc].operand);
      		break;

    	case 17:
			jge(programa[pc].operand);
      		break;

		case 18:
			jle(programa[pc].operand);
      		break;

    	case 19:
			hlt();
			break;
		
		default:
			printf("OPCODE NAO ENCONTRADO");
			break;
	}
	return 0;
}

void jmp(int operando)
{

}
void jz(int operando)
{

}
void jnz(int operando)
{

}
void jg(int operando)
{

}
void jl(int operando)
{

}
void jge(int operando)
{

}
void jle(int operando)
{

}
void hlt()
{
	
}
#include <stdio.h>
#include <stdlib.h>

void load_M(int operando); 	// 0 carrega valor em memoria para o acc
void load_V(int operando); 	// 1 carrega um valor para o acc 
void store(int operando); 	// 2 armazena o valor do acc para o ender. de memoria definido
void add(int operando);		// 3
void sub(int operando);		// 4
void mul(int operando);		// 5
void div(int operando);		// 6
void inc(int operando);		// 7 incremento
void dec(int operando);		// 8 decremento
void and(int operando);		// 9
void or(int operando);		// 10
void not(int operando);		// 11
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



int main(){

	int acc = 0;
	int pc = 0;
	int status = 0;
	int i = 0;
	inst  programa[256];
	
	short instruction

	if((FILE  *file = fopen("teste.bin", "rb")) == NULL)
	{ 	
		printf("ERRO AO ABRIR ARQUIVO");
		return 0;
	}
	
	while(fread(&instruction, 2, 1, file) != 0)
	{
		programa[i].opcode = instruction & 0xFF;
		programa[i].operand = instruction >> 8;
		i++;
	}

	switch (programa[pc].opcode)
	{​
    	;
		case 0:
			load_M(programa[pc].operand);
      		break;

    	case 1:
			load_V(programa[pc].operand);
      		break;

		case 2:
			store(programa[pc].operand);
      		break;

    	case 3:
			add(programa[pc].operand);
      		break;

		case 4:
			sub(programa[pc].operand);
      		break;

    	case 5:
			mul(programa[pc].operand);
      		break;

		case 6:
			div(programa[pc].operand);
      		break;

    	case 7:
			inc(programa[pc].operand);
      		break;

		case 8:
			dec(programa[pc].operand);
      		break;

    	case 9:
			and(programa[pc].operand);
      		break;

		case 10:
			or(programa[pc].operand);
      		break;

    	case 11:
			not(programa[pc].operand);
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
			break:
		
		default:
			printf("OPCODE NAO ENCONTRADO");
			break;
	}
	return 0;
}
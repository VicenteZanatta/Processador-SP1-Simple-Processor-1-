#include <stdio.h>
#include <stdlib.h>

void load_M(); 	// 0 carrega valor em memoria para o acc
void load_V(); 	// 1 carrega um valor para o acc 
void store(); 	// 2 armazena o valor do acc para o ender. de memoria definido
void add();		// 3
void sub();		// 4
void mul();		// 5
void div();		// 6
void inc();		// 7 incremento
void dec();		// 8 decremento
void and();		// 9
void or();		// 10
void not();		// 11
void jmp();		// 12 desvio incondicional
void jz();		// 13 desvio acc == 0
void jnz();		// 14 '' acc != 0
void jg();		// 15 '' acc > 0 
void jl();		// 16 '' acc < 0
void jge();		// 17 '' acc >= 0 
void jle();		// 18 '' acc <= 0
void hlt();		// 19 fim do programa 

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
	
	while(fread(&instruction, 2,1 file) != 0)
	{
		programa[i].opcode = instruction & 0xFF;
		programa[i].operand = instruction >> 8;
		i++;
	}



	return 0;
}
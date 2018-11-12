#include "myas.h"

#define EAX 21
#define EBX 22
#define ECX 23
#define EDX 24
#define ESI 25
#define ESP 26
#define EDI 27
#define EBP 28

int find_register(char* args){
	int argstype;
	if(args[2]=='a'){

	}
}
int instr_trans(char *op, char *args, char* mcode)
{
	// check syntax
	char* tok;
	char f_args[128];
	char* b_args;
	if(!is_valid(op, args)){
		printf("Error: %s %s is not valid\n", op, args);
		return 0;
	}
	tok=strtok(f_args,",");
	b_args=strtok(NULL,"\0");

	if(f_args[0]=='%'&&b_args[0]=='%')
		strcpy(mcode,"89");
	return 1;
}


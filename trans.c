#include "myas.h"

#define EAX 21
#define EBX 22
#define ECX 23
#define EDX 24
#define ESI 25
#define ESP 26
#define EDI 27
#define EBP 28

extern int is_valid(char *op, char *args); //reference function

int is_register(char* args){
	if(args[0]=='%'&&args[1]=='e')
		return 1;
	else
		return 0;
}
int is_memory(char* args){
	if(args[0]=='('||args[0]=='0')
		return 1;
	else
		return 0;
}
int is_memorydisplay(char* args){
	if(args[strlen(args)-1]==')'&&args[0]!='%'&&args[0]!='(')
		return 1;
	else
		return 0;
}
/*int is_memoryaddress(char* args){
	if(args[0]=='0')
		return 1;
	else
		return 0;
}*/
int what_register(char* args){
	if(args[0]=='%'&&args[1]=='e'){
		if(args[2]=='a')
			return EAX;
		else if(args[2]=='b'){
			if(args[3]=='x')
				return EBX;
			else
				return EBP;
			}
		else if(args[2]=='c')
			return ECX;
		else if(args[2]=='d'){
			if(args[3]=='x')
				return EDX;
			else
				return EDI;
			}
		else if(args[2]=='s'){
			if(args[3]=='p')
				return ESP;
 			else
				return ESI;
			}
		else
			return 0;
			}
	else
		return 0;
}

int instr_trans(char *op, char *args, char* mcode)
{
	// check syntax
	char tok[256];
	char* f_args;
	char* b_args;
	if(!is_valid(op, args)){
		printf("Error: %s %s is not valid\n", op, args);
		return 0;
	}
	strcpy(tok,args);
	f_args= strtok(tok,",");
	b_args= strtok(NULL,"\0");

	if(is_register(f_args)&&is_register(b_args)) //case 1
		strcpy(mcode,"89");
	//else if(is_register(b_args)&&is_memory(f_args)) //case2
		//strcpy(mcode,"8b");
	else if(is_register(b_args)&&is_memorydisplay(f_args)) //case3
		strcpy(mcode,"8b");
	else if(is_memory(f_args)&&what_register(b_args)==EAX)//case4//
		strcpy(mcode,"a1");
	else if(what_register(f_args)==EAX&&is_memory(b_args))//case5/
		strcpy(mcode,"a3");
	else if(f_args[0]=='$'){ //case6
		if(what_register(b_args)==EAX)
			strcpy(mcode,"b8");
		else if(what_register(b_args)==EBX)
			strcpy(mcode,"bb");
		else if(what_register(b_args)==ECX)
			strcpy(mcode,"b9");
		else if(what_register(b_args)==EDX)
			strcpy(mcode,"ba");
		else if(what_register(b_args)==ESP)
			strcpy(mcode,"bc");
		else if(what_register(b_args)==ESI)
			strcpy(mcode,"be");
		else if(what_register(b_args)==EBP)
			strcpy(mcode,"bd");
		else if(what_register(b_args)==EDI)
			strcpy(mcode,"bf");
		else 
			strcpy(mcode,"error");
		}
	else
		strcpy(mcode,"error");		

	return 1;
}

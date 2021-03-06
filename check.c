#include "myas.h"

int find_imm(char* args){ //find immediate
	
	if(args[0]=='$'){
		return 1;
	}
	return 0;
}
int find_memory(char* args){ //find memory
	if(args[0]=='0'||args[0]=='('){
		return 1;
	}
	return 0;
}
int is_valid(char *op, char *args)
{
	char tok[256];
	char* f_args; //front args before ','
	char* b_args; //back args after ','

	strcpy(tok,args); //divide args
	f_args= strtok(tok,",");
	b_args= strtok(NULL,"\0");
	
	//exception case
	if(strcmp(op,"mov")!=0){ //case1 op is not mov 
		return 0;
	}
	else if(find_imm(b_args)){ 
		return 0; //case2 back args is not immediate
	}
	else if((find_imm(f_args))&& 
(find_imm(b_args))) //case3 back,front args are not immediates
	{
		return 0;
	}
	else if(find_memory(f_args)&&find_memory(b_args))
	{ //case 4back,front args are not memories
		return 0;
	}

	return 1; //valid return 1
}

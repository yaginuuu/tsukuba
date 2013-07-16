#include <stdio.h>

void init_stack(void);
int push(unsigned char data);
int pop(void);
int depth(void);
int balance(unsigned char *p);



int balance(unsigned char *p){
	unsigned char c;
	init_stack();
	for( ; (c = *p) != '\0'; p++){
		switch(c){
			case '(':
			case '[':
			case '{':
				push(c);
				break;
			case ')':
				if(pop(c) != '(')
					return(0);
				break;
			case '}':
				if(pop(c) != '{')
					return(0);
				break;
			case ']':
				if(pop(c) != '[')
					return(0);
				break;
			default:
				break;	
		}
	}
	if(depth() == NULL)
		return(1);
	else
		return(0);
}



#define SIZE 100
unsigned char stack[SIZE];
int sp;

void init_stack(void){
	sp = SIZE;
}

int push(unsigned char data){
	if(sp < data)
		return(- 1);

}

int pop(void){
	unsigned char data;
	if(sp == NULL)
		return(- 1);

}

int depth(void){
	return(stack[]);
}
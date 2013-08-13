#include <stdio.h>
#include <stdlib.h>

struct element{
	struct element *link;
	int data;
};

struct elememt *sp = NULL;

void push(int data){
	struct element *e;
	e = (struct element *) malloc(sizeof(struct element));
	e->link = sp;//e->link = sp->link;
	e->data = data;
	sp = e;//sp->link = e;
}

int pop(){
	struct element *target = sp;
	int target_data = target->data;
	sp = target->link;
	free((void *)target);
	return target_data;
}

void sub(void){
	int arg1, arg2, res;
	arg2 = pop();
	arg1 = pop();
	res = arg1 - arg2;
	push(res);
}

void mul(){
	int arg1, arg2, res;
	arg2 = pop();
	arg1 = pop();
	res = arg1 * arg2;
	push(res);
}

void print(void){
	int data;
	data = pop();
	printf("%d\n", data);
}

void swap(void){
	int arg1, arg2;
	arg2 = pop();
	arg1 = pop();
	push(arg2);
	push(arg1);
}

void negate(void){
	push(-1);
	swap();
	mul();
}

int main(int argc, char *grgv[]){
	push(10);
	push(20);
	push(30);
	mul();
	sub();
	print();
}


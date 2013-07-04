#include <stdio.h>
#include <stdlib.h>

struct list{
	char *elem;
	struct list *next;
};

struct list *f(struct list *p, struct list *q){
	struct list *pt = p;
	if(p == NULL)
		return q;
	while(pt->next != NULL)
		pt = pt->next;
	pt->next = q;
	return p; 
}

struct list *cons(char *s, struct list *p){
	struct list *t;
	t = malloc(sizeof (struct list));
	t->elem = s;
	t->next = p;
	return t;
}

void print(struct list *p){
	if(p->next == NULL)
		printf("[ ]\n");
	else{
		printf("[ %s", p->elem);
		for(p = p->next; p->next != NULL; p = p->next)
			printf(", %s", p->elem);
		printf(" ]\n");
	}
}

int main(int argc, char *argv[]){
	struct list *p1, *p2;
	p1 = cons("blue", cons("yellow", cons("red", NULL)));
	p2 = cons("black", cons("white", NULL));
	print(f(p1, p2));
}
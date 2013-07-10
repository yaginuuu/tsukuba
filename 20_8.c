#include <stdio.h>
#include <stdlib.h>

struct list{
	char *elem;
	struct list *next;
};

struct list *f(struct list *p, struct list *q);
struct list *safe_f(struct list *p, struct list *q);
struct list *cons(char *s, struct list *p);
void print(struct list *p);
int length(struct list *p);
int length_r(struct list *p);

// ｆ関数仕様
// int main(int argc, char *argv[]){
// 	struct list *p1, *p2;
// 	p1 = cons("blue", cons("yellow", cons("red", NULL)));
// 	p2 = cons("black", cons("white", NULL));
// 	print(p1);
// 	print(p2);
//  printf("要素の数\n");
// 	printf("%d\n", length(p1));
// 	printf("%d\n", length(p2));
// 	printf("%d\n", length_r(p1));
// 	printf("%d\n", length_r(p2));
//  printf("結合\n");
// 	print(f(p1, p2));
// }

// safe_f関数仕様
int main(int argc, char *argv[]){
	struct list *p1, *p2;
	p1 = cons("blue", cons("yellow", cons("red", NULL)));
	p2 = cons("black", cons("white", NULL));
	print(p1);
	print(p2);
	printf("要素の数\n");
	printf("%d\n", length(p1));
	printf("%d\n", length(p2));
	printf("%d\n", length_r(p1));
	printf("%d\n", length_r(p2));
	printf("結合\n");
	print(safe_f(p1, p1));
}

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
		//条件をp->next != NULLにしてた。間違い。
		for(p = p->next; p != NULL; p = p->next)
			printf(", %s", p->elem);
		printf(" ]\n");
	}
}

int length_r(struct list *p){
	//条件をp->next == NULLにしてた。間違い。
	if(p == NULL)
		return 0;
	else
		return 1 + length_r(p->next);
}	

int length(struct list *p){
	int n = 0;
	//条件をp->next != NULLにしてた。間違い。
	while(p != NULL){
		n++;
		p = p->next;
	}
	return n;
}

struct list *safe_f(struct list *p, struct list *q){
	struct list *pt = q;
	if(p == NULL){
		if(q == NULL)
			return NULL;
		else 
			return cons(pt->elem, safe_f(NULL, pt->next));
	}else{
		return cons(p->elem, safe_f(p->next, pt));// safe_f関数で、pt->nextにしていた。
	}
}
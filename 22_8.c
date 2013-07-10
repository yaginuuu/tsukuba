#include <stdio.h>
#include <stdlib.h>

struct list{
	int data;
	struct list *next;
};
struct list *head = NULL;

int sum_list(void);
void insert_list(int x);
void delete_list(int x);

int main(){
	struct list *p;

	int ary[] = {4, 7, 5, 9, 10, 44, 22, 5};
	int i, x;

	for(i = 0; i < 8; i++){
		insert_list(ary[i]);
	}
	for(p = head; p != NULL; p = p->next){
		printf("%d ", p->data);
	}
	printf("\n");

	printf("sum = %d\n", sum_list());
	printf("\n");

	printf("delete number?: ");
	scanf("%d", &x);
	delete_list(x);
	printf("after delete: ");
	for(p = head; p != NULL; p = p->next){
		printf("%d ", p->data);
	}
	printf("\n");
}

int sum_list(void){
	struct list *p;
	int sum;

	sum = 0;
	p = head;
	while(p != NULL){
		sum += p->data;
		p = p->next;
	}
	return sum;
}

void insert_list(int x){
	struct list *p, *q, *t;

	q = NULL;
	for(p = head; p != NULL; p = p->next){
		if(p->data >= x)
			break;//ifの条件になった場合ループからでる！
		q = p;
	}

	t = (struct list *)malloc(sizeof(struct list));
	t->data = x;

	if(q == NULL)
		head = t;
	else
		q->next = t;
	t->next = p;
}

void delete_list(int x){
	struct list *p, *q;

	q = NULL;
	for(p = head; p != NULL; p = p->next){
		if(p->data == x){
			if(q == NULL)
				head = NULL;
			else
				q->next = p->next;
			free(p);
			return;
		}
		q = p;
	}
}
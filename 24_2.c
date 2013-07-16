#include <stdio.h>

struct queue *make_queue();
void enqueue(struct queue *q, int data);
int dequeue(struct queue *q);
int is_empty(struct queue * q);
void destroy_queue(struct queue *q);

struct element{
	struct element *next;
	int data;
};

struct queue{
	struct element *head;
	struct element *tail;
};

struct queue *make_queue(){
	struct queue *q;
	q = malloc(sizeof(struct queue));
	q->head = NULL;
	q->tail = NULL;
	return(q);
}

int is_empty(struct queue *q){
	return()
}

int dequeue(struct queue *q){
	struct element *element;
	int data;
	if(is_empty(q)){
		return(- 1);
	}
}
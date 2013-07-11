#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
};
struct node *root = NULL;

struct node *insert_node(int x, struct node *p);
int sum_node(struct node *p);
int search_node(int x, struct node *p);
int node_print(struct node *p);

int main(){
	int ary[] = {22, 34, 55, 12, 33, 44, 54, 66, 77, 10};
	int i, search_num;

	for (i = 0; i < 10; i++) {
    root = insert_node(ary[i], root);
  }

  printf("＜帰りがけ順に表示＞\n");
  node_print(root);
  printf("合計 : %d\n", sum_node(root));
  while(1) {
    printf("検索したい数値を入力して下さい。(-1を入力することで検索を終了)\n");
    printf(" ⇒ ");
    scanf("%d", &search_num);
    if (search_num == -1)
      break;
    else if (search_node(search_num, root) == 0)
      printf("検索結果 : 入力された数値は存在しません。\n");
    else
      printf("検索結果 : 入力された数値は存在します。\n");
  }
}

struct node *insert_node(int x, struct node *p){
	if(p == NULL){
		p = (struct node *)malloc(sizeof(struct node));
		p->data = x;
		p->left = NULL;
		p->right = NULL;

		return p;
	}

	if(x == p->data)
		return p;

	if(x < p->data)
		p->left = insert_node(x, p->left);
	else
		p->right = insert_node(x, p->right);

	return p;
}

int sum_node(struct node *p){
	if(p == NULL)
		return 0;

	return p->data + sum_node(p->left) + sum_node(p->right); 
}

int search_node(int x, struct node *p){
	struct node *q;

	q = p;
	while(q != NULL){//while(p != NULL){
		if(x == q->data)
			return 1;
		if(x < q->data)
			q = q->left;//q = search_node(x, p->left);
		else
			q = q->right;//q = search_node(x, p->right);
	}
	return 0;
}

int node_print(struct node *p) {
  if (p == NULL)
    return 0;

  node_print(p->left);
  printf("%d\n", p->data);
  node_print(p->right);
  return 0;
}


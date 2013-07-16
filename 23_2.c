#include <stdio.h>

heap_t make_heap(void);
void heap_add(heap_t, int);
int heap_delete_min(heap_t);
void sort1(int a[], int n);
void sort2(int a[], int n);
void swap(int *x, int *y);
void shift_up(int b[], int n);
void shift_down(int b[], int i, int size);

struct heap_t{

	int data;
	struct heap_t left_node;
	struct heap_t right_node;
};

void sort1(int a[], int n){
	int i;
	heap_t heap = make_heap();
	for(i = 0; i < n; i++)
		heap_add(heap, a[i]);
	for(i = 0; i < n; i++)
		a[n - (i + 1)] = heap_delete_min;
}

//ポインタを交換してるのではなく、ポインタの参照先を交換してるので、 ＊が必要
void swap(int *x, int *y){
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

//問題shift_up関数
void shift_up(int b[], int n){
	int parent;
	if(n == 0)
		return;
	else{
		parent = (n - 1) / 2;
		if(b[n] >= b[parent])
			return;
		else{
			swap(&b[n], &b[parent]);
			shift_up(b, parent);
		}
	}
}

void shift_down(int b[], int i, int size){
	int left = 2 * i + 1
	int right = 2 * i + 2;
	int smallest = i;
	if(right < size && b[right] < b[smallest])
		smallest = right;
	if(left < size && b[left] < b[smallest])
		smallest = left; 
	if(smallest != i){
		swap(&b[smallest], &b[i]);//iを０としてしまった。ミス。。
		shift_down(b, smallest, size);
	}

}

void sort2(int a[], int n){
	int i;
	for(i = 0; i < n; i++){
		
	}
}











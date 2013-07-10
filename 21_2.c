#include <stdio.h>

void print_array(int a[], int n);
void insertion_sort(int a[], int n);
void shift(int a[], int first, int last);
void insertion_sort_d(int a[], int n, int d);
void shell_sort(int a[], int n);
void shift_d(int a[], int first, int last, int d);

int array1[] = {80, 35, 15, 40, 65};
int dim[] = {1, 2, 4};

// int main(){
// 	insertion_sort(array1, 5);
// }
int main(){
	shell_sort(array1, 5);
}

void print_array(int a[], int n){
	int i;
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void insertion_sort(int a[], int n){
	int w, i, j;
	if(n <= 1)
		return;
	for(i = 1; i < n; i++){
		printf("i == %d: ", i);
		print_array(a, n);
		w = a[i];
		for(j = 0; j < i && a[j] < w; j++)
			continue;
		shift(a, j, i);
		a[j] = w;
	}
	printf("i == %d: ", i);
	print_array(a, n);
}

void shift(int a[], int first, int last){
	int p;
	//(p = last - 1; last > first; last--)としていた。ミス。
	for(p = last - 1; first <= p; p--){
		a[p + 1] = a[p];
	}
}



void insertion_sort_d(int a[], int n, int d){
	int w, i, j, k;
	if(n <= d)
		return;
	for(k = 0; k < d - 1; k = ){
		for(i = d + k; i < ){
			w = a[i];
			for(j = k;)
				continue;
			shift_d(a, j, i, d);
			a[j] = w;
		}
	}
}

shell_sort(int a[], int n){
	int l;
	//sizeofを↓のようにすると配列の要素数を検出できる
	for(l = sizeof(dim) / sizeof(dim[0]) - 1; l >= 0; l--){
		insertion_sort_d(a, n, dim[l]);
	}
}

void shift_d(int a[], int first, int last, int d){
	int q;
	for(q = last - d; first <= q; q -= d)
		a[a + d] = a[q];
}









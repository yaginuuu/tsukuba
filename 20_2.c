#include <stdio.h>

void is(int sz, int d[]);

int main(){
	int d[] = {2, 5, 6, 4, 9, 3, 7, 10, 33, 1};
	int sz, i = 0;

	printf("number?:");
	scanf("%d\n", &sz);//配列入力時は＆つけなくてよい。
	is(sz, d);//void関数は返り値がない
	for(i = 0; i < sz; i++){
		printf("%d, ", d[i]);
	}
}
         
void is(int sz, int d[]){
	int i, j, m;

	for(i = 1; i < sz; i++){
		m = d[i];
		for(j = i - 1; j >= 0 && d[j] >= m; j--)
			d[j + 1] = m;
		d[j + 1] = d[j];
	}
}


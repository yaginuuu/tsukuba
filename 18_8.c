#include <stdio.h>

#define N 1000

void divisor(int n);
int is_perfect(int n);

int main(){
	int i, j, sum[N + 1];
	int m, n;

	for(i = 1; i <= N; i++)
		sum[i] = 0;

	for(j = 1; j <= N / 2; j++){
		for(i = 1; i < j; i++){
			if(j % i == 0)
				sum[j] += i;
		}
	}

	for(i = 1; i <= N; i++){
		if(sum[i] == i)
			printf("%d\n", i);
	}

	printf("数字を入力してください。\n");
	scanf("%d", &m);
	printf("正の約数は以下です。。。\n");
	divisor(m);

	printf("完全数かどうかを判定します。\n1であれば完全数、そうでなければ0です。\n数字を入力してください。\n");
	scanf("%d", &n);
	is_perfect(n);

	return 0;
}

//すべての約数を求める関数
//約数とはその数を割り切ることができるすべての数
void divisor(int n){
	int x = 1;
	while(x <= n){
		if(n % x == 0)
			printf("%d\n", x);
		x++;
	}
}

int is_perfect(int n){
	int i, sum;

	if(n <= 0)
		return 0;

	sum = 0;
	for(i = 1; i < n; i++){
		if(n % i == 0)
			sum += i;
	}

	if(sum == n){
		printf("1\n");
		return 1;
	}else{
		printf("0\n");
		return 0;
	}
}
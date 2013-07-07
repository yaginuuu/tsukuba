#include <stdio.h>

#define N 1000

int main(){
	int i, j, sum[N + 1];

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

	return 0;
}
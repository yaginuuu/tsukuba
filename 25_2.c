#include <stdio.h>

#define N 6
#define M 100

typedef enum {FALSE = 0, TRUE = 1}Bool;
struct vertices{
	Bool Vertex[N];
	int Vcount;
};

void set_vertices(struct vertices *v, Bool b);
Bool remain(struct vertices *v);
Bool member(int x, struct vertices *v);
int select_min(int d[], struct vertices *v);
void add_vertex(int x, struct vertices *v);
void remove_vertex(int x, struct vertices *v);
void Dijkstra(int p, int w[N][N], int d[N]);

int main(){
	int i;
	int w[N][N] = {
				{0, M, M, 60, M, 5},
				{5, 0, 6, M, 50, M},
				{M, M, 0, 5, M, M},
				{M, M, M, 0, 5, M},
				{30, M, 20, M, 0, M},
				{M, 40, M, M, 5, 0}
			};

	int d[] = {0};

	Dijkstra(1, w, d);

	printf("3_b is this: ");
	for(i = 0; i < N; i++){
		printf("%d, ", d[i]);
	}
	printf("\n");
}

void set_vertices(struct vertices *v, Bool b){
	int i;
	for(i = 0; i < N; i++)
		v->Vertex[i] = b;
	if(b == TRUE)
		v->Vcount = N;
	else
		v->Vcount = 0;
}

Bool remain(struct vertices *v){
	if(v->Vcount)
		return TRUE;
	return FALSE;
}

Bool member(int x, struct vertices *v){
	return v->Vertex[x];
}

int select_min(int d[], struct vertices *v){
	int i, j;
	int x = M;  //←でxにMを代入しておく
	for(i = 0; i < N; i++){
		if(v->Vertex[i] && d[i] < x){
			x = d[i];
			j = i;
		}
	}
	return j;
}

void add_vertex(int x, struct vertices *v){
	v->Vertex[x] = TRUE;
	v->Vcount++;
}

void remove_vertex(int u, struct vertices *v){
	v->Vertex[u] = FALSE;
		v->Vcount--;
}

void Dijkstra(int p, int w[N][N], int d[N]){
	int i, u, x, k;
	struct vertices U, V;

	set_vertices(&V, FALSE);
	set_vertices(&U, TRUE);
	for(i = 0; i < N; i++)
		d[i] = M;
	d[p] = 0;

	while(remain(&U)){
		u = select_min(d, &U);
		printf("u = %d\n", u);
		add_vertex(u, &V);
		remove_vertex(u, &U);
		for(x = 0; x < N; x++){
			if(w[u][x] < M && member(x, &U)){
				k = d[u] + w[u][x];
				if(k < d[x])
					d[x] = k;
			}
		}
	}	
}


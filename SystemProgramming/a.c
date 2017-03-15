#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int n, a[100][100], b[100][100], c[100][100];

struct MatrixBlock {
	int n;
	// Memory limit if size equal to 100
	int a[8][8];
} res[4], mA[4], mB[4];

struct MatrixBlock mult(struct MatrixBlock a, struct MatrixBlock b) {
	struct MatrixBlock c;
	for (int i = 0; i < a.n; i++)
		for (int j = 0; j < a.n; j++)
			c.a[i][j] = 0;
	c.n = a.n;
	
	for (int i = 0; i < a.n; i++)
		for (int j = 0; j < a.n; j++)
			for (int k = 0; k < a.n; k++)
				c.a[i][j] += a.a[i][k] * b.a[k][j];
	return c;
}

struct MatrixBlock sum(struct MatrixBlock a, struct MatrixBlock b) {
	struct MatrixBlock c;
	c.n = a.n;
	
	for (int i = 0; i < a.n; i++)
		for (int j = 0; j < a.n; j++)
			c.a[i][j] = a.a[i][j] + b.a[i][j];
	return c;
}	
int cnt = 0;

static void *multBlock(void *void_blockNum) {
	int blockNum = *(int *)void_blockNum;
	if (blockNum == 0) {
		res[0] = sum(mult(mA[0], mB[0]), mult(mA[1], mB[2]));
	}
	if (blockNum == 1) {
		res[1] = sum(mult(mA[0], mB[1]), mult(mA[1], mB[3]));
	}
	if (blockNum == 2) {
		res[2] = sum(mult(mA[2], mB[0]), mult(mA[3], mB[2]));
	}
	if (blockNum == 3) {
		res[3] = sum(mult(mA[3], mB[3]), mult(mA[2], mB[1]));
	}
	return NULL;
}

int tID[4];
pthread_t th[4];

int main() {

	FILE * file;
	file = fopen("in", "r");

	fscanf(file, "%d", &n);
	int s = n / 2;
	for (int i = 0; i < 4; i++) tID[i] = i, mA[i].n = mB[i].n = s;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			fscanf(file, "%d", &a[i][j]);
			mA[i / s * 2 + j / s].a[i % s][j % s] = a[i][j];
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			fscanf(file, "%d", &b[i][j]);
			mB[i / s * 2 + j / s].a[i % s][j % s] = b[i][j];
		}


	for (int i = 0; i < 4; i++) {
		int res = pthread_create(&th[i], NULL, &multBlock, &tID[i]);
		if (res != 0) {
			printf("Error");
			return 0;
		}
	}

	for (int tID = 0; tID < 4; tID++) {
		if (pthread_join(th[tID], NULL)) {
			printf("Error(join)");
			return 0;
		}	
	}

	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%d ", res[i / s + j / s].a[i % s][j % s]);
		printf("\n");
	}
	return 0;
}

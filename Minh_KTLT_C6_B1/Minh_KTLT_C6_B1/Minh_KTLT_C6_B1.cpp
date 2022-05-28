// Minh_KTLT_C6_B1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "conio.h"
#include "cstdlib"
#include "time.h"

int SoNgauNhien(int min, int max) {
	return min + rand() % (max - min + 1);
}

void InputRC(int &row) {
	printf("Row:");
	scanf_s("%d", &row);
}

void Input(int **&a, int row) {
	a = new int*[row];
	for (int i = 0; i < row; i++) {
		a[i] = new int[row];
		for (int j = 0; j < row; j++) {
			/*a[i][j] = SoNgauNhien(0, 99);*/
			printf("A[%d][%d]: ", i, j);
			scanf_s("%d", &a[i][j]);
		}
		printf("\n");
	}
}

void Output(int **a, int row) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < row; j++) {
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
}

int SumRow(int **a, int row) {
	int total;
	for (int i = 0; i < row; i++) {
		total = 0;
		for (int j = 0; j < row; j++) {
			total += a[i][j];
		}
	}
	return total;
}

int SumColumn(int **a, int row) {
	int total;
	for (int i = 0; i < row; i++) {
		total = 0;
		for (int j = 0; j < row; j++) {
			total += a[j][i];
		}
	}
	return total;
}

int SumMainCross(int **a, int row) {
	int total = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < row; j++) {
			if (i == j)
				total += a[i][j];
		}
	}
	return total;
}

int SumSideCross(int **a, int row) {
	int total = 0;
	for (int i = 0; i < row; i++) {
		int j = row - i - 1;
		total += a[i][j];
	}
	return total;
}

void ktMaTranMaPhuong(int **a, int row) {
	if (SumRow(a, row) == SumColumn(a, row) && SumMainCross(a, row) == SumSideCross(a, row))
		printf("\nMa Tran nay la Ma Tran Ma Phuong!");
	else
		printf("\nMa Tran nay khong phai la Ma Tran Ma Phuong!");
}

void main() {
	int **a;
	int row;
	InputRC(row);
	Input(a, row);
	Output(a, row);
	ktMaTranMaPhuong(a, row);
	_getch();
}


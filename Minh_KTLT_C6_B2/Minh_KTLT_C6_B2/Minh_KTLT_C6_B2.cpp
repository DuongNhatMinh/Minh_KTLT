// Minh_KTLT_C6_B2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "conio.h"
#include "cstdlib"
#include "time.h"
#include "Windows.h"

int SoNgauNhien(int min, int max) {
	return min + rand() % (max - min + 1);
}

void InputRC(int &row, int &column) {
	do {
		printf("Row: ");
		scanf_s("%d", &row);
	} while (row < 1 || row > 50);
	do {
		printf("Column: ");
		scanf_s("%d", &column);
	} while (row < 1 || column > 50);
}

void Input(int **&a, int row, int column) {
	a = new int*[row];
	for (int i = 0; i < row; i++) {
		a[i] = new int[column];
		for (int j = 0; j < column; j++) {
			a[i][j] = SoNgauNhien(0, 99);
			/*printf("A[%d][%d]: ", i, j);
			scanf_s("%d", &a[i][j]);*/
		}
	}
}

void Output(int **a, int row, int column) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
}

int ktMaxColumn(int **a, int row, int posR, int posC) {
	for (int i = 0; i < row; i++) {
		if (a[posR][posC] < a[i][posC])
			return 0;
	}
	return 1;
}

int ktMaxRow(int **a, int column, int posR, int posC) {
	for (int i = 0; i < column; i++) {
		if (a[posR][posC] < a[posR][i])
			return 0;
	}
	return 1;
}

int ktMaxMainCross(int **a, int row, int column, int posR, int posC) {
	int i = posR - 1;
	int j = posC - 1;
	while (i >= 0 && j >= 0) {
		if (a[posR][posC] < a[i][j])
			return 0;
		i--;
		j--;
	}
	i = posR + 1;
	j = posC + 1;
	while (i < row && j < column) {
		if (a[posR][posC] < a[i][j])
			return 0;
		i++;
		j++;
	}
	return 1;
}

int ktMaxSideCross(int **a, int row, int column, int posR, int posC) {
	int i = posR - 1;
	int j = posC + 1;
	while (i >= 0 && j < column) {
		if (a[posR][posC] < a[i][j])
			return 0;
		i--;
		j++;
	}
	i = posR + 1;
	j = posC - 1;
	while (i < row && j >= 0) {
		if (a[posR][posC] < a[i][j])
			return 0;
		i++;
		j--;
	}
	return 1;
}

int isQueen(int **a, int row, int column, int posR, int posC) {
	if (!ktMaxColumn(a, row, posR, posC))
		return 0;
	if (!ktMaxRow(a, column, posR, posC))
		return 0;
	if (!ktMaxMainCross(a, row, column, posR, posC))
		return 0;
	if (!ktMaxSideCross(a, row, column, posR, posC))
		return 0;
	return 1;
}

void PoinQueen(int **a, int row, int column) {
	int posR, posC;
	int max;
	int flag = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (isQueen(a, row, column, i, j)) {
				max = a[i][j];
				posR = i;
				posC = j;
				flag = 1;
			}
		}
		if (flag == 1) {
			printf("Gia Tri Queen: %d", max);
			printf("\nVi Tri Queen: A[%d][%d]\n", posR, posC);
		}
		flag = 0;
	}
}

void main() {
	int **a;
	int row, column;
	InputRC(row, column);
	Input(a, row, column);
	Output(a, row, column);
	PoinQueen(a, row, column);
	_getch();
}


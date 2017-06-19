// Knut-Moris-Pratt.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"

#include <iostream>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
using namespace std;

int algorithm_KMP(char s[], char q[])
{
	int  i = 0, j = -1, N, M;
	N = strlen(s);
	M = strlen(q);
	int *d = (int*)malloc(M * sizeof(int)); // ������������ ������ ����� �
											/* ���������� �������-������� */
	d[0] = -1;
	while (i < M - 1)
	{
		while ((j >= 0) && (q[j] != q[i]))
			j = d[j];
		i++;
		j++;
		if (q[i] == q[j])
			d[i] = d[j];
		else
			d[i] = j;
	}
	/* ����� */
	for (i = 0, j = 0; (i < N) && (j < M); i++, j++)
		while ((j >= 0) && (q[j] != s[i]))
			j = d[j];
	free(d);  /* ������������ ������ ������� d */
	if (j == M)
		return i - j;
	else /* i==N */
		return -1;
}

void main()
{
	SetConsoleCP(1251); // ���� � ������� � ��������� 1251
	SetConsoleOutputCP(1251); // ����� �� ������� � ��������� 1251.
	//����� ������ ����� �������� ����� ������� �� Lucida Console ��� Consolas
	setlocale(LC_ALL, "Russian_Russia.1251");
	const int n = 10;

	srand((unsigned)time(NULL));
	char s[1024];

	cout << "������� ������ ��� ������:\n";
	cin.getline(s, 256);

	char q[256];

	cout << "������� ��������� ��� ������:\n";
	cin.getline(q, 256);

	int a, mas[n] = { 0 };
	a = algorithm_KMP(s, q);
	if (a == -1)
		cout << "��������� �� �������\n\n";
	else
		cout << "��������� ���������� � ������� " << a << " � ������" << endl;

	system("pause");
}
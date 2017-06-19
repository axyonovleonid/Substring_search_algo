// Knut-Moris-Pratt.cpp: определяет точку входа для консольного приложения.
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
	int *d = (int*)malloc(M * sizeof(int)); // динамический массив длины М
											/* Вычисление префикс-функции */
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
	/* поиск */
	for (i = 0, j = 0; (i < N) && (j < M); i++, j++)
		while ((j >= 0) && (q[j] != s[i]))
			j = d[j];
	free(d);  /* освобождение памяти массива d */
	if (j == M)
		return i - j;
	else /* i==N */
		return -1;
}

void main()
{
	SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
	SetConsoleOutputCP(1251); // Вывод на консоль в кодировке 1251.
	//Нужно только будет изменить шрифт консоли на Lucida Console или Consolas
	setlocale(LC_ALL, "Russian_Russia.1251");
	const int n = 10;

	srand((unsigned)time(NULL));
	char s[1024];

	cout << "Введите строку для поиска:\n";
	cin.getline(s, 256);

	char q[256];

	cout << "Введите подстроку для поиска:\n";
	cin.getline(q, 256);

	int a, mas[n] = { 0 };
	a = algorithm_KMP(s, q);
	if (a == -1)
		cout << "Подстрока не найдена\n\n";
	else
		cout << "Подстрока начинается с индекса " << a << " в тексте" << endl;

	system("pause");
}
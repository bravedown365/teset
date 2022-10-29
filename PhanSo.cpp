#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "PhanSo.h"
using namespace std;


PhanSo::PhanSo(int t, int m)
{
	tuso = t;
	mauso = m;
}
void PhanSo::Nhap()
{
	printf("Tử số: ");
	scanf("%d", &tuso);
	printf("Mẫu số: ");
	scanf("%d", &mauso);
}
void PhanSo::Xuat()const
{
	printf("%d", tuso);
	printf("/");
	printf("%d", mauso);
}
int USCLN(int a, int b)
{
	int r;
	while (b != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}
void PhanSo::ToiGian()
{
	int us = USCLN(tuso, mauso);

	tuso = tuso / us;
	mauso = mauso / us;

	if (mauso < 0)
	{
		tuso = -tuso;
		mauso = -mauso;
	}
}

PhanSo PhanSo::Cong(const PhanSo& b)
{
	return PhanSo(tuso * b.mauso + mauso * b.tuso, mauso * b.mauso);
}

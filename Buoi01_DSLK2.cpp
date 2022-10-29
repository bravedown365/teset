#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Buoi01_DSLK2.h"
using namespace std;
/******* NodePS ********/
//Phương thức thiết lập
NodePS::NodePS()
{
	next = NULL;
}

//Tạo NodePS từ Node PS PS
NodePS* createNodePS(PhanSo PS)
{
	NodePS* p = new NodePS;

	if (p == NULL)
	{
		printf("Not enough memory to allocate!");
		return NULL;
	}

	p->info.tuso = PS.tuso;
	p->info.mauso = PS.mauso;
	p->next = NULL;

	return p;
}
/////Xóa NodePS
void deleteNodePS(NodePS*& p)
{
	if (p == NULL)	return;

	p->next = NULL;
	delete p;
}
/////Xuất nội dung nút
void ShowNodePS(NodePS* p)
{
	p->info.Xuat();
}

/***** SList ******/
//Phương thức thiết lập
SListPS::SListPS()
{
	head = NULL;
	tail = NULL;
}
//b. Kiểm tra danh sách rỗng
bool isEmptySListPS(SListPS l)
{
	return l.head == NULL;
}
//c. Duyệt danh sách để xuất nội dung ra màn hình
void traverseSListPS(SListPS l)
{
	if (isEmptySListPS(l))
	{
		printf("List is empty");
		return;
	}

	for (NodePS* p = l.head; p != NULL; p = p->next)
	{
		p->info.Xuat();
		cout << '\t';
	}
}
//Thêm nút phân số p vào đầu danh sách
void addHeadSListPS(SListPS& l, NodePS* p)
{
	if (p == NULL)	return;

	if (isEmptySListPS(l))
		l.head = l.tail = p;
	else
	{
		p->next = l.head;
		l.head = p;
	}
}
//2h. Viết hàm trả về SNode chứa phân số p trong danh sách liên kết. Nếu không có p trong DSLK thì trả về NULL
NodePS* searchNodePS(SListPS l, PhanSo PS)
{
	if (isEmptySListPS(l))
	{
		cout << "List is empty.\n";
		return NULL;
	}
	
	PS.ToiGian();
	for (NodePS* p = l.head; p != NULL; p=p->next)
		if ((p->info.tuso == PS.tuso) && (p->info.mauso == PS.mauso))
			return p;
	return NULL;
}


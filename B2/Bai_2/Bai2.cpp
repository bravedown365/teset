#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Header.h"
#include <stdlib.h>
#include <string.h>
#include <iomanip>

using namespace std;

Node::Node()
{
	info.time = 0;
	next = NULL;
}

Node::Node(Data item, Node *link)
{
	info = item;
	next = link;
}

void Node::showNode()
{
	cout << "\t"
		 << setw(20) << left << info.author
		 << setw(35) << left << info.name
		 << setw(25) << left << info.singer
		 << setw(10) << left << info.time;
}

void xoaXuongDong(char str[])
{
	size_t len = strlen(str);

	int i;
	for (i = 0; i <= len; i = i + 1)
	{
		if (str[i] == '\n')
		{
			str[i] = ' ';
		}
	}
}
void inputData(Data &p)
{
	cout << "\nNhap ten bai hat:";
	rewind(stdin);
	fgets(p.name, 100, stdin);
	xoaXuongDong(p.name);

	cout << "\nNhap ten tac gia:";
	rewind(stdin);
	fgets(p.author, 100, stdin);
	xoaXuongDong(p.author);

	cout << "\nNhap ten ca si:";
	rewind(stdin);
	fgets(p.singer, 100, stdin);
	xoaXuongDong(p.singer);

	cout << "\nNhap thoi luong bai hat:";
	cin >> p.time;
}

Node *createNode(Data &so)
{
	Node *p = new Node();
	if (p == NULL)
	{
		cout << "Het bo nho nha";
		return NULL;
	}
	strcpy(p->info.name, so.name);
	strcpy(p->info.author, so.author);
	strcpy(p->info.singer, so.singer);
	p->info.time = so.time;
	p->next = NULL;
	return p;
}

void addNodeHead(SList &l, Node *p)
{
	if (l.head == NULL)
	{
		cout << endl
			 << "Hong co gi het";
		return;
	}
	if (p == NULL)
		return;
	p->next = l.head;
	l.head = p;
}

void addNodeLast(SList &l, Node *p)
{
	if (p == NULL)
		return;
	if (l.head == NULL)
		l.head = l.tail = p;
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
}

void AddNew(SList &l, Node *p)
{
	if (l.head == NULL)
	{
		cout << endl
			 << "Hong co gi het";
		return;
	}

	Data so1;
	inputData(so1);
	addNodeLast(l, createNode(so1));

	Data so2;
	inputData(so2);
	addNodeHead(l, createNode(so2));
}

Node *chonNode(SList &l, int n)
{
	if (l.head == NULL)
	{
		cout << endl
			 << "Hong co gi het";
		return NULL;
	}
	Node *p = l.head;
	for (int i = 2; i <= n; i++)
	{
		if (n == i)
			return p;
		p = p->next;
	}
	return NULL;
}

void deleteHead(SList &l)
{
	if (l.head == NULL)
	{
		cout << endl
			 << "Hong co gi het";
		return;
	}
	Node *p = l.head;
	l.head = p->next;
	p->next = NULL;
	delete p;
}

void deleteNode(SList &l, Node *p)
{
	if (l.head == NULL)
	{
		cout << endl
			 << "Hong co gi het";
		return;
	}

	Node *after_p = p->next;
	p->next = after_p->next;
	after_p->next = NULL;

	delete after_p;
}

void setSList(SList &l)
{
	l.head = l.tail = NULL;
}

void menu()
{
	cout << endl
		 << "\t\tMENU";
	cout << endl
		 << "01. Cau a";
	cout << endl
		 << "02. Cau b";
	cout << endl
		 << "03. Cau c";
	cout << endl
		 << "04. Cau d";
	cout << endl
		 << "05. Cau e";
	cout << endl
		 << "06. Cau f";
	cout << endl
		 << "07. Cau g";
	cout << endl
		 << "08. Cau h";
	cout << endl
		 << "09. Cau i";
	cout << endl
		 << "00. Thoat";
}

Data read_One(FILE *file, Data &p)
{
	fscanf(file, "%[^#]#%[^#]#%[^#]#%d\n", &p.name, &p.author, &p.singer, &p.time);
	return p;
}

void readSList(SList &l)
{
	setSList(l);
	int n;
	FILE *file;
	file = fopen("Bai_2.txt", "rt");

	if (file == NULL)
	{
		cout << endl
			 << "Failed to open this file!";
		return;
	}
	else
		cout << endl
			 << "Opened file";
	fscanf(file, "%d\n", &n);
	for (int i = 0; i < n; i++)
	{
		Data so;
		read_One(file, so);
		addNodeLast(l, createNode(so));
	}
	fclose(file);
}

void printfSList(SList l)
{
	if (l.head == NULL)
		return;
	Node *p = l.head;
	while (p != NULL)
	{
		cout << endl;
		p->showNode();
		p = p->next;
	}
}

int sumTime(SList l)
{
	if (l.head == NULL)
	{
		cout << endl
			 << "Hong co gi het";
		return 0;
	}
	int sum = 0;

	Node *p = l.head;
	while (p != NULL)
	{
		sum += p->info.time;
		p = p->next;
	}

	return sum;
}

bool checkX(SList l)
{
	char x[51];
	cout << "\nNhap x:";
	rewind(stdin);
	fgets(x, 100, stdin);
	xoaXuongDong(x);
	cout << "\n"
		 << x << x;
	if (x[strlen(x) - 1] == ' ')
	{
		x[strlen(x) - 1] = '\0';
	}
	cout << "\n"
		 << x << x;
	Node *p = l.head;
	while (p != NULL)
	{
		if (strcmp(p->info.name, x) == 0)
			return true;
		p = p->next;
	}
	return false;
}

void sortAZ(SList &l)
{
	if (l.head == NULL)
	{
		cout << endl
			 << "Hong co gi het";
		return;
	}
	Node *p = l.head;
	while (p != l.tail)
	{
		Node *q = p->next;
		while (q != NULL)
		{
			if (strcmp(p->info.name, q->info.name) > 0)
				swap(p->info, q->info);
			q = q->next;
		}
		p = p->next;
	}
}

void sortDownSinger(SList &l)
{
	if (l.head == NULL)
	{
		cout << endl
			 << "Hong co gi het";
		return;
	}
	Node *p = l.head;
	while (p != l.tail)
	{
		Node *q = p->next;
		while (q != NULL)
		{
			if (strcmp(p->info.singer, q->info.singer) < 0)
				swap(p->info, q->info);
			q = q->next;
		}
		p = p->next;
	}
}

void upHeadSong(SList &l)
{
	if (l.head == NULL)
	{
		cout << endl
			 << "Hong co gi het";
		return;
	}
	int n;
	cout << endl
		 << "Chon vi tri bai hat:";
	cin >> n;
	Node *p = l.head,
		 *q = chonNode(l, n);

	while (p != l.tail)
	{
		if (p == q)
		{
			q = p->next;
			p->next = p->next->next;
			addNodeHead(l, q);
			break;
		}
		p = p->next;
	}
}

int main()
{
	SetConsoleOutputCP(CP_UTF8);
    system("cls");
	
	int option;
	SList l;
	while (1)
	{
		do
		{
			system("cls");
			menu();
			cout << endl
				 << "Nhap lua chon: ";
			cin >> option;
			if (option < 0 || option > 9)
			{
				cout << endl
					 << "Nhap khong hop le!";
				_getch();
			}
		} while (option < 0 || option > 9);

		if (option == 0)
			break;

		switch (option)
		{
		case 1:
		{
			readSList(l);
			break;
		}
		case 2:
		{
			printfSList(l);
			break;
		}
		case 3:
		{
			cout << endl
				 << "Thoi gian de nghe het nhac la:" << sumTime(l);
			break;
		}
		case 4:
		{
			Data so;
			AddNew(l, createNode(so));
			printfSList(l);
			break;
		}
		case 5:
		{
			int n;
			cout << endl
				 << "Chon vi tri bai hat:";
			cin >> n;
			if (n == 1)
				deleteHead(l);
			else
				deleteNode(l, chonNode(l, n));
			printfSList(l);
			break;
		}
		case 6:
		{
			if (checkX(l) == true)
				cout << endl
					 << "Co X";
			else
				cout << endl
					 << "Hong co X";
			break;
		}
		case 7:
		{
			sortAZ(l);
			printfSList(l);
			break;
		}
		case 8:
		{
			sortDownSinger(l);
			printfSList(l);
			break;
		}
		case 9:
		{
			upHeadSong(l);
			printfSList(l);
			break;
		}
		}
		getch();
	}
}
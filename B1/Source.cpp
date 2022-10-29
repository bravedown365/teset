#include "LinkedList.h"

Node::Node()
{
	info = 0;
	next = NULL;
};

Node::Node(Data item, Node *link)
{
	info = item;
	next = link;
}

void Init(List &l)
{
	l.head = l.tail = NULL;
}

Node *CreatNode(int x)
{
	Node *p = new Node;
	if (p == NULL)
	{
		cout << "Khong du bo nho" << endl;
		system("pause");
		return NULL;
	}
	p->info = x;
	p->next = NULL;
	return p;
}

void AddHead(List &l, Node *p)
{
	if (l.head == NULL)
	{
		l.head = l.tail = p;
	}
	else
	{
		p->next = l.head;
		l.head = p;
	}
}

void AddTail(List &l, Node *p)
{
	if (l.tail == NULL)
	{
		l.head = l.tail = p;
	}
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
}

void CreateList(List &l)
{
	int n, x;
	Init(l);
	do
	{
		cout << "Nhap so phan tu cua DS: ";
		cin >> n;
	} while (n <= 0);
	for (int i = 1; i <= n; i++)
	{
		cout << "Nhap phan tu thu " << i << " la: ";
		cin >> x;
		Node *p = CreatNode(x);
		AddTail(l, p);
	}
}

void ShowList(List l)
{
	cout << "\nDu lieu DS la: " << endl;
	for (Node *p = l.head; p != NULL; p = p->next)
	{
		cout << p->info << "\t";
	}
}

void insertBefore(List &l, int key, int val)
{
	if (l.head->info == key)
	{
		Node *neww = CreatNode(val);
		AddHead(l, neww);
		return;
	}

	int dem1 = -1, dem2 = -1;
	bool cc = false;
	for (Node *p = l.head; p != NULL; p = p->next)
	{
		++dem1;
		if (key == p->info)
		{
			cc = true;
			break;
		}
	}
	if (cc)
	{
		for (Node *p = l.head; p != NULL; p = p->next)
		{
			++dem2;
			if (dem2 == dem1 - 1)
			{
				Node *neww = CreatNode(val);
				neww->next = p->next;
				p->next = neww;
				return;
			}
		}
	}
}

void deleteGreaterNodes(List &l, int x)
{
	for (Node *p = l.head; p != NULL; p = p->next)
	{
		if (p->next->info > x)
		{
			Node *q = p->next;
			p->next = q->next;
			q->next = NULL;
			delete q;
		}
	}
}

void deleteHeadList(List &l)
{
	if (l.head == NULL)
		return;
	else
	{
		Node *p = l.head;
		l.head = p->next;
		delete p;
	}
}

void deleteTailList(List &l)
{
	if (l.head == NULL)
		return;
	else
	{
		Node *p = l.tail;
		Node *q = l.head;
		while (q->next != l.tail)
			q = q->next;
		l.tail = q;
		l.tail->next = NULL;
		delete p;
	}
}
void deleteMidList(List &l, Node *q)
{
	if (l.head == NULL || q == NULL || q == l.tail)
		return;
	else
	{
		if (q->next == l.tail)
			deleteTailList(l);
		else
		{
			Node *p = q->next;
			q->next = p->next;
			p->next = NULL;
			delete p;
		}
	}
}
void DeleteLenX(List &l, int x)
{
	if (l.head == NULL)
		return;
	Node *p = l.head, *q = p;
	while (p != NULL)
	{
		if (p->info > x)
		{
			if (p == l.head)
			{
				p = p->next;
				q = p;
				deleteHeadList(l);
			}
			else
			{
				if (p == l.tail)
				{
					deleteTailList(l);
					break;
				}
				else
				{

					Node *v = q;
					p = p->next;
					deleteMidList(l, v);
					v = NULL;
					delete v;
				}
			}
		}
		else
		{
			q = p;
			p = p->next;
		}
	}
}

void DeleteEven(List &l)
{
	if (l.head == NULL)
		return;
	Node *p = l.head, *q = p;
	while (p != NULL)
	{
		if (p->info % 2 == 0)
		{
			if (p == l.head)
			{
				p = p->next;
				q = p;
				deleteHeadList(l);
			}
			else
			{
				if (p == l.tail)
				{
					deleteTailList(l);
					break;
				}
				else
				{
					Node *v = q;
					p = p->next;
					deleteMidList(l, v);
				}
			}
		}
		else
		{
			q = p;
			p = p->next;
		}
	}
}

void swap(int &a, int &b)
{
	int p = a;
	a = b;
	b = p;
}

void sortUp(List &sl)
{
	Node *p = sl.head;
	while (p != sl.tail)
	{
		Node *run = p->next;
		while (run != NULL)
		{
			if (p->info > run->info)
				swap(p->info, run->info);
			run = run->next;
		}
		p = p->next;
	}
}

void sortDown(List &sl)
{
	Node *p = sl.head;
	while (p != sl.tail)
	{
		Node *run = p->next;
		while (run != NULL)
		{
			if (p->info < run->info)
				swap(p->info, run->info);
			run = run->next;
		}
		p = p->next;
	}
}

bool checkPrime(int n)
{
	if (n == 1)
		return false;
	for (int i = 2; i <= n / 2; i++)
		if (n % i == 0)
			return false;
	return true;
}

int coutPrimeSList(List &l)
{
	int count = 0;
	if (l.head == NULL)
		return 0;
	Node *node = l.head;
	while (node != NULL)
	{
		if (checkPrime(node->info))
			count++;
		node = node->next;
	}
	return count;
}

bool checkPS(int n)
{
	for (int i = 1; i <= n / 2; i++)
		if (i * i == n)
			return true;
	return false;
}

int sumPPSList(List &l)
{
	int sum = 0;
	if (l.head == NULL)
		return 0;
	Node *node = l.head;
	while (node != NULL)
	{
		if (checkPS(node->info))
			sum += node->info;
		node = node->next;
	}
	return sum;
}

int findMax(List l)
{
	if (l.head == NULL)
		return 0;
	Node *node = l.head->next;
	int max = l.head->info;
	while (node != NULL)
	{
		if (max < node->info)
			max = node->info;
		node = node->next;
	}
	return max;
}

int soPtX2DungSau(List &l)
{
	int count = 0;
	if (l.head == NULL)
		return 0;
	Node *node = l.head;
	while (node != l.tail)
	{
		if (node->info > 2 * node->next->info)
			count++;
		node = node->next;
	}
	return count;
}

void Menu()
{
	cout << "1> Thêm phần tử mới vào cuối danh sách.\n"
		 << "2> Chèn thêm phần tử có giá trị x vào trước phần tử có giá trị y.\n"
		 << "3> Viết hàm xóa các phần tử lớn hơn x trong dslk.\n"
		 << "4> Viết hàm xóa các phần tử chẵn trong dslk\n"
		 << "5> Sắp xếp dslk tăng dần, giảm dần.\n"
		 << "6> Cho biết trong dslk có bao nhiêu số nguyên tố.\n"
		 << "7> Tính tổng các số chính phương trong dslk.\n"
		 << "8> Tìm phần tử nhỏ nhất, phần tử lớn nhất trong dslk.\n"
		 << "9> Cho biết trong dskl có bao nhiêu phần tử lớn hơn gấp đôi phần tử phía sau nó.\n"
		 << "10> Từ sl tạo 2 danh sách mới: sl1 chứa các số chẵn, sl2 chứa các số lẻ.\n"
		 << "\nNhập lựa chọn từ menu trên: ";
}

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	system("cls");

	int luachon, x;
	List l;

	Menu();
	cin >> luachon;
	switch (luachon)
	{
	case 1:
		CreateList(l);
		ShowList(l);
		cout << "\n\nNhap du lieu them vao cuoi: ";
		cin >> x;
		AddTail(l, CreatNode(x));
		ShowList(l);
		break;

	case 2:
		CreateList(l);
		ShowList(l);
		int y;
		cout << "\nNhap gia tri x: ";
		cin >> x;
		cout << "\nNhap gia tri y: ";
		cin >> y;
		insertBefore(l, y, x);
		ShowList(l);
		break;

	case 3:
		CreateList(l);
		ShowList(l);
		cout << "\nNhap gia tri x: ";
		cin >> x;
		DeleteLenX(l, x);
		ShowList(l);
		break;

	case 4:
		CreateList(l);
		ShowList(l);
		DeleteEven(l);
		ShowList(l);
		break;

	case 5:
		CreateList(l);
		ShowList(l);
		sortUp(l);
		// sortDown(l);
		ShowList(l);
		break;

	case 6:
		CreateList(l);
		ShowList(l);
		cout << "\nSo nguyen to trong dslk la: " << coutPrimeSList(l);
		break;

	case 7:
		CreateList(l);
		ShowList(l);
		cout << "\nTong cac so chinh phuong trong lk la: " << sumPPSList(l);
		break;

	case 8:
		CreateList(l);
		ShowList(l);
		cout << "\nPhan tu lon nhat la: " << findMax(l);
		break;

	case 9:
		CreateList(l);
		ShowList(l);
		cout << "\nSo phan tu lon hon gap doi phan tu phia sau no la: " << soPtX2DungSau(l);
		break;

	case 10:
		break;

	default:
		cout << "Khong nam trong menu!";
		break;
	}

	cout << endl;
	system("pause");
}
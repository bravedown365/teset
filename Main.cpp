#include <iostream>
#include <Windows.h>
#include "Buoi01_DSLK1.h"
#include "Buoi01_DSLK2.h"
using namespace std;

void menu()
{
	cout << "*********************" << endl;
	cout << "Bài tập thực hành buổi 1" << endl;
	cout << "*********************" << endl;
	cout << "0. Thoát" << endl;
	cout << "1. Bài 1\n";
	cout << "2. Bài 2\n";
	cout << "3. Bài 3\n";
	cout << "4. Bài 4\n";
}
void menuBai1()
{
	cout << "*********************" << endl;
	cout << "Bài tập 1" << endl;
	cout << "*********************" << endl;
	cout << "0. Thoát" << endl;
	cout << "a. Thêm phần tử mới vào cuối danh sách sl\n";
	cout << "b. Chèn thêm phần tử có giá trị x vào trước phần tử có giá trị y\n";
	cout << "c. Viết hàm xóa các phần tử lớn hơn x trong dslk\n";
	cout << "d. Viết hàm xóa các phần tử chẵn trong dslk\n";
	cout << "e. Sắp xếp dslk tăng dần, giảm dần\n";
	cout << "f. Cho biết trong dslk có bao nhiêu số nguyên tố\n";
	cout << "g. Tính tổng các số chính phương trong dslk\n";
	cout << "h. Tìm phần tử nhỏ nhất, phần tử lớn nhất trong dslk\n";
	cout << "i. Cho biết trong dslk có bao nhiêu phần tử lớn hơn gấp đôi phần tử phía sau nó\n";
	cout << "j. Từ sl tạo 2 danh sách mới: sl1 chứa các số chẵn, sl2 chứa các số lẻ\n";
}
void menuBai2()
{
	cout << "*********************" << endl;
	cout << "Bài tập 1" << endl;
	cout << "*********************" << endl;
	cout << "0. Thoát" << endl;
	cout << "b. Nhập/xuất danh sách có n phân số\n";
	cout << "c. Tối giản các phân số\n";
	cout << "d. Tính tổng/tích các phân số\n";
	cout << "e. Cho biết phân số lớn nhất/phân số nhỏ nhất\n";
	cout << "f. Tăng mỗi phân số của danh sách lên 1 đơn vị\n";
	cout << "g. Xuất các phân số lớn hơn 1 trong danh sách liên kết\n";
	cout << "h. Viết hàm trả về SNode chứa phân số p trong danh sách liên kết. Nếu không có p trong DSLK thì trả về NULL\n";
}
/////////////////
void main()
{
	SetConsoleOutputCP(CP_UTF8);

	int chonBai = 0;
	char chonCau = 0;

	do
	{
		system("cls");
		menu();
		cout << "\nChọn bài tập: ";
		cin >> chonBai;

		switch (chonBai)
		{
		case 0:
		{
			cout << "Thoát" << endl;
			break;
		}
		case 1:
			do
			{
				system("cls");
				menuBai1();
				cout << "\nChọn câu: ";
				cin >> chonCau;

				switch (chonCau)
				{
					case 48:
					{
						cout << "Thoát" << endl;
						break;
					}
					case 'a'://1a. Thêm phần tử mới vào cuối danh sách sl.
					{
						//Node* p = CreateNode(5);
						//ShowNode(p);
						SList l;
						init(l);
						//addTailSList(l, p);
						addTailSList(l, createNode(1));
						addTailSList(l, createNode(2));
						addTailSList(l, createNode(3));
						addTailSList(l, createNode(4));
						addTailSList(l, createNode(5));
						traverse(l);
						cout << endl;
						break;
					}
					case 'b'://1b. Chèn thêm phần tử có giá trị p(x) vào trước phần tử có giá trị q(y).
					{
						int x, y;
						SList l;
						init(l);
						addTailSList(l, createNode(1));
						addTailSList(l, createNode(2));
						addTailSList(l, createNode(3));
						addTailSList(l, createNode(4));
						addTailSList(l, createNode(5));
						traverse(l);
						cout << endl;

						cout << "Nhập phần tử x cần thêm: ";
						cin >> x;
						Node* p = createNode(x);
						cout << "Nhập phần tử y cần tìm: ";
						cin >> y;
						Node* q = searchSList(l, y);
						addBeforeNodeSList(l, q, p);
						traverse(l);
						cout << endl;
						break;
					}
					case 'c'://1c. Viết hàm xóa các phần tử lớn hơn x trong dslk
					{
						SList l;
						init(l);
						addTailSList(l, createNode(1));
						addTailSList(l, createNode(2));
						addTailSList(l, createNode(3));
						addTailSList(l, createNode(4));
						addTailSList(l, createNode(6));
						traverse(l);
						cout << endl;
						int x;
						cout << "Nhập phần tử x cần tìm: ";
						cin >> x;
						deleteGreaterThanXSList(l, x);
						traverse(l);
						cout << endl;
						break;
					}
					case 'd'://1d. Viết hàm xóa các phần tử chẵn trong dslk
					{
						SList l;
						init(l);
						addTailSList(l, createNode(1));
						addTailSList(l, createNode(2));
						addTailSList(l, createNode(3));
						addTailSList(l, createNode(4));
						addTailSList(l, createNode(6));
						traverse(l);
						cout << endl;
						deleteEvenSList(l);
						traverse(l);
						cout << endl;
						break;
					}
					case 'e'://1e. Sắp xếp dslk giảm dần
					{
						SList l;
						init(l);
						addTailSList(l, createNode(1));
						addTailSList(l, createNode(2));
						addTailSList(l, createNode(3));
						addTailSList(l, createNode(4));
						addTailSList(l, createNode(6));
						traverse(l);
						cout << endl;
						interchangeDescSortSList(l);
						traverse(l);
						cout << endl;
						break;
					}
					case 'f'://1f. Cho biết trong dslk có bao nhiêu số nguyên tố
					{
						SList l;
						init(l);
						addTailSList(l, createNode(1));
						addTailSList(l, createNode(2));
						addTailSList(l, createNode(3));
						addTailSList(l, createNode(4));
						addTailSList(l, createNode(6));
						traverse(l);
						cout << endl;
						cout << "Số SNT trong dslk: " << countPrime(l) << endl;
						break;
					}
					case 'g'://1g. Tính tổng các số chính phương trong dslk
					{
						SList l;
						init(l);
						addTailSList(l, createNode(1));
						addTailSList(l, createNode(2));
						addTailSList(l, createNode(3));
						addTailSList(l, createNode(4));
						addTailSList(l, createNode(6));
						traverse(l);
						cout << endl;
						cout << "Tổng các số chính phương trong dslk: " << sumSquare(l) << endl;
						break;
					}
					case 'h'://1h. Tìm phần tử nhỏ nhất, phần tử lớn nhất trong dslk
					{
						SList l;
						init(l);
						addTailSList(l, createNode(1));
						addTailSList(l, createNode(2));
						addTailSList(l, createNode(3));
						addTailSList(l, createNode(4));
						addTailSList(l, createNode(6));
						traverse(l);
						cout << endl;
						cout << "Phần tử lớn nhất trong danh sách: " << maxSList(l) << endl;
						break;
					}
					case 'i'://1i. Cho biết trong dskl có bao nhiêu phần tử lớn hơn gấp đôi phần tử phía sau nó.
					{
						SList l;
						init(l);
						addTailSList(l, createNode(5));
						addTailSList(l, createNode(4));
						addTailSList(l, createNode(3));
						addTailSList(l, createNode(2));
						addTailSList(l, createNode(1));
						traverse(l);
						cout << endl;
						cout << "Số phần tử lớn hơn gấp đôi phần tử phía sau nó: " << demDoubleSList(l) << endl;
						break;
					}
					case 'j'://1j. Từ sl tạo 2 danh sách mới: sl1 chứa các số chẵn, sl2 chứa các số lẻ.
					{
						SList l;
						init(l);
						addTailSList(l, createNode(5));
						addTailSList(l, createNode(4));
						addTailSList(l, createNode(3));
						addTailSList(l, createNode(2));
						addTailSList(l, createNode(1));
						traverse(l);
						cout << endl;

						SList l1; init(l1);
						SList l2; init(l2);
						if (!isEmpty(l))
							for (Node* p = l.head; p != NULL; p = p->next)
								if ((p->info) % 2 == 0)
									addTailSList(l1, createNode(p->info));
								else
									addTailSList(l2, createNode(p->info));
						cout << "Danh sách các số chẵn: " << endl;
						traverse(l1);
						cout << endl;
						cout << "Danh sách các số lẻ: " << endl;
						traverse(l2);
						cout << endl;
						break;
					}
					default:
						break;
				}
				if (chonCau != 48)
					system("pause");
			} while (chonCau != 48);
			break;
		case 2:
		{
			do
			{
				system("cls");
				menuBai2();
				cout << "\nChọn câu: ";
				cin >> chonCau;

				switch (chonCau)
				{
				case 48:
				{
					cout << "Thoát" << endl;
					break;
				}
				case 'b'://Nhập xuất DS có n phân số
				{
					/*PhanSo a(2, 4);
					PhanSo b(3, 5);
					PhanSo c(6, 9);

					NodePS* p = createNodePS(a);
					NodePS* q = createNodePS(b);

					SListPS l;
					addHeadSListPS(l, p);
					addHeadSListPS(l, q);
					addHeadSListPS(l, createNodePS(c));
					traverseSListPS(l);
					cout << endl;*/
					int n = 0;
					cout << "Nhập số phần tử của danh sách: ";
					cin >> n;

					if (n > 1)
					{
						SListPS l;

						for (int i = 1; i <= n; i++)
						{
							PhanSo a;
							cout << "Nhập phân số thứ " << i << ": " << endl;
							a.Nhap();
							NodePS* p = createNodePS(a);
							addHeadSListPS(l, p);
						}
						cout << "Danh sách phân số: ";
						traverseSListPS(l);
						cout << endl;
					}
					break;
				}
				case 'c'://Tối giản các phân số
				{
					PhanSo a(2, -4);
					PhanSo b(3, 5);
					PhanSo c(6, 9);

					NodePS* p = createNodePS(a);
					NodePS* q = createNodePS(b);

					SListPS l;
					addHeadSListPS(l, p);
					addHeadSListPS(l, q);
					addHeadSListPS(l, createNodePS(c));
					traverseSListPS(l);
					cout << endl;
					cout << "Danh sách sau khi tối giản:\n";
					for (p = l.head; p != NULL; p = p->next)
						p->info.ToiGian();
					traverseSListPS(l);
					cout << endl;
					break;
				}
				case 'd'://Tính tổng/tích các phân số
				{
					PhanSo a(1, 2);
					PhanSo b(3, 4);
					PhanSo c(5, 6);

					NodePS* p = createNodePS(a);
					NodePS* q = createNodePS(b);

					SListPS l;
					addHeadSListPS(l, p);
					addHeadSListPS(l, q);
					addHeadSListPS(l, createNodePS(c));
					traverseSListPS(l);
					cout << "\nTổng các phân số: ";
					PhanSo kq;
					for (p = l.head; p != NULL; p = p->next)
						kq = kq.Cong(p->info);
					
					kq.ToiGian();
					kq.Xuat();
					cout << endl;
					break;
				}
				case 'e'://
				{
					
					break;
				}
				case 'f'://
				{
					
					break;
				}
				case 'g'://
				{
					
				}
				case 'h'://Viết hàm trả về SNode chứa phân số p trong danh sách liên kết. Nếu không có p trong DSLK	thì trả về NULL
				{
					PhanSo a(1, 2);
					PhanSo b(3, 4);
					PhanSo c(5, 6);

					NodePS* p = createNodePS(a);
					NodePS* q = createNodePS(b);

					SListPS l;
					addHeadSListPS(l, p);
					addHeadSListPS(l, q);
					addHeadSListPS(l, createNodePS(c));
					traverseSListPS(l);
					cout << endl;

					PhanSo n;
					cout << "Nhập phân số cần tìm:\n";
					n.Nhap();
					if (searchNodePS(l, n) != NULL)
						cout << "Tìm thấy phân số";
					else
						cout << "Không tìm thấy phân số";
					cout << endl;
				}
				case 'i'://
				{
					break;
				}
				case 'j'://
				{
					break;
				}
				default:
					break;
				}
				if (chonCau != 48)
					system("pause");
			} while (chonCau != 48);
			break;
		}
		case 3:
		{
			cout << "Bài 3" << endl;

			break;
		}
		case 4:
		{
			cout << "Bài 4" << endl;

			break;
		}
		default:
			break;
		}
		system("pause");
	} while (chonBai != 0);
}
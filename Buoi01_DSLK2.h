///*File.h chỉ chứa các khai báo cấu trúc chương trình, ko chứa định nghĩa các phương thức hay các hàm*/
#include "PhanSo.h"

struct NodePS
{
	PhanSo info;
	NodePS* next;

	NodePS();
};

struct SListPS
{
	NodePS* head;
	NodePS* tail;

	SListPS();
};
/////////////
NodePS* createNodePS(PhanSo PS);
void traverseSListPS(SListPS l);
void addHeadSListPS(SListPS& l, NodePS* p);
NodePS* searchNodePS(SListPS l, PhanSo PS);


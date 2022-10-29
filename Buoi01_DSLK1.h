/*File.h chỉ chứa các khai báo cấu trúc chương trình, phương thức, hàm; ko chứa định nghĩa các phương thức hay các hàm*/
typedef int Data;

struct Node
{
	Data info;
	Node* next;

	Node();
};

struct SList
{
	Node* head;
	Node* tail;
};
/////////////////////
Node* createNode(int x);
void deleteNode(Node*& p);
void showNode(Node* p);

void init(SList& l);
bool isEmpty(SList l);
void traverse(SList l);
void addHeadSList(SList& l, Node* p);
void addTailSList(SList& l, Node* p);
void addAfterNodeSList(SList& l, Node* q, Node* p);
Node* searchSList(SList l, int x);
void createSList(SList& l);
void createAutoSList(SList& l);
void addBeforeNodeSList(SList& l, Node* q, Node* p);
void createSList(SList& l, int n);
void deleteHeadSList(SList& l);
void deleteTailList(SList& l);
void deleteMidSList(SList& l, Node* q);
void deleteGreaterThanXSList(SList& l, int x);
void deleteEvenSList(SList& l);
void interchangeDescSortSList(SList l);
int countPrime(SList l);
int sumSquare(SList l);
int maxSList(SList l);
int demDoubleSList(SList l);
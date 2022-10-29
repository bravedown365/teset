struct SinhVien
{
	char maSach[11];
	char tenSach[31];
	int soTrang, namSX;
	float giaTien;
};
typedef struct SinhVien SV;

struct Node
{
	SV info;
	Node *next;
	Node();
};

struct SList
{
	Node *head;
	Node *tail;
};
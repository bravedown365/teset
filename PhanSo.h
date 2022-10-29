struct PhanSo
{
	int tuso, mauso;

	PhanSo(int t = 0, int m = 1);
	
	void Nhap();
	void Xuat()const;
	void ToiGian();

	PhanSo Cong(const PhanSo& b);
};
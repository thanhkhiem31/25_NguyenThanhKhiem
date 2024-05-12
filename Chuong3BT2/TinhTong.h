#pragma once
class TinhTong
{
private:
	int tu1, mau1, tu2, mau2;
public:
	void setTu1(int _tu1);
	int getTu1() const;
	void setTu2(int _tu2);
	int getTu2() const;
	void setMau1(int _mau1);
	int getMau1() const;
	void setMau2(int _mau2);
	int getMau2() const;
	int tu_tong();
	int mau_tong();
};


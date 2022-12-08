#pragma once
#include "CauThu.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
class DoiBong
{
protected:
	string TenClb;
	vector<CauThu*> dsCauThu;
	Person Hlv;
	int Tranthamgiathidau;
	int Tranthang;
	int Tranhoa;
	int Tranthua;
	int Hieuso;
	int Diem;
public:
	DoiBong();
	DoiBong(const DoiBong& ds);
	const DoiBong& operator = (const DoiBong& ds);
	~DoiBong();
	void DocFile(string tenFile);
	void Ghifile(string tenFile);
	void Quan_li_doi_bong(string tenFile);
	void Thong_tin_doi_bong(string tenFile);
	void ThemCauThu();
	void XoaCauThu(int vt);
	void CapNhatThongTinCauThu(int vt);
	int Timkiem(int soao);
	void Menu(string tenFile);
	int MaxGhiBan();
	int MaxKienTao();
	string getTenclb();
	void setTenClb(string TenClb);
	int getDiem();
	void setDiem(int Diem);
	int getHieuso();
	void setHieuso(int Hieuso);
	int getTranThamGiaThiDau();
	void setTranThamGiaThiDau(int Tranthamgiathidau);
	int getTranThang();
	void setTranThang(int Tranthang);
	int getTranHoa();
	void setTranHoa(int Tranhoa);
	int getTranThua();
	void setTranThua(int Tranthua);
	void DocDs1DoiBong(ifstream& fileTeam);
	void GhiDsDoiBong(ofstream& fileTeam);
	void GhiDsDoiBong();
};
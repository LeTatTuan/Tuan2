#include "DoiBong.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
DoiBong::DoiBong()
{
	Diem = 0;
	Hieuso = 0;
	Tranthamgiathidau = 0;
	Tranthang = 0;
	Tranhoa = 0;
	Tranthua = 0;
}
DoiBong::DoiBong(const DoiBong& ds)
{
	
	for (int i = 0; i < ds.dsCauThu.size(); i++)
	{
		dsCauThu[i] = ds.dsCauThu[i];
	}
	TenClb = ds.TenClb;
	Hlv = ds.Hlv;
	Tranthamgiathidau = ds.Tranthamgiathidau;
	Tranthang = ds.Tranthang;
	Tranhoa = ds.Tranhoa;
	Tranthua = ds.Tranthua;
	Hieuso = ds.Hieuso;
	Diem = ds.Diem;
}
const DoiBong& DoiBong::operator=(const DoiBong& ds)
{
	if (this != &ds)
	{
		for (int i = 0; i < ds.dsCauThu.size(); i++)
		{
			dsCauThu[i] = ds.dsCauThu[i];
		}
		TenClb = ds.TenClb;
		Hlv = ds.Hlv;
		Tranthamgiathidau = ds.Tranthamgiathidau;
		Tranthang = ds.Tranthang;
		Tranhoa = ds.Tranhoa;
		Tranthua = ds.Tranthua;
		Hieuso = ds.Hieuso;
		Diem = ds.Diem;
	}
	return *this;
}
DoiBong::~DoiBong()
{
}
void DoiBong::DocFile(string tenFile)
{
	ifstream filein;
	filein.open(tenFile, ios_base::in);
	//Hlv.Input(filein);
	int lines = 0;
	while (filein.eof() == false)
	{
		string x;
		getline(filein, x);
		lines++;
	}
	filein.close();
	filein.open(tenFile, ios_base::in);
	getline(filein, TenClb, ',');
	Hlv.Input(filein);
	for (int i = 0; i < lines - 2; i++)
	{
		CauThu* c = new CauThu;
		c->Input(filein);
		dsCauThu.push_back(c);
	}
	filein.close();
	cout << "Da nhap tu file!!" << endl;
}
void DoiBong::Ghifile(string tenFile)
{
	ofstream fileout;
	fileout.open(tenFile, ios_base::out);
	fileout << "\n\n\t\t\t\t\tTHONG TIN HUAN LUYEN VIEN" << endl << endl;
	fileout << "Ho va ten                 Quoc tich       Ngay sinh       Tuoi" << endl << endl;
	Hlv.Output(fileout);
	fileout << "\n\n\t\t\t\t\t\t\t+------------------------------------------------+" << endl;
	fileout << "\t\t\t\t\t\t\t|                                                |" << endl;
	fileout << "\t\t\t\t\t\t\t|              DANH SACH CAU THU                 |" << endl;
	fileout << "\t\t\t\t\t\t\t|                                                |" << endl;
	fileout << "\t\t\t\t\t\t\t+------------------------------------------------+" << endl << endl;
	fileout << "Ho va ten                 Quoc tich       Ngay sinh       Tuoi          Cau lac bo             Ngay gia nhap      Vi tri   So ao  Ban thang   Kien tao\n\n";
	for (int i = 0; i < dsCauThu.size(); i++)
	{
		dsCauThu[i]->Output(fileout);
	}
	fileout.close();
	cout << "\n==> Da ghi thong tin cau thu vao fileout.";
}

void DoiBong::Quan_li_doi_bong(string tenFile)
{
	int luachon;
	char tt;
	//DocFile(tenFile);
	do
	{
		system("cls");
		cout << "\n\n\t\t1.Thong tin doi bong.";
		cout << "\n\n\t\t2.Them 1 cau thu.";
		cout << "\n\n\t\t3.Xoa 1 cau thu.";
		cout << "\n\n\t\t4.Cap nhat thong tin cau thu.";
		cout << "\n\n\t\t0.Thoat.";
		cout << "\nluachon = "; cin >> luachon;
		switch (luachon)
		{
		case 1:
			Thong_tin_doi_bong(tenFile);
			break;
		case 2:
			ThemCauThu();
			cout << "Da them cau thu vao cuoi danh sach!!";
			break;
		case 3:
			int vt;
			cout << "\nNhap vi tri cau thu ma ban muon xoa: "; cin >> vt;
			XoaCauThu(vt-1);
			cout << "\nDa xoa cau thu thu!!!" << vt;
			break;
		case 4:
		{
			Thong_tin_doi_bong(tenFile);
			int soao;
			cout << "\nNhap so ao cau thu can cap nhat thong tin: "; cin >> soao;
			int vt1;
			vt1 = Timkiem(soao);
			CapNhatThongTinCauThu(vt1);
			cout << "\nDa cap nhat thanh cong!!";
			break;
		}
		case 0: break;

		default:
			cout << "\nBan nhap sai cu phap. Vui long nhap lai!!!";
			cin >> luachon;
			break;
		}

		cout << "\nBan co muon tiep tuc voi cau thu khong(c/k)?"; cin >> tt;
		if (tt == 'k' || tt == 'K') break;
	} while (tt);
}
void DoiBong::Thong_tin_doi_bong(string tenFile)
{
	cout << "\n\n\t\t\t\t\tTHONG TIN HUAN LUYEN VIEN" << endl << endl;
	cout << "Ho va ten                 Quoc tich       Ngay sinh       Tuoi" << endl << endl;
	Hlv.Output();
	cout << "\n\n\t\t\t\t\t\t+------------------------------------------------+" << endl;
	cout << "\t\t\t\t\t\t|                                                |" << endl;
	cout << "\t\t\t\t\t\t|              DANH SACH CAU THU                 |" << endl;
	cout << "\t\t\t\t\t\t|                                                |" << endl;
	cout << "\t\t\t\t\t\t+------------------------------------------------+" << endl << endl;
	cout << "Ho va ten                 Quoc tich       Ngay sinh       Tuoi          Cau lac bo             Ngay gia nhap      Vi tri   So ao  Ban thang   Kien tao\n\n";
	for (int i = 0; i < dsCauThu.size(); i++)
	{
		dsCauThu[i]->Output();
	}
}
void DoiBong::ThemCauThu()
{
	CauThu* c = new CauThu;
	c->Input();
	dsCauThu.push_back(c);
}
void DoiBong::XoaCauThu(int vt)
{
	dsCauThu.erase(dsCauThu.begin() + vt);
}
void DoiBong::CapNhatThongTinCauThu(int vt)
{
	int capnhat;
	char tt;
	do
	{
		system("cls");
		cout << "\n\n\t\t1.Cap nhat vi tri thi dau.";
		cout << "\n\n\t\t2.Cap nhat so ban thang.";
		cout << "\n\n\t\t3.Cap nhat so kien tao.";
		cout << "\n\n\t\t0.Thoat.";
		cout << "\ncapnhat = "; cin >> capnhat;
		switch (capnhat)
		{
		case 1:
		{
			string vitri1; cout << "\nNhap vi tri muon cap nhat: "; fflush(stdin); cin >> vitri1;
			dsCauThu[vt]->setVitrithidau(vitri1);
			break;
		}
		case 2:
		{
			int banthang1; cout << "\nNhap so ban thang can cap nhat: "; cin >> banthang1;
			dsCauThu[vt]->setBanthang(banthang1);
			break;
		}
		case 3:
		{
			int kientao1; cout << "\nNhap so kien tao can cap nhat: "; cin >> kientao1;
			dsCauThu[vt]->setKientao(kientao1);
			break;
		}
		case 0: break;

		default:
		{
			cout << "\nBan nhap sai cu phap. Vui long nhap lai!!!";
			cin >> capnhat;
			break;
		}
		}
		cout << "\nBan co muon tiep tuc cap nhat thong tin cau thu khong(c/k)?"; cin >> tt;
		if (tt == 'k' || tt == 'K') break;
	} while (tt);
}
int DoiBong::Timkiem(int soao)
{
	int i;
	for (i = 0; i < dsCauThu.size(); i++)
	{
		if (dsCauThu[i]->getSoao() == soao)
		{
			break;
		}
	}
	return i;
}
void DoiBong::Menu(string tenFile)
{
	Quan_li_doi_bong(tenFile);
	string tenfileout = "out" + tenFile;
	Ghifile(tenfileout);
}
int DoiBong::MaxGhiBan()
{
	int soaoct;
	int maxbt = dsCauThu[0]->getBanthang();
	for (int i = 1; i < dsCauThu.size(); i++)
	{
		if (dsCauThu[i]->getBanthang() > maxbt)
		{
			maxbt = dsCauThu[i]->getBanthang();
			soaoct = dsCauThu[i]->getSoao();
		}
	}
	return soaoct;
}
int DoiBong::MaxKienTao()
{
	int soaocT;
	int maxkt = dsCauThu[0]->getKientao();
	for (int i = 1; i < dsCauThu.size(); i++)
	{
		if (dsCauThu[i]->getKientao() > maxkt)
		{
			maxkt = dsCauThu[i]->getKientao();
			soaocT = dsCauThu[i]->getSoao();
		}
	}
	return soaocT;
}
int DoiBong::getDiem()
{
	return Diem;
}
void DoiBong::setDiem(int Diem)
{
	this->Diem += Diem;
}
int DoiBong::getHieuso()
{
	return Hieuso;
}
void DoiBong::setHieuso(int Hieuso)
{
	this->Hieuso += Hieuso;
}
string DoiBong::getTenclb()
{
	return TenClb;
}
void DoiBong::setTenClb(string TenClb)
{
	this->TenClb = TenClb;
}
int DoiBong::getTranThamGiaThiDau()
{
	return Tranthamgiathidau;
}
void DoiBong::setTranThamGiaThiDau(int Tranthamgiathidau)
{
	this->Tranthamgiathidau += Tranthamgiathidau;
}
int DoiBong::getTranThang()
{
	return Tranthang;
}
void DoiBong::setTranThang(int Tranthang)
{
	this->Tranthang += Tranthang;
}
int DoiBong::getTranHoa()
{
	return Tranhoa;
}
void DoiBong::setTranHoa(int Tranhoa)
{
	this->Tranhoa = Tranhoa;
}
int DoiBong::getTranThua()
{
	return Tranhoa;
}
void DoiBong::setTranThua(int Tranthua)
{
	this->Tranthua += Tranthua;
}
void DoiBong::DocDs1DoiBong(ifstream& fileTeam)
{
	fflush(stdin);
	getline(fileTeam, TenClb, ',');
}
void DoiBong::GhiDsDoiBong(ofstream& fileTeam)
{
	fileTeam << setw(20) << TenClb;
	fileTeam << setw(20) << Tranthamgiathidau;
	fileTeam << setw(10) << Tranthang;
	fileTeam << setw(10) << Tranhoa;
	fileTeam << setw(10) << Tranthua;
	fileTeam << setw(10) << Hieuso;
	fileTeam << setw(10) << Diem << endl;
}
void DoiBong::GhiDsDoiBong()
{
	cout << setw(20) << TenClb;
	cout << setw(20) << Tranthamgiathidau;
	cout << setw(10) << Tranthang;
	cout << setw(10) << Tranhoa;
	cout << setw(10) << Tranthua;
	cout << setw(10) << Hieuso;
	cout << setw(10) << Diem << endl;
}
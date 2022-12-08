#include "CauThu.h"

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

CauThu::CauThu()
{
	banthang = 0;
	kientao = 0;
}
CauThu::~CauThu()
{

}
string CauThu::getCaulacbo()
{
	return Caulacbo;
}
void CauThu::setCaulacbo(string Caulacbo)
{
	this->Caulacbo = Caulacbo;
}
string  CauThu::getNgaygianhap()
{
	return Ngaygianhap;
}
void CauThu::setNgaygianhap(string Ngaygianhap)
{
	this->Ngaygianhap = Ngaygianhap;
}
string CauThu::getVitrithidau()
{
	return vitrithidau;
}
void CauThu::setVitrithidau(string vitrithidau)
{
	this->vitrithidau = vitrithidau;
}
int CauThu::getSoao()
{
	return soao;
}
void CauThu::setSoao(int soao)
{
	this->soao = soao;
}
int CauThu::getBanthang()
{
	return banthang;
}
void CauThu::setBanthang(int banthang)
{
	this->banthang = banthang;
}
int CauThu::getKientao()
{
	return kientao;
}
void CauThu::setKientao(int kientao)
{
	this->kientao = kientao;
}


void CauThu::Input(ifstream& filein)
{
	fflush(stdin);
	getline(filein, Hoten, ',');
	getline(filein, Quoctich, ',');
	getline(filein, Ngaysinh, ',');
	getline(filein, Caulacbo, ',');
	getline(filein, Ngaygianhap, ',');
	getline(filein, vitrithidau, ',');
	filein >> soao;
}

void CauThu::Input()
{
	Person::Input();
	cout << "Nhap cau lac bo chu quan: ";  fflush(stdin); getline(cin, Caulacbo);
	cout << "Nhap ngay gia nhap: "; fflush(stdin); getline(cin, Ngaygianhap);
	cout << "Nhap vi tri thi dau: "; fflush(stdin); getline(cin, vitrithidau);
	cout << "Nhap so ao: "; cin >> soao;
}
void CauThu::Output()
{
	Person::Output();
	cout << setw(25) << Caulacbo << setw(20) << Ngaygianhap << setw(13) << vitrithidau << setw(8) << soao << setw(11) << banthang << setw(11) << kientao << endl;
}

void CauThu::Output(ofstream& fileout)
{
	Person::Output(fileout);
	fileout << setw(25) << Caulacbo << setw(20) << Ngaygianhap << setw(13) << vitrithidau << setw(8) << soao << setw(11) << banthang << setw(11) << kientao << endl;
}

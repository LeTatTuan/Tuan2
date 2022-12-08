#include "Person.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;
Person::Person()
{

}
Person::Person(string Hoten, string Quoctich, string Ngaysinh)
{
	this->Hoten = Hoten;
	this->Quoctich = Quoctich;
	this->Ngaysinh = Ngaysinh;
}
Person::~Person()
{

}

void Person::Input()
{
	fflush(stdin);
	cin.ignore();
	cout << "Nhap ho va ten: "; fflush(stdin); getline(cin, Hoten);
	cout << "Nhap Quoc Tich: "; fflush(stdin); getline(cin, Quoctich);
	cout << "Nhap ngay sinh theo dinh dang dd/mm/yyyy: "; fflush(stdin); getline(cin, Ngaysinh);
}
void Person::Input(ifstream& filein)
{
	fflush(stdin);
	getline(filein, Hoten, ',');
	getline(filein, Quoctich, ',');
	fflush(stdin);
	getline(filein, Ngaysinh, ',');
}
void Person::Output()
{
	cout << Hoten << setw(15) << Quoctich << setw(15) << Ngaysinh << setw(10) << Tinhtuoi() << setw(15);
}
void Person::Output(ofstream& fileout)
{
	fileout << Hoten << setw(15) << Quoctich << setw(15) << Ngaysinh << setw(10) << Tinhtuoi() << setw(15);
}
string Person::getHoten()
{
	return Hoten;
}
void Person::setHoten(string Hoten)
{
	this->Hoten = Hoten;
}
string Person::getQuoctich()
{
	return Quoctich;
}
void Person::setQuoctich(string Quoctich)
{
	this->Quoctich = Quoctich;
}

string Person::getNgaysinh()
{
	return Ngaysinh;
}
void Person::setNgaysinh(string Ngaysinh)
{
	this->Ngaysinh = Ngaysinh;
}
int Person::Laynamsinh(string day)
{

	int kq = 0;
	for (int i = 6; i < day.length(); i++)
	{
		kq += ((int)day[i] - 48) * pow(10, 9 - i);

	}
	
	return kq;
}


int Person::Tinhtuoi()
{
	return 2022 - Laynamsinh(Ngaysinh);
}

#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;
class Person
{
protected:
	string Hoten;
	string Quoctich;
	string Ngaysinh;
public:
	Person();
	Person(string Hoten, string Quoctich, string Ngaysinh);
	~Person();
	void Input();
	void Input(ifstream& filein);
	void Output();
	void Output(ofstream& fileout);
	string getHoten();
	void setHoten(string Hoten);
	string getQuoctich();
	void setQuoctich(string Quoctich);
	string getNgaysinh();
	void setNgaysinh(string Ngaysinh);
	int Laynamsinh(string day);
	int Tinhtuoi();
};
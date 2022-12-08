#pragma once
#include "Person.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class CauThu : public Person {
private:
	string Caulacbo;
	string Ngaygianhap;
	string vitrithidau;
	int soao;
	int banthang;
	int kientao;
public:
	CauThu();
	CauThu(string Hoten, string Quoctich, string Ngaysinh, string Caulacbo, string Ngaygianhap, string vitrithidau, int soao, int  banthang, int kientao) :Person(Hoten, Quoctich, Ngaysinh)
	{
		this->Caulacbo = Caulacbo;
		this->Ngaygianhap = Ngaygianhap;
		this->vitrithidau = vitrithidau;
		this->soao = soao;
		this->banthang = banthang;
		this->kientao = kientao;
	}
	~CauThu();
	string getCaulacbo();
	void setCaulacbo(string Caulacbo);
	string getNgaygianhap();
	void setNgaygianhap(string Ngaygianhap);
	string getVitrithidau();
	void setVitrithidau(string vitrithidau);
	int getSoao();
	void setSoao(int soao);
	int getBanthang();
	void setBanthang(int banthang);
	int getKientao();
	void setKientao(int kientao);

	void Input(ifstream& filein);
	void Input();
	void Output(ofstream& fileout);
	void Output();
};

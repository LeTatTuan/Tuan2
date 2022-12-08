#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "DoiBong.h"
using namespace std;
class Match
{
public:
	string ThoiGianThiDau;
	DoiBong DoiNha;
	int tisoDoiNha;
	DoiBong DoiKhach;
	int tisoDoiKhach;
public:
	Match();
	~Match();
	int getTisoDoiNha();
	void setTisoDoiNha(int tisoDoiNha);
	int getTisoDoiKhach();
	void setTisoDoiKhach(int tisoDoiKhach);
	void CapNhatKetQuaTranDau();
	void ThongTinTranDau();
	void DocFileTranDau(ifstream& fileMatch);
	void GhiFileTranDau(ofstream& fileMatch);
};

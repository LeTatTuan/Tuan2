#pragma once
#include "DoiBong.h"
#include "Match.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;
class GiaiDau : public DoiBong, public Match
{
private:
	vector<DoiBong*> dsDoiBong;
	vector<Match*> dsTranDau;
public:
	void DocdsDoiBong();
	void DocdsTranDau(string tenFile);
	void SelectSort();
	void BangXepHang();
	void BangXepHang(string tenFile);
	void CapNhatKetQuaVongDau();
	void KetQuaVongDau();
	void KetQuaVongDau(string tenFile);
	void TruyCapDoiBong(int i);
	void IntroDoiBong();
	void IntroTranDau();
	int TimKiemDoiBong(string name);
	void TruycapDoiBong(int i);
	void QuanLyVongDau();
	void GanSoTranDau(int s);
};


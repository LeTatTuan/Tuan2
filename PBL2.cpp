#include "GiaiDau.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Match.h"
#include "DoiBong.h"
using namespace std;
void XinChao()
{
	ifstream f;
	f.open("league.txt", ios_base::in);
	int n = 0;
	while (!f.eof())
	{
		string x;
		getline(f, x);
		n++;
	}
	f.close();
	f.open("league.txt", ios_base::in);
	string s[25];
	for (int i = 0; i < 25; i++)
	{
		getline(f, s[i]);
	}
	for (int i = 0; i < 25; i++)
	{
		cout << s[i] << endl;
	}
	f.close();
	system("pause");
}
int main()
{
	XinChao();
	GiaiDau q;
	q.QuanLyVongDau();
	/*q.BangXepHang();
	int stt;
	cout << "Nhap so thu tu doi bong";
	cin >> stt;
	q.DocdsDoiBong();
	q.TruyCapDoiBong(stt-1);*/
}
#include "Match.h"
Match::Match()
{
	tisoDoiKhach = 0;
	tisoDoiNha = 0;
}
Match::~Match()
{

}
int Match::getTisoDoiNha()
{
	return tisoDoiNha;
}
void Match::setTisoDoiNha(int tisoDoiNha)
{
	this->tisoDoiNha = tisoDoiNha;
}
int Match::getTisoDoiKhach()
{
	return tisoDoiKhach;
}
void Match::setTisoDoiKhach(int tisoDoiKhach)
{
	this->tisoDoiKhach = tisoDoiKhach;
}
void Match::CapNhatKetQuaTranDau()
{
	int t1;
	cout << "\nSo ban thang doi khach: "; cin >> t1;
	setTisoDoiNha(t1);
	int t2;
	cout << "\nSo ban thang doi khach: "; cin >> t2;
	setTisoDoiKhach(t2);

}
void Match::ThongTinTranDau()
{
	cout << ThoiGianThiDau;
	cout << setw(20) << DoiNha.getTenclb();
	cout << setw(15) << tisoDoiNha << " - ";
	cout << tisoDoiKhach;
	cout << setw(20) << DoiKhach.getTenclb() << endl;
}
void Match::DocFileTranDau(ifstream& fileMatch)
{
	fflush(stdin);
	getline(fileMatch, ThoiGianThiDau, ',');
	string a;
	getline(fileMatch, a, ','); DoiNha.setTenClb(a);
	string b;
	getline(fileMatch, b, ','); DoiKhach.setTenClb(b);
}
void Match::GhiFileTranDau(ofstream& fileMatch)
{
	fileMatch << ThoiGianThiDau;
	fileMatch << setw(20) << DoiNha.getTenclb();
	fileMatch << setw(15) << tisoDoiNha << " - ";
	fileMatch << tisoDoiKhach;
	fileMatch << setw(20) << DoiKhach.getTenclb() << endl;
}
#include "GiaiDau.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

void GiaiDau::DocdsDoiBong()
{
	string gan[] = { "Arsenal.txt","Brentford.txt","Brighton.txt","Chelsea.txt","Fulham.txt","Liverpool.txt","ManchesterCity.txt","ManchesterUnited.txt","Newcastle.txt","TottenhamHotspur.txt" };
	for (int i = 0; i < 10; i++)
	{
		DoiBong* d = new DoiBong;
		d->DocFile(gan[i]);
		dsDoiBong.push_back(d);
	}
	cout << "\n=> Da doc file thanh cong" << endl;
}
void GiaiDau::DocdsTranDau(string tenFile)
{
	ifstream f;
	f.open(tenFile, ios_base::in);
	for (int i = 0; i < 5; i++)
	{
		Match* m = new Match;
		m->DocFileTranDau(f);
		dsTranDau.push_back(m);
	}
}
void GiaiDau::SelectSort()
{
	int n = dsDoiBong.size();
	int vt;
	for (int i = 0; i < n-1; i++)
	{
		vt = i;
		for (int j = i + 1; j < n; j++)
		{
			if (dsDoiBong[vt]->getDiem() < dsDoiBong[j]->getDiem()) vt = j;
		}
		DoiBong* p = dsDoiBong[i];
		dsDoiBong[i] = dsDoiBong[vt];
		dsDoiBong[vt] = p;
	}
}
void GiaiDau::BangXepHang()
{
	this->IntroDoiBong();
	for (int i = 0; i < dsDoiBong.size(); i++)
	{
		if (i < 9)
		{
			cout << " " << i + 1;
		}
		else cout << i + 1;
		dsDoiBong[i]->GhiDsDoiBong();
	}
	system("pause");
}
void GiaiDau::BangXepHang(string tenFile)
{
	ofstream f;
	f.open(tenFile, ios_base::out);
	f << setw(3) << "STT";
	f << setw(20) << "Ten cau lac bo";
	f << setw(20) << "So tran";
	f << setw(10) << "Tranthang";
	f << setw(10) << "Tranhoa";
	f << setw(10) << "Tranthua";
	f << setw(10) << "Hieu so";
	f << setw(10) << "Diem" << endl;
	for (int i = 0; i < dsDoiBong.size(); i++)
	{
		if (i < 9)
		{
			f << " " << i + 1;
		}
		else f << i + 1;
		dsDoiBong[i]->GhiDsDoiBong(f);
	}
}
void GiaiDau::KetQuaVongDau()
{
	system("cls");
	this->IntroTranDau();
	for (int i = 0; i < dsTranDau.size(); i++)
	{	
		dsTranDau[i]->ThongTinTranDau();
	}
}
void GiaiDau::KetQuaVongDau(string tenFile)
{
	ofstream f;
	f.open(tenFile, ios_base::app);
	f << "\nThoi gian thi dau";
	f << setw(20) << "Doi nha";
	f << setw(20) << " Ket Qua  ";
	f << setw(18) << "Doi khach" << endl << endl;
	for (int i = 0; i < dsTranDau.size(); i++)
	{
		dsTranDau[i]->GhiFileTranDau(f);
	}
}
void GiaiDau::CapNhatKetQuaVongDau()
{
	cout << "\n\n\t\tCAP NHAT KET QUA TRAN DAU!!!";
	for (int i = 0; i < dsTranDau.size(); i++)
	{
		KetQuaVongDau();
		dsTranDau[i]->CapNhatKetQuaTranDau();
		string name1 = dsTranDau[i]->DoiNha.getTenclb();
		string name2 = dsTranDau[i]->DoiKhach.getTenclb();
		int vt1 = this->TimKiemDoiBong(name1);
		int vt2 = this->TimKiemDoiBong(name2);
		int a = dsTranDau[i]->tisoDoiNha;
		int b = dsTranDau[i]->tisoDoiKhach;
		if (a > b)
		{
			dsDoiBong[vt1]->setDiem(3);
			dsDoiBong[vt1]->setHieuso(a - b);
			dsDoiBong[vt1]->setTranThang(1);
			dsDoiBong[vt2]->setDiem(0);
			dsDoiBong[vt2]->setHieuso(b - a);
			dsDoiBong[vt2]->setTranThua(1);
		}
		else if (a < b)
		{
			dsDoiBong[vt1]->setDiem(0);
			dsDoiBong[vt1]->setHieuso(a - b);
			dsDoiBong[vt1]->setTranThua(1);
			dsDoiBong[vt2]->setDiem(3);
			dsDoiBong[vt2]->setHieuso(b - a);
			dsDoiBong[vt2]->setTranThang(1);
		}
		else
		{
			dsDoiBong[vt1]->setDiem(1);
			dsDoiBong[vt1]->setHieuso(0);
			dsDoiBong[vt1]->setTranHoa(1);
			dsDoiBong[vt2]->setDiem(1);
			dsDoiBong[vt2]->setHieuso(0);
			dsDoiBong[vt2]->setTranHoa(1);
		}
	}
	KetQuaVongDau();
}
void GiaiDau::TruyCapDoiBong(int i)
{
	int n = this->dsDoiBong.size();
	if (i < 1 || i > n)
	{
		cout << "\nThu hang do khong ton tai!!!" << endl;
	}
	else {
		string tenFile = dsDoiBong[i]->getTenclb() + ".txt";
		dsDoiBong[i]->Menu(tenFile);
	}
}
void GiaiDau::IntroDoiBong()
{
	cout << setw(3) << "STT";
	cout << setw(20) << "Ten cau lac bo";
	cout << setw(20) << "So tran";
	cout << setw(10) << "Tranthang";
	cout << setw(10) << "Tranhoa";
	cout << setw(10) << "Tranthua";
	cout << setw(10) << "Hieu so";
	cout << setw(10) << "Diem" << endl;
}
void GiaiDau::IntroTranDau()
{
	cout << "Thoi gian thi dau";
	cout << setw(20) << "Doi nha";
	cout << setw(20) << " Ket Qua  ";
	cout << setw(18) << "Doi khach" << endl << endl;
}
int GiaiDau::TimKiemDoiBong(string name)
{
	int i;
	for (i = 0; i < dsDoiBong.size(); i++)
	{
		if (dsDoiBong[i]->getTenclb() == name)
			break;
	}
	return i;
}
void GiaiDau::QuanLyVongDau()
{
	this->DocdsDoiBong();
	int vongdau,stt;
	do
	{
		system("cls");
		cout << "\n\n\t\t++++++++QUAN LY VONG DAU++++++++";
		cout << "\n\n\t\t 1.Vong 1.";
		cout << "\n\n\t\t 2.Vong 2.";
		cout << "\n\n\t\t 3.Vong 3.";
		cout << "\n\n\t\t 4.Vong 4.";
		cout << "\n\n\t\t 5.Vong 5.";
		cout << "\n\n\t\t 6.Vong 6.";
		cout << "\n\n\t\t 7.Vong 7.";
		cout << "\n\n\t\t 8.Vong 8.";
		cout << "\n\n\t\t 9.Vong 9.";
		cout << "\n\n\t\t10.Bang xep hang hien tai.";
		cout << "\n\n\t\t 0.Ket thuc mua giai." << endl;
		cout << "vongdau = "; cin >> vongdau;
		switch (vongdau)
		{
		case 1:
		{
			string Round = "Round1.txt";
			DocdsTranDau(Round);
			this->CapNhatKetQuaVongDau();
			this->KetQuaVongDau(Round);
			cout << "\n\n\t\tBANG XEP HANG GIAI DAU SAU VONG " << vongdau << endl << endl;
			this->GanSoTranDau(vongdau);
			this->SelectSort();
			this->BangXepHang();
			this->BangXepHang("BangXepHang.txt");
			cout << "\\n\n\t\tTRUY CAP DOI BONG!" << endl;
			cout << "Nhap thu hang cua doi de truy cap: "; cin >> stt;
			this->TruyCapDoiBong(stt-1);
			break;
		}
		case 2:
		{
			string Round = "Round2.txt";
			dsTranDau.clear();
			DocdsTranDau(Round);
			this->CapNhatKetQuaVongDau();
			this->KetQuaVongDau(Round);
			cout << "\n\n\t\tBANG XEP HANG GIAI DAU SAU VONG " << vongdau << endl << endl;
			this->GanSoTranDau(vongdau);
			this->SelectSort();
			this->BangXepHang();
			this->BangXepHang("BangXepHang.txt");
			cout << "\\n\n\t\tTRUY CAP DOI BONG!" << endl;
			cout << "Nhap thu hang cua doi de truy cap: "; cin >> stt;
			this->TruyCapDoiBong(stt-1);
			break;
		}
		case 3:
		{
			string Round = "Round3.txt";
			dsTranDau.clear();
			DocdsTranDau(Round);
			this->CapNhatKetQuaVongDau();
			this->KetQuaVongDau(Round);
			cout << "\n\n\t\tBANG XEP HANG GIAI DAU SAU VONG " << vongdau << endl << endl;
			this->GanSoTranDau(vongdau);
			this->SelectSort();
			this->BangXepHang();
			this->BangXepHang("BangXepHang.txt");
			cout << "\\n\n\t\tTRUY CAP DOI BONG!" << endl;
			cout << "Nhap thu hang cua doi de truy cap: "; cin >> stt;
			this->TruyCapDoiBong(stt);
			break;
		}
		case 4:
		{
			string Round = "Round4.txt";
			dsTranDau.clear();
			DocdsTranDau(Round);
			this->CapNhatKetQuaVongDau();
			this->KetQuaVongDau(Round);
			cout << "\n\n\t\tBANG XEP HANG GIAI DAU SAU VONG " << vongdau << endl << endl;
			this->GanSoTranDau(vongdau);
			this->SelectSort();
			this->BangXepHang();
			this->BangXepHang("BangXepHang.txt");
			cout << "\\n\n\t\tTRUY CAP DOI BONG!" << endl;
			cout << "Nhap thu hang cua doi de truy cap: "; cin >> stt;
			this->TruyCapDoiBong(stt-1);
			break;
		}
		case 5:
		{
			string Round = "Round5.txt";
			dsTranDau.clear();
			DocdsTranDau(Round);
			this->CapNhatKetQuaVongDau();
			this->KetQuaVongDau(Round);
			cout << "\n\n\t\tBANG XEP HANG GIAI DAU SAU VONG " << vongdau << endl << endl;
			this->GanSoTranDau(vongdau);
			this->SelectSort();
			this->BangXepHang();
			this->BangXepHang("BangXepHang.txt");
			cout << "\\n\n\t\tTRUY CAP DOI BONG!" << endl;
			cout << "Nhap thu hang cua doi de truy cap: "; cin >> stt;
			this->TruyCapDoiBong(stt-1);
			break;
		}
		case 6:
		{
			string Round = "Round6.txt";
			dsTranDau.clear();
			DocdsTranDau(Round);
			this->CapNhatKetQuaVongDau();
			this->KetQuaVongDau(Round);
			cout << "\n\n\t\tBANG XEP HANG GIAI DAU SAU VONG " << vongdau << endl << endl;
			this->GanSoTranDau(vongdau);
			this->SelectSort();
			this->BangXepHang();
			this->BangXepHang("BangXepHang.txt");
			cout << "\\n\n\t\tTRUY CAP DOI BONG!" << endl;
			cout << "Nhap thu hang cua doi de truy cap: "; cin >> stt;
			this->TruyCapDoiBong(stt-1);
			break;
		}
		case 7:
		{
			string Round = "Round7.txt";
			dsTranDau.clear();
			DocdsTranDau(Round);
			this->CapNhatKetQuaVongDau();
			this->KetQuaVongDau(Round);
			cout << "\n\n\t\tBANG XEP HANG GIAI DAU SAU VONG " << vongdau << endl << endl;
			this->GanSoTranDau(vongdau);
			this->SelectSort();
			this->BangXepHang();
			this->BangXepHang("BangXepHang.txt");
			cout << "\\n\n\t\tTRUY CAP DOI BONG!" << endl;
			cout << "Nhap thu hang cua doi de truy cap: "; cin >> stt;
			this->TruyCapDoiBong(stt-1);
			break;
		}
		case 8:
		{
			string Round = "Round8.txt";
			dsTranDau.clear();
			DocdsTranDau(Round);
			this->CapNhatKetQuaVongDau();
			this->KetQuaVongDau(Round);
			cout << "\n\n\t\tBANG XEP HANG GIAI DAU SAU VONG " << vongdau << endl << endl;
			this->GanSoTranDau(vongdau);
			this->SelectSort();
			this->BangXepHang();
			this->BangXepHang("BangXepHang.txt");
			cout << "\\n\n\t\tTRUY CAP DOI BONG!" << endl;
			cout << "Nhap thu hang cua doi de truy cap: "; cin >> stt;
			this->TruyCapDoiBong(stt-1);
			break;
		}
		case 9:
		{
			string Round = "Round9.txt";
			dsTranDau.clear();
			DocdsTranDau(Round);
			this->CapNhatKetQuaVongDau();
			this->KetQuaVongDau(Round);
			cout << "\n\n\t\tBANG XEP HANG GIAI DAU SAU VONG " << vongdau << endl << endl;
			this->GanSoTranDau(vongdau);
			this->SelectSort();
			this->BangXepHang();
			this->BangXepHang("BangXepHang.txt");
			cout << "\\n\n\t\tTRUY CAP DOI BONG!" << endl;
			cout << "Nhap thu hang cua doi de truy cap: "; cin >> stt;
			this->TruyCapDoiBong(stt-1);
			break;
		}
		case 10:
		{
			this->BangXepHang();
			this->BangXepHang("BangXepHang.txt");
			cout << "\\n\n\t\tTRUY CAP DOI BONG!" << endl;
			cout << "Nhap thu hang cua doi de truy cap: "; cin >> stt;
			this->TruyCapDoiBong(stt - 1);
			break;
		}
		default:
			break;
		}
	}while (vongdau);
}
void GiaiDau::GanSoTranDau(int s)
{
	for (int i = 0; i < dsDoiBong.size(); i++)
	{
		dsDoiBong[i]->setTranThamGiaThiDau(s);
	}
}

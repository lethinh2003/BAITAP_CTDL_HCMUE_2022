#include <iostream>
#include <string>
using namespace std;

class SinhVien {
	string _strMaSinhVien, _strLop, _strNgaySinh, _strHoTen;
	float _fDiemTrungBinh;
public:
	SinhVien();
	~SinhVien();
	void display();
	void add();
	float getDTB();
	void setDTB(float d);
	string getMaSinhVien();
};
SinhVien::SinhVien() {

}
SinhVien::~SinhVien() {

}
float SinhVien::getDTB() {
	return _fDiemTrungBinh;
}
void SinhVien::setDTB(float d) {
	_fDiemTrungBinh = d;
}
string SinhVien::getMaSinhVien() {
	return _strMaSinhVien;
}
void SinhVien::display() {
	cout << "{" << _strMaSinhVien << "," << _strHoTen << "," << _strLop << "," << _strNgaySinh << "," << _fDiemTrungBinh << "}";
}
void SinhVien::add() {
	cout << "Nhap Ma Sinh Vien: ";
	cin >> _strMaSinhVien;
	cout << "Nhap Lop Sinh Vien: ";
	cin >> _strLop;
	cout << "Nhap Ngay Sinh Sinh Vien: ";
	cin >> _strNgaySinh;
	cout << "Nhap DTB Sinh Vien: ";
	cin >> _fDiemTrungBinh;
	cin.ignore();
	cout << "Nhap Ho Ten Sinh Vien: ";
	getline(cin, _strHoTen);
}
class LinkedList;
class Node {
	friend LinkedList;
	SinhVien _data;
	Node* _pNext;
public:
	Node(SinhVien data);
	void display();

};
Node::Node(SinhVien data) {
	_data = data;
	_pNext = NULL;
}
void Node::display() {
	_data.display();
	cout << endl;
}

class LinkedList {
	Node* _pHead;
	Node* _pTail;
	int _iSoLuongPhanTu;
public:
	LinkedList();
	~LinkedList();
	void addHead(SinhVien data);
	void addTail(SinhVien data);
	void display();
	void danhSachDTBLonHon5();
	void sapXepMaSinhVien();
	Node* timKiemTuanTu(string x);
	Node* searchPre(string x);
	void xoaSinhVien(string x);
	void removeHead();
	void capNhatDiemTB(string x, float d);
	Node* phanTuThuK(int k);
	void timKiemNhiPhan(string x);

};

LinkedList::LinkedList() {
	_iSoLuongPhanTu = 0;
}
LinkedList::~LinkedList() {

}
void LinkedList::addHead(SinhVien data) {
	Node* pAdd = new Node(data);
	if (_pHead == NULL) {
		_pHead = pAdd;
		_pTail = pAdd;
	}
	else {
		pAdd->_pNext = _pHead;
		_pHead = pAdd;
	}
	_iSoLuongPhanTu++;
}
void LinkedList::addTail(SinhVien data) {
	Node* pAdd = new Node(data);
	if (_pHead == NULL) {
		_pHead = pAdd;
		_pTail = pAdd;
	}
	else {
		_pTail->_pNext = pAdd;
		_pTail = pAdd;
	}
	_iSoLuongPhanTu++;
}
void LinkedList::display() {
	Node* pWalker = _pHead;
	while (pWalker != NULL) {
		pWalker->display();
		pWalker = pWalker->_pNext;
	}
}
void LinkedList::danhSachDTBLonHon5() {
	Node* pWalker = _pHead;
	while (pWalker != NULL) {
		if (pWalker->_data.getDTB() >= 5) {
			pWalker->display();
		}
		pWalker = pWalker->_pNext;
	}
}
void LinkedList::capNhatDiemTB(string x, float d) {
	Node* pSearch = timKiemTuanTu(x);
	if (pSearch != NULL) {
		pSearch->_data.setDTB(d);
		cout << "Cap nhat thanh cong" << endl;
	}
	else {
		cout << "Khong tim thay sinh vien" << endl;
	}

}
Node* LinkedList::timKiemTuanTu(string x) {
	Node* pWalker = _pHead;
	while (pWalker != NULL) {
		if (pWalker->_data.getMaSinhVien() == x) {
			return pWalker;
		}
		pWalker = pWalker->_pNext;
	}
	return pWalker;
}
Node* LinkedList::searchPre(string x) {
	Node* pWalker = _pHead;
	while (pWalker != NULL) {
		Node* pTemp = pWalker->_pNext;
		if (pTemp != NULL) {
			if (pTemp->_data.getMaSinhVien() == x) {
				return pWalker;
			}
		}
		pWalker = pWalker->_pNext;
	}
	return pWalker;
}
void LinkedList::sapXepMaSinhVien() {
	Node* pTemp, * pTemp2;
	Node* pMin;
	for (pTemp = _pHead; pTemp != NULL && pTemp->_pNext != NULL; pTemp = pTemp->_pNext) {
		pMin = pTemp;
		for (pTemp2 = pTemp->_pNext; pTemp2 != NULL; pTemp2 = pTemp2->_pNext) {
			if (pTemp2->_data.getMaSinhVien() < pMin->_data.getMaSinhVien()) {
				pMin = pTemp2;
			}
		}
		if (pMin != pTemp) {
			swap(pMin->_data, pTemp->_data);
		}

	}
}
void LinkedList::xoaSinhVien(string x) {
	Node* pSearch = timKiemTuanTu(x);
	if (pSearch == _pHead) {
		removeHead();
	}
	else {
		Node* pWalker = _pHead;
		Node* pTemp = NULL;
		while (pWalker != NULL && pWalker->_data.getMaSinhVien() != x) {
			pTemp = pWalker;
			pWalker = pWalker->_pNext;
		}
		if (pWalker == NULL) {
			return;
		}
		if (pTemp != NULL) {
			if (pWalker == _pTail) {
				_pTail = pTemp;
				_pTail->_pNext = NULL;
			}
			pTemp->_pNext = pWalker->_pNext;
			delete pWalker;
			_iSoLuongPhanTu--;
		}
	}
}
void LinkedList::timKiemNhiPhan(string x) {
	int left = 1;
	int right = _iSoLuongPhanTu;
	int mid;
	bool check = false;
	while (left <= right) {
		mid = (left + right) / 2;
		Node* pSearch = phanTuThuK(mid);
		if (pSearch->_data.getMaSinhVien() == x) {
			check = true;
			pSearch->display();
			break;
		}
		else if (pSearch->_data.getMaSinhVien() > x) {
			right = mid - 1;
		} else if (pSearch->_data.getMaSinhVien() < x) {
			left = mid + 1;
		}
	}
	if (!check) {
		cout << "Khong tim thay sinh vien" << endl;
	}
}
void LinkedList::removeHead() {
	Node* pTemp = _pHead;
	_pHead = pTemp->_pNext;
	if (_pHead == NULL) {
		_pTail = NULL;
	}
	delete pTemp;
	_iSoLuongPhanTu--;
}
Node* LinkedList::phanTuThuK(int k) {
	Node* pWalker = _pHead;
	if (k > _iSoLuongPhanTu || k < 1) {
		return NULL;
	}
	int dem = 0;
	while (pWalker != NULL) {
		dem++;
		if (dem == k) {
			return pWalker;
		}
		pWalker = pWalker->_pNext;
	}
	return pWalker;
}
int main() {
	LinkedList LopSinhVien;
	int iOption = 0;
	do {
		system("cls");
		cout << "Cac thao tac voi Lop Sinh Vien: " << endl;
		cout << "0. Ket thuc chuong trinh." << endl;
		cout << "1. CAU A: Them sinh vien vao cuoi danh sach." << endl;
		cout << "2. CAU B: Hien thi danh sach sinh vien." << endl;
		cout << "3. CAU C: Hien thi danh sach sinh vien co diem trung binh >= 5." << endl;
		cout << "4. CAU D: Tim kiem sinh vien theo ma sinh vien." << endl;
		cout << "5. CAU E: Sap xep sinh vien tang dan theo ma sinh vien." << endl;
		cout << "6. CAU F: Tim kiem nhi phan theo ma sinh vien." << endl;
		cout << "7. CAU G: Xoa sinh vien theo ma sinh vien." << endl;
		cout << "8. CAU H: Cap nhat diem trung binh cua sinh vien." << endl;
		cout << "Moi ban chon thao tac:" << endl;
		cin >> iOption;
		switch (iOption) {
		case 1: 
		{
			cout << "Them sinh vien vao cuoi danh sach:" << endl;
			SinhVien x;
			x.add();
			LopSinhVien.addTail(x);
			system("pause");
			break;

		}
		case 2:
		{
			cout << "Danh sach sinh vien:" << endl;
			LopSinhVien.display();
			system("pause");
			break;

		}
		case 3:
		{
			cout << "Danh sach sinh vien co diem trung binh >= 5:" << endl;
			LopSinhVien.danhSachDTBLonHon5();
			system("pause");
			break;

		}
		case 4:
		{
			cout << "Tim kiem sinh vien theo ma sinh vien:" << endl;
			cout << "Nhap ma sinh vien can tim: " << endl;
			string x;
			cin >> x;
			Node* result = LopSinhVien.timKiemTuanTu(x);
			if (result != NULL) {
				result->display();
			}
			else {
				cout << "Khong tim thay sinh vien" << endl;
			}
			system("pause");
			break;

		}
		case 5:
		{
			cout << "Sap xep sinh vien tang dan theo ma sinh vien:" << endl;
			LopSinhVien.sapXepMaSinhVien();
			LopSinhVien.display();
			system("pause");
			break;

		}
		case 6:
		{
			cout << "Tim kiem nhi phan theo ma sinh vien" << endl;
			LopSinhVien.sapXepMaSinhVien();
			cout << "Nhap ma sinh vien can tim: " << endl;
			string x;
			cin >> x;
			LopSinhVien.timKiemNhiPhan(x);
			system("pause");
			break;

		}
		case 7:
		{
			cout << "Xoa sinh vien theo ma sinh vien:" << endl;
			cout << "Nhap ma sinh vien can xoa: " << endl;
			string x;
			cin >> x;

			LopSinhVien.xoaSinhVien(x);
			system("pause");
			break;

		}
		case 8:
		{
			cout << "Cap nhat diem trung binh cua sinh vien: " << endl;
			cout << "Nhap ma sinh vien can cap nhat: " << endl;
			string x;
			cin >> x;
			cout << "Nhap diem trung binh can cap nhat: " << endl;
			float d;
			cin >> d;

			LopSinhVien.capNhatDiemTB(x, d);
			system("pause");
			break;

		}
		default:
			break;
		}

	}
	while (iOption != 0);
	return 0;

}
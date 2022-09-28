#include <iostream>
#include <sstream>
#define MAX_SIZE 10;
using namespace std;
class SINHVIEN;
class MONHOC {
	friend SINHVIEN;
	string _sMaMon, _sTenMon;
	int _iSoTinChi;
	float _fDiem;

public:
	MONHOC();
	MONHOC(string maMon, string tenMon, int soTinChi, float diem);
	void display();

};
MONHOC::MONHOC() {


}
MONHOC::MONHOC(string maMon, string tenMon, int soTinChi, float diem) {
	_sMaMon = maMon;
	_sTenMon = tenMon;
	_iSoTinChi = soTinChi;
	_fDiem = diem;
}
void MONHOC::display() {
	cout << "Ma Mon: " << _sMaMon << endl;
	cout << "\tTen Mon: " << _sTenMon << endl;
	cout << "\tSo Tin Chi: " << _iSoTinChi << endl;
	cout << "\tDiem: " << _fDiem << endl;

}
class LOPSINHVIEN;
class SINHVIEN {
	friend LOPSINHVIEN;
	string _sMaSinhVien, _sHoTen, _sNgaySinh;
	MONHOC* _monHoc;
	int _iSoMonHoc;
	int _iSiSoMonHoc;
public:
	SINHVIEN();
	SINHVIEN(int soMonHoc);
	~SINHVIEN();
	void add(string maSinhVien, string hoTen, string ngaySinh);
	void addMonHoc(MONHOC lecture);
	void display();
	void suaHoTen(string hoTen);
	int getNamSinh();
	float diemTrungBinh();
	bool datDieuKienHocBong();


};
SINHVIEN::SINHVIEN() {
	_iSoMonHoc = MAX_SIZE;
	_monHoc = new MONHOC[_iSoMonHoc];
	_iSiSoMonHoc = 0;
}
SINHVIEN::SINHVIEN(int soMonHoc) {
	_iSoMonHoc = soMonHoc > 0 ? soMonHoc : MAX_SIZE;
	_monHoc = new MONHOC[_iSoMonHoc];
	_iSiSoMonHoc = 0;
}
void SINHVIEN::add(string maSinhVien, string hoTen, string ngaySinh) {
	_sMaSinhVien = maSinhVien;
	_sHoTen = hoTen;
	_sNgaySinh = ngaySinh;

}
int SINHVIEN::getNamSinh() {
	string namSinh = _sNgaySinh.substr(6);
	stringstream sss;
	sss << namSinh;
	int result;
	sss >> result;
	return result;

}
bool SINHVIEN::datDieuKienHocBong() {
	if (diemTrungBinh() >= 7) {
		for (int i = 0; i < _iSiSoMonHoc; i++) {
			if (_monHoc[i]._fDiem < 5) {
				return false;
			}
		}
		return true;
	}
	else {
		return false;
	}
}
void SINHVIEN::addMonHoc(MONHOC lecture) {
	if (_iSiSoMonHoc != _iSoMonHoc) {
		_monHoc[_iSiSoMonHoc] = lecture;
		_iSiSoMonHoc++;
	}
	else {
		cout << "HOC SINH NAY DA DAY MON HOC!" << endl;
	}
}
float SINHVIEN::diemTrungBinh() {
	float S = 0;
	for (int i = 0; i < _iSiSoMonHoc; i++) {
		S = S + _monHoc[i]._fDiem;
	}
	return S / _iSiSoMonHoc;
}
void SINHVIEN::suaHoTen(string hoTen) {
	_sHoTen = hoTen;
}
void SINHVIEN::display() {
	cout << "Ma SV: " << _sMaSinhVien << endl;
	cout << "Ho Ten SV: " << _sHoTen << endl;
	cout << "Ngay Sinh: " << _sNgaySinh << endl;
	cout << "Mon Hoc: " << endl;
	for (int i = 0; i < _iSiSoMonHoc; i++) {
		cout << "\tSTT: " << i + 1 << endl; 
		cout << "\t";
		_monHoc[i].display();
	}
	cout << "Diem Trung Binh: " << diemTrungBinh() << endl;
}
SINHVIEN::~SINHVIEN() {
	//delete[] _monHoc;
}
class LOPSINHVIEN {
	SINHVIEN* _sinhVien;
	int _iSoLuongSinhVien;
	int _iSiSoSinhVien;
public:
	LOPSINHVIEN();
	LOPSINHVIEN(int soLuong);
	~LOPSINHVIEN();
	bool isFull();
	void add(SINHVIEN data);
	void display();
	int timSinhVien(string maSinhVien);
	int timSinhVienNhiPhan(string hoTen);
	void suaHoTen(int pos ,string hoTen);
	void insertionSort(int type);
	void selectionSort();
	void quickSort(int left, int right);
	void removeAt(int x);
	void danhSachHocBong();
	int getSize();
};

LOPSINHVIEN::LOPSINHVIEN() {
	_iSoLuongSinhVien = MAX_SIZE;
	_sinhVien = new SINHVIEN[_iSoLuongSinhVien];
	_iSiSoSinhVien = 0;
}
LOPSINHVIEN::~LOPSINHVIEN() {
	delete[] _sinhVien;
}
LOPSINHVIEN::LOPSINHVIEN(int soLuong) {
	_iSoLuongSinhVien = soLuong > 0 ? soLuong : MAX_SIZE;
	_sinhVien = new SINHVIEN[_iSoLuongSinhVien];
	_iSiSoSinhVien = 0;
}
bool LOPSINHVIEN::isFull() {
	if (_iSiSoSinhVien == _iSoLuongSinhVien) {
		return true;
	}
	else {
		return false;
	}
}
void LOPSINHVIEN::add(SINHVIEN data) {
	if (!isFull()) {
		_sinhVien[_iSiSoSinhVien] = data;
		_iSiSoSinhVien++;
	}
	else {
		cout << "LOP HOC DA FULL!" << endl;
	}

}
int LOPSINHVIEN::getSize() {
	return _iSiSoSinhVien;

}
int LOPSINHVIEN::timSinhVien(string maSinhVien) {
	for (int i = 0; i < _iSiSoSinhVien; i++) {
		if (_sinhVien[i]._sMaSinhVien == maSinhVien) {
			return i;
		}
	}
	return -1;
}
int LOPSINHVIEN::timSinhVienNhiPhan(string hoTen) {
	int first = 0;
	int last = _iSiSoSinhVien - 1;
	int mid;
	while (first <= last) {
		mid = (first + last) / 2;
		if (_sinhVien[mid]._sHoTen < hoTen) {
			first = mid + 1;
		}
		else if (_sinhVien[mid]._sHoTen > hoTen) {
			last = mid - 1;
		}
		else if (_sinhVien[mid]._sHoTen == hoTen) {
			return mid;
		}
	}
	return -1;
}
void LOPSINHVIEN::display() {
	for (int i = 0; i < _iSiSoSinhVien; i++) {
		cout << "--------" << endl;
		_sinhVien[i].display();
		cout << "--------" << endl;
	}
}
void LOPSINHVIEN::suaHoTen(int pos, string hoTen) {
	if (pos >= 0 && pos < _iSiSoSinhVien) {
		_sinhVien[pos].suaHoTen(hoTen);
	}

}
void LOPSINHVIEN::insertionSort(int type = -1) {
	int pos;
	SINHVIEN x;
	//xep giam dan
	if (type == -1) {
		for (int i = 1; i < _iSiSoSinhVien; i++) {
			x = _sinhVien[i];
			for (pos = i; pos > 0 &&  _sinhVien[pos]._sHoTen > _sinhVien[pos-1]._sHoTen; pos--) {
				swap(_sinhVien[pos], _sinhVien[pos - 1]);
			}
			_sinhVien[pos] = x;

		}
	} else if (type == 1) {
		for (int i = 1; i < _iSiSoSinhVien; i++) {
			x = _sinhVien[i];
			for (pos = i; pos > 0 && _sinhVien[pos]._sHoTen < _sinhVien[pos - 1]._sHoTen; pos--) {
				swap(_sinhVien[pos], _sinhVien[pos - 1]);
			}
			_sinhVien[pos] = x;

		}
	}
}
void LOPSINHVIEN::selectionSort() {
	for (int i = 0; i < _iSiSoSinhVien - 1; i++) {
		int min = i;
		for (int j = i + 1; j < _iSiSoSinhVien; j++) {
			if (_sinhVien[j].diemTrungBinh() < _sinhVien[i].diemTrungBinh()) {
				min = j;
			}
		}
		if (min != i) {
			swap(_sinhVien[i], _sinhVien[min]);
		}
	}

}
void LOPSINHVIEN::quickSort(int left, int right) {
	if (left >= right) {
		return;
	}
	int i = left;
	int j = right;
	SINHVIEN x = _sinhVien[(left + right) / 2];
	while (i < j) {
		while (_sinhVien[i].getNamSinh() < x.getNamSinh()) {
			i++;
		}
		while (_sinhVien[j].getNamSinh() > x.getNamSinh()) {
			j--;
		}
		if (i <= j) {
			swap(_sinhVien[i], _sinhVien[j]);
			i++;
			j--;
		}
	}
	quickSort(left, j);
	quickSort(i, right);


}
void LOPSINHVIEN::removeAt(int x) {
	if (x != -1) {
		for (int i = x + 1; i < _iSiSoSinhVien; i++) {
			_sinhVien[i - 1] = _sinhVien[i];
		}
		_iSiSoSinhVien--;
	}
}
void LOPSINHVIEN::danhSachHocBong() {
	for (int i = 0; i < _iSiSoSinhVien; i++) {
		if (_sinhVien[i].datDieuKienHocBong()) {
			_sinhVien[i].display();
		}
	}
}
int main() {
	LOPSINHVIEN LOPCNTTCK47(40);
	// Khoi tao sinh vien Thinh co 2 mon hoc
	SINHVIEN THINH(2);
	MONHOC OOP("2121COMP1017", "Lap trinh huong doi tuong", 3, 7.3);
	MONHOC LTNC("2121COMP1013", "Lap trinh nang cao", 3, 9.7);
	THINH.add("47.01.104.202", "Le Van Thinh", "22/10/2003");
	THINH.addMonHoc(OOP);
	THINH.addMonHoc(LTNC);
	LOPCNTTCK47.add(THINH);
	// Khoi tao sinh vien Teo co 2 mon hoc
	SINHVIEN TEO(2);
	MONHOC OOP2("2121COMP1017", "Lap trinh huong doi tuong", 3, 6);
	MONHOC LTNC2("2121COMP1013", "Lap trinh nang cao", 3, 7);
	TEO.add("47.01.104.203", "Le Van Teo", "23/01/2001");
	TEO.addMonHoc(OOP2);
	TEO.addMonHoc(LTNC2);
	LOPCNTTCK47.add(TEO);
	char cOption = '0';
	do {
		system("cls");
		cout << "0. Thoat chuong trinh." << endl;
		cout << "1. Cau b." << endl;
		cout << "2. Cau c." << endl;
		cout << "3. Cau d." << endl;
		cout << "4. Cau e." << endl;
		cout << "5. Cau f." << endl;
		cout << "6. Cau g." << endl;
		cout << "Nhap thao tac: ";
		cin >> cOption;
		switch (cOption)
		{
		case '0': {
			break;
		}
		case '1': {
			//CAU b
			//tim sinh vien sau do sua ten thanh Thinh Van Le
			int iPosSinhVien = LOPCNTTCK47.timSinhVien("47.01.104.202");
			if (iPosSinhVien != -1) {
				LOPCNTTCK47.suaHoTen(iPosSinhVien, "Thinh Van Le");
			}
			cout << "DANH SACH SINH VIEN SAU KHI CAU B:" << endl;
			LOPCNTTCK47.display();
			system("pause");
			break;
		}
		case '2': {
			//Cau c
			LOPCNTTCK47.insertionSort();
			cout << "DANH SACH SINH VIEN SAU KHI CAU C:" << endl;
			LOPCNTTCK47.display();
			system("pause");
			break;
		}
		case '3': {
			//Cau d
			//xep giam dan theo ho ten
			LOPCNTTCK47.insertionSort();
			int iPosSinhVien = LOPCNTTCK47.timSinhVienNhiPhan("Le Van Thinh");
			LOPCNTTCK47.removeAt(iPosSinhVien);
			cout << "DANH SACH SINH VIEN SAU KHI CAU D:" << endl;
			LOPCNTTCK47.display();

			system("pause");
			break;
		}
		case '4': {
			//cau e
			LOPCNTTCK47.selectionSort();
			cout << "DANH SACH SINH VIEN SAU KHI CAU E:" << endl;
			LOPCNTTCK47.display();
			system("pause");
			break;
		}
		case '5': {
			//cau f
			cout << "DANH SACH SINH VIEN SAU KHI CAU F:" << endl;
			LOPCNTTCK47.danhSachHocBong();
			cout << endl;
			system("pause");
			break;
		}
		case '6': {
			//cau g
			LOPCNTTCK47.quickSort(0, LOPCNTTCK47.getSize() - 1);
			cout << "DANH SACH SINH VIEN SAU KHI CAU G:" << endl;
			LOPCNTTCK47.display();
			system("pause");
			break;
		}
		default:
			break;
		}
	} while (cOption != '0');


	


	return 0;
}
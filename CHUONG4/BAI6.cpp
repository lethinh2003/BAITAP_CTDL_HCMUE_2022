#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class HangHoa {
	string _strMaHang;
	string _strTenHang;
	int _iSoLuong;
	int _iDonGia;
public:
	HangHoa();
	HangHoa(string maHang, string tenHang, int soLuong, int donGia);
	void display();
	friend istream& operator >> (istream& is, HangHoa& P);
	friend ostream& operator << (ostream& os, HangHoa& P);
};
HangHoa::HangHoa() {
	_strMaHang = "";
	_strTenHang = "";
	_iSoLuong = 0;
	_iDonGia = 0;
}
HangHoa::HangHoa(string maHang, string tenHang, int soLuong, int donGia) {
	_strMaHang = maHang;
	_strTenHang = tenHang;
	_iSoLuong = soLuong;
	_iDonGia = donGia;
}
void HangHoa::display() {
	cout << _strMaHang << "|" << _strTenHang << "|" << _iSoLuong << "|" << _iDonGia;
}
istream& operator >> (istream& is, HangHoa& P) {
	is.ignore();
	cout << "Nhap ten hang: ";
	getline(is, P._strTenHang);
	cout << "Nhap ma hang: ";
	is >> P._strMaHang;

	cout << "Nhap so luong: ";
	is >> P._iSoLuong;
	cout << "Nhap don gia: ";
	is >> P._iDonGia;
	return is;

}
ostream& operator << (ostream& os, HangHoa& P) {
	os << P._strMaHang << "|" << P._strTenHang << "|" << P._iSoLuong << "|" << P._iDonGia;
	return os;

}
template <class DataType>
class Queue;
template <class DataType>
class Node {
	friend Queue<DataType>;
	DataType _data;
	Node* _pNext;
public:
	Node(DataType data);
	void display();
	DataType getData();
};
template <class DataType>
Node<DataType>::Node(DataType data) {
	_data = data;
	_pNext = NULL;
}
template <class DataType>
DataType Node<DataType>::getData() {
	return _data;
}
template <class DataType>
void Node<DataType>::display() {
	cout << _data;
}

template <class DataType>
class Queue {
	int _iSize;
	Node<DataType>* _pFront;
	Node<DataType>* _pRear;
public:
	Queue();
	~Queue();
	void display();
	void enQueue(DataType data);
	DataType deQueue();
	DataType peek();
	int getSize();
	void clear();


};
template <class DataType>
Queue<DataType>::Queue() {
	_iSize = 0;
	_pFront = NULL;
}
template <class DataType>
Queue<DataType>::~Queue() {
	clear();
}
template <class DataType>
void Queue<DataType>::display() {
	Node<DataType>* pWalker = _pFront;
	while (pWalker != NULL) {
		pWalker->display();
		cout << endl;
		pWalker = pWalker->_pNext;
	}
}
template <class DataType>
void Queue<DataType>::enQueue(DataType data) {
	Node<DataType>* pAdd = new Node<DataType>(data);
	if (_pFront == NULL) {
		_pFront = pAdd;
		_pRear = pAdd;
	}
	else {
		_pRear->_pNext = pAdd;
		_pRear = pAdd;
	}
	_iSize++;
}
template <class DataType>
DataType Queue<DataType>::deQueue() {
	Node<DataType>* pTemp = _pFront;
	if (pTemp == NULL) {
		cout << "Queue rong, khong the thuc hien." << endl;
		exit;
	}
	DataType dataTemp = pTemp->_data;
	_pFront = pTemp->_pNext;
	if (_pFront == NULL) {
		_pRear = NULL;
	}
	delete pTemp;
	_iSize--;
	return dataTemp;
}
template <class DataType>
DataType Queue<DataType>::peek() {
	Node<DataType>* pTemp = _pFront;
	if (pTemp == NULL) {
		cout << "Queue rong, khong the thuc hien." << endl;
		exit;
	}
	DataType dataTemp = pTemp->_data;
	return dataTemp;
}

template <class DataType>
int Queue<DataType>::getSize() {
	return _iSize;
}

template <class DataType>
void Queue<DataType>::clear() {
	while (_pFront != NULL) {
		deQueue();
	}


}



int main() {
	Queue<HangHoa> Kho;

	int iOption = 0;
	do {
		system("cls");
		cout << "0. Thoat chuong trinh" << endl;
		cout << "1. Them mat hang vao kho" << endl;
		cout << "2. Xem tat ca hang hoa" << endl;
		cout << "3. Xem mat hang sap xuat kho" << endl;
		cout << "4. Xuat mot mat hang ra xuat kho" << endl;
		cout << "5. Don kho" << endl;
		cout << "Nhap thao tac:" << endl;
		cin >> iOption;
		switch (iOption)
		{
		case 0: {
			break;
		}
		case 1: {
			cout << "Them mat hang vao kho:  " << endl;
			cout << "Nhap so luong mat hang muon them: " << endl;
			int n;
			HangHoa k;
			cin >> n;
			for (int i = 0; i < n; i++) {
				cin >> k;
				Kho.enQueue(k);
			}
			system("pause");
			break;
		}
		case 2: {
			cout << "Xem tat ca hang hoa" << endl;
			Kho.display();
			cout << endl;
			system("pause");
			break;
		}
		case 3: {
			cout << "Xem mat hang sap xuat kho" << endl;
			HangHoa item = Kho.peek();
			cout << item << endl;
			system("pause");
			break;
		}
		case 4: {
			cout << "Xuat mot mat hang ra xuat kho" << endl;
			HangHoa item = Kho.deQueue();
			cout << item << endl;
			system("pause");
			break;
		}

		case 5: {
			cout << "Don kho" << endl;
			Kho.clear();
			system("pause");
			break;
		}
		default:
			break;
		}


	} while (iOption != 0);









	return 0;
}

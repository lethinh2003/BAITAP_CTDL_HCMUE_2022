#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class ThongTinKhachHang {
	int _iSoGhe;
	string _strTen;
public:
	ThongTinKhachHang() {
		_iSoGhe = 0;
		_strTen = "";
	}
	void setSoGhe(int soGhe) {
		_iSoGhe = soGhe;
	}
	void setTen(string ten) {
		_strTen = ten;
	}
	int getSoGhe() {
		return _iSoGhe;
	}
	string getTen() {
		return _strTen;
	}
	friend ostream& operator << (ostream& os, ThongTinKhachHang& C) {
		os << C._iSoGhe << "|" << C._strTen;
		return os;
	}
};

template <class DataType>
class Queue;
template <class DataType>
class LinkedList;
template <class DataType>
class Node {
	friend Queue<DataType>;
	friend LinkedList<DataType>;
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

template <class DataType>
class LinkedList {
	int _iSize;
	Node<DataType>* _pHead;
	Node<DataType>* _pTail;
public:
	LinkedList();
	~LinkedList();
	void display();
	void addTail(DataType data);
	void addHead(DataType data);
	void addAfter(Node<DataType>* node, DataType data);
	void addAfter(DataType q, DataType data);
	Node<DataType>* search(DataType q);
	Node<DataType>* searchPre(Node<DataType>* node);
	Node<DataType>* searchPre(DataType data);
	void removeHead();
	void removeTail();
	void remove(Node<DataType>* node);
	void remove(DataType data);
	void removeAfter(Node<DataType>* node);
	void interchangeSort();
	int getSize();
	void clear();
	Node<DataType>* timTheoSoGhe(int data);


};
template <class DataType>
LinkedList<DataType>::LinkedList() {
	_iSize = 0;
	_pHead = NULL;
	_pTail = NULL;
}
template <class DataType>
LinkedList<DataType>::~LinkedList() {
	_iSize = 0;
	_pHead = NULL;
	_pTail = NULL;
}
template <class DataType>
void LinkedList<DataType>::display() {
	Node<DataType>* pWalker = _pHead;
	while (pWalker != NULL) {
		pWalker->display();
		cout << endl;
		pWalker = pWalker->_pNext;
	}
}
template <class DataType>
void LinkedList<DataType>::addTail(DataType data) {
	Node<DataType>* pAdd = new Node<DataType>(data);

	if (_pHead == NULL) {
		_pHead = pAdd;
		_pTail = pAdd;
	}
	else {
		_pTail->_pNext = pAdd;
		_pTail = pAdd;
	}
	_iSize++;

}
template <class DataType>
void LinkedList<DataType>::addHead(DataType data) {
	Node<DataType>* pAdd = new Node<DataType>(data);

	if (_pHead == NULL) {
		_pHead = pAdd;
		_pTail = pAdd;
	}
	else {
		pAdd->_pNext = _pHead;
		_pHead = pAdd;
	}
	_iSize++;

}

template <class DataType>
int LinkedList<DataType>::getSize() {
	return _iSize;
}
template <class DataType>
void LinkedList<DataType>::addAfter(DataType q, DataType data) {
	Node<DataType>* pAdd = new Node<DataType>(data);
	Node<DataType>* pNode = search(q);
	if (pNode != NULL) {
		pAdd->_pNext = pNode->_pNext;
		pNode->_pNext = pAdd;
		if (pNode == _pTail) {
			_pTail = pAdd;
		}
		_iSize++;
	}
	else {
		addHead(data);
	}

}
template <class DataType>
void LinkedList<DataType>::addAfter(Node<DataType>* node, DataType data) {
	Node<DataType>* pAdd = new Node<DataType>(data);
	if (node != NULL) {
		pAdd->_pNext = node->_pNext;
		node->_pNext = pAdd;
		if (node == _pTail) {
			_pTail = pAdd;
		}
		_iSize++;
	}
	else {
		addHead(data);
	}

}

template <class DataType>
void LinkedList<DataType>::removeHead() {
	Node<DataType>* pTemp = _pHead;
	if (pTemp != NULL) {
		_pHead = pTemp->_pNext;
		delete pTemp;
		if (_pHead == NULL) {
			_pTail = NULL;
		}
		_iSize--;
	}


}
template <class DataType>
void LinkedList<DataType>::removeTail() {
	Node<DataType>* pTemp = _pTail;
	if (pTemp == _pHead) {
		removeHead();
	}
	else {
		_pTail = searchPre(_pTail);
		_pTail->_pNext = NULL;
		delete pTemp;
		_iSize--;
	}


}
template <class DataType>
void LinkedList<DataType>::clear() {
	while (_pHead != NULL) {
		removeHead();
	}


}

template <class DataType>
void LinkedList<DataType>::remove(Node<DataType>* node) {
	if (node != NULL) {
		if (node == _pHead) {
			_pHead = _pHead->_pNext;
			if (_pHead == NULL) {
				_pTail == NULL;
			}
		}
		else {
			Node<DataType>* pPre = searchPre(node);
			if (pPre != NULL) {
				pPre->_pNext = node->_pNext;
				if (pPre->_pNext == NULL) {
					_pTail = pPre;
				}

			}
		}
		delete node;
		_iSize--;
	}


}
template <class DataType>
void LinkedList<DataType>::remove(DataType data) {
	Node<DataType>* node = search(data);
	if (node != NULL) {
		if (node == _pHead) {
			_pHead = _pHead->_pNext;
			if (_pHead == NULL) {
				_pTail == NULL;
			}
		}
		else {
			Node<DataType>* pPre = searchPre(node);
			if (pPre != NULL) {
				pPre->_pNext = node->_pNext;
				if (pPre->_pNext == NULL) {
					_pTail = pPre;
				}

			}
		}
		delete node;
		_iSize--;
	}


}
template <class DataType>
void LinkedList<DataType>::removeAfter(Node<DataType>* node) {
	if (node != NULL) {
		Node<DataType>* pNext = node->_pNext;
		if (pNext != NULL) {
			if (pNext == _pTail) {
				_pTail = node;
			}
			node->_pNext = pNext->_pNext;
			delete pNext;
			_iSize--;
		}
	}
	else {
		removeHead();
	}



}

template <class DataType>
void LinkedList<DataType>::interchangeSort() {
	Node<DataType>* pTemp;
	Node<DataType>* pTemp2;
	for (pTemp = _pHead; pTemp->_pNext != NULL; pTemp = pTemp->_pNext) {
		for (pTemp2 = pTemp->_pNext; pTemp2 != NULL; pTemp2 = pTemp2->_pNext) {
			if (pTemp2->_data < pTemp->_data) {
				swap(pTemp2->_data, pTemp->_data);
			}
		}
	}

}
template <class DataType>
Node<DataType>* LinkedList<DataType>::timTheoSoGhe(int data) {
	Node<DataType>* pWalker = _pHead;
	while (pWalker != NULL) {
		if (pWalker->_data.getSoGhe() == data) {
			return pWalker;
		}
		pWalker = pWalker->_pNext;
	}
	return pWalker;


}

template <class DataType>
Node<DataType>* LinkedList<DataType>::search(DataType q) {
	Node<DataType>* pWalker = _pHead;
	while (pWalker != NULL) {
		if (pWalker->_data == q) {
			return pWalker;
		}
		pWalker = pWalker->_pNext;
	}
	return pWalker;


}

template <class DataType>
Node<DataType>* LinkedList<DataType>::searchPre(Node<DataType>* node) {
	if (node != NULL) {
		Node<DataType>* pWalker = _pHead;
		while (pWalker != NULL) {
			if (pWalker->_pNext == node) {
				return pWalker;
			}
			pWalker = pWalker->_pNext;
		}
		return pWalker;
	}
	else {
		return NULL;
	}

}
template <class DataType>
Node<DataType>* LinkedList<DataType>::searchPre(DataType data) {
	Node<DataType>* node = search(data);
	if (node != NULL) {
		Node<DataType>* pWalker = _pHead;
		while (pWalker != NULL) {
			if (pWalker->_pNext == node) {
				return pWalker;
			}
			pWalker = pWalker->_pNext;
		}
		return pWalker;
	}
	else {
		return NULL;
	}

}


int main() {
	LinkedList<int> SoGhe;
	Queue<ThongTinKhachHang> ThuTuXepHang;
	Queue<int> SoThuTuXepHang;
	LinkedList<ThongTinKhachHang> ThongTinKhach;
	cout << "Nhap so ghe: " << endl;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		SoGhe.addTail(i);
	}
	int iOption = 0;
	do {
		system("cls");
		cout << "0. Thoat chuong trinh" << endl;
		cout << "1. Hien thi so ghe con trong" << endl;
		cout << "2. Chuc nang lay so xep hang" << endl;
		cout << "3. Chuc nang mua ve" << endl;
		cout << "4. Chuc nang huy ve" << endl;
		cout << "5. Chuc nang hien thi nhung ve da ban" << endl;
		cout << "Nhap thao tac" << endl;
		cin >> iOption;
		switch (iOption)
		{
		case 0:
		{
			system("pause");
			break;
		}
		case 1:
		{
			cout << "Hien thi so ghe con trong" << endl;
			SoGhe.display();
			system("pause");
			break;
		}
		case 2:
		{
			cout << "Chuc nang lay so xep hang" << endl;
			SoThuTuXepHang.enQueue(SoThuTuXepHang.getSize()+ 1);
			cout << "Lay so xep hang thanh cong" << endl;
			system("pause");
			break;
		}
		case 3:
		{
			cout << "Chuc nang mua ve" << endl;
			if (SoGhe.getSize() == 0) {
				cout << "Da het ghe, vui long quay lai sau." << endl;
			}
			else if (SoThuTuXepHang.getSize() == 0) {
				cout << "Vui long doi lay so xep hang." << endl;
			}
			else {
				string tenKhachHang;
				int soGhe;
				cout << "Nhap ten khach hang (viet lien): " << endl;
				cin >> tenKhachHang;
				cout << "Nhap so ghe: " << endl;
				cin >> soGhe;
	
				Node<int>* timSoGhe = SoGhe.search(soGhe);
				if (timSoGhe == NULL) {
					cout << "So ghe khong con hoac khong hop le." << endl;
				}
				else {
					ThongTinKhachHang* khachHangMoi = new ThongTinKhachHang();
					khachHangMoi->setTen(tenKhachHang);
					khachHangMoi->setSoGhe(soGhe);
					//Them khach hang vao danh sach da mua ve
					ThongTinKhach.addTail(*khachHangMoi);
					//Loai so ghe khoi Danh Sach Ghe trong
					SoGhe.remove(soGhe);
					//Sau khi mua xong thi ra khoi hang doi
					SoThuTuXepHang.deQueue();
					cout << "Mua ve thanh cong" << endl;
					

				}
			}
			system("pause");
			break;
		}
		case 4:
		{
			cout << "Chuc nang huy ve" << endl;
			int soGhe;
			cout << "Nhap so ghe muon huy ve: " << endl;
			cin >> soGhe;
			Node<ThongTinKhachHang>* timSoGhe = ThongTinKhach.timTheoSoGhe(soGhe);

			if (timSoGhe == NULL) {
				cout << "So ghe khong ton tai hoac khong hop le." << endl;
			}
			else {
				//Them so ghe vao danh sach Ghe
				SoGhe.addTail(soGhe);
				//xoa khoi danh sach ve da mua
				ThongTinKhach.remove(timSoGhe);
			}
			system("pause");
			break;
		}
		case 5:
		{
			cout << "Chuc nang hien thi nhung ve da ban" << endl;
			ThongTinKhach.display();
			system("pause");
			break;
		}
		default:
			break;
		}
	} while (iOption != 0);











	return 0;
}

#include <iostream>
#include <cmath>
using namespace std;

class DaThuc {
	int _iHeSo;
	int _iSoMu;
public:
	DaThuc();
	DaThuc(int heSo, int soMu);
	void setDaThuc(int heSo, int soMu);
	void nhap();
	void display();
	void displayDaThuc();
	int getHeSo();
	int getSoMu();
	int tinhGiaTri(int x);
	DaThuc daoHam();
	DaThuc nhanDaThuc(DaThuc temp);
	DaThuc operator * (DaThuc& d);

};
DaThuc::DaThuc() {
	_iHeSo = 0;
	_iSoMu = 0;
};
DaThuc::DaThuc(int heSo, int soMu) {
	_iHeSo = heSo;
	_iSoMu = soMu;
};
void DaThuc::setDaThuc(int heSo, int soMu) {
	_iHeSo = heSo;
	_iSoMu = soMu;
};
DaThuc DaThuc::operator*(DaThuc& d) {
	int iHeSo = d.getHeSo() * _iHeSo;
	int iSoMu = _iSoMu + d.getSoMu();
	DaThuc result(iHeSo, iSoMu);
	return result;
}
DaThuc DaThuc::daoHam() {
	int iHeSo = _iSoMu * _iHeSo;
	int iSoMu = _iSoMu - 1;
	DaThuc* newDaThuc = new DaThuc(iHeSo, iSoMu);
	return *newDaThuc;
};
DaThuc DaThuc::nhanDaThuc(DaThuc temp) {
	int iHeSo = temp.getHeSo() * _iHeSo;
	int iSoMu = _iSoMu + temp.getSoMu();
	DaThuc* newDaThuc = new DaThuc(iHeSo, iSoMu);
	return *newDaThuc;
};
void DaThuc::nhap() {
	cin >> _iHeSo >> _iSoMu;
}
int DaThuc::tinhGiaTri(int x) {
	return _iHeSo * pow(x, _iSoMu);
}
void DaThuc::display() {
	if (_iHeSo != 0) {
		if (_iSoMu != 0) {
			if (_iSoMu == 1) {
				cout << _iHeSo << "x";
			}
			else {
				cout << _iHeSo << "x^" << _iSoMu;
			}
		}
		else {
			cout << _iHeSo;
		}
	}
}
void DaThuc::displayDaThuc() {
	if (_iHeSo != 0) {
		if (_iHeSo > 0) {
			if (_iSoMu != 0) {
				if (_iSoMu == 1) {
					cout << "+" << _iHeSo << "x";
				}
				else {
					cout << "+" << _iHeSo << "x^" << _iSoMu;
				}
			}
			else {
				cout << "+" << _iHeSo;
			}
		} else if (_iHeSo < 0) {
			if (_iSoMu != 0) {
				if (_iSoMu == 1) {
					cout << _iHeSo << "x";
				}
				else {

					cout <<  _iHeSo << "x^" << _iSoMu;
				}
			}
			else {
				cout << _iHeSo;
			}
		}
	}

	
}
int DaThuc::getHeSo() {
	return _iHeSo;
}
int DaThuc::getSoMu() {
	return _iSoMu;
}
template <class DataType>
class LinkedList;
template <class DataType>
class Node {
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
	 _data.display();
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
	Node<DataType>* searchSoMu(int q);
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
	void tinhDaoHam();
	int tinhGiaTri(int x);
	int getSoMuCaoNhat();
	Node<DataType> * phanTuThuK(int k);
	LinkedList<DataType> tong2DaThuc(LinkedList<DataType> temp);




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
		if (pWalker != _pHead) {
			pWalker->_data.displayDaThuc();
		}
		else {
			pWalker->display();
		}
		pWalker = pWalker->_pNext;
	}
}
template <class DataType>
LinkedList<DataType>  LinkedList<DataType>::tong2DaThuc(LinkedList<DataType> F2) {
	LinkedList<DataType> F3;
	string max = "f1";
	int maxSize = getSoMuCaoNhat();
	if (getSoMuCaoNhat() < F2.getSoMuCaoNhat()) {
		maxSize = F2.getSoMuCaoNhat();
		max = "f2";
	}
	for (int i = maxSize; i >= 0; i--) {
		DaThuc* temp = new DaThuc(0, 0);
		if (max == "f1") {
			Node<DataType>* pSearch = searchSoMu(i);
			Node<DataType>* pSearch2 = F2.searchSoMu(i);
			if (pSearch == NULL) {
				if (pSearch2 == NULL) {
					temp->setDaThuc(0, 0);

				}
				else if (pSearch2 != NULL) {
					temp->setDaThuc(pSearch2->getData().getHeSo(), pSearch2->getData().getSoMu());

				}
			}
			else if (pSearch != NULL) {
				if (pSearch2 == NULL) {
					temp->setDaThuc(pSearch->getData().getHeSo(), pSearch->getData().getSoMu());
				}
				else if (pSearch2 != NULL) {
					temp->setDaThuc(pSearch->getData().getHeSo() + pSearch2->getData().getHeSo(), pSearch->getData().getSoMu());

				}
			}

		}
		else if (max == "f2") {
			Node<DataType>* pSearch = F2.searchSoMu(i);
			Node<DataType>* pSearch2 = searchSoMu(i);
			if (pSearch == NULL) {
				if (pSearch2 == NULL) {
					temp->setDaThuc(0, 0);

				}
				else if (pSearch2 != NULL) {
					temp->setDaThuc(pSearch2->getData().getHeSo(), pSearch2->getData().getSoMu());

				}
			}
			else if (pSearch != NULL) {
				if (pSearch2 == NULL) {
					temp->setDaThuc(pSearch->getData().getHeSo(), pSearch->getData().getSoMu());
				}
				else if (pSearch2 != NULL) {
					temp->setDaThuc(pSearch->getData().getHeSo() + pSearch2->getData().getHeSo(), pSearch->getData().getSoMu());

				}
			}

		}
		F3.addTail(*temp);

	}
	return F3;

}
template <class DataType>
Node<DataType>* LinkedList<DataType>::phanTuThuK(int k) {
	Node<DataType>* pWalker = _pHead;
	if (k > _iSize || k < 1) {
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
int LinkedList<DataType>::getSoMuCaoNhat() {
	if (_pHead == NULL) {
		return 0;
	}
	return _pHead->_data.getSoMu();
}
template <class DataType>
int LinkedList<DataType>::tinhGiaTri(int x) {
	int sum = 0;
	Node<DataType>* pWalker = _pHead;
	while (pWalker != NULL) {
		sum = sum + pWalker->_data.tinhGiaTri(x);
		pWalker = pWalker->_pNext;
	}
	return sum;


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
void LinkedList<DataType>::tinhDaoHam() {
	Node<DataType>* pWalker = _pHead;
	while (pWalker != NULL) {
		if (pWalker != _pHead) {
			pWalker->_data.daoHam().displayDaThuc();
		}
		else {
			pWalker->_data.daoHam().display();
		}
		pWalker = pWalker->_pNext;
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
			if (pTemp2->_data.getSoMu() > pTemp->_data.getSoMu()) {
				swap(pTemp2->_data, pTemp->_data);
			}
		}
	}

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
Node<DataType>* LinkedList<DataType>::searchSoMu(int q) {
	Node<DataType>* pWalker = _pHead;
	while (pWalker != NULL) {
		if (pWalker->_data.getSoMu() == q) {
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
	LinkedList<DaThuc> F1;
	LinkedList<DaThuc> F2;
	LinkedList<int> list1;
	int iOption = 0;
	int n, k;
	int x;
	int y;
	do {
		system("cls");
		cout << "0. Thoat chuong trinh" << endl;
		cout << "1. Nhap danh sach lien ket" << endl;
		cout << "2. Hien thi danh sach" << endl;
		cout << "3. Tinh Dao Ham" << endl;
		cout << "4. Tinh gia tri cua 2 da thuc theo x" << endl;
		cout << "5. Tong 2 da thuc" << endl;
		cout << "6. Tich 2 da thuc" << endl;
		cout << "Nhap thao tac:" << endl;
		cin >> iOption;
		switch (iOption)
		{
		case 0: {
			break;
		}
		case 1: {
			cout << "Nhap danh sach list F1  " << endl;
			cout << "Nhap so luong F1: " << endl;
			cin >> n;
			DaThuc temp;
			for (int i = 0; i < n; i++) {
				temp.nhap();
				F1.addTail(temp);
			}
			F1.interchangeSort();
			cout << "Nhap danh sach list F2  " << endl;
			cout << "Nhap so luong F2: " << endl;
			cin >> n;
			for (int i = 0; i < n; i++) {
				temp.nhap();
				F2.addTail(temp);
			}
			F2.interchangeSort();
			system("pause");
			break;
		}
		case 2: {
			cout << "Hien thi danh sach:" << endl;
			F1.display();
			cout << endl;
			F2.display();
			cout << endl;
			system("pause");
			break;
		}
		case 3: {
			cout << "Tinh dao ham: " << endl;
			F1.tinhDaoHam();
			cout << endl;
			F2.tinhDaoHam();
			cout << endl;
			system("pause");
			break;
		}
		case 4: {
			cout << "Tinh gia tri cua 2 da thuc theo x: " << endl;
			cout << "Nhap x" << endl;
			int x;
			cin >> x;
			cout << "Gia tri F1: " << F1.tinhGiaTri(x) << endl; 
			cout << "Gia tri F2: " << F2.tinhGiaTri(x) << endl;

			system("pause");
			break;
		}
		case 5: {
			cout << "Tong cua 2 da thuc: " << endl;
			LinkedList<DaThuc> F3;
			F3 = F1.tong2DaThuc(F2);
		
			F3.display();
			cout << endl;
			system("pause");
			break;
		}
		case 6: {
			cout << "Tich cua 2 da thuc: " << endl;
			LinkedList<DaThuc> F3;
			LinkedList<DaThuc> FTich[100];
			int size = 0;
			for (int i = 1; i <= F1.getSize(); i++) {
				DaThuc temp;
				for (int j = 1; j <= F2.getSize(); j++) {
					temp = F1.phanTuThuK(i)->getData().nhanDaThuc(F2.phanTuThuK(j)->getData());
					FTich[size].addTail(temp);
				}
				size++;
				
			}
			LinkedList<DaThuc> FTichResult;
			for (int i = 0; i < size; i++) {
				FTich[i].interchangeSort();
				FTichResult = FTichResult.tong2DaThuc(FTich[i]);
			}
			FTichResult.display();
			cout << endl;
			system("pause");
			break;
		}
		default:
			break;
		}



	} while (iOption != 0);






	return 0;
}

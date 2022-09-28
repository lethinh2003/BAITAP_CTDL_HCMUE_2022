#include <iostream>
#include <cmath>
using namespace std;

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
	cout << _data;
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
	void hienThiNguyenTo();
	double trungBinhCong();
	int demSoLanXuatHien(DataType x);
	DataType soChinhPhuongCuoiCung();
	Node<DataType>* phanTuThuK(int k);
	DataType phanTuNhoNhat();
	int getSize();
	void addAfter(DataType q, DataType data);
	void addAfter(Node<DataType>* node, DataType data);
	Node<DataType>* search(DataType q);
	void addPhanTuKhongTrung(DataType data);
	void removeHead();
	void xoaKPhanTuDauDanhSach(int k);
	void remove(Node<DataType>* node);
	void xoaPhanTuCoGiaTriX(DataType x);
	Node<DataType>* searchPre(Node<DataType>* node);
	Node<DataType>* searchPTuCuoiCung(DataType x);
	void xoaPhanTuSauPhanTuQ(DataType q);
	void xoaPhanTuLapLai();
	void interchangeSort();
	Node<DataType>* timNodeBeHon(DataType q);
	void themPhanTuVaoDanhSachTangDan(DataType q);
	void capNhatSoHoanThien();
	DataType getSumPhanTu();
	Node<DataType>* getMax();

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
		cout << " ";
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
void LinkedList<DataType>::hienThiNguyenTo() {
	Node<DataType>* pWalker = _pHead;
	while (pWalker != NULL) {
		if (isPrime(pWalker->_data)) {
			pWalker->display();
			cout << " ";
		}
		pWalker = pWalker->_pNext;
	}
}
template <class DataType>
double LinkedList<DataType>::trungBinhCong() {
	Node<DataType>* pWalker = _pHead;
	double result = 0;
	while (pWalker != NULL) {
		result = result + pWalker->_data;
		pWalker = pWalker->_pNext;
	}
	return result / _iSize;
}
template <class DataType>
DataType LinkedList<DataType>::getSumPhanTu() {
	Node<DataType>* pWalker = _pHead;
	DataType sum = 0;
	while (pWalker != NULL) {
		sum = sum + pWalker->_data;
		pWalker = pWalker->_pNext;
	}
	return sum;
}
template <class DataType>
Node<DataType>* LinkedList<DataType>::getMax() {
	Node<DataType>* pWalker = _pHead;
	Node<DataType>* pMax = _pHead;
	while (pWalker != NULL) {
		if (pWalker->_data >= pMax->_data) {
			pMax = pWalker;
		}
		pWalker = pWalker->_pNext;
	}
	return pMax;
}
template <class DataType>
int LinkedList<DataType>::demSoLanXuatHien(DataType x) {
	Node<DataType>* pWalker = _pHead;
	int dem = 0;
	while (pWalker != NULL) {
		if (pWalker->_data == x) {
			dem++;
		}
		pWalker = pWalker->_pNext;
	}
	return dem;
}
template <class DataType>
DataType LinkedList<DataType>::soChinhPhuongCuoiCung() {
	Node<DataType>* pWalker = _pHead;
	DataType result = -1;
	while (pWalker != NULL) {
		if (isChinhPhuong(pWalker->_data)) {
			result = pWalker->_data;
		}
		pWalker = pWalker->_pNext;
	}
	return result;
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
}
template <class DataType>
DataType LinkedList<DataType>::phanTuNhoNhat() {
	DataType min = _pHead->_data;
	Node<DataType>* pWalker = _pHead;
	while (pWalker != NULL) {
		if (min > pWalker->_data) {
			min = _pHead->_data;
		}
		pWalker = pWalker->_pNext;
	}
	return min;
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
		_iSize++;
	}
	else {
		addHead(data);
	}

}
template <class DataType>
void LinkedList<DataType>::addPhanTuKhongTrung(DataType data) {
	int demSoLan = demSoLanXuatHien(data);
	if (demSoLan == 0) {
		addTail(data);
	}
	else {
		cout << "Phan tu " << data << " da xuat hien trong danh sach, khong the them!" << endl;
	}


}
template <class DataType>
void LinkedList<DataType>::removeHead() {
	Node<DataType>* pTemp = _pHead;
	if (pTemp != NULL) {
		_pHead = pTemp->_pNext;
		delete pTemp;
		_iSize--;
	}


}
template <class DataType>
void LinkedList<DataType>::xoaKPhanTuDauDanhSach(int k) {
	if (k > 0 && k <= _iSize) {
		while (k > 0) {
			removeHead();
			k--;
		}

	}


}
template <class DataType>
void LinkedList<DataType>::xoaPhanTuCoGiaTriX(DataType x) {
	Node<DataType>* pTemp = search(x);
	while (pTemp != NULL) {
		if (pTemp == _pHead) {
			removeHead();
			pTemp = search(x);
		}
		else {
			Node<DataType>* pPre = searchPre(pTemp);
			if (pPre != NULL) {
				pPre->_pNext = pTemp->_pNext;
				if (pPre == _pTail) {
					_pTail = pPre;
				}
				delete pTemp;
				_iSize--;
				pTemp = search(x);

			}
		}


	}


}
template <class DataType>
void LinkedList<DataType>::remove(Node<DataType>* node) {
	if (node != NULL) {
		if (node == _pHead) {
			_pHead = _pHead->_pNext;
			if (node == _pTail) {
				_pTail = _pHead;
			}
		}
		else {
			Node<DataType>* pPre = searchPre(node);
			if (pPre != NULL) {
				pPre->_pNext = node->_pNext;

			}
		}
		delete node;
		_iSize--;
	}


}
template <class DataType>
void LinkedList<DataType>::xoaPhanTuSauPhanTuQ(DataType q) {
	Node<DataType>* pSearch = search(q);
	if (pSearch != NULL) {
		Node<DataType>* pNext = pSearch->_pNext;
		if (pNext != NULL) {
			pSearch->_pNext = pNext->_pNext;
			delete pNext;
		}
	}


}
template <class DataType>
void LinkedList<DataType>::xoaPhanTuLapLai() {
	Node<DataType>* pWalker = _pHead;
	while (pWalker != NULL) {
		int soLanXuatHien = demSoLanXuatHien(pWalker->_data);
		while (soLanXuatHien > 1) {
			Node<DataType>* pSearchLast = searchPTuCuoiCung(pWalker->_data);
			remove(pSearchLast);
			soLanXuatHien = demSoLanXuatHien(pWalker->_data);
		}
		pWalker = pWalker->_pNext;
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
void LinkedList<DataType>::themPhanTuVaoDanhSachTangDan(DataType q) {
	Node<DataType>* searchLess = timNodeBeHon(q);
	if (searchLess == NULL) {
		addHead(q);
	}
	else {
		addAfter(searchLess, q);
	}

}
template <class DataType>
void LinkedList<DataType>::capNhatSoHoanThien() {
	Node<DataType>* pWalker = _pHead;
	while (pWalker != NULL) {
		if (isPerfectNumber(pWalker->_data)) {
			pWalker->_data = 0;
		}
		pWalker = pWalker->_pNext;
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
Node<DataType>* LinkedList<DataType>::timNodeBeHon(DataType q) {
	Node<DataType>* pResult = NULL;
	Node<DataType>* pWalker = _pHead;
	while (pWalker != NULL) {
		if (pWalker->_data < q) {
			pResult = pWalker;
		}
		pWalker = pWalker->_pNext;
	}
	return pResult;


}
template <class DataType>
Node<DataType>* LinkedList<DataType>::searchPTuCuoiCung(DataType q) {
	Node<DataType>* pResult = NULL;
	Node<DataType>* pWalker = _pHead;
	while (pWalker != NULL) {
		if (pWalker->_data == q) {
			pResult = pWalker;
		}
		pWalker = pWalker->_pNext;
	}
	return pResult;

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

int main() {
	LinkedList<int> list1;
	LinkedList<int> list2;
	LinkedList<int> list3;
	cout << "Nhap danh sach list 1 " << endl;
	int n, k;
	cout << "Nhap n 1: " << endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		list1.addTail(k);

	}
	cout << endl;
	cout << "Nhap danh sach list 2 " << endl;
	cout << "Nhap n 2: " << endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		list2.addTail(k);

	}

	// hien thi
	cout << "List 1" << endl;
	list1.display();
	cout << endl;
	cout << "List 2" << endl;
	list2.display();
	cout << endl;
	/*
	* 
	* 
	//CAU A
	list3 = list1;
	for (int i = 1; i <= list2.getSize(); i++) {
		list3.addTail(list2.phanTuThuK(i)->getData());
	}
	cout << "List 3" << endl;
	list3.display();
	cout << endl;


	//CAU B
	for (int i = 1; i <= list1.getSize(); i++) {
		Node<int>* pSearch = list2.search(list1.phanTuThuK(i)->getData());
		if (pSearch == NULL) {
			list3.addTail(list1.phanTuThuK(i)->getData());
		}

	}
	cout << "List 3" << endl;
	list3.display();
	cout << endl;

	//CAU C
	for (int i = 1; i <= list1.getSize(); i++) {
		Node<int>* pSearch = list2.search(list1.phanTuThuK(i)->getData());
		if (pSearch != NULL) {
			list3.addTail(list1.phanTuThuK(i)->getData());
		}
	}
	cout << "List 3" << endl;
	list3.display();
	cout << endl;

	//CAU D
	list3 = list1;
	for (int i = 1; i <= list2.getSize(); i++) {
		list3.addTail(list2.phanTuThuK(i)->getData());
	}
	cout << "List 3" << endl;
	list3.xoaPhanTuLapLai();
	list3.display();
	cout << endl;


	//CAU E
	int minSize = min(list1.getSize(), list2.getSize());
	int maxSize = max(list1.getSize(), list2.getSize());
	for (int i = 1; i <= maxSize; i++) {
		int temp = 0;
		if (i <= minSize) {
			temp = list1.phanTuThuK(i)->getData() + list2.phanTuThuK(i)->getData();
		}
		else {
			if (minSize == list1.getSize()) {
				temp = temp + list2.phanTuThuK(i)->getData();
			} else if (minSize == list2.getSize()) {
				temp = temp + list1.phanTuThuK(i)->getData();
			}
		}
		list3.addTail(temp);

	}
	cout << "List 3" << endl;
	list3.display();
	cout << endl;

	//CAU F
	cout << "Phan tu bi trung: " << endl;
	bool check = false;
	for (int i = 1; i <= list1.getSize(); i++) {
		Node<int>* pSearch = list2.search(list1.phanTuThuK(i)->getData());
		if (pSearch != NULL) {
			check = true;
			cout << list1.phanTuThuK(i)->getData() << " ";
			
		}
	}
	if (check == false) {
		cout << "Khong co phan tu bi trung" << endl;
	}
	cout << endl;


	//CAU G
	if (list2.getSize() != 0) {

	int getSumList2 = list2.getSumPhanTu();
	for (int i = 1; i <= list1.getSize(); i++) {
		if (list1.phanTuThuK(i)->getData() > getSumList2) {
			Node<int>* pSearch = list1.search(list1.phanTuThuK(i)->getData());
			list1.remove(pSearch);
			break;
		}
	}
	}
	cout << "List 1 sau khi xoa " << endl;
	list1.display();
	cout << endl;

	//CAU H
	Node<int>* getMaxList2 = list2.getMax();
	if (getMaxList2 != NULL) {
		list1.xoaPhanTuCoGiaTriX(getMaxList2->getData());
	}
	cout << "List 1 sau khi xoa " << endl;
	list1.display();
	cout << endl;
	*/




	




	return 0;
}

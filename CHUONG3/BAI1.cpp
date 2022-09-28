#include <iostream>
#include <cmath>
using namespace std;
bool isPerfectNumber(int n);
bool isPrime(int n);
bool isChinhPhuong(int n);
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
};
template <class DataType>
Node<DataType>::Node(DataType data) {
	_data = data;
	_pNext = NULL;
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
		if (_pHead == NULL) {
			_pTail = NULL;
		}
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
				if (pPre->_pNext == NULL) {
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
void LinkedList<DataType>::xoaPhanTuSauPhanTuQ(DataType q) {
	Node<DataType>* node = search(q);
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
	LinkedList<int> list;
	int iOption = 0;
	do {
		system("cls");
		cout << "0. Thoat chuong trinh" << endl;
		cout << "1. CAU A: Nhap danh sach lien ket (add Tail)" << endl;
		cout << "2. CAU B: Hien thi danh sach" << endl;
		cout << "3. CAU C: Hien thi nguyen to" << endl;
		cout << "4. CAU D: Trung binh cong cac phan tu" << endl;
		cout << "5. CAU E: Dem so lan xuat hien cua mot so" << endl;
		cout << "6. CAU F: Xuat so chinh phuong cuoi cung" << endl;
		cout << "7. CAU G: Tim phan tu thu k" << endl;
		cout << "8. CAU H: Tim phan tu nho nhat" << endl;
		cout << "9. CAU I: Them phan tu sau phan tu q" << endl;
		cout << "10. CAU J: Them vao danh sach sao cho phan tu chua co trong danh sach" << endl;
		cout << "11. CAU K: Xoa k phan tu dau danh sach" << endl;
		cout << "12. CAU L: Xoa phan tu co gia tri bang x" << endl;
		cout << "13. CAU M: Xoa phan tu sau phan tu q trong danh sach" << endl;
		cout << "14. CAU N: Xoa phan tu lap lai" << endl;
		cout << "15. CAU O: Sap xep tang dan dung interchange sort" << endl;
		cout << "16. CAU P: Them phan tu vao danh sach tang dan" << endl;
		cout << "17. CAU Q: Cap nhat danh sach so hoan thien = 0" << endl;
		cout << "Nhap thao tac:" << endl;
		cin >> iOption;
		switch (iOption)
		{
		case 0: {
			break;
		}
		case 1: {
			int n, k;
			cout << "Nhap danh sach " << endl;
			cout << "Nhap n so muon them vao duoi " << endl;
			cin >> n;
			for (int i = 0; i < n; i++) {
				cin >> k;
				list.addTail(k);

			}
			system("pause");
			break;
		}
		case 2: {

			//CAU B
			// hien thi danh sach
			cout << "Danh sach cac phan tu: " << endl;
			list.display();
			cout << endl;
			system("pause");
			break;
		}
		case 3: {
			//CAU C
			// hien thi nguyen to
			cout << "Danh sach cac phan tu la so nguyen to: " << endl;
			list.hienThiNguyenTo();
			cout << endl;
			system("pause");
			break;
		}
		case 4: {
			//CAU D
			// trung binh cong cac phan tu
			cout << "Trung binh cong cac phan tu: " << endl;
			cout << list.trungBinhCong();
			cout << endl;

			system("pause");
			break;
		}
		case 5: {
			//CAU E
	// dem so lan xuat hien cua mot so
			int x;
			cout << "Dem so lan xuat hien cua mot so" << endl;
			cin >> x;
			cout << "So lan xuat hien cua " << x << " la: " << list.demSoLanXuatHien(x);
			cout << endl;
			system("pause");
			break;
		}
		case 6: {
			//CAU F
	// xuat so chinh phuong cuoi cung
			cout << "So Chinh Phuong cuoi cung: " << endl;
			int sCP = list.soChinhPhuongCuoiCung();
			if (sCP == -1) {
				cout << "Day so khong co so chinh phuong " << endl;
			}
			else {
				cout << "La: " << sCP;
			}
			cout << endl;
			system("pause");
			break;
		}
		case 7: {
			//CAU G
// tim phan tu thu k;
			int k;
			cout << "Nhap phan tu thu k" << endl;
			cin >> k;
			Node<int>* item = list.phanTuThuK(k);
			if (item == NULL) {
				cout << "Vi tri thu k khong hop le" << endl;
			}
			else {
				item->display();
			}
			cout << endl;
			system("pause");
			break;
		}
		case 8: {
			//CAU H
	// tim phan tu nho nhat;
			cout << "Phan tu nho nhat: " << endl;
			if (list.getSize() == 0) {
				cout << "Danh sach khong co phan tu nho nhat" << endl;
			}
			else {
				int minItem = list.phanTuNhoNhat();
				cout << minItem;

			}
			cout << endl;
			system("pause");
			break;
		}
		case 9: {
			//CAU I
	//them phan tu sau phan tu q;
			cout << "Them phan tu sau phan tu q " << endl;
			cout << "Nhap phan tu q: " << endl;
			int q, data;
			cin >> q;
			cout << "Nhap phan tu muon them: " << endl;
			cin >> data;
			list.addAfter(q, data);
			cout << "Danh sach sau khi them" << endl;
			list.display();
			cout << endl;

			system("pause");
			break;
		}
		case 10: {
			//CAU J
	//Them vao danh sach sao cho phan tu chua co trong danh sach
			int data;
			cout << "Them phan tu sao cho trong danh sach chua co: " << endl;
			cout << "Nhap phan tu muon them " << endl;
			cin >> data;
			list.addPhanTuKhongTrung(data);
			cout << "Danh sach sau khi them" << endl;
			list.display();
			cout << endl;
			system("pause");
			break;
		}
		case 11: {
			//CAU K
	//xoa k phan tu dau danh sach;
			int k;
			cout << "Xoa k phan tu dau danh sach: " << endl;
			cout << "Nhap k phan tu: " << endl;
			cin >> k;
			list.xoaKPhanTuDauDanhSach(k);
			cout << "Danh sach sau khi xoa" << endl;
			list.display();
			cout << endl;
			system("pause");
			break;
		}
		case 12: {
			//CAU L
	// xoa phan tu co gia tri bang x
			int k;
			cout << "Xoa phan tu co gia tri bang x trong danh sach: " << endl;
			cout << "Nhap phan tu co gia tri x: " << endl;
			cin >> k;
			list.xoaPhanTuCoGiaTriX(k);
			cout << "Danh sach sau khi xoa" << endl;
			list.display();
			cout << endl;
			system("pause");
			break;
		}
		case 13: {
			//CAU M
	// xoa phan tu sau phan tu q trong danh sach
			int k;
			cout << "Xoa phan tu sau phan tu q trong danh sach: " << endl;
			cout << "Nhap phan tu co gia tri q: " << endl;
			cin >> k;
			list.xoaPhanTuSauPhanTuQ(k);
			cout << "Danh sach sau khi xoa" << endl;
			list.display();
			cout << endl;

			system("pause");
			break;
		}
		case 14: {
			//CAU N
	//xoa phan tu lap lai
			cout << "Xoa phan tu lap lai trong danh sach: " << endl;
			list.xoaPhanTuLapLai();
			cout << "Danh sach sau khi xoa" << endl;
			list.display();
			cout << endl;
			system("pause");
			break;
		}
		case 15: {
			//CAU O
	//sap xep tang dan dung interchange sort
			cout << "Sap xep tang dan: " << endl;
			list.interchangeSort();
			cout << "Danh sach sau khi sap xep" << endl;
			list.display();
			cout << endl;

			system("pause");
			break;
		}
		case 16: {
			//CAU P
	// them phan tu vao danh sach tang dan;
			cout << "them phan tu vao danh sach tang dan:" << endl;
			cout << "Nhap phan tu muon them:" << endl;
			list.interchangeSort();
			int q;
			cin >> q;
			list.themPhanTuVaoDanhSachTangDan(q);
			cout << "Danh sach sau khi them: " << endl;
			list.display();


			system("pause");
			break;
		}
		case 17: {

			//CAU Q
			// Cap nhat danh sach so hoan thien = 0;
			cout << "Cap nhat danh sach so hoan thien = 0:" << endl;
			list.capNhatSoHoanThien();
			cout << "Danh sach sau khi cap nhat: " << endl;
			list.display();
			system("pause");
			break;
		}
		default:
			break;
		}
	} while (iOption != 0);


	return 0;
}
bool isPrime(int n) {
	if (n < 2) {
		return false;
	}
	int dem = 0;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			dem++;
		}
	}
	if (dem == 0) {
		return true;
	}
	return false;
}
bool isChinhPhuong(int n) {
	int temp = sqrt(n);
	if (temp * temp == n) {
		return true;
	}
	return false;
}
bool isPerfectNumber(int n) {
	if (n == 0) {
		return false;
	}
	int sum = 0;
	for (int i = 1; i < n; i++) {
		if (n % i == 0) {
			sum = sum + i;
		}
	}
	return sum == n;
}
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
	LinkedList<int> list1;
	int iOption = 0;
	int n, k;
	int x;
	int y;
	do {
		system("cls");
		cout << "0. Thoat chuong trinh" << endl;
		cout << "1. Nhap danh sach lien ket (add Tail)" << endl;
		cout << "2. Nhap danh sach lien ket (add Head)" << endl;
		cout << "3. Hien thi danh sach" << endl;
		cout << "4. Them phan tu x vao sau phan tu y" << endl;
		cout << "5. Tim phan tu x" << endl;
		cout << "6. Tim phan tu dung truoc phan tu x" << endl;
		cout << "7. Xoa phan tu dau" << endl;
		cout << "8. Xoa phan tu cuoi" << endl;
		cout << "9. Xoa phan tu sau phan tu x" << endl;
		cout << "10. Xoa phan tu x" << endl;
		cout << "11. Xoa danh sach" << endl;
		cout << "Nhap thao tac:" << endl;
		cin >> iOption;
		switch (iOption)
		{
		case 0: {
			break;
		}
		case 1: {
			cout << "Nhap vao duoi danh sach list  " << endl;
			cout << "Nhap so luong muon them: " << endl;
			cin >> n;
			for (int i = 0; i < n; i++) {
				cin >> k;
				list1.addTail(k);
			}
			system("pause");
			break;
		}
		case 2: {
			cout << "Nhap vao dau danh sach list  " << endl;
			cout << "Nhap so luong muon them: " << endl;
			cin >> n;
			for (int i = 0; i < n; i++) {
				cin >> k;
				list1.addHead(k);
			}
			system("pause");
			break;
		}
		case 3: {
			cout << "Hien thi danh sach:" << endl;
			list1.display();
			cout << endl;
			system("pause");
			break;
		}
		case 4: {
			cout << "Them phan tu x vao sau phan tu y:" << endl;
			cout << "Nhap phan tu x: " << endl;

			cin >> x;
			cout << "Nhap phan tu y: " << endl;

			cin >> y;
			list1.addAfter(y, x);
			system("pause");
			break;
		}
		case 5: {
			cout << "Tim kiem phan tu x:" << endl;
			cout << "Nhap phan tu x: " << endl;
			cin >> x;
			Node<int>* search = list1.search(x);
			if (search == NULL) {
				cout << "Khong tim thay x" << endl;
			}
			else {
				search->display();
				cout << endl;
			}
			cout << endl;
			system("pause");
			break;
		}
		case 6: {
			cout << "Tim kiem phan tu dung truoc phan tu x:" << endl;
			cout << "Nhap phan tu x: " << endl;
			cin >> x;
			Node<int>* search = list1.searchPre(x);
			if (search == NULL) {
				cout << "Khong tim thay phan tu dung truoc x" << endl;
			}
			else {
				search->display();
				cout << endl;
			}
			cout << endl;
			system("pause");
			break;
		}
		case 7: {
			cout << "Xoa phan tu dau" << endl;
			list1.removeHead();
			cout << endl;
			system("pause");
			break;
		}
		case 8: {
			cout << "Xoa phan tu cuoi" << endl;
			list1.removeTail();
			cout << endl;
			system("pause");
			break;
		}
		case 9: {
			cout << "Xoa phan tu sau phan tu x" << endl;
			cout << "Nhap phan tu x: " << endl;
			cin >> x;
			Node<int>* search = list1.search(x);
			list1.removeAfter(search);
			system("pause");
			break;
		}
		case 10: {
			cout << "Xoa phan tu x" << endl;
			cout << "Nhap phan tu x: " << endl;
			cin >> x;
			list1.remove(x);
			system("pause");
			break;
		}
		case 11: {
			cout << "Xoa danh sach" << endl;
			list1.clear();
			system("pause");
			break;
		}
		default:
			break;
		}



	} while (iOption != 0);
	





	return 0;
}

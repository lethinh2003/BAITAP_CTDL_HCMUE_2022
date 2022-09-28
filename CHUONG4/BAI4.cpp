#include <iostream>
#include <cmath>
using namespace std;

template <class DataType>
class Stack;
template <class DataType>
class Node {
	friend Stack<DataType>;
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
class Stack {
	int _iSize;
	Node<DataType>* _pTop;

public:
	Stack();
	~Stack();
	void display();
	void push(DataType data);
	DataType pop();
	DataType peek();
	int getSize();
	void clear();


};
template <class DataType>
Stack<DataType>::Stack() {
	_iSize = 0;
	_pTop = NULL;
}
template <class DataType>
Stack<DataType>::~Stack() {
	clear();
}
template <class DataType>
void Stack<DataType>::display() {
	Node<DataType>* pWalker = _pTop;
	while (pWalker != NULL) {
		pWalker->display();
		pWalker = pWalker->_pNext;
	}
}
template <class DataType>
void Stack<DataType>::push(DataType data) {
	Node<DataType>* pAdd = new Node<DataType>(data);
	if (_pTop == NULL) {
		_pTop = pAdd;
	}
	else {
		pAdd->_pNext = _pTop;
		_pTop = pAdd;
	}
	_iSize++;
}
template <class DataType>
DataType Stack<DataType>::pop() {
	Node<DataType>* pTemp = _pTop;
	if (pTemp == NULL) {
		cout << "Stack rong, khong the thuc hien." << endl;
		exit;
	}
	DataType dataTemp = pTemp->_data;
	_pTop = pTemp->_pNext;
	delete pTemp;
	_iSize--;
	return dataTemp;
}
template <class DataType>
DataType Stack<DataType>::peek() {
	Node<DataType>* pTemp = _pTop;
	if (pTemp == NULL) {
		cout << "Stack rong, khong the thuc hien." << endl;
		exit;
	}
	DataType dataTemp = pTemp->_data;
	return dataTemp;
}

template <class DataType>
int Stack<DataType>::getSize() {
	return _iSize;
}

template <class DataType>
void Stack<DataType>::clear() {
	while (_pTop != NULL) {
		pop();
	}


}
void QuickSort(int* a, int left, int right);



int main() {

	int a[100];
	int sl = 0;
	cout << "Nhap so luong phan tu: " << endl;
	cin >> sl;
	for (int i = 0; i < sl; i++) {
		cin >> a[i];
	}
	cout << "Day truoc khi Quick Sort: " << endl;
	for (int i = 0; i < sl; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	QuickSort(a, 0, sl - 1);

	cout << "Day sau khi Quick Sort: " << endl;
	for (int i = 0; i < sl; i++) {
		cout << a[i] << " ";
	}






	return 0;
}
void QuickSort(int* a, int left, int right) {
	Stack<int> stackLeft;
	Stack<int> stackRight;
	stackLeft.push(left);
	stackRight.push(right);
	while (stackLeft.getSize() != 0) {
		int i = stackLeft.peek();
		int j = stackRight.peek();
		int valueLeft = stackLeft.pop();
		int valueRight = stackRight.pop();
		int x = a[(valueLeft + valueRight)/2];
		while (valueLeft < valueRight) {
			while (a[valueLeft] < x) {
				valueLeft++;
			}
			while (a[valueRight] > x) {
				valueRight--;
			}
			if (valueLeft <= valueRight) {
				swap(a[valueLeft], a[valueRight]);
				valueLeft++;
				valueRight--;
			}
		}
		if (valueRight > i) {
			stackLeft.push(i);
			stackRight.push(valueRight);

		}

		if (valueLeft < j) {
			stackLeft.push(valueLeft);
			stackRight.push(j);

		}
	}
}
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



int main() {
	Stack<int> stack;
	int n;
	cout << "Doi co so 10 sang co so 2:" << endl;
	cout << "Nhap n: " << endl;
	cin >> n;
	while (n > 0) {
		int temp = n % 2;
		stack.push(temp);
		n = n / 2;
	}
	
	stack.display();






	return 0;
}

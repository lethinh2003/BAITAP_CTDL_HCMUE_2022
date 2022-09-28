#include <iostream>
#include <sstream>
#define MAX_SIZE 100;
using namespace std;

template <class DataType>
class Stack {
	DataType* _array;
	int _iTop;
	int _iCapacity;
public:
	Stack();
	Stack(int maxSize);
	~Stack();
	void init();
	bool empty();
	bool full();
	DataType top();
	bool isFull();
	bool isEmpty();
	void push(DataType data);
	DataType pop();
	DataType peek();
	void display();
	bool checkBefore(char x);
	bool checkAfter(char x);
	bool checkIsEqual(char x1, char x2);
	bool laDayNgoacDung(string s);
};
template <class DataType>
Stack<DataType>::Stack() {
	_iCapacity = MAX_SIZE;
	_array = new DataType[_iCapacity];
	_iTop = -1;
}
template <class DataType>
Stack<DataType>::Stack(int maxSize) {
	_iCapacity = maxSize > 0 ? maxSize : MAX_SIZE;
	_array = new DataType[_iCapacity];
	_iTop = -1;
}
template <class DataType>
Stack<DataType>::~Stack() {
	delete[] _array;
	_iTop = -1;
}
template <class DataType>
bool Stack<DataType>::isFull() {
	return _iTop == _iCapacity - 1;
}
template <class DataType>
bool Stack<DataType>::isEmpty() {
	return _iTop == -1;
}
template <class DataType>
void Stack<DataType>::push(DataType data) {
	if (!isFull()) {
		_array[++_iTop] = data;
	}
	else {
		cout << "Stack day" << endl;
	}
}
template <class DataType>
DataType Stack<DataType>::pop() {
	if (!isEmpty()) {
		DataType temp = _array[_iTop];
		_iTop--;
		return temp;

	}
	else {
		return ' ';
	}
}
template <class DataType>
void Stack<DataType>::display() {
	if (!isEmpty()) {
		for (int i = _iTop; i >= 0; i--) {
			cout << _array[i] << endl;
		}
	}
	else {
		cout << "Stack rong" << endl;
	}
}
template <class DataType>
DataType Stack<DataType>::peek() {
	if (!isEmpty()) {
		return _array[_iTop];
	}
	else {
		exit;
	}
}
template <class DataType>
bool Stack<DataType>::checkBefore(char x) {
	if (x == '(' || x == '[' || x == '{') {
		return true;
	}
	return false;

}
template <class DataType>
bool Stack<DataType>::checkAfter(char x) {
	if (x == ')' || x == ']' || x == '}') {
		return true;
	}
	return false;

}
template <class DataType>
bool Stack<DataType>::checkIsEqual(char x1, char x2) {
	if (x1 == ')' && x2 == '(' || x1 == ']' && x2 == '[' || x1 == '}' && x2 == '{') {
		return true;
	}
	return false;
}
template <class DataType>
bool Stack<DataType>::laDayNgoacDung(string s) {
	for (int i = 0; i < s.length(); i++) {
		if (checkBefore(s[i])) {
			push(s[i]);
		}
		else if (checkAfter(s[i])) {
			if (isEmpty()) {
				return false;
			}
			char temp = peek();
			if (checkIsEqual(s[i], temp)) {
				pop();
			}

		}
	}
	
	if (!isEmpty()) {
		return false;
	}
	return true;
}

int main() {
	Stack<int> StackInt(100);
	string a;
	while (cin >> a) {
		if (a != "+" && a != "-" && a != "*" && a != "/") {
			stringstream ss;
			ss << a;
			int b;
			ss >> b;
			StackInt.push(b);
		}
		else {
			int result = 0;
			int temp1 = StackInt.pop();
			int temp2 = StackInt.pop();;
			if (a == "+") {
				result = (temp2 + temp1);
			}
			else if (a == "-") {
				result = (temp2 - temp1);
			}
			else if (a == "*") {
				result = (temp2 * temp1);
			}
			else if (a == "/") {
				result = (temp2 / temp1);
			}
			StackInt.push(result);
		}
	}
	StackInt.display();
	






	return 0;
}

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
	int precedence(char x);
	
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
int Stack<DataType>::precedence(char x) {
		if (x == '(')
			return 0;
		if (x == '+' || x == '-')
			return 1;
		if (x == '*' || x == '/' || x == '%')
			return 2;

		return 3;
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
			cout << _array[i];
		}
	}
	else {
		
	}
}
template <class DataType>
DataType Stack<DataType>::peek() {
	if (!isEmpty()) {
		return _array[_iTop];
	}
	else {
		return ' ';
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
	Stack<char> stack(100);
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			stack.push(str[i]);
		} else if (str[i] == ')') {
			char temp = stack.pop();
			while (temp != '(') {
				cout << temp;
				temp = stack.pop();
			}
		}
		else if (str[i] >= 'a' && str[i] <= 'z') {
			cout << str[i];
		}
		else {
			if (stack.peek() != ' ' && stack.precedence(str[i]) < stack.precedence(stack.peek())) {
				cout << stack.pop();
			}
			stack.push(str[i]);
		}

	}
	stack.display();






	return 0;
}

#include <iostream>
#define MAX_SIZE 10;
using namespace std;

template <class DataType>
class ArrayList {
	DataType* _item;
	int _iSize;
	int _iCapacity;
public:
	ArrayList();
	ArrayList(int maxSize);
	~ArrayList();
	bool isFull();
	void add(DataType data);
	void display();
	void linearSearch(DataType x);
};
template <class DataType>
ArrayList<DataType>::ArrayList() {
	_iCapacity = MAX_SIZE;
	_item = new DataType[_iCapacity];
	_iSize = 0;
}
template <class DataType>
ArrayList<DataType>::ArrayList(int maxSize) {
	_iCapacity = maxSize > 0 ? maxSize : MAX_SIZE;
	_item = new DataType[_iCapacity];
	_iSize = 0;
}
template <class DataType>
ArrayList<DataType>::~ArrayList() {
	delete[] _item;
}
template <class DataType>
bool ArrayList<DataType>::isFull() {
	if (_iSize == _iCapacity) {
		return true;
	}
	else {
		return false;
	}
}
template <class DataType>
void ArrayList<DataType>::add(DataType data) {
	if (!isFull()) {
		_item[_iSize] = data;
		_iSize++;
	}
	else {
		cout << "LIST FULL" << endl;
	}
}
template <class DataType>
void ArrayList<DataType>::display() {
	for (int i = 0; i < _iSize; i++) {
		cout << _item[i] << " ";
	}
}
template <class DataType>
void ArrayList<DataType>::linearSearch(DataType x) {
	for (int i = 0; i < _iSize; i++) {
		if (_item[i] == x) {
			cout << i << " ";
		}
	}
}
int main() {
	int iN;
	cout << "NHAP SO LUONG PHAN TU:" << endl;
	cin >> iN;
	ArrayList<int> ListNumbers(iN);
	int iX;
	while (cin >> iX) {
		ListNumbers.add(iX);
	}

	//tim phan tu co value = 2;
	int iValueSearch = 2;
	ListNumbers.linearSearch(iValueSearch);
	return 0;
}
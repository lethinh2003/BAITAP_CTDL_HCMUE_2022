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
	void interchangeSort();
	int binarySearch(DataType x);
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
int ArrayList<DataType>::binarySearch(DataType x) {
	int dem = 0;
	int a[100];
	int b[100];
	int first = 0; 
	int last = _iSize - 1;
	int mid;
	while (first <= last) {
		mid = (first + last) / 2;
		if (x > _item[mid]) {
			first = mid + 1;
			a[dem] = first;
			b[dem] = last;
			dem++;
			
		}
		else if (x < _item[mid]) {
			last = mid - 1;
			a[dem] = first;
			b[dem] = last;
			dem++;
		}
		else if (x == _item[mid]) {
			cout << "So lan chia doi mang la: " << dem << endl;
			for (int i = 0; i < dem; i++) {
				cout << "Lan " << i+1 << " : x = " << x << " nam trong doan[" << a[i] << ".." << b[i] << "]" << endl;
			}
			return mid;
		}
	}

	return -1;
}
template <class DataType>
void ArrayList<DataType>::interchangeSort() {
	for (int i = 0; i < _iSize -1; i++) {
		for (int j = i + 1; j < _iSize; j++) {
			if (_item[j] < _item[i]) {
				swap(_item[j], _item[i]);
			}
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
	ListNumbers.interchangeSort();
	ListNumbers.display();
	cout << endl;
	//tim kiem gia tri 2
	cout << ListNumbers.binarySearch(2);
	

	return 0;
}
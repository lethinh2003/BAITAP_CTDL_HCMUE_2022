#include <iostream>
#include <Windows.h>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>
#include <conio.h>
#include<stdlib.h>
#include <ctime>

#pragma warning(disable:4996)
using namespace std;

class Video {
	string _strTenPhim;
	string _strTheLoai;
	string _strDaoDien;
	string _strNamChinh;
	string _strNuChinh;
	int _iNamSanXuat;
public:
	Video();
	Video(string tenPhim, string theLoai, string daoDien, string namChinh, string nuChinh, int namSanXuat);
	void display();
	void setDate(string date);
	void setTheLoai(string theLoai);
	int getNamSanXuat();
	string getTenPhim();
	string getTenDienVienNam();
	string thongTinFile();
	string getDaoDien();
};
Video::Video() {
	_strTenPhim = "";
	_strTheLoai = "";
	_strDaoDien = "";
	_strNamChinh = "";
	_strNuChinh = "";
	_iNamSanXuat = 0;
}
Video::Video(string tenPhim, string theLoai, string daoDien, string namChinh, string nuChinh, int namSanXuat = 0) {
	_strTenPhim = tenPhim;
	_strTheLoai = theLoai;
	_strDaoDien = daoDien;
	_strNamChinh = namChinh;
	_strNuChinh = nuChinh;
	_iNamSanXuat = namSanXuat;
}
void Video::display() {
	cout << _strTenPhim << "#" << _strTheLoai << "#" << _strDaoDien << "#" << _strNamChinh << "#" << _strNuChinh << "#" << _iNamSanXuat;
}
void Video::setDate(string date) {
	stringstream ss(date);
	int namSX;
	ss >> namSX;
	_iNamSanXuat = namSX;
}
void Video::setTheLoai(string theLoai) {
	_strTheLoai = theLoai;
}
int Video::getNamSanXuat() {
	return _iNamSanXuat;
}
string Video::getTenPhim() {
	return _strTenPhim;
}
string Video::getDaoDien() {
	return _strDaoDien;
}
string Video::getTenDienVienNam() {
	return _strNamChinh;
}
string Video::thongTinFile() {
	string result = "";
	stringstream ss;
	ss << _iNamSanXuat;
	string namSXString;
	ss >> namSXString;
	result = _strTenPhim + "#" + _strTheLoai + "#" + _strDaoDien + "#" + _strNamChinh + "#" + _strNuChinh + "#" + namSXString;
	return result;
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
	void setData(DataType data);
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
void Node<DataType>::setData(DataType data) {
	_data = data;
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
	Node<DataType>* searchTenPhim(string x);
	Node<DataType>* searchTenDVNam(string x);
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
	void xuLyDocFile();
	void updateFile();
	void ghiDanhSachPhimTheoDienVien(string tenDienVien);
	void thongKeTheoDaoDien();
	void thongKePhimMoi();




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
		cout << endl;
		
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
void LinkedList<DataType>::xuLyDocFile() {
	ifstream ifile("Input.txt");
	string s;
	while (getline(ifile, s)) {
		stringstream ss(s);
		string temp;
		vector<string> dataTemp;
		while (getline(ss, temp, '#')) {
			dataTemp.push_back(temp);
		}
		if (dataTemp.size() != 6) {
			continue;
		}
		DataType* newItem = new DataType(dataTemp[0], dataTemp[1], dataTemp[2], dataTemp[3], dataTemp[4]);
		newItem->setDate(dataTemp[5]);
		LinkedList<DataType>::addTail(*newItem);
	}
	ifile.close();

}
template <class DataType>
void LinkedList<DataType>::updateFile() {
	ofstream ofile;
	// Empty file
	ofile.open("Input.txt");
	ofile << "";
	ofile.close();
	// Update file
	ofile.open("Input.txt", ios::in | ios::app);
	Node<DataType>* pWalker = _pHead;
	while (pWalker != NULL) {
		ofile << pWalker->getData().thongTinFile() << endl;
		pWalker = pWalker->_pNext;
	}
	ofile.close();

}
template <class DataType>
void LinkedList<DataType>::ghiDanhSachPhimTheoDienVien(string tenDienVien) {
	LinkedList<DataType> listTemps;
	Node<DataType>* pWalker = _pHead;
	bool check = false;
	//tim phim theo dien vien
	while (pWalker != NULL) {
		if (pWalker->getData().getTenDienVienNam() == tenDienVien) {
			check = true;
			listTemps.addTail(pWalker->_data);
		}
		pWalker = pWalker->_pNext;
	}
	if (check == false) {
		cout << "Khong tim thay bo phim nao." << endl;
	}
	else {
		listTemps.display();
		cout << endl;

	//tao file

		char* fileName;
		ofstream ofile;
		string strFile = tenDienVien + ".txt";
		fileName = new char[strFile.length() + 1];
		strcpy(fileName, strFile.c_str());
		if (fileName != NULL)
		{
			ofile.open(fileName, ios_base::out);
			Node<DataType>* pWalker = listTemps._pHead;
			while (pWalker != NULL) {
				ofile << pWalker->getData().thongTinFile() << endl;
				pWalker = pWalker->_pNext;
			}

			cout << "Tao file thanh cong" << endl;

			ofile.close();
		}
		delete[] fileName;

	}


}
template <class DataType>
void LinkedList<DataType>::thongKeTheoDaoDien() {
	int luuVet[100] = { 0 };
	Node<DataType>* pTemp;
	Node<DataType>* pTemp2;
	int dem = 0;
	for (pTemp = _pHead; pTemp != NULL; pTemp = pTemp->_pNext) {
		if (luuVet[dem] == 1) {
			continue;
		}
		LinkedList<DataType> listTemps;
		listTemps.addTail(pTemp->_data);
		string tenDaoDien = pTemp->_data.getDaoDien();
		int tongSoPhim = 1;
		int dem2 = dem + 1;
		for (pTemp2 = pTemp->_pNext; pTemp2 != NULL; pTemp2 = pTemp2->_pNext) {
			if (pTemp2->_data.getDaoDien() == pTemp->_data.getDaoDien()) {
				listTemps.addTail(pTemp2->_data);
				luuVet[dem2] = 1;
				tongSoPhim++;
			}
			dem2++;
		}
		//Hien thi thong ke
		cout << "================" << endl;
		cout << "Ten dao dien: " << tenDaoDien << endl;
		cout << "Tong so phim: " << tongSoPhim << endl;
		listTemps.display();
		cout << "================" << endl;
		//Tao file
		char* fileName;
		ofstream ofile;
		string strFile = tenDaoDien + ".txt";
		fileName = new char[strFile.length() + 1];
		strcpy(fileName, strFile.c_str());
		if (fileName != NULL)
		{
			ofile.open(fileName, ios_base::out);
			ofile << "Ten dao dien: " << tenDaoDien << endl;
			ofile << "Tong so phim: " << tongSoPhim << endl;
			Node<DataType>* pWalker = listTemps._pHead;
			while (pWalker != NULL) {
				ofile << pWalker->getData().thongTinFile() << endl;
				pWalker = pWalker->_pNext;
			}

			ofile.close();
		}
		delete[] fileName;
		dem++;
	}



}
template <class DataType>
void LinkedList<DataType>::thongKePhimMoi() {
	//sap xep giam dan theo nam sx
	interchangeSort();

	//tao file

	char* fileName;
	ofstream ofile;
	string strFile = "PhimMoi.txt";
	fileName = new char[strFile.length() + 1];
	strcpy(fileName, strFile.c_str());
	if (fileName != NULL)
	{
		ofile.open(fileName, ios_base::out);
		Node<DataType>* pWalker = _pHead;
		int dem = 0;
		while (pWalker != NULL && dem != 3) {
			cout << pWalker->getData().thongTinFile() << endl;
			ofile << pWalker->getData().thongTinFile() << endl;
			pWalker = pWalker->_pNext;
			dem++;
		}

		cout << "Tao file thanh cong" << endl;

		ofile.close();
	}
	delete[] fileName;



}
template <class DataType>
void LinkedList<DataType>::interchangeSort() {
	Node<DataType>* pTemp;
	Node<DataType>* pTemp2;
	for (pTemp = _pHead; pTemp->_pNext != NULL; pTemp = pTemp->_pNext) {
		for (pTemp2 = pTemp->_pNext; pTemp2 != NULL; pTemp2 = pTemp2->_pNext) {
			if (pTemp2->_data.getNamSanXuat() > pTemp->_data.getNamSanXuat()) {
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
Node<DataType>* LinkedList<DataType>::searchTenPhim(string x) {
	Node<DataType>* pWalker = _pHead;
	while (pWalker != NULL) {
		if (pWalker->_data.getTenPhim() == x) {
			return pWalker;
		}
		pWalker = pWalker->_pNext;
	}
	return pWalker;


}
template <class DataType>
Node<DataType>* LinkedList<DataType>::searchTenDVNam(string x) {
	Node<DataType>* pWalker = _pHead;
	while (pWalker != NULL) {
		if (pWalker->_data.getTenDienVienNam() == x) {
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
	LinkedList<Video> listVideos;
	int iOption = 0;
	bool checkDocFile = false;
	do {
		system("cls");
		cout << "0. Thoat chuong trinh" << endl;
		cout << "1. Doc file (doc 1 lan duy nhat)" << endl;
		cout << "2. Hien thi danh sach video" << endl;
		cout << "3. Cap nhat the loai cho bo phim co ten X" << endl;
		cout << "4. Tim phim tu mot dien vien nam" << endl;
		cout << "5. Thong ke phim theo dao dien" << endl;
		cout << "6. Ghi ra 3 bo phim moi nhat" << endl;
		cout << "Nhap thao tac:" << endl;
		cin >> iOption;
		switch (iOption)
		{
		case 0: {
			break;
		}
		case 1: {
			if (checkDocFile == true) { 
				cout << "Doc file that bai" << endl;
			}
			else {
				listVideos.xuLyDocFile();
				checkDocFile = true;
				cout << "Doc file thanh cong" << endl;
			}
			system("pause");
			break;
		}
		case 2: {
			cout << "Hien thi danh sach:" << endl;
			listVideos.display();
			cout << endl;
			system("pause");
			break;
		}
		case 3: {
			cout << "Cap nhat the loai cho bo phim co ten X" << endl;
			cout << "Nhap ten phim muon cap nhat:" << endl;
			string tenPhim;
			cin >> tenPhim;
			Node<Video>* timPhim = listVideos.searchTenPhim(tenPhim);
			if (timPhim == NULL) {
				cout << "Khong tim thay bo phim nao" << endl;
			}
			else {
				timPhim->display();
				cout << endl;
				string theLoai;
				cout << "Nhap the loai phim muon cap nhat (hai, hinhsu, tinhcam):" << endl;
				cin >> theLoai;
				Video temp = timPhim->getData();
				temp.setTheLoai(theLoai);
				timPhim->setData(temp);
				listVideos.updateFile();
				cout << "Cap nhat thanh cong" << endl;
				listVideos.display();
			}

		
			system("pause");
			break;
		}
		case 4: {
			cout << "Tim phim tu mot dien vien nam" << endl;
			cout << "Nhap ten dien vien nam muon tim:" << endl;
			string tenDV;
			cin >> tenDV;
			listVideos.ghiDanhSachPhimTheoDienVien(tenDV);	

			system("pause");
			break;
		}
		case 5: {
			cout << "Thong ke phim theo dao dien" << endl;
			listVideos.thongKeTheoDaoDien();

			system("pause");
			break;
			
			system("pause");
			break;
		}
		case 6: {
			cout << "Ghi ra 3 bo phim moi nhat" << endl;
			listVideos.thongKePhimMoi();
			system("pause");
			break;
		}
		default:
			break;
		}



	} while (iOption != 0);






	return 0;
}

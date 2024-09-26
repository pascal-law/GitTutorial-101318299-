#include "File.h"

File::File(string name, string content, Date& date) {
	fileName = name;
	fileContent = content;
	fileDate = date;
}

bool File::lessThan(Date& d) {
	return fileDate.lessThan(d);
}

void File::print() {
	cout << "File name: " << fileName << endl;
	cout << "Last modified date: " ;
	fileDate.print();
	cout << endl;
}

void File::printContents() {
	print();
	cout << "Content: " << fileContent << endl;
}
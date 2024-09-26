#include "File.h"

File::File(string name, string content, Date& date) {
	this->name = name;
	this->content = content;
	this->date = date;
}

bool File::lessThan(Date& d) {
	return date.lessThan(d);
}

void File::print() {
	cout << "File name: " << name << endl;
	cout << "Last modified: " ;
	date.print();
	cout << endl;
}

void File::printContents() {
	print();
	cout << "Content: " << content << endl;
}
#include "File.h"

File::File(string name, string content, Date& date) {
	name = name;
	content = content;
	date = date;
}

bool File::lessThan(Date& d) {
	return date.lessThan(d);
}

void File::print() {
	cout << "File name: " << name << endl;
	cout << "Last modified date: " ;
	date.print();
	cout << endl;
}

void File::printContents() {
	print();
	cout << "Content: " << content << endl;
}
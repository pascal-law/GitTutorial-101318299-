#include "File.h"c

File::File(string name, string content, Date& date) {
	name = name;
	content = content;
	date = date;
}

bool File::lessThan(Date& d) {
	return date.lessThan(d);
}

void File::print() {
	cout << name << ", last modified: ";
	date.print();
	cout << endl;
}

void File::printContents() {
	cout << content << endl;
}
#include "File.h"

File::File() {
	this->name = "";
	this->content = "";
	this->date = Date();
}


File::File(const string& name, const string& content, Date& date) {
	this->name = name;
	this->content = content;
	this->date = date;
}

const string& File::getName() { return name; }

Date File::getDate() { return date; }

bool File::lessThan(File& f) {
	return date.lessThan(f.date);
}

void File::print() {
	cout << "File: " << name << endl;
	cout << "Last modified: " ;
	date.print();
	cout << endl;
}

void File::printContents() {
	print();
	cout << "Content: " << content << endl;
}
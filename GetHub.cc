#include "GetHub.h"

GetHub::GetHub() {
	rl = new RepoList();
}

GetHub::~GetHub() {
	delete rl; // delete rl will call the destructor of RepoList
}

void GetHub::addRepo(const string& title, const string& owner) {
	rl->add(new Repo(title, owner));
}

// RepoList's remove methods return a Repo pointer and thus cannot free the allocated memory
// So we do it here
void GetHub::deleteRepo(int index) {
	Repo* repoPtr = rl->remove(index);
	if (repoPtr == nullptr) {
		cout << "There is no such Repo." << endl;
	} else {
		delete repoPtr;
	}
}

int GetHub::getNumRepos() {
	return rl->getNumRepos();
}

// If the index given is valid, return a pointer to the Repo at the given index using the double pointer output parameter.
// Return true if successful, and false otherwise.
bool GetHub::download(int index, Repo** repop) {
	if (!rl->isInvalidIndex(index)) {
		*repop = rl->get(index);
		return true;
	}
	return false;
}


// File functions

// If the Repo exists and there is room in the Repo, use the arguments to add a new File to the Repo.
void GetHub::addFile(const string& repoTitle, const string& fileTitle, const string& content, Date& date) {
	Repo* r = rl->get(repoTitle);
	if (r != nullptr) {
		r->addFile(fileTitle, content, date);
	}
}

void GetHub::addFile(int repo, const string& fileTitle,	const string& content, Date& date) {
	Repo* r = rl->get(repo);
	if (r != nullptr) {
		r->addFile(fileTitle, content, date);
	}
}

// Attempt to remove and delete the File at the given index from the Repo.
// If there is no such Repo, or no such File, output an error message.
void GetHub::deleteFile(int repo, int file) {
	Repo* r = rl->get(repo);
	if (r == nullptr) {
		cout << "There is no such Repo." << endl;
	}
	else {
		if(!r->removeFile(file)) {
			cout << "There is no such File in this Repo." << endl;
		}
	}
}

void GetHub::printRepos() {
	cout << "Gethub" << endl;
	cout << "========" << endl;
	for (int i = 0; i < rl->getNumRepos(); i++) {
		cout << i << ") Title: " << rl->get(i)->getTitle() << endl;
		cout << "Owner: " << rl->get(i)->getOwner() << endl;
	}
}

void GetHub::printRepo(int index) {
	rl->get(index)->printFiles();
}

void GetHub::printFileContents(int repoIndex, int fileIndex) {
	if (!rl->isInvalidIndex(repoIndex)) {
		rl->get(repoIndex)->printContents(fileIndex);
	}
}

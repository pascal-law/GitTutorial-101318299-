#include "RepoList.h"

RepoList::RepoList() {
	numRepos = 0;
	repoList = new Repo*[MAX_ARRAY];
}
		

RepoList::~RepoList() {
	for (int i = 0; i < numRepos; i++) {
		delete repoList[i];
	}
	delete [] repoList;
}

int RepoList::getNumRepos() { return numRepos; }

bool RepoList::isInvalidIndex(int index) {
	return index < 0 || index >= numRepos;
}

// assume that the repoList is contains no nullptr all the way till numRepos
// add to the back of the array
bool RepoList::add(Repo* r) {
	if (numRepos >= MAX_ARRAY) return false;
	repoList[numRepos++] = r;
	return true;
}

Repo* RepoList::get(const string& title) {
	for (int i = 0; i < numRepos; ++i){
        if (repoList[i]->getTitle() == title){
            return repoList[i];
        }
    }
    return nullptr;
}

Repo* RepoList::get(int index) {
	if (isInvalidIndex(index)) return nullptr;
	return repoList[index];
}

Repo* RepoList::remove(const string& title) {
	int index = 0;
	while (!(repoList[index]->getTitle() == title) && index < numRepos) {
		++index;
	}
	return remove(index);
}

Repo* RepoList::remove(int index) {
	if (isInvalidIndex(index)) return nullptr;
	Repo* r = repoList[index];
	while (index < numRepos - 1) {
		repoList[index] = repoList[index + 1];
		++index;
	}
	--numRepos;
	return r;
}

int RepoList::size() {
	return numRepos;
}

bool RepoList::isFull() {
	return numRepos >= MAX_ARRAY;
}
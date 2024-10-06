#ifndef REPOLIST_H
#define REPOLIST_H

#include "defs.h"
#include "Repo.h"

class RepoList {
	public:
		//constructor
		RepoList();
				
		//destructor
		~RepoList();
		
		int getNumRepos();
		bool isInvalidIndex(int index);


		//other
		bool add(Repo* r);
		Repo* get(const string& name);
		Repo* get(int index);
		Repo* remove(const string& name);
		Repo* remove(int index);
		int size();
		bool isFull();
	
	private:
		int numRepos;
		Repo** repoList;
};

#endif
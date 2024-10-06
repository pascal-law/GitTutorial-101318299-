#ifndef GETHUB_H
#define GETHUB_H

#include "RepoList.h"

class GetHub {
	public:
		GetHub();
		~GetHub();

		// Repo functions
		void addRepo(const string& repo, const string& owner);
		void deleteRepo(int repo);
		int getNumRepos();
		bool download(int index, Repo** repop);

		// File functions
		void addFile(const string& repoTitle, const string& fileTitle, const string& content, Date& date);
		void addFile(int repo, const string& fileTitle,	const string& content, Date& date);
		void deleteFile(int repo, int file);

		// print functions
		void printRepos();
		void printRepo(int index);
		void printFileContents(int repoIndex, int fileIndex);
		

	private:
		RepoList* rl;

};

#endif
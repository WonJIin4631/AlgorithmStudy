#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

struct Trie {
	Trie* next[26];
	bool term;
	int cnt = 0;
	Trie() : term(false) {
		memset(next, 0, sizeof(next));
	}
	~Trie() {
		for (int i = 0; i < 26; i++) {
			if (next[i])
				delete next[i];
		}
	}
	void insert(const char* key) {
		if (key == "\0")
			term = true;
		else {
			int curr = *key - 'a';
			if (next[curr] == NULL)
				next[curr] = new Trie();
			cnt += 1;
			next[curr]->insert(key + 1);
		}
	}
	Trie* find(const char * key) {
		if (*key == '\0') {
			return this;
		}

		int curr = *key - 'a';
		
		if (*key == '?') {
			for (int i = 0; i < 26; i++) {
				if (next[curr] != NULL)
					return next[curr]->find(key + 1);
			}
		}
		if (next[curr] == NULL)
			return NULL;

		return next[curr]->find(key + 1);
	}


};

vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;
	Trie *root = new Trie();
	for (int i = 0; i < words.size(); i++) {
		root->insert(words[i].c_str);
	}
	for (int i = 0; i < queries.size(); i++) {
		cout << root->find(queries[i].c_str)->cnt << '\n';
	}
	return answer;
}
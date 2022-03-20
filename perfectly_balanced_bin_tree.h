//Torok Szabolcs - tsim2095 - 514/2 - ADATSZERKEZETEK PROJEKT

#ifndef PERFECTLY_BALANCED_BIN_TREE_H
#define PERFECTLY_BALANCED_BIN_TREE_H
#include <string>

struct Node {
	std::string e_1;
	std::string e_2;
	Node* bal;
	Node* jobb;
	Node* elozo;
};


class TEBFa {
private:
	Node* gyoker;
	int magassag;
	std::string* tomb_1;
	std::string* tomb_2;
	int n;

	//új csomópontot hoz létre - insertNodes tagfüggvénnyel m?ködik együtt
	Node* createNode(std::string, std::string);
	//konstruktorból vagy resize tagfüggvény által kapott információ alapján
	//képlet szerint felépiti a tökéletesen kiegyensúlyozott fát
	void insertNodes(Node**, std::string*, std::string*, int, int, int);
	//töröl egy létez? csomópontot -- destruktorral múködik együtt
	void destroyNodes(Node**);
	//vizuális alakban kiirja a fát
	void printTree(Node*, int);
	
public:
	TEBFa(); 
	TEBFa(const char*);
	TEBFa(std::string*, std::string*, int);
	TEBFa(const TEBFa&);
	~TEBFa();

	//ujrameretezi a fat adott meretre, adott elemekkel
	void resize(std::string*, std::string*, int);
	//visszateriti a fa gyokeret
	Node* getRoot();
	//visszateriti a fa magassagat
	int getHeight();
	//beszur egy uj elemet a faba
	void insertElement(std::string, std::string);
	//vizualis formaban szemlelteti a fat
	void printTree();

	//bejarasok
	//alapertelmezetten, parameter nelkuli meghivaskor a bejarasok a gyokerbol indulnak
	void inorder();
	void preorder();
	void postorder();
	
	//tetszoleges csucsbol inditott bejarasok
	void inorder(Node*);
	void preorder(Node*);
	void postorder(Node*);

};


#endif // !PERFECTLY_BALANCED_BIN_TREE_H
#pragma once

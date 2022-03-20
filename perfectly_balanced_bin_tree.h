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

	//�j csom�pontot hoz l�tre - insertNodes tagf�ggv�nnyel m?k�dik egy�tt
	Node* createNode(std::string, std::string);
	//konstruktorb�l vagy resize tagf�ggv�ny �ltal kapott inform�ci� alapj�n
	//k�plet szerint fel�piti a t�k�letesen kiegyens�lyozott f�t
	void insertNodes(Node**, std::string*, std::string*, int, int, int);
	//t�r�l egy l�tez? csom�pontot -- destruktorral m�k�dik egy�tt
	void destroyNodes(Node**);
	//vizu�lis alakban kiirja a f�t
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

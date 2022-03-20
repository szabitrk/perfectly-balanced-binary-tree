//Torok Szabolcs - tsim2095 - 514/2 - ADATSZERKEZETEK PROJEKT

#include "perfectly_balanced_bin_tree.h"
#include <iostream>
#include <fstream>

//----------------------------PRIVÁT----------------------------


Node* TEBFa::createNode(std::string hu, std::string de)
{
	Node* node = new Node;
	node->bal = nullptr;
	node->jobb = nullptr;
	node->elozo = nullptr;
	node->e_1 = hu;
	node->e_2 = de;

	return node;
}

void TEBFa::insertNodes(Node** gy, std::string* seged_hu, std::string* seged_de, int kezd, int veg, int i)
{
	if (veg - kezd >= 0)
	{
		if (i > magassag)
			magassag = i;

		*gy = createNode(seged_hu[kezd], seged_de[kezd]);
		int nb = (veg - kezd + 1) / 2;
		int nj = (veg - kezd + 1) - nb - 1;

		if (nb > 0)
		{
			insertNodes((&(*gy)->bal), seged_hu, seged_de, kezd + 1, kezd + nb, i + 1);
			((*gy)->bal)->elozo = *gy;
		}
		if (nj > 0)
		{
			insertNodes((&(*gy)->jobb), seged_hu, seged_de, veg - nj + 1, veg, i + 1);
			((*gy)->jobb)->elozo = *gy;
		}
	}
}

void TEBFa::destroyNodes(Node** gy)
{

	if (*(&(*gy)->bal))
		destroyNodes((&(*gy)->bal));

	if (*(&(*gy)->jobb))
		destroyNodes((&(*gy)->jobb));

	//std::cout << "Node: " << *(&(*gy)->ertek) << " destroyed.\n";
	delete* gy;
}

void TEBFa::printTree(Node* gy, int depth)
{
	if (gy != nullptr)
	{
		printTree(gy->jobb, depth + 1);
		std::cout << std::endl;
		for (int i = 0; i < depth; i++)
		{
			std::cout << "\t\t";
		}

		std::cout << gy->e_1 << std::endl;
		for (int i = 0; i < depth; i++)
		{
			std::cout << "\t\t";
		}
		std::cout << gy->e_2 << std::endl;
		printTree(gy->bal, depth + 1);
	}
}

//----------------------------KONSTRUKTOROK ÉS DESTRUKTOR----------------------------


TEBFa::TEBFa()
{
	gyoker = nullptr;
	magassag = 0;
	tomb_1 = nullptr;
	tomb_2 = nullptr;
	n = 0;
}

TEBFa::TEBFa(const char* input)
{
	gyoker = nullptr;
	magassag = 0;

	std::ifstream fin(input);

	fin >> n;
	tomb_1 = new std::string[n];
	tomb_2 = new std::string[n];
	for (int i = 0; i < n; i++)
	{
		fin >> tomb_1[i] >> tomb_2[i];
	}
	insertNodes(&gyoker, tomb_1, tomb_2, 0, n-1, 0);
}

TEBFa::TEBFa(std::string* a, std::string* b, int meret)
{
	gyoker = nullptr;
	n = meret;
	tomb_1 = new std::string[n];
	tomb_2 = new std::string[n];
	magassag = 0;
	for (int i = 0; i < n; i++)
	{
		tomb_1[i] = a[i];
		tomb_2[i] = b[i];
	}
	insertNodes(&gyoker, tomb_1, tomb_2, 0, n - 1, 1);
}

TEBFa::TEBFa(const TEBFa& b)
{
	n = b.n;
	tomb_1 = new std::string[n];
	tomb_2 = new std::string[n];
	for (int i = 0; i < n; i++)
	{
		tomb_1[i] = b.tomb_1[i];
		tomb_2[i] = b.tomb_2[i];
	}
	gyoker = nullptr;
	magassag = 0;
	insertNodes(&gyoker, tomb_1, tomb_2, 0, n - 1, 0);
}

TEBFa::~TEBFa()
{
	destroyNodes(&gyoker);
	delete[] tomb_1;
	delete[] tomb_2;
}

//----------------------------FUNKCIONÁLIS FÜGGVÉNYEK----------------------------


Node* TEBFa::getRoot()
{
	return gyoker;
}

int TEBFa::getHeight()
{
	return magassag;
}

void TEBFa::resize(std::string* a, std::string* b, int uj_meret)
{
	destroyNodes(&gyoker);
	delete[] tomb_1;
	delete[] tomb_2;
	n = uj_meret;
	tomb_1 = new std::string[n];
	tomb_2 = new std::string[n];
	for (int i = 0; i < n; i++)
	{
		tomb_1[i] = a[i];
		tomb_2[i] = b[i];
	}
	insertNodes(&gyoker, tomb_1, tomb_2, 0, n - 1, 0);
}

void TEBFa::insertElement(std::string e1, std::string e2)
{
	std::string* a = new std::string[n + 1];
	std::string* b = new std::string[n + 1];
	for (int i = 0; i < n; i++)
	{
		a[i] = tomb_1[i];
		b[i] = tomb_2[i];
	}
	a[n] = e1;
	b[n] = e2;
	resize(a, b, n + 1);
	delete[] a;
}

void TEBFa::printTree()
{
	std::cout << "-------------------------------------------------" << std::endl;
	printTree(this->gyoker, 0);
	std::cout << "-------------------------------------------------" << std::endl;
}

//----------------------------BEJÁRÁSOK----------------------------

void TEBFa::inorder(Node* gy)
{
	if (gy != nullptr)
	{
		inorder(gy->bal);
		std::cout << gy->e_1<< " - " << gy->e_2 << ", ";
		inorder(gy->jobb);
	}

	if (gy == gyoker)
		std::cout << std::endl;
}

void TEBFa::postorder(Node* gy)
{
	if (gy != nullptr)
	{
		postorder(gy->bal);
		postorder(gy->jobb);
		std::cout << gy->e_1 << " - " << gy->e_2 << ", ";
	}

	if (gy == gyoker)
		std::cout << std::endl;
}

void TEBFa::preorder(Node* gy)
{
	if (gy != nullptr)
	{
		std::cout << gy->e_1 << " - " << gy->e_2 << ", ";
		preorder(gy->bal);
		preorder(gy->jobb);
	}

	if (gy == gyoker)
		std::cout << std::endl;
}

void TEBFa::inorder()
{
	inorder(this->gyoker);
}

void TEBFa::postorder()
{
	postorder(this->gyoker);
}

void TEBFa::preorder()
{
	preorder(this->gyoker);
}


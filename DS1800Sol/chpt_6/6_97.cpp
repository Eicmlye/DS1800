#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "6_97.h"

BiTree buildBiTree(size_t level)
{
	#define CLRSTDIN do { while (getchar() != '\n') { continue; }} while (0)
	#define INDENT(m_indsize) do { for (size_t index = 0; index < m_indsize; ++index) { std::cout << "    "; }} while (0)

	// Welcome guide;
	if (level == 1) {
		std::cout << "A binary tree is being built. " << std::endl;
		std::cout << "Enter the name (20 char at most) and data of the node after prompting (e.g. \"nodeName 100\"), " << std::endl;
		std::cout << "or enter \"null node\" for empty node. " << std::endl << std::endl;
		std::cout << "The quotation marks are not neccessary for input. " << std::endl;
		std::cout << "Root: ";
	}

	// test empty input and rewinding;
	char temp = '\0';
	while ((temp = getchar()) == '\n') {
		// move back to the end of the line;
		std::cout << "\033[1A";
		for (size_t index = 0; index < (level - 1) * 4 + 8; ++index) {
			std::cout << "\033[1C";
		}
		if (level == 1) {
			std::cout << "\033[2D";
		}
	}
	ungetc(temp, stdin);

	// load in data;
	TreeNode* node = new TreeNode;
	if (scanf("%s %d", &(node->data.name), & (node->data.size)) == 2) {
		// clear stdin for the next empty-input test;
		CLRSTDIN;

		INDENT(level);
		std::cout << "Lchild: ";
		node->lchild = buildBiTree(level + 1);
		if (node->lchild == nullptr) {
			std::cout << "\r\033[1A\033[K";
			INDENT(level);
			std::cout << "Lchild: NULL" << std::endl;
		}

		INDENT(level);
		std::cout << "Rchild: ";
		node->rchild = buildBiTree(level + 1);
		if (node->rchild == nullptr) {
			std::cout << "\r\033[1A\033[K";
			INDENT(level);
			std::cout << "Rchild: NULL" << std::endl;
		}

		if (node->lchild == nullptr && node->rchild == nullptr) {
			std::cout << "\r\033[1A\033[K";
			std::cout << "\r\033[1A\033[K";
		}

		return node;
	}
	else { // empty child;
		// clear stdin for the next empty-input test;
		CLRSTDIN;

		return nullptr;
	}
}

size_t printCatalog(BiTree catalog)
{
	if (catalog != nullptr) {
		size_t cache = printCatalog(catalog->lchild);

		std::cout << catalog->data.name << " (";

		std::cout << catalog->data.size + cache;

		std::cout << ')' << std::endl;

		return cache + catalog->data.size + printCatalog(catalog->rchild);
	}
	else {
		return 0; 
	}
}
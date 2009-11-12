#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "arvore_binaria.h"


BTNode::BTNode() {
	lchild = NULL;
	lchild = NULL;
	parent = NULL;
}

// parent
BTNode::BTNode(BTNode* p) {
	lchild = NULL;
	rchild = NULL;
	parent = p;
}

// parent, element
template <class T>
BTNode::BTNode(BTNode* p, T& e) {
	lchild 	= NULL;
	rchild 	= NULL;
	parent 	= p;
	elem	= t;
}

// parent, left, right
BTNode::BTNode(BTNode* p, BTNode* l, BTNode* r) {
	lchild	= l;
	rchild	= r;
	parent	= p;
}

// parent, left, right, element
template <class T>
BTNode::BTNode(BTNode* p, BTNode* l, BTNode* r, T& e) {
	lchild	= l;
	rchild	= r;
	parent	= p;
	elem	= e;
}

bool
BTNode::setParent(BTNode* p) {
	parent	= p;
}

BTNode*
BTNode::getParent() const { return parent; }

bool
BTNode::setRight(BTNode* r) {
	rchild	= r;
}

BTNode*
BTNode::getRight() const { return rchild; }

bool
BTNode::setLeft(BTNode* l) {
	lchild	= l;
}

BTNode*
BTNode::getLeft() const { return lchild; }


bool
BTNode::setElem(T& e) {
	elem = e;
}

T
BTNode::getElem() const { return elem; }


BinTree::BinTree() {
	size	= 0;
	root	= NULL;
}

int
BinTree::size() const {
	
		bool 	isEmpty() const;
		BTNode* root();
		BTNode* parent(BTNode*);
		bool 	isInternal(BTNode*);
		bool 	isExternal(BTNode*);
		bool 	isRoot(BTNode*);
		BTNode* leftChild(BTNode*);
		BTNode* rightChild(BTNode*);
		BTNode* sibiling(BTNode*);
		void 	swap(BTNode*, BTNode*);
		void 	replace(BTNode*, T&);
		BTNode* remove(BTNode*);
		BTNode* insertLeft(BTNode*, T&);
		BTNode* insertRight(BTNode*, T&);
		BTNode* search(BTNode*, T&);
		BTNode* expandExternal(BTNode*);
		BTNode* removeAboveExternal(BTNode*);

	private:

		int	size;
		BTNode*	root;
};

#endif

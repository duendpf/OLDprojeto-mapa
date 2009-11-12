#ifndef _ARVORE_BINARIA_H_
#define _ARVORE_BINARIA_H_

template <class T>
class BTNode 
{
	public:

		BTNode();
		BTNode(BTNode*); // parent
		BTNode(BTNode*, T&); // parent, element
		BTNode(BTNode*, BTNode*, BTNode*); // parent, left, right
		BTNode(BTNode*, BTNode*, BTNode*, T&); // parent, left, right, element

		bool 	setParent(BTNode*);
		BTNode* getParent() const;

		bool 	setRight(BTNode*);
		BTNode* getRight() const;
		bool 	setLeft(BTNode*);
		BTNode* getLeft() const;

		bool 	setElem(T&);
		T 	getElem() const;
	
	private:

		BTNode* rchild;
		BTNode* lchild;
		BTNode* parent;
		T elem;
};


template <class T>
class BinTree
{
	public:

		BinTree();

		int 	size() const;
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

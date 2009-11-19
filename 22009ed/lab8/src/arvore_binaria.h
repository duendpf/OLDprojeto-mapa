#ifndef _ARVORE_BINARIA_H_
#define _ARVORE_BINARIA_H_

template <class T>
class BTNode 
{
	public:

		BTNode();
		BTNode(BTNode*); // parent - will be the left of parent
		BTNode(BTNode*, T&); // parent, element - will be the left of parent
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
		BinTree(BTNode<T>*); // root

		int 	size() const;
		int	size(BTNode<T>*) const;
		bool 	isEmpty() const;
		BTNode<T>* root();
		BTNode<T>* parent(BTNode<T>*);
		bool 	isInternal(BTNode<T>*);
		bool 	isExternal(BTNode<T>*);
		bool 	isRoot(BTNode<T>*);
		BTNode<T>* leftChild(BTNode<T>*);
		BTNode<T>* rightChild(BTNode<T>*);
		BTNode<T>* sibiling(BTNode<T>*);
		void 	swap(BTNode<T>*, BTNode<T>*);
		void 	replace(BTNode<T>*, T&);
		BTNode<T>* remove(BTNode<T>*);
		BTNode<T>* insertLeft(BTNode<T>*, T&);
		BTNode<T>* insertRight(BTNode<T>*, T&);
		BTNode<T>* search(BTNode<T>*, T&);
		BTNode<T>* expandExternal(BTNode<T>*);
		BTNode<T>* removeAboveExternal(BTNode<T>*);

	private:

		int		tsize;
		BTNode<T>*	troot;
};

template <class T>
BTNode<T>::BTNode() {
	lchild = NULL;
	lchild = NULL;
	parent = NULL;
}

// parent
template <class T>
BTNode<T>::BTNode(BTNode<T>* p) {
	lchild = NULL;
	rchild = NULL;
	parent = p;
}

// parent, element
template <class T>
BTNode<T>::BTNode(BTNode<T>* p, T& e) {
	lchild 	= NULL;
	rchild 	= NULL;
	parent 	= p;
	elem	= e;
}

// parent, left, right
template <class T>
BTNode<T>::BTNode(BTNode<T>* p, BTNode<T>* l, BTNode<T>* r) {
	lchild	= l;
	rchild	= r;
	parent	= p;
}

// parent, left, right, element
template <class T>
BTNode<T>::BTNode(BTNode<T>* p, BTNode<T>* l, BTNode<T>* r, T& e) {
	lchild	= l;
	rchild	= r;
	parent	= p;
	elem	= e;
}

template <class T>
bool
BTNode<T>::setParent(BTNode<T>* p) {
	parent	= p;
}

template <class T>
BTNode<T>*
BTNode<T>::getParent() const { return(parent); }

template <class T>
bool
BTNode<T>::setRight(BTNode<T>* r) {
	rchild	= r;
}

template <class T>
BTNode<T>*
BTNode<T>::getRight() const { return(rchild); }

template <class T>
bool
BTNode<T>::setLeft(BTNode<T>* l) {
	lchild	= l;
}

template <class T>
BTNode<T>*
BTNode<T>::getLeft() const { return(lchild); }


template <class T>
bool
BTNode<T>::setElem(T& e) {
	elem = e;
}

template <class T>
T
BTNode<T>::getElem() const { return(elem); }


template <class T>
BinTree<T>::BinTree() {
	tsize	= 0;
	troot	= NULL;
}

template <class T>
BinTree<T>::BinTree(BTNode<T>* r) {
	tsize	= 1;
	troot	= r;
}

template <class T>
int
BinTree<T>::size() const { return(tsize); }

template <class T>
int
BinTree<T>::size(BTNode<T>* stroot) const {
	if(troot == NULL)
		return(0);
	else {
		// the count of the root node in question
		int count = 1;

		// descend into left subtree
		count += size(stroot->getLeft());
		// descend into right subtee
		count += size(stroot->getright());

		return(count);
	}
}


template <class T>
bool
BinTree<T>::isEmpty() const { return(troot == NULL); }

template <class T>
BTNode<T>*
BinTree<T>::root() { return(troot); }

template <class T>
BTNode<T>*
BinTree<T>::parent(BTNode<T>* node) { return(node->getParent()); }

template <class T>
bool
BinTree<T>::isInternal(BTNode<T>* node) { return(node->getLeft() != NULL && node->getRight() != NULL); }

template <class T>
bool
BinTree<T>::isExternal(BTNode<T>* node) { return(node->getLeft() == NULL && node->getRight() == NULL); }

template <class T>
bool
BinTree<T>::isRoot(BTNode<T>* node) { return(node->getParent() == NULL); }

template <class T>
BTNode<T>*
BinTree<T>::leftChild(BTNode<T>* node) { return(node->getLeft()); }

template <class T>
BTNode<T>*
BinTree<T>::rightChild(BTNode<T>* node) { return(node->getRight()); }

template <class T>
BTNode<T>*
BinTree<T>::sibiling(BTNode<T>* node) {
	if(node == node->getParent()->getLeft())
		return node->getParent()->getRight();
	else
		return node->getParent()->getLeft();
}

template <class T>
void
BinTree<T>::swap(BTNode<T>* n1, BTNode<T>* n2) {
	BTNode<T> tmp;
	tmp.setParent(n1->getParent());
	tmp.setLeft(n1->getLeft());
	tmp.setRight(n1->getRight());
	tmp.setElem(n1->getElem());

	n1->setParent(n2->getParent());
	n1->setLeft(n2->getLeft());
	n1->setRight(n2->getRight());
	n1->setElem(n2->getElem());

	n2->setParent(tmp.getParent());
	n2->setLeft(tmp.getLeft());
	n2->setRight(tmp.getRight());
	n2->setElem(tmp.getElem());
}

template <class T>
void
BinTree<T>::replace(BTNode<T>* node, T& e) {
	node->setElem(e);
}

template <class T>
BTNode<T>*
BinTree<T>::remove(BTNode<T>* node) {
	if(isExternal(node)) {
		if(node->getParent()->getLeft() == node)
			node->getParent()->setLeft(NULL);
		else
			node->getParent()->setRight(NULL);
		
		return(node);
	} else {
		remove(node->getLeft());
		remove(node->getRight());
		return(node);
	}
}

template <class T>
BTNode<T>*
BinTree<T>::insertLeft(BTNode<T>* node, T& e) {
	if(node->getLeft() == NULL) {
		BTNode<T>* n = new BTNode<T>(node, e);
		node->setLeft(n);
		return(n);
	} else {
		BTNode<T> *n = new BTNode<T>(node, node->getLeft(), NULL, e);
		node->setLeft(n);
		n->getLeft()->setParent(n);
		return(n);
	}
}

template <class T>
BTNode<T>*
BinTree<T>::insertRight(BTNode<T>* node, T& e) {
	if(node->getRight() == NULL) {
		BTNode<T> *n = new BTNode<T>(node, e);
		node->setRight(n);
		return(n);
	} else {
		BTNode<T> *n = new BTNode<T>(node, NULL, node->getRight(), e);
		node->setRight(n);
		n->getRight()->setParent(n);
		return(n);
	}
}

template <class T>
BTNode<T>*
BinTree<T>::search(BTNode<T>* node, T& e) {
	// test here if the is null 
	// if it is, say goodbye!
	if(node == NULL || node->getElem() == e) {
		return(node);
	} else {
		search(node->getLeft(), e);
		search(node->getRight(), e);
	}
}

template <class T>
BTNode<T>*
BinTree<T>::expandExternal(BTNode<T>* node) {
	if(isInternal(node)) {
		return(NULL);
	} else {
		BTNode<T> *nleft = new BTNode<T>(node);
		BTNode<T> *nright = new BTNode<T>(node);

		node->setLeft(nleft);
		node->setRight(nright);

		return(node);
	}
}

// this func. send to deep space the left and the parent of the passed node, as
// it turns to a leaf in the place of his parent
template <class T>
BTNode<T>*
BinTree<T>::removeAboveExternal(BTNode<T>* node) {
	if(isExternal(node)) {
		return(NULL);
	} else {
		if(sibiling(node) != NULL)
			delete sibiling(node);

		BTNode<T> *nparent = node->getParent()->getParent();
		if(node->getParent() == nparent->getLeft()) {
			nparent->setLeft(node);
		} else {
			nparent->setRight(node);
		}

		delete node->getParent();
		node->setParent(nparent);
		return(node);
	}
}
#endif

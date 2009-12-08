#ifndef _BTREE_H_
#define _BTREE_H_

/*
 * uses C++ templates, for this reason there is no .cpp
 * yes, it is frustrating...
 */

#define MAXPAGESIZE 10

template<class T>
class BTNode {
	public:
		BTNode();
		BTNode(BTNode<T> &);
		BTNode(const T &);

		/* all the operations will be done by BTree class, which will be
		 * friend of BTNode
		 *
		 * thus, BTNode does not need an usual interface
		 *
		 * idea by Adam Drozdek, in "Estrutura de dados e algoritmos em
		 * C++" (ed. Thomson Learning)
		 */

	private:
		bool		leaf;
		int		keyTally;
		// not the element itself, but the key of the element
		// it could be a class that carries a pointer to the real
		// payload and a key.
		T		keys[MAXPAGESIZE-1];
		BTNode<T>	*pointers[MAXPAGESIZE];

		friend	class BTree;
};

template<class T>
class BTree {
	public:
		BTree();
		BTree(T &);

		BTNode<T>	*search(T &, BTNode<T> *);
		bool		insert(T &);
		T		remove(T &);

	private:
		BTNode<T>	*troot;
};

template <class T>
BTNode<T>::BTNode() {
	leaf = true;
	keyTally = 0;

	for(int i = 0; i < MAXPAGESIZE-1; i++) {
		T tmpk;
		keys[i] = tmpk;
	}

	for(int i = 0; i < MAXPAGESIZE-1; i++) {
		pointers[i] = NULL;
	}
}
		BTNode(BTNode<T> &);
		BTNode(const T &);



#endif

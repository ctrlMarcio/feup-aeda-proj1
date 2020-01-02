#ifndef _BST_H_
#define _BST_H_

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

template<class Comparable, class LessThan>
class BSTItrIn;

template<class Comparable, class LessThan>
class BSTItrPre;

template<class Comparable, class LessThan>
class BSTItrPost;

template<class Comparable, class LessThan>
class BSTItrLevel;

template<class Comparable, class LessThan>
class iteratorBST;

template<class Comparable, class LessThan = std::less<Comparable>> 
class BST;

template<class Comparable, class LessThan>
class BinaryNode
{
    Comparable element;
    BinaryNode *left;
    BinaryNode *right;

    BinaryNode( const Comparable & theElement, BinaryNode *lt, BinaryNode *rt )
            : element( theElement ), left( lt ), right( rt ) { }

	friend class BST<Comparable, LessThan>;

	friend class BSTItrIn<Comparable, LessThan>;

	friend class BSTItrPre<Comparable, LessThan>;

	friend class BSTItrPost<Comparable, LessThan>;

	friend class BSTItrLevel<Comparable, LessThan>;

	friend class iteratorBST<Comparable, LessThan>;
};

template<class Comparable, class LessThan>
class BST
{
public:
    explicit BST( const Comparable & notFound );
    BST( const BST & rhs );
    ~BST( );

    const Comparable & findMin( ) const;
    const Comparable & findMax( ) const;
    const Comparable & find( const Comparable & x ) const;
    bool isEmpty( ) const;
    void printTree( ) const;

    void makeEmpty( );
    bool insert( const Comparable & x );
    bool remove( const Comparable & x );

    const BST & operator=( const BST & rhs );

	iteratorBST<Comparable, LessThan> begin() const;

	iteratorBST<Comparable, LessThan> end() const;

private:
	BinaryNode<Comparable, LessThan> *root;
    const Comparable ITEM_NOT_FOUND;
	LessThan lt;

	const Comparable &elementAt(BinaryNode<Comparable, LessThan> *t) const;

	bool insert(const Comparable &x, BinaryNode<Comparable, LessThan> *&t) const;

	bool remove(const Comparable &x, BinaryNode<Comparable, LessThan> *&t) const;

	BinaryNode<Comparable, LessThan> *findMin(BinaryNode<Comparable, LessThan> *t) const;

	BinaryNode<Comparable, LessThan> *findMax(BinaryNode<Comparable, LessThan> *t) const;

	BinaryNode<Comparable, LessThan> *find(const Comparable &x, BinaryNode<Comparable, LessThan> *t) const;

	void makeEmpty(BinaryNode<Comparable, LessThan> *&t) const;

	void printTree(BinaryNode<Comparable, LessThan> *t) const;

	BinaryNode<Comparable, LessThan> *clone(BinaryNode<Comparable, LessThan> *t) const;

	friend class BSTItrIn<Comparable, LessThan>;

	friend class BSTItrPre<Comparable, LessThan>;

	friend class BSTItrPost<Comparable, LessThan>;

	friend class BSTItrLevel<Comparable, LessThan>;

	friend class iteratorBST<Comparable, LessThan>;
};

// Note that all "matching" is based on the < method.

template<class Comparable, class LessThan>
BST<Comparable, LessThan>::BST(const Comparable &notFound) :
        root(NULL), ITEM_NOT_FOUND( notFound )
{ }

template<class Comparable, class LessThan>
BST<Comparable, LessThan>::BST(const BST<Comparable, LessThan> &rhs) : root(NULL), ITEM_NOT_FOUND(rhs.ITEM_NOT_FOUND)
{
    *this = rhs;
}


template<class Comparable, class LessThan>
BST<Comparable, LessThan>::~BST()
{
    makeEmpty( );
}

template<class Comparable, class LessThan>
bool BST<Comparable, LessThan>::insert(const Comparable &x)
{
    return insert( x, root );
}

template<class Comparable, class LessThan>
bool BST<Comparable, LessThan>::remove(const Comparable &x)
{
    return remove( x, root );
}

template<class Comparable, class LessThan>
const Comparable &BST<Comparable, LessThan>::findMin() const
{
    return elementAt( findMin( root ) );
}

template<class Comparable, class LessThan>
const Comparable &BST<Comparable, LessThan>::findMax() const
{
    return elementAt( findMax( root ) );
}

template<class Comparable, class LessThan>
const Comparable &BST<Comparable, LessThan>::
find( const Comparable & x ) const
{
    return elementAt( find( x, root ) );
}

template<class Comparable, class LessThan>
void BST<Comparable, LessThan>::makeEmpty()
{
    makeEmpty( root );
}

template<class Comparable, class LessThan>
bool BST<Comparable, LessThan>::isEmpty() const
{
    return root == NULL;
}


template<class Comparable, class LessThan>
void BST<Comparable, LessThan>::printTree() const
{
    if( isEmpty( ) )
        cout << "Empty tree" << endl;
    else
        printTree( root );
}

template<class Comparable, class LessThan>
const BST<Comparable, LessThan> &
BST<Comparable, LessThan>::
operator=(const BST<Comparable, LessThan> &rhs)
{
    if( this != &rhs )
    {
        makeEmpty( );
        root = clone( rhs.root );
    }
    return *this;
}


template<class Comparable, class LessThan>
iteratorBST<Comparable, LessThan> BST<Comparable, LessThan>::begin() const {
	iteratorBST<Comparable, LessThan> it;
    it.setBST(root);
    return it;
}

template<class Comparable, class LessThan>
iteratorBST<Comparable, LessThan> BST<Comparable, LessThan>::end() const {
	iteratorBST<Comparable, LessThan> it;
    it.setBST(NULL);
    return it;
}


// private methods

template<class Comparable, class LessThan>
const Comparable &BST<Comparable, LessThan>::
elementAt(BinaryNode<Comparable, LessThan> *t) const
{
    if( t == NULL )
        return ITEM_NOT_FOUND;
    else
        return t->element;
}


template<class Comparable, class LessThan>
bool BST<Comparable, LessThan>::
insert(const Comparable &x, BinaryNode<Comparable, LessThan> *&t) const {
    if (t == NULL) {
		t = new BinaryNode<Comparable, LessThan>(x, NULL, NULL);
        return true;
    } else if (lt(x, t->element))
        return insert( x, t->left );
	else if (lt(t->element, x))
        return insert( x, t->right );
    else
        return false;  // Duplicate; do nothing
}

template<class Comparable, class LessThan>
bool BST<Comparable, LessThan>::
remove(const Comparable &x, BinaryNode<Comparable, LessThan> *&t) const
{
    if( t == NULL )
        return false;   // Item not found; do nothing
	if (lt(x, t->element))
        return remove( x, t->left );
	else if (lt(t->element, x))
        return remove( x, t->right );
    else if( t->left != NULL && t->right != NULL ) // Two children
    {
        t->element = findMin( t->right )->element;
        return remove( t->element, t->right );
    }
    else
    {
		BinaryNode<Comparable, LessThan> *oldNode = t;
        t = ( t->left != NULL ) ? t->left : t->right;
        delete oldNode;
        return true;
    }
}

template<class Comparable, class LessThan>
BinaryNode<Comparable, LessThan> *
BST<Comparable, LessThan>::findMin(BinaryNode<Comparable, LessThan> *t) const
{
    if( t == NULL )
        return NULL;
    if( t->left == NULL )
        return t;
    return findMin( t->left );
}


template<class Comparable, class LessThan>
BinaryNode<Comparable, LessThan> *
BST<Comparable, LessThan>::findMax(BinaryNode<Comparable, LessThan> *t) const
{
    if( t != NULL )
        while( t->right != NULL )
            t = t->right;
    return t;
}

template<class Comparable, class LessThan>
BinaryNode<Comparable, LessThan> *
BST<Comparable, LessThan>::
find(const Comparable &x, BinaryNode<Comparable, LessThan> *t) const
{
    if( t == NULL )
        return NULL;
	else if (lt(x, t->element))
        return find( x, t->left );
	else if (lt(t->element, x))
        return find( x, t->right );
    else
        return t;    // Match
}
/****** NONRECURSIVE VERSION*************************
        template <class Comparable, class LessThan>
        BinaryNode<Comparable, LessThan> *
        BST<Comparable, LessThan>::
        find( const Comparable & x, BinaryNode<Comparable, LessThan> *t ) const
        {
            while( t != NULL )
                if( lt(x, t->element) )
                    t = t->left;
                else if( lt(t->element, x) )
                    t = t->right;
                else
                    return t;    // Match

            return NULL;   // No match
        }
*****************************************************/

/**
 * Internal method to make subtree empty.
 */
template<class Comparable, class LessThan>
void BST<Comparable, LessThan>::
makeEmpty(BinaryNode<Comparable, LessThan> *&t) const
{
    if( t != NULL )
    {
        makeEmpty( t->left );
        makeEmpty( t->right );
        delete t;
    }
    t = NULL;
}

template<class Comparable, class LessThan>
void BST<Comparable, LessThan>::printTree(BinaryNode<Comparable, LessThan> *t) const
{
    if( t != NULL )
    {
        printTree( t->left );
        cout << t->element << endl;
        printTree( t->right );
    }
}

template<class Comparable, class LessThan>
BinaryNode<Comparable, LessThan> *
BST<Comparable, LessThan>::clone(BinaryNode<Comparable, LessThan> *t) const
{
    if( t == NULL )
        return NULL;
    else
		return new BinaryNode<Comparable, LessThan>(t->element, clone(t->left), clone(t->right));
}


/**************
// Iteradores
**************/


template<class Comparable, class LessThan>
class BSTItrPost {
public:
	BSTItrPost(const BST<Comparable, LessThan> &bt);

    void advance();
    const Comparable &retrieve() { return itrStack.top()->element; }
    bool isAtEnd() {return itrStack.empty(); }

private:
	stack<BinaryNode<Comparable, LessThan> *> itrStack;
    stack<bool> visitStack;

	void slideDown(BinaryNode<Comparable, LessThan> *n);
};


template<class Comparable, class LessThan>
BSTItrPost<Comparable, LessThan>::BSTItrPost(const BST<Comparable, LessThan> &bt)
{
    if (!bt.isEmpty())
        slideDown(bt.root);
}

template<class Comparable, class LessThan>
void BSTItrPost<Comparable, LessThan>::advance()
{
    itrStack.pop();
    visitStack.pop();
    if ((!itrStack.empty()) && (visitStack.top() == false)) {
        visitStack.pop();
        visitStack.push(true);
        slideDown(itrStack.top()->right);
    }
}

template<class Comparable, class LessThan>
void BSTItrPost<Comparable, LessThan>::slideDown(BinaryNode<Comparable, LessThan> *n)
{
    while (n) {
        itrStack.push(n);
        if (n->left) {
            visitStack.push(false);
            n = n->left;
        } else if (n->right) {
            visitStack.push(true);
            n = n->right;
        } else {
            visitStack.push(true);
            break;
        }
    }
}


/////////////////////

template<class Comparable, class LessThan>
class BSTItrPre {
public:
	BSTItrPre(const BST<Comparable, LessThan> &bt);

    void advance();
    const Comparable &retrieve() { return itrStack.top()->element; }
    bool isAtEnd() {return itrStack.empty(); }

private:
	stack<BinaryNode<Comparable, LessThan> *> itrStack;

};

template<class Comparable, class LessThan>
BSTItrPre<Comparable, LessThan>::BSTItrPre(const BST<Comparable, LessThan> &bt)
{
    if (!bt.isEmpty())
        itrStack.push(bt.root);
}

template<class Comparable, class LessThan>
void BSTItrPre<Comparable, LessThan>::advance()
{
	BinaryNode<Comparable, LessThan> *actual = itrStack.top();
	BinaryNode<Comparable, LessThan> *seguinte = actual->left;
    if (seguinte)
        itrStack.push(seguinte);
    else {
        while (!itrStack.empty()) {
            actual = itrStack.top();
            itrStack.pop();
            seguinte = actual -> right;
            if (seguinte) {
                itrStack.push(seguinte);
                break;
            }
        }
    }
}


template<class Comparable, class LessThan>
class BSTItrIn {
public:
	BSTItrIn(const BST<Comparable, LessThan> &bt);

    void advance();
    const Comparable &retrieve() { return itrStack.top()->element; }
    bool isAtEnd() {return itrStack.empty(); }

private:
	stack<BinaryNode<Comparable, LessThan> *> itrStack;

	void slideLeft(BinaryNode<Comparable, LessThan> *n);
};

template<class Comparable, class LessThan>
BSTItrIn<Comparable, LessThan>::BSTItrIn(const BST<Comparable, LessThan> &bt)
{
    if (!bt.isEmpty())
        slideLeft(bt.root);
}

template<class Comparable, class LessThan>
void BSTItrIn<Comparable, LessThan>::slideLeft(BinaryNode<Comparable, LessThan> *n)
{
    while (n) {
        itrStack.push(n);
        n = n->left;
    }
}

template<class Comparable, class LessThan>
void BSTItrIn<Comparable, LessThan>::advance()
{
	BinaryNode<Comparable, LessThan> *actual = itrStack.top();
    itrStack.pop();
	BinaryNode<Comparable, LessThan> *seguinte = actual->right;
    if (seguinte)
        slideLeft(seguinte);
}


template<class Comparable, class LessThan>
class BSTItrLevel {
public:
	BSTItrLevel(const BST<Comparable, LessThan> &bt);

    void advance();
    const Comparable &retrieve() { return itrQueue.front()->element; }
    bool isAtEnd() {return itrQueue.empty(); }

private:
	queue<BinaryNode<Comparable, LessThan> *> itrQueue;

};

template<class Comparable, class LessThan>
BSTItrLevel<Comparable, LessThan>::BSTItrLevel(const BST<Comparable, LessThan> &bt)
{
    if (!bt.isEmpty())
        itrQueue.push(bt.root);
}

template<class Comparable, class LessThan>
void BSTItrLevel<Comparable, LessThan>::advance()
{
	BinaryNode<Comparable, LessThan> *actual = itrQueue.front();
    itrQueue.pop();
	BinaryNode<Comparable, LessThan> *seguinte = actual->left;
    if (seguinte)
        itrQueue.push(seguinte);
    seguinte = actual->right;
    if (seguinte)
        itrQueue.push(seguinte);
}


/////  outro iterador em ordem
template<class Comparable, class LessThan>
class iteratorBST {
	stack<BinaryNode<Comparable, LessThan> *> itrStack;

	void slideLeft(BinaryNode<Comparable, LessThan> *n);

	void setBST(BinaryNode<Comparable, LessThan> *root);

	friend class BST<Comparable, LessThan>;
public:
	iteratorBST<Comparable, LessThan> &operator++(int);
    Comparable operator*() const;

	bool operator==(const iteratorBST<Comparable, LessThan> &it2) const;

	bool operator!=(const iteratorBST<Comparable, LessThan> &it2) const;
};

template<class Comparable, class LessThan>
void iteratorBST<Comparable, LessThan>::slideLeft(BinaryNode<Comparable, LessThan> *n)
{
    while (n) {
        itrStack.push(n);
        n = n->left;
    }
}

template<class Comparable, class LessThan>
void iteratorBST<Comparable, LessThan>::setBST(BinaryNode<Comparable, LessThan> *root) {
    if (root!=NULL)
        slideLeft(root);
}

template<class Comparable, class LessThan>
iteratorBST<Comparable, LessThan> &iteratorBST<Comparable, LessThan>::operator++(int) {
	BinaryNode<Comparable, LessThan> *atual = itrStack.top();
    itrStack.pop();
	BinaryNode<Comparable, LessThan> *seguinte = atual->right;
    if (seguinte)
        slideLeft(seguinte);
    return *this;
}

template<class Comparable, class LessThan>
Comparable iteratorBST<Comparable, LessThan>::operator*() const {
    return itrStack.top()->element;
}

template<class Comparable, class LessThan>
bool iteratorBST<Comparable, LessThan>::operator==(const iteratorBST<Comparable, LessThan> &it2) const {
    return itrStack == it2.itrStack;
}

template<class Comparable, class LessThan>
bool iteratorBST<Comparable, LessThan>::operator!=(const iteratorBST<Comparable, LessThan> &it2) const {
    return itrStack != it2.itrStack;
}


#endif

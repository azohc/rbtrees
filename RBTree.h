#ifndef rbtree_h
#define rbtree_h

/*
Implementar o Java o en C++ un arbol roji-negro escorado a la izquierda con las operaciones
de buscar, insertar y borrar una clave.

RBTree Properties:
1. Every node is either red or black.
2. The root is black.
3. Every leaf (NIL) is black.
4. If a node is red, then both its children are black.
5. For each node, all simple paths from the node to descendant leaves contain the same number of black nodes.


https://www.cs.usfca.edu/~galles/visualization/RedBlack.html
https://github.com/azohc/dom/blob/master/ADT/Arbin.h


*/

#include <list>

const bool RED = true;
const bool BLACK = false;

template <class K, class V>
class RBTree {
public:
    //Constructor for an empty tree
    RBTree() {
        _NIL = new Node();
        _root = _NIL;
        _root->_parent = _NIL;
        _root->_left = _NIL;
        _root->_right = _NIL;
    } 

    //Constructor for a single-node tree
    RBTree(const K key, const V value) {
        _NIL = new Node();
        _root = new Node(key, value);
        _root->_parent = _NIL;
        _root->_left = _NIL;
        _root->_right = _NIL;
    }

    //Destructor
    ~RBTree() {
        free(_root);
        _root = nullptr;
    }

    
    //READ BOOK PAGE 308
    //Insert an element into the tree
    void insert(K key, V value){
        Node* x = _root;
        Node* y = _NIL;
        Node* z = new Node(key, value);
        z->_left = _NIL;
        z->_right = _NIL;

        
        while(x != _NIL){
            y = x;
            if(z->_key < x->_key)
                x = x->_left;
            else
                x = x->_right;
        }
        
        z->_parent = y;
        
        if(y == _NIL)
            _root = z;
        else if (z->_key < y->_key)
            y->_left = z;
        else
            y->_right = z;

        z->_color = RED;

        insert_fixup(z);        
    }

    

    //Delete


    //Get
    


    std::list<V> inorder_treewalk(){
        std::list<V> l;
        gen_list_inorder(l, _root);
        return l;
    }
    

    //Maybe get iterator to key
    
    //Maybe TODO: Observer function that checks if a given key exists in the tree

    
protected:
    class Node {
    public:
        Node() {
            _color = BLACK;
        }

        Node(K key, V value) {
            _key = key;
            _value = value;
            _color = BLACK;
        }

        bool _color;
        K _key;
        V _value;
        Node *_left;
        Node *_right;
        Node *_parent;
    };

    Node *_root;
    Node *_NIL;


     //Constructor to make a red-black tree from a node
    RBTree(Node *root){
        _root = root;
    }


private:    

    void insert_fixup(Node* z){
        while (isRed(z->_parent)) {
            if (z->_parent == z->_parent->_parent->_left) {
                Node *y = z->_parent->_parent->_right;
                if (isRed(y)) { 
                    z->_parent->_color = BLACK;
                    y->_color = BLACK;
                    z->_parent->_parent->_color = RED;
                    z = z->_parent->_parent;
                }
                else {
                    if (z == z->_parent->_right) {
                        z = z->_parent;
                        left_rotate(z);
                    }
                    z->_parent->_color = BLACK;
                    z->_parent->_parent->_color = RED;
                    right_rotate(z->_parent->_parent);
                }
            }
            else {
                Node *y = z->_parent->_parent->_left;
                if (isRed(y)) { 
                    z->_parent->_color = BLACK;
                    y->_color = BLACK;
                    z->_parent->_parent->_color = RED;
                    z = z->_parent->_parent;
                }
                else {
                    if (z == z->_parent->_left) {
                        z = z->_parent;
                        right_rotate(z);
                    }
                    z->_parent->_color = BLACK;
                    z->_parent->_parent->_color = RED;
                    left_rotate(z->_parent->_parent);
                }
            }
        }
    }

    void left_rotate(Node* x){
        Node *y = x->_right;
        x->_right = y->_left;

        if(y->_left != _NIL)
            y->_left->_parent = x;
        
        y->_parent = x->_parent;

        if(x->_parent == _NIL)
            _root = y;
        else if(x == x->_parent->_left)
            x->_parent->_left = y;
        else
            x->_parent->_right = y;
        
        y->_left = x;
        x->_parent = y;
    }

    void right_rotate(Node* x){
        Node *y = x->_left;
        x->_left = y->_right;

        if(y->_right != _NIL)
            y->_right->_parent = x;
        
        y->_parent = x->_parent;

        if(x->_parent == _NIL)
            _root = y;
        else if(x == x->_parent->_right)
            x->_parent->_right = y;
        else
            x->_parent->_left = y;
        
        y->_right = x;
        x->_parent = y;
    }

    bool isRed(Node *n) {
        if(n == _NIL)
            return false;
        return n->_color;
    }


    void gen_list_inorder(std::list<V> &l, Node* r){
        if(r == _NIL)
            return;
        gen_list_inorder(l, r->_left);
        l.push_back(r->_value);
        gen_list_inorder(l, r->_right);
    }

    //Free all the children nodes that branch from root    
    void free(Node *root) {
        if(root != _NIL) {
            free(root->_left);
            free(root->_right);
            delete root;
        }
    }
};

#endif
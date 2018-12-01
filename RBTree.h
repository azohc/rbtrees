#ifndef rbtree_h
#define rbtree_h

/*
Implementar o Java o en C++ un arbol roji-negro escorado a la izquierda con las operaciones
de buscar, insertar y borrar una clave.
*/

#include <cstddef>

const bool RED = true;
const bool BLACK = false;

template <class K, class V>
class RBTree {
public:
    //Constructor for an empty tree
    RBTree() : _root(NULL) {} 

    //Constructor for a single-node tree
    RBTree(const K key, const V value) {
        _root = new Node(key, value, BLACK);
    }

    //Destructor
    ~RBTree() {
        free(_root);
        _root = NULL;
    }

    
    //READ BOOK PAGE 308
    //Insert an element into the tree
    


    //Delete


    //Get
    

    //Maybe get iterator to key
    
    
    
    
    //Maybe TODO: Observer function that checks if a given key exists in the tree
    
        
   
    
protected:
    class Node {
    public:
        //TODO maybe remove?
        //Node() : _left(NULL), _right(NULL), _color(BLACK), _key(NULL), _value(NULL) {}

        Node(K key, V value, bool color) {
            _key = key; _value = value; _color = color;
            _left = NULL; _right = NULL;
        }

        bool isRed(Node *n) {
            if(n == NULL)
                return false;
            return n->_color;
        }

        K _key;
        V _value;
        bool _color;
        Node *_left;
        Node *_right;
    };

    Node *_root;

     //Constructor to make a red-black tree from a node
    RBTree(Node *root){
        _root = root;
    }

private:
    //Free all the children nodes that branch from root    
    void free(Node *root) {
        if(root != NULL) {
            free(_root->_left);
            free(_root->_right);
            delete _root;
        }
    }
};

#endif
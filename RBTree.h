#ifndef rbtree_h
#define rbtree_h

/*
Implementar o Java o en C++ un arbol roji-negro escorado a la izquierda con las operaciones
de buscar, insertar y borrar una clave.
*/


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
    

    //Delete


    //Get
    




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

        bool isRed(Node *n) {
            if(n == _NIL)
                return false;
            return n->_color;
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
    //Free all the children nodes that branch from root    
    void free(Node *root) {
        if(root != _NIL) {
            free(_root->_left);
            free(_root->_right);
            delete _root;
        }
    }
};

#endif
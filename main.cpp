#include <iostream>
#include "RBTree.h"

using std::list;
using std::iterator;
using std::cin;
using std::cout;
using std::endl;


int main(){

    RBTree<int, int> t = RBTree<int, int>();
    

    t.insert(1,1);
    t.insert(2,2);
    t.insert(4,4);
    t.insert(5,5);
    t.insert(7,7);
    t.insert(8,8);
    t.insert(11,11);
    t.insert(14,14);
    t.insert(15,15);
    


    list<int> l = t.inorder_treewalk();

    for(list<int>::const_iterator it = l.cbegin(); it != l.cend(); it++)
        cout << *it << " ";

    cout << endl;   
    
    //system("PAUSE");
    return 0;
}
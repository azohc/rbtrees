#include <iostream>
#include "RBTree.h"

using std::list;
using std::iterator;
using std::cin;
using std::cout;
using std::endl;


int main(){

    RBTree<int, int> t = RBTree<int, int>(33, 33);
    

    for(int i = 0; i < 10; i++){
        if(i == 7 || i == 8 || i == 9)
            t.insert(6*i, 6*i);
        else
            t.insert(-2*i, -2*i);
    }


    list<int> l = t.inorder_treewalk();

    for(list<int>::const_iterator it = l.cbegin(); it != l.cend(); it++)
        cout << *it << " ";

    cout << endl;   
    
    system("PAUSE");
    return 0;
}
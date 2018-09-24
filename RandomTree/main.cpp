#include <iostream>
#include "crandomtree.hpp"

using namespace std;

int main()
{
    RDTree<int> myTree (9);

    myTree.add(8);
    myTree.add(7);
    myTree.add(6);
    myTree.add(5);
    myTree.add(4);
    myTree.show();

    int Val;
    cout<<"tu veux quoi ? :";
    cin>>Val;
    myTree.find(Val);
    return 0;
}

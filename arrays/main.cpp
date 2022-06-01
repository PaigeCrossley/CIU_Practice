#include <iostream>
#include "vectorClass.h"

using namespace std;

int main()
{
    cout << "Initiating vector sequence..." << endl << endl;
    vectorClass<int> vec;

    cout << "Let's check if it's empty: 1 = True, 0 = False" << endl << vec.isEmpty() << endl << endl;

    cout << "Initial capacity check: " << vec.getCapacity() << endl << "Push 1 through 6 and print" << endl;
    vec.push(1);
    vec.push(2);
    vec.push(3);
    vec.push(5);
    vec.push(6);
    vec.print();
    cout << "New capacity check: " << vec.getCapacity() << endl << endl;

    cout << "Oops, missed 4, let's add that where it belongs using pushAt" << endl << "Initial capacity check: " << vec.getCapacity() << endl;
    cout << "Initial size check: " << vec.size_() << endl;
    vec.pushAt(4, 3);
    vec.print();
    cout << "New capacity check: " << vec.getCapacity() << endl;
    cout << "New size check: " << vec.size_() << endl << endl;
    
    cout << "I want to replace 3 with 8" << endl;
    vec.replace_(2,8);
    vec.print();
    cout << "Alright, put it back" << endl;
    vec.replace_(2,3);
    vec.print();
    cout << "What if I try replacing an element that doesn't exist, like at index 8" << endl;
    vec.replace_(8,4);
    vec.print();
    cout << "No changes were made" << endl << endl;

    cout << "Show me the element at index 2: " << vec.get(2) << endl;
    cout << "Now me the element at index 8: " << vec.get(8) << " (There is no index 8)" << endl << endl;


    cout << "Push 7" << endl;
    vec.push(7);
    cout << "Initial capacity check: " << vec.getCapacity() << endl;
    cout << "Initial size check: " << vec.size_() << endl;
    vec.print();
    cout << "Sike, remove it with pop" << endl;
    vec.pop();
    cout << "New capacity check: " << vec.getCapacity() << endl;
    cout << "New size check: " << vec.size_() << endl;
    vec.print();
    cout << endl;

    cout << "Let's check if it's empty again: 1 = True, 0 = False" << endl << vec.isEmpty() << endl << endl;

    cout << "Add 0 to the front using prepend" << endl;
    vec.prepend(0);
    cout << "New capacity check: " << vec.getCapacity() << endl;
    cout << "New size check: " <<vec.size_() << endl;
    vec.print();
    cout << endl;

    cout << "Delete the first element using deleteAt" << endl;
    vec.deleteAt(0);
    cout << "New capacity check: " << vec.getCapacity() << endl;
    cout << "New size check: " << vec.size_() << endl;
    vec.print();
    cout << endl;

    cout << "Add 7 to the end using pushAt" << endl;
    vec.pushAt(7,7);
    cout << "New capacity check: " << vec.getCapacity() << endl;
    cout << "New size check: " << vec.size_() << endl;
    vec.print();
    cout << endl;

    cout << "Show me the index of 5: " << vec.find_(5) << endl;
    cout << "Now show me the index of 9: " << vec.find_(9) << " (There are no 9's)" << endl << endl;

    cout << "Delete all 9's using deleteAll" << endl;
    vec.deleteAll(9);
    vec.print();
    cout << "Initial capacity check: " << vec.getCapacity() << endl;
    cout << "Initial size check: " << vec.size_() << endl;
    cout << "Mix in some 0's" << endl;
    vec.pushAt(0,1);
    vec.pushAt(0,3);
    vec.pushAt(0,5);
    vec.push(0);
    vec.push(0);
    vec.push(0);
    vec.push(0);
    vec.push(0);
    vec.push(0);
    vec.push(0);
    cout << "New capacity check: " << vec.getCapacity() << endl;
    cout << "New size check: " << vec.size_() << endl;
    vec.print();
    cout << "Delete all 0's using deleteAll" << endl;
    vec.deleteAll(0);
    vec.print();
    cout << "Newer capacity check: " << vec.getCapacity() << endl;
    cout << "Newer size check: " << vec.size_() << endl;
};

#include <iostream>
#include "SList.h"

using namespace std;

int main()
{
    SList<int> llist;

    cout << "Initial size check: " << llist.size_() << endl;
    cout << "Is the list empty? (1 = Yes, 0 = No)" << endl << llist.empty_() << endl << endl;

    cout << "Time to add some elements to the list using push()" << endl;
    llist.push(1);
    llist.push(2);
    llist.push(3);
    llist.push(5);
    llist.print();
    cout << "New size check: " << llist.size_() << endl;
    cout << "Is the list empty? (1 = Yes, 0 = No)" << endl << llist.empty_() << endl << endl;

    cout << "Let's add a 0 at the front using push_front_()" << endl;
    llist.push_front_(0);
    llist.print();
    cout << "New size check: " << llist.size_() << endl << endl;

    cout << "Oops, we skipped 4, let's add that in using insert_()" << endl;
    llist.insert_(4, 4);
    llist.print();
    cout << "New size check: " << llist.size_() << endl;
    cout << "What about inserting 8 at index 8?" << endl;
    llist.insert_(8,8);
    llist.print();
    cout << "New size check: " << llist.size_() << endl;
    cout << "Nope, doesn't insert anything" << endl << endl;

    cout << "What's the value at index 3? " << llist.value_at(3) << endl;
    cout << "What about at index 8? " << llist.value_at(8) << " (There is no index 8)" << endl << endl;

    cout << "What's the first value in the list? " << llist.front_() << endl << endl;

    cout << "Let's remove that 0 from the list using pop_front_()" << endl;
    llist.pop_front_();
    llist.print();
    cout << "New size check: " << llist.size_() << endl << endl;

    cout << "What's the new first value in the list? " << llist.front_() << endl << endl;

    cout << "Just going to add a few more values to the list" << endl;
    llist.push(6);
    llist.push(7);
    llist.push(8);
    llist.push(9);
    llist.print();
    cout << "New size check: " << llist.size_() << endl;
    cout << "What's the last value in the list? " << llist.back_() << endl;
    cout << "Let's remove the last value with pop_back_()" << endl;
    llist.pop_back_();
    llist.print();
    cout << "New size check: " << llist.size_() << endl;
    cout << "What's the new last value in the list? " << llist.back_() << endl << endl;

    cout << "What is the value 2 nodes away from the end of the list? " << llist.value_n_from_end(2) << endl;
    cout << "What about 5 nodes away? " << llist.value_n_from_end(5) << endl << endl;

    cout << "Let's delete the value at index 3" << endl;
    llist.erase_(3);
    llist.print();
    cout << "New size check: " << llist.size_() << endl;
    cout << "I'll just add it back" << endl;
    llist.insert_(4,3);
    llist.print();
    cout << endl;

    cout << "What's the index of 6? " << llist.find_(6) << endl;
    cout << "What about 0? " << llist.find_(0) << " (There is no 0)" << endl << endl;

    cout << "I'm going to add some zero's to the list for the next part" << endl;
    llist.push(0);
    llist.push(0);
    llist.push(0);
    llist.push(0);
    llist.push_front_(0);
    llist.insert_(0,3);
    llist.insert_(0,4);
    llist.insert_(0,6);
    llist.print();
    cout << "Let's remove the first 0 in the list with remove_()" << endl;
    llist.remove_(0);
    llist.print();
    cout << "New size check: " << llist.size_() << endl;
    cout << "Again" << endl;
    llist.remove_(0);
    llist.print();
    cout << "New size check: " << llist.size_() << endl;
    cout << "Now let's remove them all" << endl;
    llist.removeAll(0);
    llist.print();
    cout << "New size check: " << llist.size_() << endl << endl;

    cout << "Now the last function, reverse_(), to reverse the list" << endl;
    llist.reverse_();
    llist.print();
}

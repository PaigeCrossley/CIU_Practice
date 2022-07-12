#include <iostream>
#include "QArr.h"

using namespace std;

int main()
{
    cout << "Initialize the array" << endl << endl;
    QArr<int> qa;

    cout << "Is the array empty? (1 = T, 0 = F)" << endl << qa.empty_() << endl << endl;

    cout << "Let's fill the array..." << endl;
    qa.enqueue(1);
    qa.enqueue(2);
    qa.enqueue(3);
    qa.enqueue(4);
    qa.enqueue(5);

    cout << "Is the array empty now? (1 = T, 0 = F)" << endl << qa.empty_() << endl << endl;

    cout << "Print the array:" << endl;
    qa.print();

    cout << "Let's try adding one more element..." << endl;
    qa.enqueue(6);
    cout << "Oops, doesn't work, gotta dequeue" << endl;
    cout << qa.dequeue() << endl;
    cout << "Print the array:" << endl;
    qa.print();
    cout << endl;

    cout << "Now try adding the new element" << endl;
    qa.enqueue(6);
    qa.print();
    cout << "All good!" << endl << endl;

    cout << "Now let's empty the array" << endl;
    cout << qa.dequeue() << endl;
    cout << qa.dequeue() << endl;
    cout << qa.dequeue() << endl;
    cout << qa.dequeue() << endl;
    cout << qa.dequeue() << endl;
    cout << "Print the array:" << endl;
    qa.print();
    cout << "Let's try removing one more element..." << endl;
    cout << qa.dequeue() << endl;
    cout << "Oops, doesn't work, gotta enqueue first" << endl;
}

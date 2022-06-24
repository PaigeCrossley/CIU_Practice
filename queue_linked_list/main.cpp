#include <iostream>
#include "QLL.h"

using namespace std;

int main()
{
    QLL<int> Q;

    cout << "Is the queue empty?" << endl << Q.empty_() << " (1 = True, 0 = False)" << endl << endl;

    cout << "Let's add some nodes with enqueue" << endl << endl;
    Q.enqueue(1);
    Q.enqueue(2);
    Q.enqueue(3);
    Q.enqueue(4);
    Q.enqueue(5);
    cout << "Now is the queue empty?" << endl << Q.empty_() << " (1 = True, 0 = False)" << endl << endl;

    cout << "Time to dequeue them" << endl << endl;
    Q.dequeue();
    Q.dequeue();
    Q.dequeue();
    Q.dequeue();
    Q.dequeue();
    cout << endl << "Is the queue empty?" << endl << Q.empty_() << " (1 = True, 0 = False)" << endl << endl;

    cout << "What happens if I dequeue an empty list?" << endl;
    Q.dequeue();
    cout << "Nothing" << endl;
}

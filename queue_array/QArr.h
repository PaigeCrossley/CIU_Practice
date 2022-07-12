#ifndef QARR_H
#define QARR_H

using namespace std;

template <typename T>
class QArr
{
    // arr is the integer pointer which stores the address of our vector
    T* arr;

    // current is the number of elements currently present in the vector
    int current;

    public:
        QArr() // initalizes the array with a capacity of 5
        {
            arr = new T[5];
            current = 0;
        };

        void enqueue(T data) // if the array is not full, it will add the new element at the end of the array
        {
            if(full() == 0) {
                arr[current] = data;
                current++;
            } else {
                cout << "Array full: Must dequeue first" << endl;
            }
        };

        T dequeue() // if the array is not empty it will return the first element and move the remaining elements one index to the left, if it is empty it will return -1
        {
            if(empty_() == 0){
                T temp;

                temp = arr[0];

                for(int i = 0; i < 5; i++) {
                    arr[i] = arr[i+1];
                };

                current--;

                return temp;
            } else {
                return -1;
            }

        };

        bool empty_() { return current == 0; }; // checks if the array is empty

        bool full() { return current == 5; }; // checks if the array is full

        void print() {
            for (int i = 0; i < current; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

#endif // QARR_H

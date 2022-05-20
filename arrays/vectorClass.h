#ifndef VECTORCLASS_H
#define VECTORCLASS_H

using namespace std;

template <typename T>
class vectorClass 
{
     // arr is the integer pointer which stores the address of our vector
    T* arr;

    // capacity is the total storage capacity of the vector
    int capacity;

    // current is the number of elements currently present in the vector
    int current;

public:
    // Constructor creates the empty array with capacity of 1
    vectorClass()
    {
        arr = new T[1];
        capacity = 1;
        current = 0;
    }

    // Function to add an element at the end
    void push(T data) 
    {
        // check and perform resizing
        resize_();

        // Inserting data
        arr[current] = data;
        current++;
    }

    // function to add element at any index
    void pushAt(T data, int index) 
    {
        // if index is equal to capacity or is at the end of the array then this function is same as push defined above
        if ((index == capacity) || (index == current+1)) {
            push(data);
        }else {
            resize_();

            // Create a copy of the array so that the elements can be shifted by 1
            T* arrCopy = new T[capacity];
            for (int i = 0; i < capacity; i++) {
                arrCopy[i] = arr[i];
            };

            // shift the elements
            for(int i = index; i <= capacity; i++) {
                arr[i+1] = arrCopy[i];

            }
            // add the new element and delete the copy array
            arr[index] = data;
            current++;
            delete [] arrCopy;
        }
    }

    // function to extract element at any index, returns -1 if out of range
    T get(int index) 
    {

        // if index is within the range
        if (index < current)
            return arr[index];
        else
            return -1;
    }

    // function to delete last element
    void pop() 
    {
        current--;
        resize_();
    }

    // function to get the current size of the vector
    int size_() { return current; }

    // function to get capacity of the vector
    int getCapacity() { return capacity; }

    // function to print array elements
    void print() 
    {
        for (int i = 0; i < current; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // function to tell user whether the array is empty or not
    bool isEmpty() { return current == 0; }

    // function to add an element at index 0
    void prepend(T data) 
    {
        pushAt(data,0);
    }

    // function to remove the element at a given index
    void deleteAt(int index) 
    {
        // reallocate the elements
        for(int i = index; i <= capacity; i++) {
            arr[i] = arr[i+1];

        }
        current--;
        resize_();
    }

    // function to find a given element, returns index or -1 if not found
    int find_(T data) 
    {
        for(int i = 0; i < current; i ++) {
            if(arr[i] == data)
                return i;
        }
        return -1;
    }

    // recursively deletes every instance of the given element
    void deleteAll(T data) 
    {
        int index = find_(data);
        if(index == -1) {
            nullptr;
        } else {
            deleteAt(index);
            resize_();
            deleteAll(data);
        }

    }

private:
    // function to check if we need to adjust the capacity to fit new elements or make it smaller after elements have been removed
    void resize_() 
    {
        if (current == capacity) {
            T* temp = new T[2 * capacity];

            // copying old array elements to new array
            for (int i = 0; i < capacity; i++) {
                temp[i] = arr[i];
            }

            // deleting previous array
            delete[] arr;
            capacity *= 2;
            arr = temp;
        }else if(capacity > 1 && current == (capacity / 4)) {
            T* temp = new T[capacity/2];

            // copying old array elements to new array
            for (int i = 0; i < capacity; i++) {
                temp[i] = arr[i];
            }

            // deleting previous array
            delete[] arr;
            capacity /= 2;
            arr = temp;
        }
    }
};

#endif // VECTORCLASS_H

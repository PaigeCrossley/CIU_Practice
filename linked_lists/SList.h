#ifndef SLIST_H
#define SLIST_H

using namespace std;

template <typename T>
class SList
{
    struct Node // creating a structure for the node values and pointers
    {
        T value;
        Node* next;
    };

    // prototyping the len variable that stores the length of the linked list
    int len;

    // prototyping the head node
    Node* head;

    // prototyping the tail node
    Node* tail;

    public:
        SList()
        {
            len = 0; // initializing the list with length 0
        }

        int size_() { return len; }; // returns the number of elements in the list

        bool empty_() { return len == 0; }; // returns true (1) if the list is empty

        T value_at(int index) // returns the value at the given index or -1 if the index is out of bounds
        {
            if(index > len-1) {
                return -1;
            }else{
                Node* trvl = head;
                for(int i = 0; i < index; i++) {
                    trvl = trvl->next;
                }
                return trvl->value;
            }
        }

        void push_front_(T value) // creates a node with the given value to the front
        {
            Node* n;
            if(empty_() == 1) {
                n = new Node;
                n->value = value;
                n->next = nullptr;

                head = n;
                tail = n;
                len++;
            }else {
                n = new Node;
                n->value = value;

                n->next = head;
                head = n;
                len++;
            }
        }

        void pop_front_() // removes the first element in the list
        {
            if(empty_() == 1) {
                nullptr;
            }else {
                Node* trvl = head;

                head = head->next;

                delete trvl;

                len--;
            }
        }

        void push(T value) // adds a node with the given value at the end
        {
            Node* n;
            if(empty_() == 1) {
                push_front_(value);
            }else {
                n = new Node;
                n->value = value;
                n->next = nullptr;

                tail->next = n;
                tail = n;
                len++;
            }
        }

        void pop_back_() // removes the last element
        {
            if(len <= 1) {
                pop_front_();
            }else {
                Node* curr = head;
                Node* prev;

                while(curr->next != NULL) {
                    prev = curr;
                    curr = curr->next;
                }
                tail = prev;
                prev->next = nullptr;
                delete curr;
                len--;
            }
        }

        T front_() { return head->value; }; // returns the value of the first element

        T back_() { return tail->value; }; // returns the value of the last element

        void insert_(T value, int index) // inserts the given value at the given index
        {
            if(index > len) {
                nullptr;
            }else {
                if(index == len) {
                    push(value);
                } else if(index == 0) {
                    push_front_(value);
                } else {
                    Node* curr = head;
                    Node* prev;

                    Node* n = new Node();
                    n->value = value;

                    for(int i = 0; i < index; i++) {
                        prev = curr;
                        curr = curr->next;
                    }
                    n->next = curr;
                    prev->next = n;
                    len++;
                }
            }
        }

        void erase_(int index) // removes the element at the given index, does nothing if the index is greater than or equal to the length
        {
            if(index >= len) {
                nullptr;
            }
            else {
                if(index == 0) {
                    pop_front_();
                } else if(index == len-1) {
                    pop_back_();
                } else {
                    Node* curr = head;
                    Node* prev;

                    for(int i = 0; i < index; i++) {
                        prev = curr;
                        curr = curr->next;
                    }
                    prev->next = curr->next;
                    delete curr;
                    len--;
                }
            }
        }

        T value_n_from_end(int n) // returns the value of the element n elements away from the end of the list (considers the end of the list to be index 0), will return -1 if n > length,
        {
            if(n > len) {
                return -1;
            } else {
                int num = len-n;

                if(num == 0) {
                    return front_();
                }else if(num == len){
                    return back_();
                }else {
                    Node* trvl = head;

                    for(int i = 0; i < num; i++) {
                        trvl = trvl->next;
                    }
                    return trvl->value;
                }
            }
        }

        void reverse_() // reverses the order of the list
        {
            Node* curr = head;
            Node* next = nullptr;
            Node* prev = nullptr;

            while(curr != NULL) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            tail = head;
            head = prev;
        }

        void remove_(T value) // removes the first element in the list with the given value, does nothing if it is not in the list
        {
            if(find_(value) == -1) {
                nullptr;
            } else {
                erase_(find_(value));
            }
        }

        void removeAll(T value) // recursive version of the above
        {
            while(find_(value) != -1) {
                erase_(find_(value));
            }
        }

        int find_(T value) // finds the first element in the list with the given value and returns the index, returns -1 if it is not found
        {
            Node* trvl = head;
            int i = 0;
            while(trvl != NULL) {
                if(trvl->value == value){
                    return i;
                } else {
                    trvl = trvl->next;
                    i++;
                }
            }
            return -1;
        }

        void print() // prints the elements in the linked list
        {
            Node* trvl = head;
            while(trvl != NULL) {
                cout << trvl->value << " ";
                trvl = trvl->next;
            };
            cout << endl;
        }
};

#endif // SLIST_H

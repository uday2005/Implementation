#include <bits/stdc++.h>
using namespace std;

#include <iostream>
using namespace std;

//self implementation of the array
class MyArray {
private:
    int* arr;
    int capacity;
    int length;

public:
    // Constructor
    MyArray(int size) {
        capacity = size;
        arr = new int[capacity];
        length = 0;
    }

    // Destructor
    ~MyArray() {
        delete[] arr;
    }

    // Insert value at end
    void push(int value) {
        if (length < capacity) {
            arr[length++] = value;
        } else {
            cout << "Array is full\n";
        }
    }

    // Set value at index
    void set(int index, int value) {
        if (index >= 0 && index < length) {
            arr[index] = value;
        } else {
            cout << "Index out of bounds\n";
        }
    }

    // Get value at index
    int get(int index) const { // we use cosnst here as to it will not change the state of the object it is read only
        if (index >= 0 && index < length) {
            return arr[index];
        } else {
            cout << "Index out of bounds\n";
            return -1;
        }
    }

    // Display all elements
    void display() const {
        cout << "Array elements: ";
        for (int i = 0; i < length; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Get current size
    int size() const {
        return length;
    }
};

class MyVector{
    int* arr;   //pointer to arr
    int capacity; // current capacity
    int length; // current number of elements

    int next_power_of_2(int n){
        int p = 16;
        while(p<n) p<<= 1;
        return p;

    }

public:

    // constructor
    MyVector(int start_size = 16){
        capacity = next_power_of_2(start_size);
        arr = new int[capacity];
        length = 0;
    }
    ~MyVector(){
        delete[] arr; 
    }

    // Add element to the end
    void push_back(int val){
        if(length == capacity){
            // Need to resize

            int new_capacity = capacity * 2;
            int* newarr = new int[new_capacity];

            // copy old data using pointer math

            for(int i = 0; i<length ; i++){
                *(newarr + i) = *(arr + i);
               

            }
            delete[] arr;
            arr= newarr;
            capacity = new_capacity;
        }
            *(arr + length) = val; // this can also corresponds to the arr[length] = val;
            ++length;
    }

    int size(){ return length;}

    int get(int idx) const { // here const as it is only read only 
        if(idx <0 || idx >= length ){
            cout <<"Index out of bound\n";
            return -1;
        }
        return *(arr + idx);
    }

    void set(int idx , int val){
        if(idx < 0 || idx >= length){
            cout << "Index out of bound\n";
            return;
        }

        *(arr + idx) = val;
    }

      // Print all elements
    void print() const {
        cout << "MyVector: ";
        for (int i = 0; i < length; ++i)
            cout << *(arr + i) << " ";
        cout << endl;
    }

    bool is_empty() {
        int sz = size();
        return (sz == 0);
    }
    void prepend(int val){
        if(length == capacity){
            
            int new_capacity = capacity * 2;
            int* newarr = new int[new_capacity];

            // copy old data using pointer math

            for(int i = 0; i< length ; i++){
                *(newarr+ i+1) = *(arr + i); // shift by 1 right
            }
            delete[] arr;
            arr = newarr;
            capacity = new_capacity;
        }
        else{
            // right shift the position of the value
            for(int i = length ; i> 0 ; i-- ){
                *(arr + i) = *(arr + i-1);
            }
        }
        *(arr)  = val;
        length ++;
    }

    int  pop(){
        if(size() == 0){
            cout << "Array is empty" << endl;
            return -1;
        }
        else{
            int val =  arr[length-1];
            length --; // remove the last element

            // Optional: shrink capacity if too much unused space
        if (capacity > 16 && capacity > 4 * length) {
            resize(capacity / 2);
        }
            return val;
        }
    }

        // delete at that index and shift all trailing elements at left
    void delete_index(int idx){
        if(idx <0 || idx >=  size()){
            cout<< "Index is out of bound" << endl;
            return ;
        }
        else{
            for(int i  = idx ; i< length-1 ; i++){
                *(arr + i) = *(arr+i + 1);
            }
            length--;
        }
    }

    // delete the val in array even if it is multiple time
    void delete_val(int val){
        int j = 0;
        for(int i = 0; i<length ; i++){
            if(arr[i] !=  val){ // this is called two pointer method and overwrite method
                arr[j] = arr[i];
                j++;
            }
        }
        length = j;
    }

    int find(int val){
        for(int i = 0 ; i< length ; i++){
            if(arr[i] == val){
                return i;
            }
        }
        return -1;
    }

private:

    void resize(int new_capacity){
        
            int* new_arr = new int[new_capacity];

        // copy existing element to the new array
            for(int i = 0 ; i<length; i++){
                new_arr[i] = arr[i];
            }
            
            delete[] arr;
            arr= new_arr;
            capacity = new_capacity;

        }

// Increase size:
// When length == capacity, call resize(capacity * 2);

// Decrease size:
// When capacity > 4 * length, call resize(capacity / 2); (but never shrink below a minimum, like 16)


};
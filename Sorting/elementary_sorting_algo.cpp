#include <bits/stdc++.h>
using namespace std;

class SelectionSort{
    private:
        vector<int> arr;
    
    public:

     // Constructor to initialize the array
    SelectionSort(vector<int> input) : arr(input) {}

    
    void sort(){
    int n = arr.size();
    for(int i = 0; i< n ; i++){
        int min = i;
        for(int j = i+1 ; j< n ; j++){
            if(arr[min] > arr[j]){
                min = j;
            }
        }
        swap(arr[i],arr[min]);
    }
    }
   void print() {
        for (int x : arr) {
            cout << x << " ";
        }
        cout << endl;
    }

};

class InsertionSort{

    private:
        vector<int> arr;

    public:

    InsertionSort(vector<int> data_input) : arr(data_input){};

    void sort(){
        int n = arr.size();

        for(int i = 1 ; i< n; i++){
            for(int j =i ; j>0 ; j--){
                if(arr[j] > arr[j-1]){
                    swap(arr[j],arr[j-1]);
                }
            }
        }
    }

     void print() {
        for (int x : arr) {
            cout << x << " ";
        }
        cout << endl;
    }
};


// It is just an insertion sort which will move not just by one gap but by multiple gaps
class ShellShort{
        private:
        vector<int> arr;

    public:

    ShellShort(vector<int> data_input) : arr(data_input){};

   void sort(){
    int n = arr.size();
    int h = 1;
    // Here we are folowing the 3 * h + 1 sequence
    while( 3 * h < n){ 
        h = 3 * h +1;
    }

    while(h >=1){
        for(int i = h; i< n; i++){
            for(int j = i; j> 0; j--){
                if(arr[j] < arr[j-h]){
                    swap(arr[j] , arr[j-1]);
                }
            }  
        }
        h = h/3;
    }

   }

};

class Shuffling{

    private:
        vector<int> arr;
    
    public:

     // Constructor to initialize the array
    Shuffling(vector<int> input) : arr(input) {}

    // first approach is generate a real number for each array and then sort the array;
    void shuffle_1(){
    int n = arr.size();
    random_device rd; // Seed generator
    mt19937 gen(rd()); // Mersenne Twister engine
    uniform_real_distribution<float> dis(0.0f, 1.0f); // Range [0.0, 1.0)

    vector<int> shuffled_arr(n);

    vector<pair<float , int>> key_index;

    for(int i = 0; i < n; i++){
       key_index.push_back({dis(gen) , i});
    }

    // Sort the pairs by the random key
    sort(key_index.begin(), key_index.end());

    for(auto p : key_index){
        shuffled_arr.push_back(arr[p.second]);
    }
    // p.second is used for accesing the array
    arr = shuffled_arr;
    }

    // This is the knuth's approach of shuffling
    void shuffle_2(){
        // In each iteration i , pick integer r b/w 0 and i uniformly and swap a[i] and a[r]

    random_device rd; // Seed generator
    mt19937 gen(rd()); // Mersenne Twister engine
   

        int n  = arr.size();

        // Loop forward used from 0 to n-2
        // here n-1 beacuse we don't want to shuffle last element unnecessarily.
        for(int i = 0 ; i< n-1 ; i++){
            // this random index should be chosen from unshuffled 
            uniform_real_distribution<int> dis(i, n-1); // Range [0.0, i)
            int r= dis(gen);
            swap(arr[i], arr[r]);
        }

    //        // Loop backward from the last index to 1
    // for (int i = n - 1; i > 0; --i) {
    //     // Generate a random integer between 0 and i (inclusive)
    //     uniform_int_distribution<int> dis(0, i);
    //     int r = dis(gen);
    //     swap(arr[i], arr[r]);
    // }

    }
};

class BubbleSort{

    private:
        vector<int> arr;
    
    public:

     // Constructor to initialize the array
    BubbleSort(vector<int> input) : arr(input) {}

    void sort(){
        int n = arr.size();

        for(int i = 0; i<n-1; i++){
            bool is_sorted = false;
            for(int j = 0 ; j< n-i-1; j++){
                if(arr[j] > arr[j+1]){
                    swap(arr[j] , arr[j+1]);
                    is_sorted = true;
                }
            }
            if(!is_sorted){
                break;
            }
        }
    }
};


// Convex hull is left 
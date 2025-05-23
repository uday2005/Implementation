#include <bits/stdc++.h>
using namespace std;

class quick_sort
{
private:
    vector<int> arr;

public:
    quick_sort(vector<int> input) : arr(input) {};
    
    // This is teh 2 way partiinoning sucks for duplicate items

    int partition(vector<int> &arr,int l0 , int hi ){
        // int pivot = arr[l0];
        // int i = l0;
        // int j = hi;

        // while(true){
            
        //     while(arr[i++] < arr[l0] ){
        //         if(i == hi) break;
        //     }

        //     while(arr[j--] > arr[l0]){
        //         if(j == l0) break;
        //     }
        //     if(i >= j) break;
        //     swap(arr[i], arr[j]);
        // }

    int pivot = arr[l0];
    int i = l0 - 1;
    int j = hi + 1;

    while (true) {
        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j) return j;

        swap(arr[i], arr[j]);
    }



        swap(arr[l0] , arr[j]);
        return j;
    }

    void shuffle(vector<int> &arr){

    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(arr.begin(), arr.end(), gen);
    }

    void sort(vector<int>&arr , int l0 , int hi){

       if( hi <= l0) return ;
        shuffle(arr);
       int p = partition(arr,l0 , hi);

       sort(arr,l0,p-1);
       sort(arr , p+1 ,hi);

    }

    // For finding the kth smallest element
    int quick_select(vector<int> &arr , int key){
        int n = arr.size();

        shuffle(arr);

        int l0 = 0;
        int hi = n-1;

        while(l0 < hi){

            int j = partition(arr, l0 , hi);

            if(j< key){
                l0 = j+1;
            }
            else if( j> key){
                hi = j-1;
            }
            else{
                return arr[key];
            }
        }
        return arr[key];  // or arr[l0], since l0 == hi at this point

    }
    
    // it is the best for the duplicate 
    int three_way_partionining(vector<int> &arr,int lo , int hi){
        int pivot = arr[lo];
        int lt = lo;
        int gt = hi;
        int i = lo;

        while(i<= gt){

            if(arr[i] <pivot){
                swap(arr[i], arr[lt]);
                i++;
                lt++;
            }
            else if( arr[i] > pivot){
                swap(arr[i] , arr[gt]);
                gt--;
            }
            else{
                i++;
            }
        }
    }
    
};



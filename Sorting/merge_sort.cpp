#include <bits/stdc++.h>
using namespace std;

class MergeSort{
    private:
        vector<int> arr;

    public:

    MergeSort(vector<int> input) : arr(input) {};

    void merge(vector<int> &arr, int low , int mid ,int high){
        
        vector<int> temp;
        
        int i = low ; // left array
        int j = mid+1; // right array

        while( i<= mid && j <= high){
            if(arr[i] <= arr[j]){
                temp.push_back(arr[i]);
                i++;
            }

            if(arr[j] < arr[i]){
                temp.push_back(arr[j]);
                j++;
            }
        }

        while(i<= mid){
                temp.push_back(arr[i]);
                i++;
            
        }
        while(j <= high){
            temp.push_back(arr[j]);
                j++;
        }

        // now copy the value of temp back to arr

        for(int k = 0; k< temp.size(); i++){
            arr[k+ low] = temp[k];
        }
    }

    void sort(vector<int> &arr , int low ,  int high){

        if(low >= high) return; // base case
        int mid = low + (high -low)/2;
        sort(arr,low, mid);
        sort(arr,mid+1 ,high);
        if(arr[mid] < arr[mid+1]) return; // if the array is already sorted
        merge(arr,low ,mid , high);
    }

    // one of the improvements we can do is stop if the array is already sorted.
    // how can we do it is as if the biggest item in first half is less then smallest item in second half.

    // recursive approach goes top down approach , so the idea is an iterative algorithm for mergeosrt 
    //that avoids recurssion by taking bottom up approach.

    void bottom_up_sort(vector<int> &arr){
        int n = arr.size();

        // divides array into [1,2,4,8,16,32.......]
        for(int width = 1; width < n; width *= 2){

            for(int i = 0 ; i< n; i+= 2 * width){
                int left = i;
                int mid = min(i+width,n);
                int right = min(i + 2 * width, n);

                // shift index as it is actual index so shift it so it will start from 0
                merge(arr,left,mid-1,right-1);
            }
        }
    }

};

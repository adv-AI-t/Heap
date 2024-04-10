#include<iostream>
using namespace std;

void heapify(int arr[], int n, int i){
    int largest = i;
    int leftIndex = i*2;
    int rightIndex = i*2+1;

    if(leftIndex<n && arr[largest]<arr[leftIndex])
    swap(arr[largest], arr[leftIndex]);
    if(rightIndex<n && arr[largest]<arr[rightIndex])
    swap(arr[largest], arr[rightIndex]);

    if(largest!=i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest); 
    }
}

int main()
{
    int arr1[8] = {-1, 40, 30, 20, 10, 70, 80, 90};
    int n=7;
    for(int i=n/2; i>0; i--)
    {
        heapify(arr1, n, i);
    }

    for(int j=1; j<n; j++)
    {
        cout<<arr1[j]<<" ";
    }
    return 0;
}
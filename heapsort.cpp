#include<iostream>
using namespace std;

class Heap{
    int arr[100];
    int size;

    public:
    
    Heap()
    {
        size = 0;
    }

    Heap(int arr[], int n)
    {
        for(int i=1; i<=n; i++)
            this->arr[i] = arr[i];
        size = n;
    }
    
    void heapify(int n, int i)
    {
        int largest = i;
        int leftIndex = 2*i;
        int rightIndex = 2*i +1;

        if(leftIndex<=n && arr[largest]<arr[leftIndex])
        swap(arr[largest], arr[leftIndex]);
        if(rightIndex<=n && arr[largest]<arr[rightIndex])
        swap(arr[largest], arr[rightIndex]);

        if(largest!=i)
        {
            swap(arr[largest], arr[i]);
            heapify(n, largest);
        }
    }

    void showHeap()
    {
        for(int i=1; i<=size; i++)
        {
            cout<<arr[i]<<" ";
        } 
    }


    void heapSort()
    {
        int n=size;
        while(n>1)
        {
            swap(arr[1], arr[n]);
            n--;
            heapify(n, 1);
         }
    }
};

int main()
{
    
    int arr[5] = {-1, 5,6,1,2};
    int n = 4;
    Heap h1(arr, n);
    h1.showHeap();
    for(int i=n/2; i>0; i--)
    h1.heapify(n, i);
    cout<<"After sorting:\n";
    h1.heapSort();
    h1.showHeap();
    return 0;
}
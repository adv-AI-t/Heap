#include<iostream>
using namespace std;

class Heap{
    int arr[10];
    int size;

public:
    Heap(){

        arr[0] = -1;
        size = 0;
    }

    void insertNode(int n){
        size++;
        arr[size] = n;
        int ptr = size;
        while(ptr!=1){
            if(arr[ptr/2]<arr[ptr])
            {
                swap(arr[ptr/2], arr[ptr]);
            }
            else
            break;
        }
    }

    void showHeap()
    {
        for(int i=1; i<=size; i++)
        {
            cout<<arr[i]<<" ";
        }
    }

    void deleteRoot()
    {
        if(size==0)
        return;

        arr[1] = arr[size];
        size--;
        int ptr = 1;
        while(ptr<size)
        {
            int leftIndex = ptr*2;
            int rightIndex = ptr*2 + 1;
            if(leftIndex<size && arr[ptr]<arr[leftIndex])
            {
                swap(arr[ptr], arr[leftIndex]);
                ptr = leftIndex;
            }    
            else if(rightIndex<size && arr[ptr]<arr[rightIndex])
            {
                swap(arr[ptr], arr[rightIndex]);
                ptr = rightIndex;
            }
            else
            return;
        }
    }
};



int main()
{
    Heap h1;
    h1.insertNode(60);
    h1.insertNode(20);
    h1.insertNode(40);
    h1.insertNode(50);
    h1.insertNode(30);
    h1.showHeap();
    h1.deleteRoot();
    cout<<"After deletion:\n";
    h1.showHeap();

    return 0;
}
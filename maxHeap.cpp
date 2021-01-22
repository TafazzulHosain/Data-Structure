#include<bits/stdc++.h>
using namespace std;
int left(int i){ return 2*i;}
int right(int i){ return (2*i + 1);}



void max_heapify(int heap[] ,int heap_size , int i)
{
    int l = left(i);
    int r = right(i);
    int leargest;

    if(l <= heap_size and heap[l] > heap[i])
    {
        leargest = l;
    }
    else
        leargest = i;

    if(r <= heap_size and heap[r] > heap[leargest])
        leargest = r;

    if(leargest != i)
    {
        swap(heap[i] , heap[leargest]);
        max_heapify(heap, heap_size, leargest);
    }

}

void heapSort(int heap[] ,int heap_size)
{
    for(int i = heap_size; i>1; i--)
    {

        swap(heap[1] , heap[i]);
        heap_size--;
        max_heapify(heap,heap_size,1);
    }
}

void build_heap(int heap[] , int heap_size)
{
    for(int i = heap_size/2 ; i >= 1; i--)
    {
        max_heapify(heap , heap_size , i);
    }

}
int main()
{
    int heap[]={0,3,5,4,8,2,8,9,7,1,6};
    int heap_size = sizeof(heap)/sizeof(heap[0]);
    heap_size = heap_size -1;

    for(int i =1 ; i<11; i++)
        cout<<heap[i]<<" ";
    build_heap(heap , heap_size);
    cout<<endl;

    heapSort(heap,heap_size);

    for(int i =1; i<11; i++) cout<<heap[i]<<" ";

    return 0;
}

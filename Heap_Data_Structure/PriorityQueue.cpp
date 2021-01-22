#include<bits/stdc++.h>
using namespace std;

int left(int pos){return 2*pos;}
int right(int pos){return (2*pos +1);}

int perent(int pos){return pos/2;}

void max_heapify(int heap[] , int heap_size, int pos)
{
    int l = left(pos);
    int r = right(pos);

    int largest;

    if(l <= heap_size and heap[l] > heap[pos] )
        largest = l;
    else largest = pos;
    if(r <= heap_size and heap[r] > heap[largest])
        largest = r;

    if(largest != pos)
    {
        swap(heap[largest] , heap[pos]);

        max_heapify(heap , heap_size , largest);

    }
}

int extractNode(int heap[] , int heap_size)
{
    int max_node = heap[1];

    swap(heap[1] , heap[heap_size]);

    heap_size--;

    max_heapify(heap , heap_size , 1);

    return max_node;
}

int insertNode(int heap[] ,int heap_size , int node)
{
    int p , i;
    heap_size++;
    heap[heap_size] = node;

    i = heap_size;

    while(i > 1 and heap[i] > heap[perent(i)])
    {
        p = perent(i);

        swap(heap[p] , heap[i]);

        i = p;

    }
    return heap_size;
}

void build_heap(int heap[] , int heap_size)
{
    for(int i = heap_size/2; i >=1 ; i--)
    {
        max_heapify(heap , heap_size , i);
    }
}
int main()
{
    int heap[]={0,3,5,4,8,2,8,9,7,1,6};
    int heap_size = sizeof(heap)/sizeof(heap[0]);
    heap_size = heap_size -1;

    build_heap(heap , heap_size);

    int node = extractNode(heap , heap_size);

    cout<<"Max node is = "<<node<<endl;


    cout<<"enter your node : ";
    cin>>node;

    heap_size = insertNode(heap , heap_size , node);


    node = extractNode(heap , heap_size);

    cout<<"Max node is = "<<node<<endl;


    return 0;
}

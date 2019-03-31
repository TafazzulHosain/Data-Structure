Merge sort Algorithm implementation.......
     Here we can sort 3 types list. such as
     1.randomly unsorted list
     2.Semi unsorted list
     2.Reverse list

#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int a[50],num;///Global Declaration of Array And size
void merge(int,int,int);
///Marge Sort Implementation
void merge_sort(int low,int high)
{
     int mid;
     if(low>=high)
        return ;
        mid = (low + high)/2;
        merge_sort(low,mid);
        merge_sort(mid+1,high);
        merge(low,mid,high);

}
void merge(int low,int mid,int high)
{
     int h,i,j,b[50],k;
     h=low;
     i=low;
     j=mid+1;

     while((h<=mid)&&(j<=high))
     {
          if(a[h]<=a[j])
          {
               b[i]=a[h];
               h++;
          }
          else
          {
               b[i]=a[j];
               j++;
          }
          i++;
     }
     if(h>mid)
     {
          for(k=j;k<=high;k++)
          {
               b[i]=a[k];
               i++;
          }
     }
     else
     {
          for(k=h;k<=mid;k++)
          {
               b[i]=a[k];
               i++;
          }
     }
     for(k=low;k<=high;k++)
        a[k]=b[k];
}
///inputs
void Random()
{
    srand(time(0));
    for(int i=1;i<=num;i++)
    {
        a[i] =(rand()%100);
    }
}
void SemiSort()
{
    for(int i=1;i<=num;i++)
    {
        cin>>a[i];
    }
}
void Reverse()
{
    for(int i=1;i<=num;i++)
    {
        cin>>a[i];
    }
}
void Show()
{
     cout<<endl;
     cout<<"So, the sorted list (using MERGE SORT) will be :"<<endl;
     cout<<endl<<endl;
     for(int i=1;i<=num;i++)
        cout<<a[i]<<"  ";
     cout<<endl<<endl<<endl<<endl;
}
///Marge sort Program
int main()
{
     int i,give;
     cout<<"Please Enter the NUMBER OF ELEMENTS you want to sort"<<endl;
     cin>>num;
     cout<<endl;
     cout<<"Now, Please Enter you Option"<<endl;
     while(1)
    {
        cout<<"For randomly input press 1"<<endl;
        cout<<"For Semi sort input press 2"<<endl;
        cout<<"For Reversed input press 3"<<endl;
        cout<<"For end the program press 4"<<endl;
        cin>>give;
        switch(give)
        {
            case 1:
            {
                Random();
                merge_sort(1,num);
                Show();
            }
            break;
            case 2:
            {
                SemiSort();
                merge_sort(1,num);
                Show();
            }
            break;
            case 3:
            {
                Reverse();
                merge_sort(1,num);
                Show();
            }
            break;
            case 4:exit(1);
            break;
            default :cout<<"Entered Possible Option"<<endl;
        }
    }
 return 0;
}



#include<iostream>

using namespace std;

void swap(int array[], int pos1, int pos2);
void FullPerm(int array[], int begin, int size);

int main(void)
{
    int array[] = {1,3,7,1,9};
    FullPerm(array, 0, sizeof(array)/sizeof(int));

    return 0;

}

void FullPerm(int array[], int begin, int size)
{
    if(begin==size-1)
    {
        for(int i=0;i<size;i++)
        {
            cout<<array[i]<<" ";
        }
        cout<<endl;
    }

    for(int i=begin;i<size;i++)
    {
        swap(array, begin, i);
        FullPerm(array, begin+1, size);
        swap(array, begin, i);
    }
}

void swap(int array[], int pos1, int pos2)
{
    int tmp = array[pos1];
    array[pos1] = array[pos2];
    array[pos2] = tmp;
}
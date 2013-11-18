/*
全排列
用了递归的思想. 首先把数组分成第一个和从第二个开始两部分(子排列, 递归展开)。然后把第一个和子序列其中一个交换, 再排, 再排, 再排
*/

#include <iostream>
#include <algorithm>

using namespace std;

void swap(int array[], int pos1, int pos2);
void FullPerm(int array[], int begin, int size);
void FullPermStd(int array[], int begin, int size);

int main(void)
{
    int array[] = {1,3,7,1,9};
    FullPerm(array, 0, sizeof(array)/sizeof(array[0]));

    int array2[] = {1,3,2};
    FullPermStd(array2, 0, sizeof(array2)/sizeof(array2[0]));

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


//std提供了一个计算全排列的算法
//首先把元素从小到大放好，然后反复调用next_permutation()
void FullPermStd(int array[], int begin, int size)
{
    sort(array, array+size);
    do
    {
        for(int i=0;i<size;i++)
        {
            cout<<array[i]<<" ";
        }
        cout<<endl;
    }while(next_permutation(array, array+size));
    //貌似只能是N个不同元素
}
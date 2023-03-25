#include <iostream>
using namespace std;
void Insert(int &sorttill, int a[])
{
    for (int i = 0; i < sorttill; i++)
    {
        if (a[sorttill] > a[i])
        {
            continue;
        }
        else if (a[sorttill] == a[i])
        {
            for (int j = sorttill; j > i + 1; j--)
            {
                swap(a[j], a[j - 1]);
            }
            sorttill++;
            break;
            //place at i+1
        }
        else
        {

            for (int j = sorttill; j > i; j--)
            {
                swap(a[j], a[j - 1]);
            }
            sorttill++;
            break;
            //place at i
        }
    }
}

int main()
{
    int arr[] = {8, 9, 10, 11, 12};
    int s = 5;
    int sorttill = 0;
    int temp = 0;
    for (int i = 0; i < s; i++)
    {
        if (arr[i] >= temp)
        {
            temp = arr[i];
            sorttill++;
        }
        else
        {
            break;
        }
    }
    //sorttill is index value of first unsorted element
    //array is already sorted
    if (sorttill == s)
    {
        for (int i = 0; i < s; i++)
        {
            cout << arr[i] << endl;
        }
    }
    //array unsorted
    else
    {
        while (sorttill != s)
        {
            Insert(sorttill, arr);
        }
        for (int i = 0; i < s; i++)
        {
            cout << arr[i] << endl;
        }
    }
    return 0;
}
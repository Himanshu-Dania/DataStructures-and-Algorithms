#include <iostream>
using namespace std;
int getBit(int n, int pos)
{ // gives bit at index i
    return (n & 1 << pos);
}
void setBit(int &n, int pos)
{ // sets bit to 1 at index 1
    n = (n | 1 << pos);
}
void unsetBit(int &n, int pos)
{ // sets bit to 0 at index 1
    int mask = ~(1 << pos);
    n = (n & mask);
}
void updateBit(int &n, int pos, int val)
{ // updates bit to any val at index 1
    if (val == 1)
    {
        setBit(n, pos);
    }
    else
    {
        unsetBit(n, pos);
    }
}
bool ispoweroftwo(int n)
{ // checks if n is power of 2
    if (n == 0)
    {
        return false;
    }
    n = (n & n - 1);
    if (n == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int numberof1s(int n)
{ // finds out numbers of 1s in binary representation
    int count = 0;
    while (n != 0)
    {
        n = (n & (n - 1));
        count++;
    }
    return count;
}
void subsets(int arr[], int size)
{ // prints all possible subsets of array elements
    for (int i = 0; i < (1 << size); i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (getBit(i, j))
            {
                cout << arr[j] << " ";
            }
        }
        cout << endl;
    }
}
int unique1(int arr[], int size)
{ // gives the single unique number in an arrray in which all other element occur twice
    int x = 0;
    for (int i = 0; i < size; i++)
    {
        x = x ^ arr[i];
    }
    return x;
}
pair<int, int> unique2(int arr[], int size)
{ // gives the two unique numbers in an arrray in which all other element occur twice
    int x = 0;
    for (int i = 0; i < size; i++)
    {
        x = x ^ arr[i];
    }
    // cout<<x<<endl;
    int pos = 0;
    int setbit = 0;
    while (setbit == 0)
    {
        setbit = getBit(x, pos);
        pos++;
        // cout<<pos<<endl;
    }
    pos = pos - 1;
    // cout<<"new pos"<<pos<<endl;
    int nx1 = 0;
    for (int i = 0; i < size; i++)
    {
        if (getBit(arr[i], pos))
        {
            nx1 = nx1 ^ arr[i];
        }
    }
    // cout<<nx1<<endl;
    int nx2 = nx1 ^ x;
    // cout<<nx2<<endl;
    return {nx1, nx2};
}
int unique_3(int arr[], int size)
{ // gives the single unique number in an arrray in which all other element occur thrice
    int x = 0;
    for (int i = 0; i < 64; i++)
    {
        int sum = 0;
        for (int j = 0; j < size; j++)
        {
            if (getBit(arr[j], i))
            {
                sum++;
            }
        }
        sum = sum % 3;
        if (sum == 1)
        {
            setBit(x, i);
        }
    }
    return x;
}
int unique_k(int arr[], int size, int k)
{ // gives the single unique number in an arrray in which all other element occur k times
    if (k % 2 == 0)
    {
        int x = 0;
        for (int i = 0; i < size; i++)
        {
            x = x ^ arr[i];
        }
        return x;
    }
    else
    {
        int x = 0;
        for (int i = 0; i < 64; i++)
        {
            int sum = 0;
            for (int j = 0; j < size; j++)
            {
                if (getBit(arr[j], i))
                {
                    sum++;
                }
            }
            sum = sum % k;
            if (sum == 1)
            {
                setBit(x, i);
            }
        }
        return x;
    }
}
int main()
{
    int arr[] = {4, 4, 4, 5, 4, 6, 6, 6, 4, 6, 6};
    // cout<<unique3(arr, 7);
    cout << unique_k(arr, 11, 5);

    return 0;
}
#include<iostream>
using namespace std;

int main()
{
    int a[50], temp, size;

    cout << "Enter the size of the array: ";
    cin >> size;

    cout << "Enter the array elements: \n";

    for(int i = 0; i<size; i++)
    {
        cout << "Enter Element#" << i+1 << ": ";
        cin >> a[i];
    }
    cout << "\n";

    cout << "\nArray before bubble sort: ";
    for(int i = 0; i<size; i++)
    {
        cout << "Element#"<< i+1 << ": "<< a[i] << "\n ";
    }

    for(int i = 0; i<size; i++)
    {
        for(int j = 0; j<(size - i); j++)
        {
            if(a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    cout << "\n\nArray After bubble sort: ";
    for(int i = 0; i<size; i++)
    {
        cout << "Element#"<< i+1 << ": "<< a[i] << "\n ";
    }

    return 0;
}
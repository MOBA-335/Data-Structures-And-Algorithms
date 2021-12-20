//Bubble sort Algorithm using Array
#include<iostream>
using namespace std;

int main()
{
    int i, j, n, temp;

    cout << "Enter The no of numbers: ";
    cin >> n;

    int array[n];


    cout << "Enter the numbers in a random order: ";
    for( i = 0; i<n; i++)
    {
        cout << "> ";
        cin >> array[i];    
    }

    for(int i = 0; i<n; i++)
    {
        for(j = 0; j<n-i; j++)
        {
            if(array[j] > array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

    cout << "Array after bubble sort: ";
    for(i = 0; i < n; i++)
    {
        cout << array[i] << endl;
    }



    return 0;
}
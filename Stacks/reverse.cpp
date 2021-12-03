#include<iostream>
#include<string.h>
#include<stack>
using namespace std;

void Reverse(char C[], int n);

int main()
{
    char array[51];
    cout << "Enter a String: ";
    gets(array);
    Reverse(array, strlen(array));
    printf("Output = %s", array);
    return 0;
}

void Reverse(char c[], int n)
{
    stack<char> S;
    for(int i = 0; i<n; i++)
    {
        S.push(c[i]);
    }
    for(int i =0; i<n; i++)
    {
        c[i] = S.top();
        S.pop();
    }
}

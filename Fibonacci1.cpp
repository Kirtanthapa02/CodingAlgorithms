//Take input how many fibonacci number you want. Those many fibonacci number is stored in an array. 
//The algorithm finds a series of fibonacci numbers that will add up to a given input number.
#include <iostream>
using namespace std;
// 1 1 2 3 5 
int fib(int n)
{
    int F0 = 1;
    int F1 = 1;
    int Fn = 0;
    if(n<=1){
        return 1;
    }
    for(int i=0;i<n-1;i++)
    {
        Fn = F0 + F1;
        F0 = F1;
        F1 = Fn;
    }
    return Fn;
}
int Binary_Search(int *arr,int length,int x)
{
    int start_index = 0;
    int end_index = length -1;
    int resultant_index = -1;
    while(start_index<=end_index)
    {
        int mid_index = (start_index+end_index)/2;
        if(arr[mid_index]==x)
        {
            resultant_index = mid_index;
            start_index=mid_index+1;
        }
        else if(arr[mid_index]<x)
        {
            resultant_index = mid_index;
            start_index = mid_index + 1;
        }
        else
        {
            end_index = mid_index - 1;
        }
    }
    return resultant_index;
}

void printArray(int *arr,int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int n;//How many fibonacci number you want to store in array
    cout<<"Enter size of array:";
    cin>>n;

    int* Fib_array = new int[n];
    for(int i=0;i<n;i++)
    {
        Fib_array[i] = fib(i);
    }
    printArray(Fib_array,n);

    int x;
    cout<<"Enter a number:";//sum of fibonacci series will sum to this number
    cin>>x;

    while(x>0)
    {
        int largest_fib = Binary_Search(Fib_array,n,x);
        cout<<"F"<<largest_fib<<" ";
        x = x - fib(largest_fib);
    }
    cout<<endl;
    cout<<"F0 is 1st fibonacci number"<<endl;
    return 0;
}


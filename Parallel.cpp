#include <bits/stdc++.h>
using namespace std;

void min_reduction(vector<int> &arr)
{
    int min_value = INT_MAX;
#pragma omp parallel for reduction(min : min_value)
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < min_value)
        {
            min_value = arr[i];
        }
    }
    cout << "Minimum Value from Array :- " << min_value << endl;
}

void max_reduction(vector<int> &arr)
{
    int max_value = INT_MIN;
#pragma omp parallel for reduction(max : max_value)
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > max_value)
        {
            max_value = arr[i];
        }
    }
    cout << "Maximum value from Array :- " << max_value << endl;
}

void sum_reduction(vector<int> &arr)
{
    int sum = 0;
#pragma omp parallel for reduction(+ : sum)
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }
    cout << "Sum of Array :- " << sum << endl;
}

void avg_reduction(vector<int> &arr)
{
    int sum = 0;
#pragma omp parallel for reduction(+ : sum)
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }
    cout << "Average of Array :- " << (double)sum / arr.size() << endl;
}

int main()
{
    vector<int> arr = {5, 2, 9, 1, 7, 6, 8, 3, 4, 12};
    
    min_reduction(arr);
    max_reduction(arr);
    sum_reduction(arr);
    avg_reduction(arr);
}
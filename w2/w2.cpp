#include <iostream>
#include <algorithm>
#include <memory>
#include <numeric>
#include <functional>
#include <cmath>
using namespace std;

int calc_sum(int count, const unique_ptr<int[]>& numbers);
int find_min(int count, const unique_ptr<int[]>& numbers);
int find_max(int count, const unique_ptr<int[]>& numbers);

int main()
{

    int arraySize;
    cout << "enter array size: ";
    cin >> arraySize;
    cout << endl;

    unique_ptr<int[]> myArray(new int[arraySize]);

    for (int i = 0; i < arraySize; i++)
    {
        cout << "Number " << i+1 << ": ";
        cin >> myArray[i];
    }

    auto arrayEnd = myArray.get() + arraySize;

    for (int i = 0; i < arraySize; i++)
    {
        cout << myArray[i] << " ";
    }
    cout << endl;

    int sum = accumulate(myArray.get(), arrayEnd, 0);
    cout << "Sum: " << sum << endl;

    cout << "Average" << floor(sum/arraySize) << endl;

    cout << "Min: " << accumulate(myArray.get()+1, arrayEnd, myArray[0], [](auto x, auto y)
        {
            return (x < y) ? x : y;
        }) << endl;

    cout << "Max: " << accumulate(myArray.get()+1, arrayEnd, myArray[0], [](auto x, auto y)
        {
            return (x > y) ? x : y;
        }) << endl;

    arrayEnd = transform(myArray.get(), arrayEnd, myArray.get(), [](auto x){
            return x * x;
        });
    cout << "Square of each number:";
    for_each(myArray.get(), arrayEnd, [](auto x) { cout << x << " " ; });
    cout << endl;

    arrayEnd = remove_if(myArray.get(), arrayEnd,[](auto x) {
        return x >= 1000; 
    });
    cout << "Square of each number:";
    for_each(myArray.get(), arrayEnd, [](auto x) { cout << x << " " ; });
    cout << endl;

    arrayEnd = remove_if(myArray.get(), arrayEnd, [](auto x){
        return (x%2) == 0;
    });
    cout << "Square of each number:";
    for_each(myArray.get(), arrayEnd, [](auto x) { cout << x << " " ; });
    cout << endl;


    cout << "enter array size: ";
    cin >> arraySize;
    cout << endl;

    for (int i = 0; i < arraySize; i++)
    {
        cout << "Number " << i+1 << ": ";
        cin >> myArray[i];
    }

    for (int i = 0; i < arraySize; i++)
    {
        cout << myArray[i] << " ";
    }
    cout << endl;

    cout<< calc_sum(arraySize, myArray)<<endl;
    cout<< find_min(arraySize, myArray)<<endl;
    cout<< find_max(arraySize, myArray)<<endl;
}
int calc_sum(int count, const unique_ptr<int[]>& numbers)
{
   int sum = 0;
   for (int i = 0; i < count; i++) {  
      sum += numbers[i];
   }
   return sum;
}

int find_min(int count, const unique_ptr<int[]>& numbers)
{
   int min = numbers[0];
   for (int i = 1; i < count; i++) {
      min = (numbers[i] < min) ? numbers[i] : min;
   }
   return min;
}

int find_max(int count, const unique_ptr<int[]>& numbers)
{
   int max = numbers[0];
   for (int i = 1; i < count; i++) {
      max = (numbers[i] > max) ? numbers[i] : max;
   }
   return max;
}



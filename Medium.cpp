#include <iostream>
#include <vector>
using namespace std;
// Function to find the elements that appear more than n/3 times in the array
vector<int> solve(int arr[], int n) {
  vector<int> ans;
  int flag = 0;
  //Traversing the array
  for (int i = 0; i < n; i++)
  {
    int count = 0;
    //Iterate through the remaining elements of the array
    for (int j = i; j < n; j++)
    {
      //Check if the current element is equal to the element at index j, if they are equal then increment the counter
      if (arr[i] == arr[j])
      {
        count++;
      }
    }
    //Check if the count is greater than n/3
    if (count > (n / 3)) {
      ans.push_back(arr[i]);
      //Set the flag to indicate that an element has been found
      flag = 1;
    }
  }
  // Check if the flag is still 0, meaning no element has been found to appear more than n/3 times
  if (!flag) {
    //Add all elements to the ans vector since no element satisfies the condition
    for (int i = 0; i < n; i++) {
      ans.push_back(arr[i]);
    }
  }
  //returning the ans vector
  return ans;
}

int main() {
  int n;
  vector<int> ans;
  cout << "Enter the size of the array: ";
  cin >> n;

  int arr[n];
  cout << "Enter the elements of the array: ";
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  //store the returned vector in a vector
  ans = solve(arr, n);
  cout << "The number which repeated more than n/3 times in the array is: ";
  for (auto val : ans) {
    cout << val << " ";
  }
  return 0;
}

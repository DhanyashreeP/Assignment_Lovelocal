#include<iostream>
#include<deque>
#include<vector>
using namespace std;
vector<int> maxSlidingWindow(int nums[],int n,int k){
    vector<int> ans;
    deque<int> dq;
    //processing the first window of k elements
    for(int i=0;i<k;i++){
        //removing the index of the elements which are smaller the the current element
        while(!dq.empty() && nums[i]>=nums[dq.back()]){
            dq.pop_back();
        }
        //inserting the current element index into the deque
        dq.push_back(i);
    }
    //storing the maximum element of the first window in the ans vector
    ans.push_back(nums[dq.front()]);

    //processing the remaining windows
    for(int i=k;i<n;i++){
        //remove the out of window elements
        while(!dq.empty() && i-dq.front()>=k){
            dq.pop_front();
        }
        //removing the index of the elements which are smaller the the current element
        while(!dq.empty() && nums[i]>=nums[dq.back()]){
            dq.pop_back();
        }
        //inserting the current element index into the deque
        dq.push_back(i);
        //stroring the maximum element of each window in the ans vector
        ans.push_back(nums[dq.front()]);
    }
    //returning the ans vector which contains the maximum element of each window
    return ans;
}
int main(){
    int n;
    int nums[n];
    int k;
    vector<int> ans;
    cout << "Enter the size of the array "<<endl;
    cin >> n;
    cout << "Enter an array: "<< endl;
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    cout << "Enter the window size, k: "<< endl;
    cin >> k;
    //vector returned by the maxSlidingWindow() function is stored in ans vector
    ans=maxSlidingWindow(nums,n,k);
    //printing the elements of the ans vector using foreach loop
    cout <<"Printing the answer: ";
    for(auto val:ans){
        cout << val << " ";
    }
}
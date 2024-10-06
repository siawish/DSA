#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void nextGreaterElement( vector<int>& nums) {
    
    int n = nums.size();
    vector<int> result(n); 

    stack<int> s; 

   
    for (int i = n - 1; i >= 0; --i) {
       
        while (!s.empty() && s.top() <= nums[i]) {
            s.pop();
        }

       
           result[i] = s.empty() ? -1 : s.top();

       
        s.push(nums[i]);
    }
    // Print 
        for (int i = 0; i < n; ++i) {
            cout << result[i] << " ";
        }
}

int main() {
    vector<int> nums = { 4, 5, 2, 25 };

    cout << "\n Input: [ ";
    for (int num : nums) {
        cout << num << " ";
    }

    cout << "]\n Output: [ ";
    nextGreaterElement(nums);
    cout << "]" << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

//Given a possibly rotated array at an unknown pivot index find the index of target value
//Time complexity - O(logn)
 int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left=0, right=n-1;
        while(left <= right)
        {
            int mid = left + (right-left)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
            {
                if(nums[left] <= nums[mid] && target < nums[left] )
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            else
            {
                if(target > nums[right] && nums[mid] <= nums[right])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        
        return -1;
    }
int main()
{
    vector<int> arr={4,5,6,7,0,1,2};
    int target = 2;
    cout<<"Index of target is "<<search(arr,target);
}

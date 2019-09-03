class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target to find.
     * @return: The first position of target. Position starts from 0.
     */
    int binarySearch(vector<int> &nums, int target) {
        // write your code here
        int size = nums.size();
        int left = 0, right = size - 1, mid = 0;
        while (left + 1 < right){
            mid = left + (right - left) / 2;
            if (nums[mid] < target){
                left = mid;
            }
            else{
                right = mid;
            }
        }
        if (nums[left] == target){
            return left;
        }
        else if (nums[right] == target){
            return right;
        }
        else{
            return -1;
        }
    }
};
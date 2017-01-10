#ifndef searchroatedsortedarray_h
#define searchroatedsortedarray_h

// Leetcode 33 Search in Rotated Sorted Array 

int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return -1;
        int low = 0, high = n - 1;
        while(low < high) {
        	int mid = (high - low)/2 + low;
        	if(nums[mid] > nums[high]) {
        		low = mid + 1;
        	}  else {
        		high = mid;
        	}
        }

        int k = low;
        low = 0;
        high = n - 1;
        while(low <= high) {
        	int mid = (high - low)/2 + low;
        	int real_mid = (mid + k) % n;
        	if(nums[real_mid] == target) {
        		return real_mid;
        	} else if(nums[real_mid] < target) {
        		low = mid + 1;
        		
        	} else {
        		high = mid - 1;
        	}
        }
        return -1;
    }

 // Leetcode 81 Search in Rotated Sorted Array II
 
 bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        while(low < high) {
        	int mid = (high - low)/2 + low;
        	if(nums[mid] == target) return true;
        	if(nums[mid] > nums[high]) {
        		if(nums[mid] > target && nums[low] <= target) {
        			high = mid - 1;
        		} else {
        			low = mid + 1;
        		}
        	} else if(nums[mid] < nums[high]) {
        		if(nums[mid] < target && nums[high] >= target) {
        			low = mid + 1;
        		} else {
        			high = mid - 1;
        		}
        	} else {
        		high--;
        	}
        }
        return nums[mid] == target;
    }

 // Leetcode 153 Find Minimum in Rotated Sorted Array 
 
 int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1;
        while(low < high) {
        	int mid = (high - low)/2 + low;
        	if(nums[mid] > nums[high]) {
        		low = mid + 1;
        	} else if (nums[mid] < nums[high]) {
        		high = mid;
        	} else {
        		high--;
        	}
        }
        return nums[low];
    }

#endif
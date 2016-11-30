#ifndef TWOSUM_H
#define TWOSUM_H

#include <iostream>
#include <vector>

// Leetcode 1 Two sum

vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> res(2,0);
	unordered_map<int,int> mymap;
	for(int i = 0; i < nums.size(); i++) {
		if(mymap.find(target - nums[i]) != mymap.end()) {
			res[0] = mymap[target-nums[i]];
			res[1] = i;
			return res;
		} else {
			mymap.emplace(nums[i],i);
		}
	}
	return res;
}


// Leetcode 15 3Sum

vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> res;
	if(nums.size() < 3) return res;
	sort(nums.begin(), nums.end());
	for(int i = 0; i < nums.size(); i++) {
		int j = i + 1, k = nums.size() - 1;
		while(j < k) {
			if((nums[i] + nums[j] + nums[k]) == 0) {
				vector<int> curr(3,0);
				curr[0] = nums[i];
				curr[1] = nums[j];
				curr[2] = nums[k];
				res.push_back(curr);
				j++;
				k--;
				while(j < k && nums[j] == nums[j-1]) j++;
				while(k > j && nums[k] == nums[k + 1]) k--;
			} else if((nums[i] + nums[j] + nums[k]) > 0) {
				k--;
			} else {
				j++;
			}
		}
		while(i < (nums.size() - 2) && nums[i] == nums[i+1]){
			i++;
		}
	}
	return res;
}

// Leetcode 16 3Sum Closest

int threeSumClosest(vector<int>& nums, int target) {
	sort(nums.begin(), nums.end());
	int index1 = -1, index2 = -1, index3 = -1, min_dis = INT_MAX;
	for(int i = 0; i < nums.size() - 2; i++) {
		int j = i + 1, k = nums.size() - 1;
		while(j < k) {
			int tmp_sum = nums[i] + nums[j] + nums[k];
			if( tmp_sum == target) {
				return tmp_sum;
			} else if(tmp_sum > target) {
				if((tmp_sum - target) < min_dis) {
					index1 = i;
					index2 = j;
					index3 = k;
					min_dis = tmp_sum - target;
				}
				k--;
			} else {
				if((target - tmp_sum) < min_dis) {
					index1 = i;
					index2 = j;
					index3 = k;
					min_dis = target - tmp_sum;
				}
				j++;
			}
		}
		while(i < nums.size() - 2 && nums[i] == nums[i+1]) i++;
	}
	return (nums[index1] + nums[index2] + nums[index3]);
}

// Leetcode 18 4Sum

vector<vector<int>> fourSum(vector<int>& nums, int target) {
	vector<vector<int>> res;
	if(nums.size() < 4) return res;
	sort(nums.begin(), nums.end());
	for(int i = 0; i < nums.size() - 3; i++) {
		for(int j = i + 1; j < nums.size() - 2; j++) {
			int r = j + 1, k = nums.size() - 1;
			while(r < k) {
			    if((nums[i] + nums[j] + nums[r] + nums[k]) == target) {
					vector<int> curr(4,0);
					curr[0] = nums[i];
					curr[1] = nums[j];
					curr[2] = nums[r];
					curr[3] = nums[k];
					res.push_back(curr);
					r++;
					k--;
					while(r < k && nums[r] == nums[r-1]) r++;
					while(k > r && nums[k] == nums[k+1]) k--;
			    } else if((nums[i] + nums[j] + nums[r] + nums[k]) > target) {
				    k--;
			    } else {
				    r++;
			    }
			}
			while((j < (nums.size() - 2)) && (nums[j] == nums[j+1])) j++;
		}
		while((i < (nums.size() - 3)) && (nums[i] == nums[i + 1])) i++;
	}
	return res;
}

#endif
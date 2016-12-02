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

// Leetcode 167 Two Sum II
// Input array is already sorted
vector<int> twoSum2(vector<int>& numbers, int target) {
	vector<int> res(2,0);
	int i = 0, j = numbers.size() - 1;
	while(i < j) {
		if((numbers[i] + numbers[j]) == target) {
			res[0] = i + 1;
			res[1] = j + 1;
			return res;
		} else if((numbers[i] + numbers[j]) > target) {
			j--;
		} else {
			i++;
		}
	}
	return res;
}

// Leetcode 40 Combination Sum II 
void backtracking_combinationSum2(vector<vector<int>>& res, vector<int>& curr, vector<int>& candidates, int target, int level) {
	if(target == 0) {
		res.push_back(curr);
		return;
	} else if(target < 0) {
		return;
	} else {
		for(int i = level; i < candidates.size(); i++) {
			curr.push_back(candidates[i]);
			backtracking_combinationSum2(res, curr, candidates, target - candidates[i], i + 1);
			curr.pop_back();
			while(i < (candidates.size() - 1) && (candidates[i] == candidates[i + 1])) i++;
		}
	}
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	vector<vector<int>> res;
	vector<int> curr;
	sort(candidates.begin(), candidates.end());
	backtracking_combinationSum2(res, curr, candidates, target, 0);
	return res;
}

//Leetcode 39 Combination Sum

void backtracking_combinationSum(vector<vector<int>>& res, vector<int>& curr, vector<int>& candidates, int target, int level) {
	if(target == 0) {
		res.push_back(curr);
		return;
	} else if(target < 0) {
		return;
	} else {
		for(int i = level; i < candidates.size(); i++) {
			curr.push_back(candidates[i]);
			backtracking_combinationSum(res, curr, candidates, target - candidates[i], i);
			curr.pop_back();
			while(i < (candidates.size() - 1) && (candidates[i] == candidates[i + 1])) i++;
		}
	}
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<vector<int>> res;
	vector<int> curr;
	sort(candidates.begin(),candidates.end());
	backtracking_combinationSum(res, curr, candidates, target, 0);
	return res;
}

// Leetcode 259: 3Sum Smaller

int threeSumSmaller(vector<int>& nums, int target) {
	int count = 0;
	if(nums.size() < 3) return count;
	sort(nums.begin(), nums.end());
	for(int i = 0; i < nums.size() - 2; i++) {
		if((nums[i] + nums[i+1] + nums[i+2]) >= target) break; 
		int j = i + 1, k = nums.size() - 1;
		while(j < k) {
			int tmp_sum = nums[i] + nums[j] + nums[k];
			if(tmp_sum >= target) {
				k--;
			} else {
				count += (k - j);
				j++;
			}
		}
	} 
	return count;
}
// Leetcode 216: Combination Sum III

void backtracking_combinationSum3(vector<vector<int>>& res, vector<int>& curr, int k, int n, int level) {
	if(curr.size() == k) {
		if(n == 0) {
			res.push_back(curr);
		}
		return;
	} else if(curr.size() > k || n <= 0) {
		return;
	} else {
		for(int i = level; i <= 9; i++) {
			curr.push_back(i);
			backtracking_combinationSum3(res, curr, k, n - i, i + 1);
			curr.pop_back();
		}
	}
}
vector<vector<int>> combinationSum3(int k, int n) {
	vector<vector<int>> res;
	vector<int> curr;
	backtracking_combinationSum3(res, curr, k, n, 1);
	return res;
}

// Leetcode 377 Combination Sum IV


int combinationSum4(vector<int>& nums, int target) {
	vector<int> dp(target + 1);
	dp[0] = 1;
	sort(nums.begin(), nums.end());
	for(int i = 1; i <= target; i++) {
		for(auto num:nums){
			if(i < num) break;
			dp[i] += dp[i - num];
		}
	}
	return dp.back();
}


#endif
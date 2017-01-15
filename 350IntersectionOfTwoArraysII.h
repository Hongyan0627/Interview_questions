//  LeetCode
//
//  Created by Hongyan on 01/15/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) { 
        vector<int> res;
        unordered_map<int,int> mymap;
        for(auto num:nums1) {
        	mymap[num]++;
        }
        for(auto num:nums2) {
        	if(mymap[num] > 0) {
        		res.push_back(num);
        		mymap[num]--;
        	}
        }
        return res;
	}
};
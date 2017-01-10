//  LeetCode
//
//  Created by Hongyan on 01/10/17.
//  Copyright © 2017 Hongyan. All rights reserved.
//

class ListNode {
	int val;
	ListNode* next;
	ListNode(int x):val(x), next(NULL){}
};

class PhoneDirectory {
private:
	int maxCap;
	queue<int> available_nums;
	vector<bool> used;
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        used.resize(maxNumbers, false);
        maxCap = maxNumbers;
        for(int i = maxNumbers - 1; i >= 0; i--) {
        	available_nums.push(i);
        }
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if(!available_nums.empty()) {
        	int num = available_nums.front();
        	available_nums.pop();
        	used[num] = true;
        	return num;
        } else {
        	return -1;
        }
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return (number >= 0 && number < maxCap && used[number] == false);
    }
    
    /** Recycle or release a number. */
    void release(int number) {
    	if(number >= 0 && number < maxCap) {
    		available_nums.push(number);
    		used[number] = false;
    	} 
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */
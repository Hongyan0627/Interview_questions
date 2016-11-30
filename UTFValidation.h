#ifndef UTFVALIDATION_H
#define UTFVALIDATION_H

#include <vector>

// Leetcode 393 UTF-8 Validation

bool validUtf8(vector<int>& data) {
	int count = 0;
	for(auto c:data) {
		if(count == 0) {
			if((c>>5) == 0b110) count = 1;
			else if((c>>4) == 0b1110) count = 2;
			else if((c>>3) == ob11110) count = 3;
			else if((c>>7)) return false;
		} else {
			if((c>>6) != 0b10) return false;
			count--;
		}
	}
	return count == 0;
}


#endif
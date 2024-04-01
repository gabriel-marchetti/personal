#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> twoNums = vector<int>();
        for( vector<int>::iterator it1 = nums.begin(); it1 != nums.end() - 1; it1++ ){
            int contentIt1 = *it1;
            for( vector<int>::iterator it2 = it1 + 1; it2 != nums.end(); it2++ ){
                int contentIt2 = *it2;
                if( contentIt1 + contentIt2 == target ){
                    twoNums.push_back( static_cast<int>(it1 - nums.begin()) );
                    twoNums.push_back( static_cast<int>(it2 - nums.begin()) );
                    return twoNums;
                }
            }
        }

        return twoNums;
    }
};
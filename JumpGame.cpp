//You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
// Input: nums = [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
https://leetcode.com/problems/jump-game/
#include<bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums){

int maxJump=0;
int n=nums.size();
for(int i=0;i<n;i++){
if(i>maxJump)
 break;

maxJump=max(maxJump,i+nums[i]);
if(maxJump>n-1)
return true;
}
return false;
}
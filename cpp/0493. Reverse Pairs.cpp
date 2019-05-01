// Given an array nums, we call (i, j) an important reverse pair if i < j and nums[i] > 2*nums[j].
// You need to return the number of important reverse pairs in the given array.

// Example1:
// Input: [1,3,2,3,1]
// Output: 2

// Example2:
// Input: [2,4,3,5,1]
// Output: 3

// Note:
// The length of the given array will not exceed 50,000.
// All the numbers in the input array are in the range of 32-bit integer.


// https://leetcode.com/problems/reverse-pairs/discuss/97268/General-principles-behind-problems-similar-to-%22Reverse-Pairs%22
class Solution {
public:
	int reversePairs(vector<int>& nums) {
		if (nums.empty())
			return 0;

		vector<int> buf(nums.size(), 0);
		return mergeSort(nums, 0, nums.size(), buf);
	}

	int mergeSort(vector<int>& nums, int begin, int end, vector<int>& buf)
	{
		if (end - begin <= 1)
			return 0;		

		int res = 0;
		int mid = begin + ((end - begin) >> 1);
		res += mergeSort(nums, begin, mid, buf) + mergeSort(nums, mid, end, buf);
		res += merge(nums, begin, mid, end, buf);

		return res;
	}

	int merge(vector<int>& nums, int begin, int mid, int end, vector<int>& buf)
	{
		int res = 0;
		for (int i = begin, j = mid; i < mid; ++i)
		{
		    while (j < end && nums[i] / 2.0 > nums[j])
		        j++;
		        
		    res += j - mid;
		}
		
		int cur = begin;
		int left = begin;
		int right = mid;
		while (left < mid && right < end)
		{
			if (nums[left] <= nums[right])		
				buf[cur++] = nums[left++];
			else
				buf[cur++] = nums[right++];
		}

		while (left < mid)
			buf[cur++] = nums[left++];
		while (right < end)
			buf[cur++] = nums[right++];

		for (int i = begin; i < end; ++i)
			nums[i] = buf[i];

		return res;
	}
};
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int mostCommon = nums[0];
        int maxElement = 0;
        unordered_map<int, int> elements; //first int value from nums, second int is count
        for(int i=0;i<nums.size();i++)
        {
            elements[nums[i]]++;
            if(elements[nums[i]]>maxElement)
            {
                maxElement = elements[nums[i]];
                mostCommon = nums[i];
            }
        }
    return mostCommon;
    }

};

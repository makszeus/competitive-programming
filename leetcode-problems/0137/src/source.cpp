class Solution {
public:
    int singleNumber(vector<int>& nums) {
        size_t counterOne = 0;
        size_t counterTwo = 0;
        
        for (size_t i = 0; i < nums.size(); ++i) {
            counterOne = (~counterTwo) & (counterOne ^ nums[i]);
            counterTwo = (~counterOne) & (counterTwo ^ nums[i]);
        }
        return counterOne;
    }
};

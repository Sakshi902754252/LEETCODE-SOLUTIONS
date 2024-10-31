class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int>mp;
        int n = nums.size();

        for(int &num : nums)
        {
            mp[num]++;
        }
        for (auto &m : mp){
            if(m.second > n/2){
                return m.first;
            }
        }
        return -1;
    }
};
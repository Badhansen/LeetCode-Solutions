class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorityElement, counter = 0;
        for(int i = 0; i < nums.size(); i++){
            if(counter == 0){
                majorityElement = nums[i];
                counter = 1;
            }
            else{
                (majorityElement == nums[i]) ? counter++ : counter--;
            }
        }
        return majorityElement;
    }
};
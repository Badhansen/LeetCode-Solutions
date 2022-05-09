public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        Dictionary<int, int> phonebook = new Dictionary<int, int> ();
        for(int i = 0; i < nums.Length; i++){
            int complement = target - nums[i];
            if(phonebook.ContainsKey(complement)){
                return new [] {i, phonebook[complement]};
            }
            phonebook[nums[i]] = i;
        }
        return new [] {0, 1};
    }
}


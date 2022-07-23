// @Author: KING-SEN
// Programming Language Used: C++

class Solution {
public:
    void invCount(vector<pair<int, int>> &array, vector<int>& count, int low, int mid, int high){
        int i = low, j = mid + 1, k = 0;
        vector<pair<int, int>> temp(high - low + 1);
        
        while(i <= mid && j <= high){
            if(array[i].first > array[j].first){
                count[array[i].second] += high - j + 1;
                temp[k++] = array[i++];
            }
            else{
                temp[k++] = array[j++];
            }
        }
        while(i <= mid){
            temp[k++] = array[i++];
        }
        while(j <= high){
            temp[k++] = array[j++];
        }
        for(int i = low; i <= high; i++){
            array[i] = temp[i - low];
        }
    }
    void mergeSort(vector<pair<int, int>> &array, vector<int>& count, int low, int high){
        if(low >= high) return;
        
        int mid = (low + high) / 2;
        
        mergeSort(array, count, low, mid);
        mergeSort(array, count, mid + 1, high);
        invCount(array, count, low, mid, high);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int length = nums.size();
        vector<pair<int, int>> array;
        vector<int> count(length, 0);
        
        for(int i = 0; i < length; i++){
            array.push_back({nums[i], i});
        }
        
        mergeSort(array, count, 0, length - 1);
        
        return count;
    }
};

// Time Complexity: O(N log N), where N is the length of the array
// Space Complexity: O(N), since we need a constant number of arrays of size O(N).
class Solution {
public:
    int calculate(vector<int>& heights,int i){
        int j=i-1;
        int k=i+1;
        int count=1;
        while(j>=0 && heights[j]>=heights[i]){
            count++;
            j--;
        }
        while(k<heights.size() && heights[k]>=heights[i]){
            count++;
            k++;
        }
        return count*heights[i];
    }
    int largestRectangleArea(vector<int>& heights) {
        int ans=0;
        if(heights.size()==0) return 0;
        ans=max(ans,calculate(heights,0));
        for(int i=1;i<heights.size();i++){
            if(heights[i]==heights[i-1]) continue;
            ans=max(ans,calculate(heights,i));
        }
        return ans;
    }
};
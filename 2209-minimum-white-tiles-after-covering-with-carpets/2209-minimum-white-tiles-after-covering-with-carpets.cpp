class Solution {
public:
    int carpetLen, fLen;
    vector<int> sum;
    vector<vector<int>> dp;
    int solve(int pos, int numCar, string& floor){
        if(pos >= fLen){
            return 0;
        }
        
        if(numCar == 0){
            return 0;
        }
        
        int &ret = dp[pos][numCar];
        
        if(ret != -1){
            return ret;
        }
        
        int taken = 0, notTaken = 0;
        int fSum = 0, lSum = 0;
        
        fSum = pos > 0 ? sum[pos - 1] : 0;
        lSum = pos + carpetLen > fLen ? sum[fLen - 1] : sum[pos + carpetLen - 1];
        
        taken = lSum - fSum + solve(pos + carpetLen,  numCar - 1, floor);
        notTaken = solve(pos + 1, numCar, floor);
        
        return ret = max(taken, notTaken);
    }
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        fLen = floor.size();
        this->carpetLen = carpetLen;
        sum.resize(fLen + 1, 0);
        dp.resize(fLen + 1, vector<int> (numCarpets + 1, -1));
        sum[0] = floor[0] - '0';
        
        for(int i = 1; i < fLen; i++){
            sum[i] = sum[i - 1] + (floor[i] - '0');
        }
        
        return sum[fLen - 1] - solve(0, numCarpets, floor);
    }
};
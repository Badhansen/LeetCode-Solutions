class Solution {
public:
    int compareVersion(string version1, string version2) {
        int v1Len = version1.size(), v2Len = version2.size();
        int i = 0, j = 0;
        while(i < v1Len || j < v2Len){
            int num1 = 0, num2 = 0;
            while(i < v1Len && version1[i] != '.'){
                num1 = num1 * 10 + (version1[i] - '0');
                i++;
            }
            while(j < v2Len && version2[j] != '.'){
                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }
            if(num1 > num2){
                return 1;
            }
            else if(num1 < num2){
                return -1;
            }
            i++, j++;
        }
        return 0;
    }
};
class Solution {
public:
    struct Node{
        int boxUnit, boxUnitPrice;
        Node(){}
        bool operator < (const Node& x) const{
            return boxUnitPrice > x.boxUnitPrice;
        }
    };
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int boxLength = boxTypes.size();
        vector<Node> items;
        
        for(int i = 0; i < boxLength; i++){
            Node x;
            x.boxUnit = boxTypes[i][0];
            x.boxUnitPrice = boxTypes[i][1];
            items.push_back(x);
        }
        
        sort(items.begin(), items.end());
        int minSize, answer = 0;
        
        for(int i = 0; i < boxLength; i++){
            minSize = min(truckSize, items[i].boxUnit);
            
            answer += (minSize * items[i].boxUnitPrice);
            truckSize -= minSize;
            
            if(truckSize == 0) break;
        }
        return answer;
    }
};
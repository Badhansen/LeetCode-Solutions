class Solution {
public:
    bool isCellFree(int index, vector<int> &flowerbed){
        if(index == flowerbed.size())
            return true;
        return flowerbed[index] == 0;
    }
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt = 0, freeCell = 1, placeFlower = 0;
        for(int i = 0; i < flowerbed.size(); i++){
            if(flowerbed[i]) freeCell = 0;
            else{
                freeCell++;
                if(freeCell == 2 && isCellFree(i + 1, flowerbed)){
                    placeFlower++;
                    freeCell = 0;
                }
            
            }
        }
        return n <= placeFlower;
    }
};
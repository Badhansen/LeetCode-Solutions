class ParkingSystem {
    int b, m, s;
    int b_count, m_count, s_count;
public:
    
    ParkingSystem(int big, int medium, int small) {
        b = big;
        m = medium;
        s = small;
        b_count = m_count = s_count = 0;
    }
    
    bool addCar(int carType) {
        if(carType == 1){
            if(get_big_car_count() < b){
                big_car_added();
                return true;
            }
            else
                return false;
        }
        else if(carType == 2){
            if(get_medium_car_count() < m){
                medium_car_added();
                return true;
            }
            else
                return false;
        }
        else{
            if(get_small_car_count() < s){
                small_car_added();
                return true;
            }
            else
                return false;
        }
    }
    int get_big_car_count(){
        return b_count;
    }
    int get_medium_car_count(){
        return m_count;
    }
    int get_small_car_count(){
        return s_count;
    }
    void big_car_added(){
        b_count++;
    }
    void medium_car_added(){
        m_count++;
    }
    void small_car_added(){
        s_count++;
    }
    
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
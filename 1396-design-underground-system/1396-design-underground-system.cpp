class UndergroundSystem {
private:
    unordered_map<int, pair<string, int>> checkin;
    unordered_map<string, pair<int, int>> routes;
public:
    UndergroundSystem() {
        checkin.clear();
        routes.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        checkin[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto [station, time] = checkin[id];
        checkin.erase(id);
        string destination = station + "|" + stationName;
        routes[destination].first++;
        routes[destination].second += (t - time);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string destination = startStation + "|" + endStation;
        double avg = routes[destination].second;
        avg /= routes[destination].first;
        return avg;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
class UndergroundSystem {
public:
    map<int,pair<string,int>>mp;
    map<string,pair<int,int>>ump;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        mp[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string newstring = mp[id].first+" "+stationName;
        int timetaken = t -mp[id].second;
        ump[newstring].first += timetaken;
        ump[newstring].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string newstring = startStation+" "+endStation;
        double result = (double)ump[newstring].first/ump[newstring].second;
        return result;
    }
    
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
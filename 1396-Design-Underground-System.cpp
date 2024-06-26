class UndergroundSystem {
public:
	unordered_map<int,pair<string,int>> pre;
	unordered_map<string,unordered_map<string,int>> times;  // total times from end to start station
	unordered_map<string,unordered_map<string,int>> check; // diff time from end to start station
	UndergroundSystem() {

	}

	void checkIn(int id, string stationName, int t) {
		pre[id]={stationName,t};
	}

	void checkOut(int id, string stationName, int t) {
		check[stationName][pre[id].first]+=t-pre[id].second;
		times[stationName][pre[id].first]+=1;

	}

	double getAverageTime(string startStation, string endStation) {
		return (double)check[endStation][startStation]/times[endStation][startStation];
	}
};
/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        map< int, vector<int> > mAdj;
	for (auto& curPair : adjacentPairs) {
		mAdj[curPair[0]].push_back(curPair[1]);
		mAdj[curPair[1]].push_back(curPair[0]);
	}

	vector<int> vRes {};
	for (auto& curPair : mAdj) {
		if (curPair.second.size() == 1) {
			vRes.push_back(curPair.first);
			vRes.push_back(curPair.second[0]);
			break;
		}
	}

	while (vRes.size() < adjacentPairs.size() + 1) {
		int cur = vRes.back(), prev = vRes[vRes.size() - 2];
		vector<int> curAdj = mAdj[cur];
		if (curAdj[0] != prev)
			vRes.push_back(curAdj[0]);
		else
			vRes.push_back(curAdj[1]);
	}
	return vRes;
    }
};

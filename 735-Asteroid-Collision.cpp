class Solution {
public:
	vector<int> asteroidCollision(vector<int>& asteroids) {
		vector<int> res;
		if (asteroids.empty()) return res;
		bool hasCollision = false;
		res = asteroids;
		do {
			hasCollision = false;
			vector<int> tmp;
			size_t first = 0;
			while (first<res.size() && res[first]==0) ++first; /* ignore 0 */
			if (first>=res.size()) break;
			auto sz = res.size();
			tmp.push_back(res[first]);
			for (auto i=first+1; i<sz; ++i) {
				if (res[i]==0) continue; /* ignore 0 */
				if ((res[i] < 0 && tmp.back() < 0) || 
					(res[i] > 0 && tmp.back() > 0) || 
					(tmp.back() < 0 && res[i] > 0)) {
					/* no collision */
					tmp.push_back(res[i]);
				}
				else {
					if (abs(tmp.back()) > abs(res[i])) /* do nothing, the small one explode */;
					else if (abs(tmp.back()) == abs(res[i])) {
						/* both explode */
						tmp.pop_back();
						if (tmp.empty()) { /* tmp should never empty because we call tmp.back() above as default */
							i += 1;
							if (i < res.size()) tmp.push_back(res[i]);
						}
					}
					else {
						/* the small one explode */
						tmp.pop_back();
						tmp.push_back(res[i]);
					}
					hasCollision = true;
				}
			}
			res.swap(tmp);
		} while (hasCollision && res.size()>1);
		return res;
    }
};

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		if (intervals.empty()) return vector<Interval>();
		sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start < b.start;});
		while (true)
		{
			bool flag = true;
			for (auto it = intervals.begin(); it != intervals.end() - 1; it++)
			{
				if (it->end >= (it + 1)->start)
				{
					if (it->end <= (it + 1)->end)//{[1,4], [2,3]}情况
						it->end = (it + 1)->end;
					intervals.erase(it + 1);
					flag = false;
					break;
				}
			}
			if (flag) break;
		}
		return intervals;
	}
};
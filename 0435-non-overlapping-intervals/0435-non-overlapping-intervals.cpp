class Solution {
public:

    static bool compare(const vector<int>& a, const vector<int>& b)
    {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), compare);

        int prev = 0;
        int count = 1;

        for(int i = 1; i < n; i++)
        {
            if(intervals[i][0] >= intervals[prev][1])
            {
                prev = i;
                count++;
            }
        }
        return n - count;
    }
};
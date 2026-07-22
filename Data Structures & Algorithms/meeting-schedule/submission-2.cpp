/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals){
        if(intervals.empty()) return true;

        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b){
                return a.start < b.start;
        });

        for(int i=0; i<intervals.size()-1; i++){
            Interval a = intervals[i];
            Interval b = intervals[i+1];
            if(b.start < a.end) return false;
        }
        return true;
    }
};

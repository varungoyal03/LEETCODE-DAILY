class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {  vector<vector<int>> finalTimeline;
      
        int currentIndex = 0;
        int totalIntervals = intervals.size();

        // Extract boundaries for crystal-clear readability
        int newStart = newInterval[0];
        int newEnd   = newInterval[1];

        // Phase 1: Zone 1 (Safe Left)
        // Skip all intervals where the current box ENDS before the new box STARTS
        while (currentIndex < totalIntervals && intervals[currentIndex][1] < newStart) {
            finalTimeline.push_back(intervals[currentIndex]);
            currentIndex++;
        }

        // Phase 2: Zone 2 (The Crash Zone / Merge)
        // Merge while the current box STARTS before or exactly when the new box ENDS
        while (currentIndex < totalIntervals && !(intervals[currentIndex][0] > newEnd )) {
            
            // The giant merged box takes the earliest start and the latest end
            newStart = min(newStart, intervals[currentIndex][0]);
            newEnd   = max(newEnd, intervals[currentIndex][1]);
            
            currentIndex++;
        }
        // Push the giant fused box into the timeline
        finalTimeline.push_back({newStart, newEnd});

        // Phase 3: Zone 3 (Safe Right)
        // Add all remaining boxes that were safely out of the way
        while (currentIndex < totalIntervals) {
            finalTimeline.push_back(intervals[currentIndex]);
            currentIndex++;
        }

        return finalTimeline;
    }
};
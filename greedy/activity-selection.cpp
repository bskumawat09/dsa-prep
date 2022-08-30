/*
https://practice.geeksforgeeks.org/problems/activity-selection-1587115620/1
*/

class Meeting {
public:
    int start;
    int end;

    Meeting(int s, int e) {
        start = s;
        end = e;
    }
};

bool comparator(const Meeting* m1, const Meeting* m2) {
    if(m1->end < m2->end)
        return true;
    return false;
}

class Solution {
public:
    int activitySelection(int start[], int end[], int n) {
        vector<Meeting*> meets(n);

        for(int i = 0; i < n; i++)
            meets[i] = new Meeting(start[i], end[i]);

        sort(meets.begin(), meets.end(), comparator);

        int ans = 0;
        int lastEndingTime = 0;

        for(int i = 0; i < n; i++) {
            if(meets[i]->start > lastEndingTime) {
                ans++;
                lastEndingTime = meets[i]->end;
            }
        }

        return ans;
    }
};

/*
Intuition:
Sort all the activities in accsending order of their end time.
Now iterate and check if current activity's (startTime > lastEndingTime).

Time    = O(N*logN)
Space   = O(N);
*/

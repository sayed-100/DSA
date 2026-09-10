class Solution {
public:
    bool can_we_place(vector<int>& position, int force, int balls)
    {
        int cnt_balls = 1;
        int last_ball = position[0];
        for(int i = 1; i < position.size(); i++)
        {
            if(position[i] - last_ball >= force)
            {
                cnt_balls++;
                last_ball = position[i];
            }
            if(cnt_balls >= balls) return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int low = 1, high = position[position.size() - 1]  - position[0];  
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(can_we_place(position, mid, m) == true)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return high;
    }
};
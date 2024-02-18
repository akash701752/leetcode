class Solution {
public:

    int mostBooked(int n, vector<vector<int>>& meetings) {
        
        if(meetings.size() < 2)
            return 0;
        
        
        sort(begin(meetings), end(meetings));

        vector<int> usage_count(n, 0);

        // since we only occupy room from available room so no worry about occupied size
        // size of occupied <= available_max_size(i.e n)
        //-----------long long is used since we do arithmetic with finish_time near line no 73-------//
        priority_queue<pair<long long, int>, 
                        vector<pair<long long, int>>, 
                        greater<>> occupied;

        priority_queue<int, vector<int>, greater<int>> available;

        // create a min heap for available rooms
        for(int room_no=0; room_no<n; room_no++) 
            available.push(room_no);

        for(auto &meeting: meetings)
        {
            int start_time = meeting[0];

            // make available all rooms which has ended meeting
            while(occupied.size())
            {
                // earliest end time 
                int end_time = occupied.top().first;
                if(end_time <= start_time)
                {
                    // empty the room
                    int room_no = occupied.top().second;
                    occupied.pop();

                    // make room available
                    available.push(room_no);
                }
                else
                {   // since there is no room to empty
                    break;
                }

            }

            // if room available then allocate room
            int room_no = -1;
            if(available.size()) // if room is empty and available for meeting
            {
                // get room from available heap
                room_no = available.top();
                available.pop();

                // set meeting in above room_no
                occupied.push({meeting[1], room_no});
            }
            else if(occupied.size()) // if rooms are busy
            {
                // set priority of current meeting ASAP after first available room
                
                // get earliest meeting end_time
                auto earliest_end = occupied.top().first;
                room_no = occupied.top().second; // the room that will get available earliest
                occupied.pop();

                // set earliest meeting start time for current meeting
                auto new_end_time = earliest_end + meeting[1] - meeting[0];

                // push into priority priority_queue
                occupied.push({new_end_time, room_no});

            }

            // if current meeting get a room choice then increment its usage counter
            if(room_no != -1)
                usage_count[room_no]++;

        }

        // get index of max usage
        int idx=-1;
        int maxVal = 0;
        for(int i=0; i<n; i++)
        {
            if(usage_count[i] > maxVal)
            {
                idx = i;
                maxVal = usage_count[i];
            }
        }        

        return idx;
        
    }
};

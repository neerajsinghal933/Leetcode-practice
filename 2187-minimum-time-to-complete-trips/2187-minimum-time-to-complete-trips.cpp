class Solution {
public:
    long long minimumTime(vector<int>& time, int tar) {
        long long mod = 1e9;
        long long n = time.size();
        sort(time.begin(), time.end());
        long long max_time = LONG_MAX;
        long long min_time = 0;
        // cout<<max_time;
        while(min_time <= max_time)
        {
            long long sum = 0;
            long long mid = (min_time+max_time)/2;
            for(long long x:time)
            {
                sum += (mid/x)%mod;
            }
            // if(sum==tar)
            //     return mid;
            if(sum<tar)
                min_time = mid+1;
            else
                max_time = mid-1;
        }
        return min_time;
    // }
        // long long n = time.size();
//         long long min_time = INT_MAX;
//         for(long long x:time)
//         {
//             min_time = min(min_time, ((long long)(tar%mod)*(x%mod))%mod);
//         }
//         cout<<min_time;
//         while(min_time)
//         {
//             long long sum = 0;
//             for(int x:time)
//             {
//                 sum += min_time/x;
//             }
//             if(sum==tar)
//                 return min_time;
            
//             min_time--;
//         }
//         return 1;
        // while(1)
        // {
        //     int i=1;
        //     long long sum = 0;
        //     for(int x:time)
        //     {
        //         sum += i/x;
        //     }
        //     if(sum==tar)
        //         return i;
        //     i++;
        // }
    }
};
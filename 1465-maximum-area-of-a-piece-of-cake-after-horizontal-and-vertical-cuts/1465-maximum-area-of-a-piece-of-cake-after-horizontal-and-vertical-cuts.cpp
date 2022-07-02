class Solution {
public:
    int maxArea(int h, int w, vector<int>& hori, vector<int>& veri) {
        int mod = 1e9+7;
        sort(hori.begin(), hori.end());
        sort(veri.begin(), veri.end());
        int hsz = hori.size();
        int vsz = veri.size();
        vector<int>a, b;
        a.push_back(hori[0]);
        b.push_back(veri[0]);
        for(int i=1;i<hsz;i++)
        {
            a.push_back(hori[i] - hori[i-1]);
        }
        a.push_back(h-hori[hsz-1]);
        for(int i=1;i<vsz;i++)
        {
            b.push_back(veri[i] - veri[i-1]);
        }
        // cout<<vsz<<endl;
        b.push_back(w-veri[vsz-1]);
        // for(int i=0;i<b.size();i++)
        //     cout<<b[i]<<" ";
        int first = *max_element(a.begin(), a.end());
        int second = *max_element(b.begin(), b.end());
        // cout<<first<<" "<<second;
        // return (long long)(first%mod*second%mod)%mod;
        return moduloMultiplication(first, second, mod);
    }
    
    long long moduloMultiplication(long long a, long long b,
                               long long mod)
    {
        long long res = 0; // Initialize result

        // Update a if it is more than
        // or equal to mod
        a %= mod;

        while (b) {
            // If b is odd, add a with result
            if (b & 1)
                res = (res + a) % mod;

            // Here we assume that doing 2*a
            // doesn't cause overflow
            a = (2 * a) % mod;

            b >>= 1; // b = b / 2
        }

        return res;
    }
};
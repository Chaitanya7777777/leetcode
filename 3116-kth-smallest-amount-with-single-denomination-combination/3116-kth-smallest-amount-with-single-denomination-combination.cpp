class Solution {
    
    long long gcd(long long a, long long b) {
        while (b) {
            long long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }
    long long countNumbers(long long x, vector<pair<long long, int>>& subsets) {
        
        long long count = 0;

        for (auto p : subsets) {
            long long L = p.first;
            int sign = p.second;

            if (L <= x) {
                count += sign * (x / L);
            }
        }

        return count;
    }

public:

    long long findKthSmallest(vector<int>& coins, int k) {

        int n = coins.size();

        vector<pair<long long, int>> subsets;
        for (int mask = 1; mask < (1 << n); mask++) {

            long long L = 1;
            int bits = 0;

            for (int i = 0; i < n; i++) {

                if (mask & (1 << i)) {
                    L = lcm(L, coins[i]);
                    bits++;
                }
            }

            if (bits % 2 == 1)
                subsets.push_back({L, 1});
            else
                subsets.push_back({L, -1});
        }
        long long low = 1;
        long long high = 1LL*k*(*min_element(coins.begin(), coins.end()));
        while (low < high) {

            long long mid = low + (high - low) / 2;

            if (countNumbers(mid, subsets) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};
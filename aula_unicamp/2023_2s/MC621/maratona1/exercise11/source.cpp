#include <bits/stdc++.h>

struct interval {
    long long lower_bound;
    long long upper_bound;
};


int main(void)
{
    long long t;
    std::cin >> t;

    for(int i{0}; i < t; i++){
        long long n, x;
        std::cin >> n >> x;
        interval intervals[n];
        long long a;
        for(long long j{0}; j < n; j++){
            std::cin >> a;
            long long aux1 = a - x;
            long long aux2 = a + x;
            intervals[j].lower_bound = ( aux1 < 0 ) ? 0 : aux1;
            intervals[j].upper_bound = aux2;
        }

        long long counter = 0;
        long long lower = 0, upper = 10e9;
        for(long long j{0}; j < n; j++){
            lower = ( lower < intervals[j].lower_bound ) ? intervals[j].lower_bound : lower;
            upper = ( upper < intervals[j].upper_bound ) ? upper : intervals[j].upper_bound;
            
            if( lower > upper ){
                counter++;
                lower = intervals[j].lower_bound;
                upper = intervals[j].upper_bound;
            }
        }

        std::cout << counter << std::endl;
    }

    return 0;
}
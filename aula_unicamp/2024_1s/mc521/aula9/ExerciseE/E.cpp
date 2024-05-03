#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while( t-- ){
        int n, k;
        vector<long long> numbers;
        numbers.clear();
        cin >> n >> k;
        for( int i{0}; i < n * k; ++i ){
            int tmp;
            cin >> tmp;
            numbers.push_back(tmp);
        }
        double start_d = ( ceil( (double) n / 2) - 1 ) * k,
               step_d = n - ceil( (double) n / 2);

        int start = (int) start_d,
            step = (int) step_d;
        
        // cout << start_d << endl;
        // cout << step_d << endl;

        // cout << "n: " << n << endl;
        // cout << "k: " << k << endl;
        // cout << "Start: " << start << endl;
        // cout << "Step: " << step << endl;

        long long sum = 0;
        step++;
        while( start < n*k ){
            sum += numbers.at(start);
            start += step;
        }
        cout << sum << endl;

        // cout << "----------------" << endl;

    }

    return 0;
}
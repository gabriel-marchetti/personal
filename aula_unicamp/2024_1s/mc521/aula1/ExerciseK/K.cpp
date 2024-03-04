#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    int rear_gears[55], pedal_gears[55];
    vector<double> ratios;
    double ratio;
    scanf("%d", &n);
    for( int i{0}; i < n; i++ )
        scanf("%d", &pedal_gears[i]);
    scanf("%d", &m);
    for( int i{0}; i < m; i++ )
        scanf("%d", &rear_gears[i]);

    for(int i{0}; i < n; i++ ){
        for( int j{0}; j < m; j++ ){
            ratio = (double) rear_gears[j] / pedal_gears[i];
            ratios.push_back(ratio);
        }
    }

    sort( ratios.begin(), ratios.end() );

    int index{0}, answer{0};
    double maximum_integer_ratio{0};
    for( int i{(int)ratios.size() - 1};  i >= 0; i-- ){
        if( ratios[i] == (int) ratios[i] ){
            index = i;
            maximum_integer_ratio = ratios[i];
            answer++;
            break;
        }
    }

    index--;
    while( ratios[index] == (int) ratios[index] 
    && ratios[index] == maximum_integer_ratio ){
        answer++;
        index--;
    }

    cout << answer << endl;

    return 0;
}
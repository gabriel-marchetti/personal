#include <bits/stdc++.h>

using namespace std;

int main(void){
    int t;
    while( cin >> t ){
        if( t == 0 ) break;
        double matrix[t+1][2];
        double leftSum{0}, rightSum{0};
        leftSum = 0; rightSum = 0;
        for( int i{0}; i < t; i++ ){
            cin >> matrix[i][0] >> matrix[i][1];
        }
        matrix[t][0] = matrix[0][0];
        matrix[t][1] = matrix[0][1];

        for( int j{0}; j < t; j++ ){
            rightSum = rightSum + matrix[j][0]*matrix[j+1][1];
            leftSum  = leftSum + matrix[j+1][0] * matrix[j][1];
        } 

        // cout << rightSum << ' ' << leftSum << endl;;
        if( rightSum > leftSum ){
            printf("CCW %.1f\n", (rightSum-leftSum)/2);
        } else{
            printf("CW %.1f\n", (-rightSum+leftSum)/2);
        }

    }

    return 0;
}
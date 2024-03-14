#include <bits/stdc++.h>

using namespace std;

class SegmentTree{
    private:
        vector<int> st, A;
        int n;
        int left(int p){ return p << 1; }
        int right(int p){ return ( p << 1 ) + 1; }

        void build(int p, int L, int R){
            if( L == R ){
                st[p] = L;
            } else{
                build(left(p), L, (L+R)/2 );
                build(right(p), (L+R)/2 + 1, R);

                int p1 = st[left(p)], p2 = st[right(p)];
                st[p] = ( A[p1] <= A[p2] ) ? p1 : p2;
        }}

        int rmq(int p, int L, int R, int i, int j){
            if( i > R || j < L ) return -1;
            if( L >= i && R <= j ) return st[p];

            int p1 = rmq( left(p),L, (L+R)/2, i, j );
            int p2 = rmq( right(p), (L+R)/2 + 1, R, i, j );

            if( p1 == -1 ) return p2;
            if( p2 == -1 ) return p1;
            return ( A[p1] <= A[p2] ) ? p1 : p2;
        }

    public:
        SegmentTree(const vector<int> &_A){
            A = _A;
            n = (int)A.size();
            st.assign( 4 * n, 0);
            build(1, 0, n-1);
        }

        int rmq(int i, int j){ return rmq(1, 0, n-1, i, j); }
};

int main(){
    int arr[] = { 18, 17, 13, 19, 15, 11, 20 };
    vector<int> A(arr, arr + 7);
    SegmentTree st(A);

    printf(" idx    0,  1,  2,  3,  4,  5,  6\n");
    printf(" A is   18, 17, 13, 19, 15, 11, 20\n");

    printf("RMQ(1, 3) = %d\n", st.rmq(1, 3));
    printf("RMQ(4, 6) = %d\n", st.rmq(4, 6));
    printf("RMQ(3, 4) = %d\n", st.rmq(3, 4));
    printf("RMQ(0, 0) = %d\n", st.rmq(0, 0));
    printf("RMQ(0, 1) = %d\n", st.rmq(0, 1));
    printf("RMQ(0, 6) = %d\n", st.rmq(0, 6));

    return 0;
}
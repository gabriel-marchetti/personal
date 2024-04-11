#include <bits/stdc++.h>

using namespace std;

int string_cmp( string str1, string str2 ){
    /**
     *  lambda function for string comparison
     * 
     *  return:
     *      1: if str1 is lexigraphicaly greater than str2
     *      0: if they are equal.
     *      -1: otherwise 
     */
    int smaller_size = min( str1.size(), str2.size() );
    for( int i = 0; i < smaller_size; ++i ){
        if( str1.at(i) == str2.at(i) )
            continue;
        else if( str1.at(i) > str2.at(i) )
            return 1;
        else
            return -1;
    }

    /**
     * If a string is a prefix of the other one 
     */
    if( str1.size() == str2.size() ){
        return 0;
    }
    if( str1.size() > str2.size() ){
        return 1;
    }
    return -1;
}

int main( ){
    string str1, str2;
    getline( cin, str1 );
    getline( cin, str2 );

    transform( str1.begin(), str1.end(), str1.begin(), ::tolower );
    transform( str2.begin(), str2.end(), str2.begin(), ::tolower );

    //cout << str1 << '\n';
    //cout << str2 << '\n';
    printf("%d\n", string_cmp(str1, str2));
    return 0;
}
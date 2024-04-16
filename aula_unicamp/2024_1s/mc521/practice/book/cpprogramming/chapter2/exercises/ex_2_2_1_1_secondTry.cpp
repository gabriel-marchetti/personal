#include <bits/stdc++.h>
using namespace std;

typedef struct{
    int age;
    string last_name;
    string first_name;
} person;

int str_cmp( string a, string b ){
    /**
     * Equal : 0
     * A lexicographicaly inferior to B : -1
     * otherwise : 1
     */
    int smaller_len = min( a.size(), b.size() );
    for( int i{0}; i < smaller_len; ++i ){
        if( a[i] < b[i] ) return -1;
        if( a[i] > b[i] ) return 1;
    }

    if( a.size() < b.size() ) return -1;
    if( a.size() > b.size() ) return 1;
    return 0;
}

int main(){
    person people[] = {
        {20, "Almeida", "Gabriel"},
        {20, "Almeida", "Bruno"},
        {20, "Ziraldo", "Cunha"},
        {20, "Almeida", "Gabriel"},
        {20, "Almeida", "Gabriel"}
    };
    
    // auto comparator = [&]( person a, person b ){
    //     if( a.age != b.age ){
    //         return a.age > b.age;
    //     }
    //     else if( str_cmp(a.last_name, b.last_name) != 0 ){
    //         int result = str_cmp( a.last_name, b.last_name );
    //         if( result == 1 )
    //             return true;
    //         else
    //             return false;
    //     }
    //     else{
    //         int result = str_cmp( a.first_name, b.first_name );
    //         if( result == 1 )
    //             return false;
    //         else
    //             return true;
    //     }
    // };

    auto comparator = [&]( person a, person b ){
        if( a.age != b.age ){
            return a.age > b.age;
        }
        else if( str_cmp( a.last_name, b.last_name ) != 0 ){
            return str_cmp( a.last_name, b.last_name ) > 0;
        }
        else{
            return str_cmp( a.first_name, b.first_name ) < 0;
        }
    };

    for( auto &[age, last_name, first_name] : people ){
        cout << age << ' ' << last_name << ' ' << first_name << endl;
    }
    cout << "================================" << endl;
    sort( people, people + 5, comparator );
    for( auto &[age, last_name, first_name] : people ){
        cout << age << ' ' << last_name << ' ' << first_name << endl;
    }


    return 0;
}
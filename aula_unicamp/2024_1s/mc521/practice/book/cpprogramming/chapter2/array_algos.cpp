#include <bits/stdc++.h>
using namespace std;

typedef struct {
    int id;
    int solved;
    int penalty;
} team;

bool icpc_cmp( team a, team b ){
    if( a.solved != b.solved ){
        return a.solved > b.solved;
    }
    else if( a.penalty != b.penalty ){
        return a.penalty < b.penalty;
    }
    else{
        return a.id < b.id;
    }
}

int main(){
    int arr[] = {10, 7, 2, 15, 4};
    vector<int> v(arr, arr+5);

    // Sorting in descending order;
    sort( v.rbegin(), v.rend() );
    // using the (auto &val : v) use reference iteration, that means that 
    // changing val will change the value of the original container
    // NOTE: Using ( auto val : v ) will use a copy of the element
    for( auto &val : v )
        printf("%d ", val);
    printf("\n");
    printf("==========================\n");

    // Sorting a Standar Array, i.e., a static array
    sort(arr, arr + 5);
    reverse(arr, arr + 5);
    for( int i{0}; i < 5; ++i )
        printf("%d ", arr[i]);
    printf("\n");
    printf("==========================\n");

    shuffle( v.begin(), v.end(), default_random_engine() );
    for( auto &val : v )
        printf("%d ", val);
    printf("\n");    
    printf("==========================\n");

    // Sorting a slice of the array
    partial_sort(v.begin(), v.begin() + 3, v.end());
    for( auto &val : v )
        printf("%d ", val);
    printf("\n");    
    printf("==========================\n");


    // Sorting team based on its result
    team maratona_interna[5] = { {1, 1, 10},
                                 {2, 8, 60},
                                 {3, 8, 60},
                                 {4, 3, 100},
                                 {5, 2, 80} };

    // Printing Array by its instantiation
    for( int i{0}; i < 5; ++i ){
        printf("id: %d, solved: %d, penalty: %d\n",
                maratona_interna[i].id, maratona_interna[i].solved,
                maratona_interna[i].penalty);
    } 
    printf("==========================\n");

    // Sorting based on lambda icpc_cmp
    sort(maratona_interna, maratona_interna + 5, icpc_cmp);
    for( int i{0}; i < 5; ++i ){
        printf("id: %d, solved: %d, penalty: %d\n",
                maratona_interna[i].id, maratona_interna[i].solved,
                maratona_interna[i].penalty);
    }
    printf("==========================\n");

    // Suposse that we have a competition that consists in teams of two people
    // and we sum the ages of them two! This results in the team id.
    typedef tuple<int, string, string> team;
    team A_team = make_tuple( 10, "Gabriel", "Sabrina" ),
         B_team = make_tuple( 20, "Bruno", "Thais" ),
         C_team = make_tuple( 20, "Maurizio", "Claudia" ),
         D_team = make_tuple( 5, "Andre", "Andreza" ),
         E_team = make_tuple( 0, "Eloah", "Julia" );

    vector<team> teams;
    teams.reserve(5);
    teams.push_back(A_team);
    teams.push_back(B_team);
    teams.push_back(C_team);
    teams.push_back(D_team);
    teams.push_back(E_team);

    // Testing with the c_str() method for strings.
    for( auto &[value, member1, member2] : teams ){
        // Another way of transforming a String to a char* is by doing 
        // char *c_str1 = &member1[0]
        // char *c_str2 = &member2[0]
        printf("Added Ages: %d, Members: %s and %s\n",
                value, member1.c_str(), member2.c_str());
    }
    printf("==========================\n");

    // Another way of doing this:
    for( auto &[value, member1, member2] : teams ){
        char *c_str1 = &(member1[0]);
        char *c_str2 = &(member2[0]);
        printf("Added Ages: %d, Members: %s and %s\n",
                value, member1.c_str(), member2.c_str());                
    }
    printf("==========================\n");

    // Sorting based on its points.
    sort( teams.rbegin(), teams.rend() );
    for( auto &[value, member1, member2] : teams ){
        printf("Added Ages: %d, Members: %s and %s\n",
                value, member1.c_str(), member2.c_str());
    }
    printf("==========================\n");

    // Now we are working with binary searchs.

    return 0;
}
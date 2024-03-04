#include <bits/stdc++.h>
#define MAX 5010

using namespace std;

struct team{
    int program_st, math_st, sportsman_st;
};

int main(){
    int num_students, read_student, teams_formed{0},
        index_program{0}, index_math{0}, index_sportsman{0};
    cin >> num_students;
    team teams[MAX];
    // Initialize teams
    for(int i{0}; i < num_students; i++){
        teams[i].math_st = 0;
        teams[i].program_st = 0;
        teams[i].sportsman_st = 0;
    }

    for(int i{0}; i < num_students; i++){
        cin >> read_student;
        
        if( read_student == 1 ){
            teams[index_program].program_st = i + 1;
            index_program++;
        } else if ( read_student == 2 ){
            teams[index_math].math_st = i + 1;
            index_math++;
        } else if ( read_student == 3 ){
            teams[index_sportsman].sportsman_st = i + 1;
            index_sportsman++;
        }
    }

    int i{0};

    while( teams[i].math_st != 0 && teams[i].program_st != 0 &&
           teams[i].sportsman_st != 0)
    {
            teams_formed++;
            i++;
    }
    cout << teams_formed << endl;

    i = 0;
    while( teams[i].math_st != 0 && teams[i].program_st != 0 &&
           teams[i].sportsman_st != 0
        ){
            cout << teams[i].program_st << ' ' << teams[i].math_st << ' ' 
            << teams[i].sportsman_st << endl;
            i++;
    }



    return 0;
}
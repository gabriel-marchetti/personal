#include <bits/stdc++.h>
using namespace std;

typedef struct{
    int age;
    string last_name;
    string first_name;
} person;

bool person_cmp( person a, person b ){
    if( a.age != b.age ){
        return a.age > b.age;
    }
    int comparison_last_name = a.last_name.compare(b.last_name);
    if( comparison_last_name != 0 ){
        if( comparison_last_name < 0 ){
            return a.last_name < b.last_name;
        }
        else{
            return a.last_name > b.last_name;
        }
    }
    int comparison_first_name = a.first_name.compare(b.first_name);
    if( comparison_first_name != 0 ){
        if( comparison_first_name < 0 )
            return a.first_name > b.first_name;
        else
            return a.first_name < b.first_name;
    }  
}

int main(){
    person people[] = { 
                        {19, "Gadelha", "Abrina"},
                        {18, "Alberto", "Lucas"},
                        {19, "Gadelha", "Sabrina"},
                        {18, "Balberto", "Geronimo"},
                        {19, "Gadelha", "Abrina"}
                        };
    for( auto &[age, last_name, first_name] : people ){
        cout << "Age: " << age << "\t\tLast name: " << last_name << "\tFirst Name: " << first_name << endl;
    }
    sort( people, people + 5, person_cmp );

    printf("===============================\n");
    // Expected-Order
    /**
     * {19, "Gadelha", "Sabrina"},
     * {19, "Gadelha", "Abrina"},
     * {19, "Gadelha", "Abrina"},
     * {18, "Alberto", "Lucas"},
     * {18, "Balberto", "Geronimo"}
     */
    for( auto &[age, last_name, first_name] : people ){
        cout << "Age: " << age << "\t\tLast name: " << last_name << "\tFirst Name: " << first_name << endl;
    }

    return 0;
}
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <string>

std::string getDayOfWeek(int day, int month, int year){
    std::string daysWeek[] = {"Sunday", "Monday", "Tuesday", 
                              "Wednesday", "Thursday", "Friday", "Saturday"};

    tm date{};
    date.tm_year = year - 1900;
    date.tm_mon = month - 1;
    date.tm_mday = day;

    time_t date_t = mktime( &date );
    int dayOfWeek = localtime(&date_t)->tm_wday;

    return daysWeek[dayOfWeek];
}

int timeElapsed(int day, int month, int year){
    tm pastDate{};
    pastDate.tm_mday = day;
    pastDate.tm_mon = month - 1;
    pastDate.tm_year = year - 1900;

    time_t now = time(0);
    tm *currentDate = localtime(&now);

    time_t pastDate_t = mktime(&pastDate);
    time_t currentDate_t = mktime(currentDate);

    double secondsElapsed = difftime(currentDate_t, pastDate_t);

    return secondsElapsed / ( 60 * 60 * 24 );
}

int main(){
    int day, month, year;
    scanf("%d/%d/%d", &day, &month, &year);

    std::string dayOfWeek = getDayOfWeek(day, month, year);
    int daysElapsed = timeElapsed(day, month, year);
    
    std::cout << "It was: " << dayOfWeek << '\n';
    printf("Days elapsed: %d\n", daysElapsed);
    printf("Years elapsed: %d\n", daysElapsed/365 );

    return 0;
}
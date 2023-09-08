#include <stdio.h>

int strLen(char string[])
{
    int i;
    for(i = 0; string[i] != '\n'; i++);
    return i;
}

int main()
{
    char str1[11], str2[11];
    int len1, len2;
    int plus1 = 0, plus2 = 0, minus1 = 0, minus2 = 0, unc1 = 0, unc2 = 0;
    double prob;
    
    for(int i = 0; i < len1; i++){
        if(str1[i] == '+') plus1++;
        if(str2[i] == '+') plus2++;
        if(str1[i] == '-') minus1++;
        if(str2[i] == '-') minus2++;
        if(str1[i] == '?') unc1++; // nao deve ocorrer.
        if(str2[i] == '?') unc2++;
    }
    int end1, end2;
    end1 = plus1 - minus1;
    end2 = plus2 - minus2;

    if (end1 == end2){
        prob = 1;
    } else {

    }

}
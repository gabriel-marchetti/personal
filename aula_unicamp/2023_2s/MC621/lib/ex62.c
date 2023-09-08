#include <stdio.h>

int strLen(char *string)
{
    int i;
    for(i = 0; string[i] != '\0'; i++);
    return i;
}

void recursionSolve(int dif, int cout, int numUnk, int iter, int *posCas, int *negCas)
{
    if( iter < numUnk ){
        recursionSolve(dif, cout+1, numUnk, iter+1, posCas, negCas);
        recursionSolve(dif, cout-1, numUnk, iter+1, posCas, negCas);
    } else {
        if ( dif == cout ){
            (*posCas)++; 
        } else {
            (*negCas)++;
        }
    }
}

int main()
{
    char str1[11], str2[11];
    int *pa, *po;
    scanf("%s", str1);
    scanf("%s", str2);

    int len = strLen(str1);

    int end1 = 0, end2 = 0;
    int unk = 0;
    for(int i = 0; i < len; i++){
        if(str1[i] == '+') end1++;
        if(str1[i] == '-') end1--;
        if(str2[i] == '+') end2++;
        if(str2[i] == '-') end2--;
        if(str2[i] == '?') unk++;
    }

    int dif = end1 - end2;
    int posCas = 0, negCas = 0;
    int cout = 0, iter = 0;

    recursionSolve(dif, 0, unk, 0, &posCas, &negCas);
    double prob = (double)posCas/(negCas+posCas);
    printf("%.12f\n", prob);

}
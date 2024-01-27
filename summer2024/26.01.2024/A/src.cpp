#include <bits/stdc++.h>
#define MAXN 200010

long long summation( long long array[MAXN], long long sizeArray, long long indexMaxDiffAbs, 
    bool signDiff 
    ){
    long long sum{0};
    long long whereWillBe{0};
    // Se for positivo, então vejo no sentido n, n-1, n-2, ...
    // Se for negativo, então vejo no sentido 1, 2, 3, ...
    if( signDiff ){
        std::cout << "Caso 1\n";
        for(long long i{sizeArray}; i >= 1; --i ){
            if( array[i] <= array[indexMaxDiffAbs] ){
                whereWillBe = i;
                break;
            }
            sum += i * array[i];
            std::cout << array[i] << '\n';
        }

        
        sum +=  whereWillBe * array[indexMaxDiffAbs];
        std::cout << array[indexMaxDiffAbs] << '\n';

        for( long long i{1}; i < indexMaxDiffAbs; ++i ){
            sum += i * array[i];
            std::cout << array[i] << '\n';
        }

        for( long long i{indexMaxDiffAbs}; i < whereWillBe; i++ ){
            sum += i * array[i + 1];
            std::cout << array[i+1] << '\n';
        }

    } else {
        std::cout << "Caso 2\n";
        for(long long i{1}; i <= sizeArray; ++i){
            if( array[indexMaxDiffAbs] < array[i] ){
                whereWillBe = i;
                break;
            }
            sum += i * array[i];
            std::cout << array[i] << '\n';
        }

        sum += whereWillBe * array[indexMaxDiffAbs];
        std::cout << array[indexMaxDiffAbs] << '\n';

        for( long long i{whereWillBe}; i < indexMaxDiffAbs; ++i ){
            sum += (i+1)*array[i];
            std::cout << array[i] << '\n';
        }

        for( long long i{indexMaxDiffAbs + 1}; i <= sizeArray; ++i ){
            sum += i * array[i];
            std::cout << array[i] << '\n';
        }

    }

    return sum;
}

int main(){
    long long sizeArray{0}, reader{0}, maxDiffAbs{0}, indexMaxDiffAbs{0};
    long long array[MAXN], differenceArray[MAXN];
    bool signDiff{0};
    std::cin >> sizeArray;
    for(long long i{1}; i <= sizeArray; ++i){
        std::cin >> reader;
        array[i] = reader;
        differenceArray[i] = reader - i;
        if( maxDiffAbs < std::abs(differenceArray[i]) ){
            maxDiffAbs = differenceArray[i];
            indexMaxDiffAbs = i;
        }
    }

    signDiff = true; // Assume it is positive.
    if( differenceArray[indexMaxDiffAbs] < 0 )
        signDiff = false; 

    long long answer = summation(array, sizeArray, indexMaxDiffAbs, signDiff);
    std::cout << answer << '\n';

    return 0;
}
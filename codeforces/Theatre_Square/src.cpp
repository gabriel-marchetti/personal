#include <iostream>

long long factor(int length, int division)
{
    if ( length % division > 0 ){
        return length / division + 1;
    } else {
        return length / division;
    }
}

int main()
{
    long long n{0}, m{0}, a{0};
    std::cin >> n >> m >> a;

    // long long n_factor  = (n + a - 1) / a; (Não entendi porque funciona...)
    // long long m_factor  = (n + a - 1) / a; (Não entendi porque funciona...)

    long long n_factor = factor(n, a);
    long long m_factor = factor(m, a);

    std::cout << n_factor * m_factor << std::endl;
    return 0;
}
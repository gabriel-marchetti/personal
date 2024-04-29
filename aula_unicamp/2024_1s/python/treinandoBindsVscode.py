def factorial( x : int ) -> int:
    # ! Unexpected case
    if( x < 0 ):
        # print('Factorial is not extended for negative numbers.')
        return -1
    # ! Base Case.
    if( x == 0 ):
        return 1
    return x * factorial( x - 1 )

if __name__ == '__main__':
    # * Running test cases for function fibonacci.
    print(factorial(3)) # Should be 6
    print(factorial(4)) # Should be 24
    print(factorial(5)) # Should be 120
    
    # ! Testing for cases that should not work
    print(factorial(-1)) # Should not work. Return -1
    print(factorial(-2)) # Should not work. Return -1
    
def checkDivisibility( number : int ) -> bool:
    # * False if divisible
    # * True if not divisible
    return ( number % 3 == 0 )

if __name__ == '__main__':
    print('What range do you want to print?')
    val = int(input())
    for val_i in range(val+1):
        if( checkDivisibility(val_i) ):
            continue
        print(val_i, end = ' ')
    print()
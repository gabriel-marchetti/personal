def accessJoe( name : str, password : str ) -> bool:
    if( name.lower() != 'joe' ):
        print('''You're not Joe, so you can't access this system.''')
        return False
    # * Name is equal to 'Joe', doesn't matter the case of letters.
    if( password == 'jellyfish' ):
        print('Access Granted')
        return True
    print('Wrong Password')
    return False

if __name__ == '__main__':
    name = ''
    password = ''
    flag = False
    while( True ):
        print('''What's your name: ''')
        name = input()
        print('Password: ')
        password = input()
        if( accessJoe(name, password) ):
            Flag = True
            break
    if( Flag ):
        print('Hello Joe, how can i help you?')
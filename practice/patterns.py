import sys

def square(N):
    """

        Prints a NxN square consisting of '*'

        e.g N = 4

        * * * *
        * * * *
        * * * *

    """

    # approach 1
    # for _ in range(N): # rows
    #     for _ in range(N): # columns
    #         print('*',end=' ')
    #     print()
    
    # approach 2
    for _ in range(N):
        print("* "*N)



def lt(N):

    """
    e.g. N = 5

      j  0 1 2 3 4
    i    
    0    *
    1    * *
    2    * * *
    3    * * * *
    4    * * * * *

    Key : Fill area where j <= i

    """

    # approach 1
    # for i in range(N):
    #     for j in range(N):
    #         if(j<=i):
    #             print("*",end=" ")
    #     print()

    # approach 2
    for i in range(N):
        print("* "*(i+1))


def ut(N):

    """
    e.g. N = 5

      j  0 1 2 3 4
    i    
    0    * * * * *
    1      * * * *
    2        * * *
    3          * *
    4            *

    Key : Fill area where j >= i

    """

    # approach 1
    # for i in range(N):
    #     for j in range(N):
    #         if(j>=i):
    #             print("*",end=" ")
    #         else:
    #             print(" ",end=" ")
    #     print()

    # approach 2
    for i in range(N):
        print(i*"  "+(N-i)*"* ")



def lt_inverted(N):

    """

    e.g. N = 5

      j  0 1 2 3 4
    i    
    0            *
    1          * *
    2        * * *
    3      * * * *
    4    * * * * *

    Key : 
        1. spaces : N-(i+1)
        2. * : i+1
        3. Fill area where j >= N-(i+1)

    """
    # approach 1
    # for i in range(N):
    #     for j in range(N):
    #         if(j>=N-(i+1)):
    #             print("*",end=" ")
    #         else:
    #             print(" ",end=" ")
    #     print()

    # approach 2
    for i in range(N):
        print("  "*(N-i-1)+"* "*(i+1))


def ut_inverted(N):

    """

    e.g. N = 5

      j  0 1 2 3 4
    i    
    0    * * * * *
    1    * * * *
    2    * * *
    3    * * 
    4    * 

    Key : 
        1. spaces : i
        2. * : N-i
        3. Fill area where j <= N-(i+1)

    """
    # approach 1
    # for i in range(N):
    #     for j in range(N):
    #         if(j<=N-(i+1)):
    #             print("*",end=" ")
    #         else:
    #             print(" ",end=" ")
    #     print()

    # approach 2
    for i in range(N):
        print("* "*(N-i)+"  "*i)


def pattern6(N):
    """

    e.g. N = 5

      j  1 2 3 4 5
    i    
    1    1
    2    1 2
    3    1 2 3
    4    1 2 3 4
    5    1 2 3 4 5 

    Key : output numbers <= i

    """

    # for i in range(1,N+1):
    #     for j in range(1,i+1):
    #         print(j,end=" ")
    #     print()

    for i in range(1,N+1):
        print(*[str(j) for j in range(1,i+1)])


def pattern7(N):
    """

    e.g. N = 5

      j  1 2 3 4 5
    i    
    1    1
    2    2 2
    3    3 3 3
    4    4 4 4 4
    5    5 5 5 5 5 

    Key : output "i" i times for each i

    """

    # for i in range(1,N+1):
    #     for _ in range(1,i+1):
    #         print(i,end=" ")
    #     print()

    for i in range(1,N+1):
        print(*list(str(i)*i))


def pattern8(N):
    """

    e.g. N = 5

      j  0 1 2 3 4
    i    
    0    1 2 3 4 5
    1    1 2 3 4
    2    1 2 3
    3    1 2 
    4    1 

    Key : output [1 to N-i] for every row

    """
    
    for i in range(N):
        for j in range(1,N-i+1):
            print(j,end=" ")
        print()


def pattern9(N):
    """

    e.g. N = 5

      j  1 2 3 4 5
    i    
    1        *
    2      * * *
    3    * * * * * 
 

    Key : 
        rows = N
        columns = (N*2)-1
        * : N-i < j < N+i
        space elsewhere

    """
    for i in range(1,N+1):
        for j in range(1,N*2):
            if(N-i < j < N+i):
                print("*",end="")
            else:
                print(" ",end="")
        print()



def pattern10(N):
    """

    e.g. N = 5

      j  1 2 3 4 5
    i    
    1    * * * * *
    2      * * *
    3        * 
 

    Key : 
        rows = N
        columns = (N*2)-1
        * : i-1 < j < 2*N-i+1
        space elsewhere

    """
    for i in range(1,N+1):
        for j in range(1,N*2):
            if(i-1 < j < 2*N-i+1):
                print("*",end="")
            else:
                print(" ",end="")
        print()


def pattern11(N):
    '''
            *    
           ***   
          *****  
         ******* 
        *********
        *********
         ******* 
          *****  
           ***   
            *       
    '''
    pattern9(N)
    pattern10(N)

def pattern12(N):
    '''
            * 
            * * 
            * * * 
            * * * * 
            * * * * * 
            * * * * 
            * * * 
            * * 
            * 
    '''
    for i in range(1,N+1):
        print("*"*i)
    for i in range(N-1,0,-1):
        print("*"*i)


def pattern13(N):
    """

    e.g. N = 5

      j  0 1 2 3 4
    i    
    0    1 
    1    0 1
    2    1 0 1
    3    0 1 0 1
    4    1 0 1 0 1

    Key : 
        output area : j<=i
        i+j even -> 1 else 0

    """

    for i in range(N):
        for j in range(N):
            if(j<=i):
                print("1",end=" ") if (i+j)%2 == 0 else print("0",end=" ")
        print()


def pattern14(N):
    """

    e.g. N = 5

      j  1 2 3 4 5 6 7 8
    i    
    1    1             1
    2    1 2         2 1 
    3    1 2 3     3 2 1
    4    1 2 3 4 4 3 2 1

    Key : 
        rows = N
        columns = 2*N
        For each Row: [i 2N-2i i]
    """

    for i in range(1,N+1):

        for j in range(1,i+1):
            print(j,end="")
        
        for _ in range(2*N - 2*i):
            print(" ",end="")
        
        for k in range(i,0,-1):
            print(k,end="")
        
        print()
        

def pattern15(N):

    '''
        1
        2 3
        4 5 6
        7 8 9 10
        11 12 13 14 15
    '''

    x = 1

    for i in range(N):
        for j in range(N):
            if (j<=i):
                print(x,end=" ")
                x+=1
        print()


def pattern16(N):
    
    '''
        A
        AB
        ABC
        ABCD
        ABCDE
    
        Key: 
            use ascii 
            N can range from [1-26]

    '''
    for i in range(N):
        x = 65
        for j in range(N):
            if (j<=i):
                print(chr(x),end="")
                x+=1
        print()


def pattern17(N):
  
    """

    e.g. N = 5

      j  0 1 2 3 4
    i    
    0    A B C D E
    1    A B C D
    2    A B C
    3    A B 
    4    A 

    Key : 
        Fill area where j <= N-(i+1)

    """

    for i in range(N):
        x = 65
        for j in range(N):
            if (j<=N-(i+1)):
                print(chr(x),end="")
                x+=1
        print()


def pattern18(N):

    '''
        A
        BB
        CCC
        DDDD
        EEEEE
    '''

    x = 65

    for i in range(N):
        print(chr(x)*(i+1),end="")
        print()
        x+=1


def pattern19(N):
    """

    e.g. N = 5

      j  0 1 2 3 4
    i    
    0        A
    1      A B A
    2    A B C B A 

    Key:
        spaces: N-1-i
        characters: 2*i+1
        increment: 2*i+1-i
        decrement: i
 
    """

    for i in range(N):

        alphabets = 2*i+1

        for _ in range(N-1-i):
            print(" ",end=" ")
        
        x = 65

        # for j in range(2*i+1-i):
        #     print(chr(x),end=" ")
        #     if(j<i):
        #         x+=1

        # for _ in range(i):
        #     x-=1
        #     print(chr(x),end=" ")

        for j in range(2*i+1):
            print(chr(x),end=" ")
            if (j<alphabets//2):
                x+=1
            else:
                x-=1
            

        for _ in range(N-1-i):
            print(" ",end=" ")

        print()
        

def pattern20(N):

    '''
        E 
        D E 
        C D E 
        B C D E 
        A B C D E 
    '''
    
    for i in range(N):
        x = 65
        x+= N-1-i
        for j in range(N):
            if(j<=i):
                print(chr(x),end=" ")
                x+=1
        print()


def pattern21_top(N):

    '''
        **********
        ****  ****
        ***    ***
        **      **
        *        *
    '''
    
    for i in range(N):

        for _ in range(N-i):
            print("*",end="")

        for _ in range(2*i):
            print(" ",end="")
    
        for _ in range(N-i):
            print("*",end="")
        
        print()

        
def pattern21_bottom(N):

    '''
        *        *
        **      **
        ***    ***
        ****  ****
        **********
    '''
   
    for i in range(1,N+1):

        for _ in range(1,i+1):
            print("*",end="")
        
        for _ in range(2*N - 2*i):
            print(" ",end="")
        
        for _ in range(i,0,-1):
            print("*",end="")
        
        print()
        
def pattern21(N):

    '''
        **********
        ****  ****
        ***    ***
        **      **
        *        *
        *        *
        **      **
        ***    ***
        ****  ****
        **********
    '''

    pattern21_top(N)
    pattern21_bottom(N)


def pattern21_top_modified(N):

    '''
        ****  ****
        ***    ***
        **      **
        *        *
    '''
    
    for i in range(N):
        if i == 0: continue
        for _ in range(N-i):
            print("*",end="")

        for _ in range(2*i):
            print(" ",end="")
    
        for _ in range(N-i):
            print("*",end="")
        
        print()

def pattern22(N):
    '''
        *        *
        **      **
        ***    ***
        ****  ****
        **********
        ****  ****
        ***    ***
        **      **
        *        *
    '''
    pattern21_bottom(N)
    pattern21_top_modified(N)

def hollow_square(N):
    '''
        * * * * * 
        *       * 
        *       * 
        *       * 
        * * * * * 
    '''
    for i in range(N):
        for j in range(N):
            if(i>0 and i<N-1 and j>0 and j<N-1):
                print(" ",end=" ")
            else:
                print("*",end=" ")
        print()


def pattern23(N):

    '''
        4 4 4 4 4 4 4           0 0 0 0 0 0 0
        4 3 3 3 3 3 4           0 1 1 1 1 1 0
        4 3 2 2 2 3 4           0 1 2 2 2 1 0
        4 3 2 1 2 3 4   ---->   0 1 2 3 2 1 0
        4 3 2 2 2 3 4           0 1 2 2 2 1 0 
        4 3 3 3 3 3 4           0 1 1 1 1 1 0 
        4 4 4 4 4 4 4           0 0 0 0 0 0 0

        Key:
            4 - currMatrix = NewMatrix
            values in NewMatrix are min distances
            4 - min distances = currMatrix
    '''
    size = 2*N-1

    for i in range(2*N-1):
        for j in range(2*N-1):
            min_distance = min(i,j,size-i-1,size-j-1)
            print(N-min_distance,end=" ")
        print()

if __name__ == "__main__":

    for line in sys.stdin:
        pattern23(int(line.strip()))
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
                print("*",end=" ")
            else:
                print(" ",end=" ")
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
                print("*",end=" ")
            else:
                print(" ",end=" ")
        print()




if __name__ == "__main__":

    for line in sys.stdin:
        pattern10(int(line.strip()))
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



if __name__ == "__main__":

    for line in sys.stdin:
        square(int(line.strip()))
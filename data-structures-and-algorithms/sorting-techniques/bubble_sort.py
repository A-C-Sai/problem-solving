
def swap(lst,i,j):
    lst[i],lst[j] = lst[j],lst[i]

def bubble_sort(lst):

    '''
        Max : O(n^2)
        Min : O(n) -> sorted list; n-1 comparisons, 0 swaps (only 1 pass required)
        Bubble sort is a stable algorithm
    '''  

    for i in range(len(lst)-1): # n-1 passes
        swap_done = 0
        for j in range(len(lst)-1-i): # compare two adjacent elements
            if(lst[j]>lst[j+1]):
                swap_done = 1 
                swap(lst,j,j+1)
            
        if swap_done == 0: break # Adaptive



if __name__ == "__main__":
    bubble_sort([8,5,7,3,2])



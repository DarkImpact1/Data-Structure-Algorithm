# a function to sort the array using QuickSort
def QuickSort(array):
  # termination condition 
    if len(array) <=1:
        return array
      
    # selecting the pivot element from the array to find it's correct position
    pivot = array[0]

    # printing the initial array which have to be sorted
    print(f"initial array {array}")

    # parititioning the array in which all the smaller number are separated and assigned to another array name left_partition
    left_partition = [i for i in array[1:] if i<=pivot]
    print(f"left partition {left_partition}")

    # parititioning the array in which all the greater number are separated and assigned to another array name right_partition
    right_partition = [i for i in array[1:] if i > pivot]
    print(f"right partition {right_partition}")

    #using recursive call to sort the left_partition and right partition 
    sorted_left_partition = QuickSort(left_partition)
    sorted_right_partition = QuickSort(right_partition)

    # finally returning the sorted array 
    return sorted_left_partition + [pivot] + sorted_right_partition

unsorted = [5,2,6,1,4,8,9,10,7]
print(QuickSort(unsorted))

def median_of_medians(A, i):

    #divide A into sublists of len 5
    print "A:\t", A, "\t\tI:\t",i
    sublists = [A[j:j+5] for j in range(0, len(A), 5)]
    medians = [sorted(sublist)[len(sublist)/2] for sublist in sublists]
    print "sublists:\t", sublists
    print "medians:\t", medians
    if len(medians) <= 5:
        pivot = sorted(medians)[len(medians)/2]
    else:
        #the pivot is the median of the medians
        pivot = median_of_medians(medians, len(medians)/2)

    #partitioning step
    low = [j for j in A if j < pivot]
    high = [j for j in A if j > pivot]

    k = len(low)
    if i < k:
        return median_of_medians(low,i)
    elif i > k:
        return median_of_medians(high,i-k-1)
    else: #pivot = k
        return pivot

#Here are some example lists you can use to see how the algorithm works
A = [1,2,3,4,5,1000,8,9,99]
B = [1,2,3,4,5,6]
print median_of_medians(A, 0) #should be 1
print median_of_medians(A,7) #should be 99
print median_of_medians(B,4) #should be 5


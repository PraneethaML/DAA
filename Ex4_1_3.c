#include <time.h>
#include <stdio.h>
#include <limits.h>

#define CROSSOVER   28

/* structure to store the result */
typedef struct {
    int left;
    int right;
    int sum;
} maxSubarray;

/* brute force method */
maxSubarray maxSubarray_bf(int A[], int l, int h)
{
    int i, j, temp_sum;
    maxSubarray ret = {0, 0, INT_MIN};
    
    for (i = l; i < h; i++) {
        temp_sum = 0;
        for (j = i; j < h; j++) {
            temp_sum += A[j];
            if (temp_sum > ret.sum) {
                ret.sum = temp_sum;
                ret.left = i;
                ret.right = j + 1;
            }
        }
    }
    return ret;
}

/* function for finding crossing maximum sub-array */
maxSubarray maxCrossingSubarray(int A[], int l, int m, int h)
{
    int i, j;
    maxSubarray ret = {0, 0, 0};
    int left_sum = INT_MIN;
    int right_sum = INT_MIN;
    int sum = 0;
    
    for (i = m - 1; i >= l; i--) {
        sum += A[i];
        if (sum > left_sum) {
            left_sum = sum;
            ret.left = i;
        }
    }
    
    sum = 0;
    for (j = m; j < h; j++) {
        sum += A[j];
        if (sum > right_sum) {
            right_sum = sum;
            ret.right = j + 1;
        }
    }
    ret.sum = left_sum + right_sum;
    
    return ret;
}

/* recursive method */
maxSubarray maxSubarray_rc(int A[], int l, int h)
{
    if (h == l + 1) {
        maxSubarray ret = {l, h, A[l]};
        return ret;
    } else {
        int m = (l + h) / 2;
        maxSubarray left = maxSubarray_rc(A, l, m);
        maxSubarray right = maxSubarray_rc(A, m, h);
        maxSubarray cross = maxCrossingSubarray(A, l, m, h);
        
        if (left.sum >= right.sum && left.sum >= cross.sum)
            return left;
        else if (right.sum >= left.sum && right.sum >= cross.sum)
            return right;
        else
            return cross;
    }
}

/* modified mixed method */
maxSubarray maxSubarray_mx(int A[], int l, int h)
{
    if (h - l < CROSSOVER) {
        return maxSubarray_bf(A, l, h);
    } else {
        int m = (l + h) / 2;
        maxSubarray left = maxSubarray_rc(A, l, m);
        maxSubarray right = maxSubarray_rc(A, m, h);
        maxSubarray cross = maxCrossingSubarray(A, l, m, h);
        
        if (left.sum >= right.sum && left.sum >= cross.sum)
            return left;
        else if (right.sum >= left.sum && right.sum >= cross.sum)
            return right;
        else
            return cross;
    }
}

/* driver code to measure performance */
int main()
{
    int i, n = 2, flag = 0;
    int A[100] = {20, -21, 43, 23, -92, 45, -56, -5, 34, -17,
                    34, 65, 8, 9, 125, 2, -10, 89, 46, 65, -49, 
                    3, -45, 34, 76, 32, -76, -2, 3, 45, 44, 34, 67, 
                    -67, 99, 10, 11, -37, 44, 76, -90, 89, -32, 34, 
                    88, 56, -6, -89, -90, -34, -56, 23, 29, 2, 6, 9, 
                    2, -34, -45, 34, 22, 177, 44, 90, -45, -36, 55, 
                    23, 56, -56, -167, -54, 23, 45, 14, 62, -46, -56, 
                    -34, 45, 32, 20, -87, 39, 82, 94, -67, -45, 88, 
                    -36, 21, 18, 16, 81, -102, 99, -45, 67, 45, 76};
    
    clock_t start, stop;
    double time_bf, time_rc, time_mx;

    printf("Size BruteForce Recursive Mixed\n");
    printf("-------------------------------\n");
	
	
    while(!flag) {
        start = clock();
        for (i = 0; i < 1000000; i++) {
            maxSubarray R1 = maxSubarray_bf(A, 0, n);
        }
        stop = clock();
        time_bf = ((double) (stop - start)) / CLOCKS_PER_SEC;
        
        start = clock();
        for (i = 0; i < 1000000; i++) {
            maxSubarray R2 = maxSubarray_rc(A, 0, n);
        }
        stop = clock();
        time_rc = ((double) (stop - start)) / CLOCKS_PER_SEC;
		
        start = clock();
        for (i = 0; i < 1000000; i++) {
            maxSubarray R1 = maxSubarray_mx(A, 0, n);
        }
        stop = clock();
        time_mx = ((double) (stop - start)) / CLOCKS_PER_SEC;
		
       
		printf("%d\t\t%f\t\t%f\t\t%f\n",n,time_bf,time_rc,time_mx);
        n++;
        if (time_bf > time_rc) {
            flag = 1;
		
		
        }
    }

    return 0;
}

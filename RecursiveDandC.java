
public class RecursiveDandC {
   
    int maxSum = Integer.MIN_VALUE;   
    public int maxSubArray(int[] A) {
        return maxSubArray(A, 0, A.length - 1);
    }
    
    int maxSubArray(int[] A, int left, int right) {
        if (left > right) {
            return Integer.MIN_VALUE;
        }
        
        int mid = (left + right)  / 2;
        int leftMax = maxSubArray(A, left, mid - 1);
        int rightMax = maxSubArray(A, mid + 1, right);
        maxSum = Math.max(maxSum, leftMax);
        maxSum = Math.max(maxSum, rightMax);
        
        // across mid
        int leftSum = 0;       
        int currSum = 0;
        for (int i = mid - 1; i >= left; i--) {
            currSum += A[i];
            leftSum = Math.max(leftSum, currSum);
        }
        int rightSum = 0;
        currSum = 0;
        for (int i = mid + 1; i <= right; i++) {
            currSum += A[i];
            rightSum = Math.max(rightSum, currSum);
        }
        maxSum = Math.max(maxSum, leftSum + A[mid] + rightSum);
        
        return maxSum;
    }
}
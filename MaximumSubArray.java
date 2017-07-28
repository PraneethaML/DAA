import java.util.Scanner;

public class MaximumSubArray {
	public static void main(String args[]){
		
		RecursiveDandC sol= new RecursiveDandC();
		Scanner s = new Scanner(System.in);
		System.out.println("Enter array size");
		int n = s.nextInt();
	   
		int[] A = new int[n];
		System.out.println("enter array elements");
		for (int i=0; i<A.length; i++)
	    {
	      A[i]=s.nextInt();
	    }
		
		sol.maxSubArray(A);
	   System.out.println(sol.maxSum);
	}

}

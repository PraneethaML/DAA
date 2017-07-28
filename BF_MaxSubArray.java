import java.util.Scanner;

public class BF_MaxSubArray {
	
	
	

	//private int ans;

	public static void main(String args[]){

		BF_MaxSubArray msa= new BF_MaxSubArray();
		Scanner s = new Scanner(System.in);
		System.out.println("Enter array size");
		int n = s.nextInt();
	   
		int[] A = new int[n];
		System.out.println("enter array elements");
		for (int i=0; i<n; i++)
	    {
	      A[i]=s.nextInt();
	    }
		
		msa.maxSum(A,n);
	   System.out.println(msa.maxSum(A,n));
	
	}

	public  int maxSum(int A[],int n)
	{
		int ans=Integer.MIN_VALUE;
	    
	    
		for(int i = 0;i<n;i++)
	    {
	       int  sum = 0;
	        for(int j=i;j<n;j++)
	        {
	        	
	            sum = sum + A[j];
	            ans=Math.max(ans,sum);
	        }
	    }
	    return ans;


}
}
	

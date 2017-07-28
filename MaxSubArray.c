#include<stdio.h>

#include<math.h>
#include<limits>


void main(){
int i,j,m,n,sum=0,ans=INT_MIN;
printf("Enter size of array");
scanf("%d",&n);
printf("Enter array elements");
for(m=0;m<n;m++)
{
	scanf("%d",&arr[m])
}
int BF_Maximum_Sum_Subarray(int arr[],int n)
{
	
	for(i = 0;i< n; i++)						
	{
		int sum = 0;
		for(j = 1;j <= n; j++)	
		{
			if(i+j > n)
				break;
			sum+= arr[i + j - 1];	
			ans = max(ans,sum);
		}
	}
	return ans;
}

printf("ans=%d",ans);
}
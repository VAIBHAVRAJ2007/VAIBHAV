import java.util.Scanner;
class Sort{
	public static void main(String []args)
	{
		int i,j,n;
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter range: ");
		n=sc.nextInt();
		int arr[ ] = new int[n];
		for(i=0;i<n;i++){
			System.out.print("Enter a number:");
			arr[i]=sc.nextInt();
		}
		System.out.print("Array elements before sorting:");
		for(int x : arr)
		{
			System.out.print(x + "  ");
		}
		for(i=1;i<=n-1;i++)
		{
			for(j=0;j<n-i;j++)
			{
				if(arr[j]>arr[j+1])
				{
					int temp;
					temp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = temp;
				}
			}
		}
		System.out.print("\nArray elements after sorting:");
		for(int x : arr)
		{
			System.out.print(x + "  ");
		}
	}
}
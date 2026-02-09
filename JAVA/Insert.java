import java.util.Scanner;
class Insert{
	public static void main(String [] args)
	{
		int arr[ ] = new int [5];
		Scanner sc = new Scanner(System.in);
		int i,p,v;
		for(i=0;i<5;i++){
			System.out.print("Enter a number:");
			arr[i] = sc.nextInt();
		}
		System.out.print("Array elements are:");
		for(int x : arr)
			System.out.print(x + "  ");
		System.out.print("\nEnter positon:");
		p = sc.nextInt();
		System.out.print("Enter value:");
		v = sc.nextInt();
		for(i=0;i<5;i++)
		{
			if(
		}
		arr[p-1]=v;
		System.out.print("Array elements are:");
		for(int x : arr)
			System.out.print(x + "  ");
	}

}
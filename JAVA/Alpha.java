import java.util.Scanner;

class Alpha{
	public static void main(String []args)
	{
		char ch;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter a symbol: ");
		ch = sc.next().charAt(0);
		if(ch>=65 && ch<=90 || ch>=97 && ch<=122)
		{
			if(ch==65 || ch==69 || ch==73 || ch==79 || ch==85)
			{
				System.out.println(ch+" is a vowel.");
			}
			else if(ch==97 || ch==101 || ch==105 || ch==111 || ch==117)
			{
				System.out.println(ch+" is a vowel.");
			}
			else
			{
				System.out.println(ch+" is a consonant.");
			}
		}
		else {
			System.out.println("Not a alphabet.");
		}
	}
}
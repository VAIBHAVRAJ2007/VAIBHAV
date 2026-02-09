import java.util.Scanner;

class Calculator {
	public static void main(String[] st) {
		int ch, a, b;
		Scanner sc = new Scanner(System.in);
		System.out.println("Calculator:");
		do {
			
			System.out.println("Please choose a option:");
			System.out.println("1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.Remainder\n6.Exit");
			ch = sc.nextInt();
			switch (ch) {
				case 1:
					System.out.println("Enter a : ");
					a = sc.nextInt();
					System.out.println("Enter b : ");
					b = sc.nextInt();
					System.out.println("Result: " + (a + b));
					break;
				case 2:
					System.out.println("Enter a : ");
					a = sc.nextInt();
					System.out.println("Enter b : ");
					b = sc.nextInt();
					System.out.println("Result: " + (a - b));
					break;
				case 3:
					System.out.println("Enter a : ");
					a = sc.nextInt();
					System.out.println("Enter b : ");
					b = sc.nextInt();
					System.out.println("Result: " + (a * b));
					break;
				case 4:
					System.out.println("Enter a : ");
					a = sc.nextInt();
					System.out.println("Enter b : ");
					b = sc.nextInt();
					System.out.println("Result: " + (a / b));
					break;
				case 5:
					System.out.println("Enter a : ");
					a = sc.nextInt();
					System.out.println("Enter b : ");
					b = sc.nextInt();
					System.out.println("Result: " + (a % b));
					break;
				case 6:
					System.exit(0);
					break;
				default:
					System.out.println("Invalid operation.");
			}
		} while (true);
	}
}
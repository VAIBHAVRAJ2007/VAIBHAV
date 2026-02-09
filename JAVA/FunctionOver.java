import java.util.Scanner;
class FunctionOver
{
	public static void main(String [] args)
	{
		int a,b;
		double c;
		Overloading1 ovl = new Overloading1();
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter a Integer A = ");
		a=sc.nextInt();
		System.out.println("Enter a Integer B = ");
		b=sc.nextInt();
		System.out.println("Enter a Double C = ");
		c=sc.nextDouble();
		ovl.setValue(a,b);
		ovl.setValue(a,c);
		ovl.setValue(a);
		ovl.setValue();
		Overriding1 ovr;
		ovr = new Overriding3();
		ovr.f1();
	}	
}
class Overloading1
{
	void setValue(int x, int y)
	{
		int a;
		int b;
		a=x;
		b=y;
		System.out.println("Integer a = "+a);
		System.out.println("Integer b = "+b);
	}
	void setValue(int x, double y)
	{
		int a;
		double c;
		a=x;
		c=y;
		System.out.println("Integer a = "+a);
		System.out.println("Double c = "+c);
	}
	void setValue(int x)
	{
		int a;
		a=x;
		System.out.println("Integer a = "+a);
	}
	void setValue(double y)
	{
		double c;
		c=y;
		System.out.println("Double c = "+c);
	}
	void setValue()
	{
		int a = 10, b = 20;
		System.out.println("a = "+a);
		System.out.println("b = "+b);
	}
}


class Overriding1
{
	void f1()
	{
		System.out.print("Hello, my ");
	}
}
class Overriding2 extends Overriding1
{
	void f1()
	{
		super.f1();
		System.out.print("name is ");
	}
}
class Overriding3 extends Overriding2
{
	void f1()
	{
		super.f1();
		System.out.print("Vaibhav Raj.");
	}
}
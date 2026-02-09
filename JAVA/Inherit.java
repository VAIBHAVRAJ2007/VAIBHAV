class Parent
{
	private int a,b;
	void fun1()
	{
		System.out.println("Parent function1 executed.");
	}
	void fun2()
	{
		System.out.println("Parent function2 executed.");
		System.out.println(a + " " + b);
	}
	Parent(int p, int q)
	{
		System.out.println("Parent constructor executed 1.");
		a=p;
		b=q;
		System.out.println("Parent constructor executed 2.");
	}
}
class Child extends Parent
{
	int c,d;
	void fun3()
	{
		System.out.println("Child function3 executed.");
	}
	Child()
	{
		System.out.println("Child constructor executed 1.");
		super(1,10);
		System.out.println("Child constructor executed 2.");
	}
}
class Inherit
{
	public static void main(String args [ ])
	{
		Child c1 = new Child();
		c1.fun1();
		c1.fun2();
		c1.fun3();
	}
}
class Parent
{
	int x=5,y=10;
	void fun1(int x, int y)
	{
		this.x = x;				//differentiate instance variable from local variable
		this.y = y;
	}
	void fun2()
	{
		System.out.println("Parent x = "+x);
		System.out.println("Parent y = "+y);
	}
	void fun3()
	{
		System.out.println("super function");
		this.fun4();					//call current class method
	}
	void fun4()
	{
		System.out.println("this function");
	}
}
class Child extends Parent
{
	int x=20;
	void showP()
	{
		super.fun3();				//call parent class method
		System.out.println("Super Parent x = "+super.x);
		System.out.println("Super Parent y = "+super.y);
	}
}
class ThisKey
{
	public static void main(String args[])
	{
		Child c1 = new Child();
		c1.fun2();
		c1.fun1(1,2);
		c1.fun2();
		c1.showP();	
	}
}
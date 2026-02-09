class Base{
	int a;
	void show()
	{
		System.out.println("Base1");
	}
	//Base(int x)
	//{
	//	a=x;
	//	System.out.println("a = "+a);
	//}
}
class Derived extends Base{
	void show()
	{
		
		System.out.println("Derived");
		super.show();
	}
	//Derived()
	//{
		//super(5);
	//	System.out.println("Derived Class");
		//super(50);
	//}
}
class Inherit1{
	public static void main(String [ ] args)
	{
		//Derived d = new Derived();
		//d.show();
		Base b;
		b = new Base();
		b.show();
		b = new Derived();
		b.show();
	}
}
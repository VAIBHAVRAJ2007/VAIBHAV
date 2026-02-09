class WrapPrint
{
	int x,y;
	float z;
	void fun1()
	{
		String s1 = "123";
		Integer i1 = Integer.valueOf("10101",2);
		y = i1.intValue();
		
		Float d1= Float.valueOf(254);
		z=d1.floatValue();
						

		x = Integer.parseInt(s1);
	}
	void print()
	{
		System.out.println(x);
		System.out.println(y);
		System.out.println(z);
	}
}


class Wrap
{
	public static void main(String [] args)
	{
		 WrapPrint w1 = new WrapPrint();
	     	w1.fun1();
		w1.print();
	}
}
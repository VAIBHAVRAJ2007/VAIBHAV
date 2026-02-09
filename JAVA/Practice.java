class School
{
	static void fun1()           //static member function
	{
		String name="raj";    //static member variable
		int roll=12469;           //static member variable
		System.out.print(name + " " +roll+" ");

	}
}

class College
{ 
	String name;
	int roll;
	void fun1()
	{
		name="Rahul";
		roll=12447;
		System.out.print(name + " " +roll+" ");

	}
	void fun2()
	{
		name="Ronny";
		roll=12546;
		System.out.print(name + " " +roll+" ");

	}
}
class Practice
{
	public static void main(String []args)
	{
		//School details1 = new School();
		College details2 = new College();
		School.fun1();
		details2.fun1();
		details2.fun2();
		details2.name ="Raju";
		System.out.println(details2.name);
		
	}
}
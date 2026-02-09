class Fibonacci{

	static void fib(int num){
		int n1=1;
		int n2=1;
		int n3;
		System.out.print("Fibonacci series : "+n1+" "+n2+" ");
		for(int i=3;i<=num;i++)
		{
			n3=n1+n2;
			System.out.print(n3+" ");
			n1=n2;
			n2=n3;
		}
	}

	public static void main(String [] args){
		int n=10;
		//Fibonacci f = new Fibonacci();
		fib(n);
	}
}
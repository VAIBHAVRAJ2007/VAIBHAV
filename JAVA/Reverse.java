class Palindrome{
	int palin(int num){
		int rem,rev=0;
		while(num!=0){
			rem=num%10;
			rev = rev*10+rem;
			num/=10;
		}
			return rev;
	}
	void palin1(int rev,int num){	
		if(rev==num)
			System.out.println("Given number "+num+" is palindrome."); 
		else
			System.out.println("Given number "+num+" is not palindrome."); 
	}
	public static void main(String []args){
		int num=121,rev;
		Palindrome r = new Palindrome();
		rev=r.palin(num);
		r.palin1(rev,num);
		System.out.println("Reverse of the number: "+rev);
	}
}
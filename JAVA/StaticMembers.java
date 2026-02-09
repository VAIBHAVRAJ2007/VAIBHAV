class A {
    private  int x;
    private static int y;         //static member can be accessed without using object by using static function

    //private variable accessed by using function

    void fun1() {
        y = 22;
	x=5;
    }

    void fun3() {
        y = 45;
    }

    void fun2() {
        System.out.println(y);
	 System.out.println(x);
    }
}

class StaticMembers {
    public static void main(String[] args) {
        A a1 = new A();
        A a2 = new A();
        a1.fun1();
        //a2.fun3();
        a2.fun2();
    }
}

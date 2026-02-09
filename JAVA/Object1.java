class Example {
    int x; // instance(object) member variable
    int y; // instance(object) member variable

    void fun1() // instance(object) member function
    {
        System.out.println("fun1");
    }

    void fun2() // instance(object) member function
    {
        System.out.println("fun2");
    }

}

class Object1 {
    public static void main(String[] args) {
        System.out.println("main");
        Example e1 = new Example();
        Example e2 = new Example();
        e1.fun1();
        e2.fun2();
        e1.x = 5;
        e2.x = 50;
        System.out.println(e1.x);
        // System.out.println(e1.y);
        System.out.println(e2.x);
    }

}

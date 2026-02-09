class Area {
    static void fun1() // static member function
    {
        System.out.println("Area1");
    }

    static void fun2() {
        System.out.println("Area2");
    }
}

class Example {
    static void fun1() {
        System.out.println("A");
    }

    static void fun2() {
        System.out.println("B");
    }

    public static void main(String[] args) {
        System.out.println("C");
        Area.fun1();
        fun1();
        fun2();
    }

}
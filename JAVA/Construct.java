class Demo {
	int x, y;

	void fun1() {
		x=1;
		y=2;
	}

	Demo() {
		x = 3;
		y = 4;
	}

	Demo(int p, int q) {
		x = p;
		y = q;
	}

	Demo(double p, double q) {
		Double d = Double.valueOf(p);
		x = d.intValue();
		Double d1 = Double.valueOf(q);
		y = d1.intValue();
	}
}

class Construct {
	public static void main(String[] args) {
		Demo d1 = new Demo(5, 10);
		d1.fun1();
		Demo d2 = new Demo(25.5, 35.4);
		Demo d3 = new Demo();
		System.out.println("x = " + d1.x);
		System.out.println("y = " + d1.y);
		System.out.println("x = " + d2.x);
		System.out.println("y = " + d2.y);
		System.out.println("x = " + d3.x);
		System.out.println("y = " + d3.y);
	}
}
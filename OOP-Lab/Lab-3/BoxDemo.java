import java.util.Scanner;

class Box{
	double width;
	double height;
	double depth;

	double volume(){
		return width*height*depth;
	}

	void setDim(double w, double h, double d){
		width = w;
		height = h;
		depth = d;
	}
}

class BoxDemo{
	public static void main(String[] args){
		Box box1 = new Box();
		Box box2 = new Box();

		box1.setDim(10,20,15);
		box2.setDim(3,6,9);

		System.out.println("Volume 1: " + box1.volume());
		System.out.println("Volume 2: " + box2.volume());
	}
}

class SumArray{
	private int sum;

	synchronized int sumArray(int nums[]){
		sum=0;

		for(int i=0; i<nums.length; i++){
			sum += nums[i];

			System.out.println("Running total for " + Thread.currentThread().getName() + " is " + sum);
		}

		//allow task switch
		try{
			Thread.sleep(10);

		}catch(InterruptedException e){
			System.out.println("Thread interrupted.");
		}

		return sum;
	}
}


class MyThread implements Runnable{
	Thread thrd;
	static SumArray sa = new SumArray();
	int a[];
	int answer;

	//Construct new thread
	MyThread(String name, int nums[]){
		thrd = new Thread(this, name);
		a = nums;
		thrd.start();
	}

	//Begin execution of new thread
	public void run(){
		System.out.println(thrd.getName() + "starting");

		//try catch whenever sleeping //for can be outside also, essentially sleep ko contain karna chahiye.

		// synchronized(sa){
		// 	answer = sa.sumArray(a);
		// }
		answer = sa.sumArray(a);
		System.out.println("Sum for" + thrd.getName() + "is " + answer);

		System.out.println(thrd.getName() + "terminating");
	}
}

class Multi{
	public static void main(String args[]){
		System.out.println("Main thread starting");

		int arr[] = {1,2,3,4,5,6,7,8};

		MyThread mt1 = new MyThread("Child #1", arr);
		MyThread mt2 = new MyThread("Child #2", arr);
		MyThread mt3 = new MyThread("Child #3", arr);


		// for(int i=0; i<50; i++){
		// 	System.out.println("In Main");
		// 	try{
		// 		Thread.sleep(100);
		// 	}catch(InterruptedException e){
		// 		System.out.println("Main thread interrupted");
		// 	}
		// }

		try{
			mt1.thrd.join();
			System.out.println("Child 1 is joined");
			mt2.thrd.join();
			System.out.println("Child 2 is joined");
			mt3.thrd.join();
			System.out.println("Child 3 is joined");
		}catch(InterruptedException e){
			System.out.println("Main thread interrupted.");
		}

		System.out.println("Main thread ending");
	}
}
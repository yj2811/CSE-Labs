class Q{
	int n;
	boolean set = false;

	//inter communication mein synchronized
	synchronized void put(int n){
		while(set){
			try{
				wait();
			}catch(InterruptedException e){
				System.out.println("Interrupted exception caught.");
			}
		}

		try{
			Thread.currentThread().sleep(1000);

		}catch(InterruptedException e){
			System.out.println("Thread interrupted.");
		}

		this.n = n;
		set = true;
		System.out.println("Put: " + n);
		notify();

	}

	synchronized int get(){
		while(!set){
			try{
				wait();
			}catch(InterruptedException e){
				System.out.println("Interrupted exception caught.");
			}
		}

		try{
			Thread.currentThread().sleep(1000);

		}catch(InterruptedException e){
			System.out.println("Thread interrupted.");
		}

		set = false;
		System.out.println("Got: " + n);
		notify();
		return n;
	}


}

class Producer implements Runnable{
	Q q;
	Thread thrd;
	Producer(Q q){
		this.q = q;
		thrd = new Thread(this, "Producer");
		thrd.start();
	}

	public void run(){
		int i=0;

		while(true){
			q.put(i++);
		}
	}

}

class Consumer implements Runnable{
	Q q;

	Thread thrd;
	Consumer(Q q){
		this.q = q;
		thrd = new Thread(this, "Consumer");
		thrd.start();
	}

	public void run(){
		int i=0;

		while(true){
			q.get();

		}
	}

}


public class ProdCon{
	public static void main(String args[]){
		Q q = new Q();

		new Producer(q);
		new Consumer(q);

		System.out.println("Control-C to stop");
	}
}
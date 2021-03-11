//thread.getName().compareTo("Tick") == 0 ki jagah 2 different classes to implement run.

//can't believe I did it.

class TickTockT{
	String state = "tocked";

	synchronized void tick(boolean running){
		if(!running){
			state = "ticked";
			notify();
			return;
		}

		while(state != "tocked"){
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

		System.out.println("Tick");

		state = "ticked";
		notify();

	}

	synchronized void tock(boolean running){
		if(!running){
			state = "tocked";
			notify();
			return;
		}


		while(state != "ticked"){
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


		System.out.println("Tock");

		state = "tocked";
		notify();

	}
}

class TickThread implements Runnable{
	Thread thrd;
	TickTockT tt;

	TickThread(String name, TickTockT tt){
		thrd = new Thread(this, name);
		this.tt = tt;
		thrd.start();
	}

	public void run(){
		for(int i=0; i<5; i++){
			tt.tick(true);
		}
		tt.tick(false);

	}
}

class TockThread implements Runnable{
	Thread thrd;
	TickTockT tt;


	TockThread(String name, TickTockT tt){
		thrd = new Thread(this, name);
		this.tt = tt;
		thrd.start();
	}

	public void run(){
		for(int i=0; i<5; i++){
			tt.tock(true);
		}
		tt.tock(false);
	}
}

public class TickTock{
	public static void main(String args[]){
		TickTockT tt = new TickTockT();
		TickThread tickt = new TickThread("TickThread", tt);
		TockThread tockt = new TockThread("TockThread", tt);



		try{
			tickt.thrd.join();
			tockt.thrd.join();
		}catch(InterruptedException exc){
			System.out.println("Interrupted");
		}

	}

}
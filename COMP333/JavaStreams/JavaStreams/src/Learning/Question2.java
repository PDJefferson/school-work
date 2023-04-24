package Learning;

import java.util.stream.IntStream;

public class Question2 implements Runnable {
	int[] result;
	int n;
	int i; 
	public Question2(int[] result, int n, int i ) {
		this.result = result;
		this.n = n;
		this.i =i;
	}
	
	public static int[] question(int n) throws InterruptedException {
		int[] result = new int[n];
		
		for(int i = 0 ;i < n ; i++) {
			new Thread(new Question2(result,n, i)).start();
		}
		Thread.sleep(1000);
		return result;
	}

	@Override
	public void run() {
		result[i] =n;
	}
}

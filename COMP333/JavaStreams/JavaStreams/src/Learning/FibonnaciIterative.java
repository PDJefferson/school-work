package Learning;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class FibonnaciIterative implements Runnable {
	long[] result;
	int i;
	public FibonnaciIterative(long[ ] result, int i) {
		this.result = result;
		this.i= i;
	}
	public static void main(String[] args) throws InterruptedException {
		// TODO Auto-generated method stub
		int n = 10;
		for(int i = 0;i< n ;i++) {
			System.out.print(fibonacci(i) + " ");
		}
	}
	public static long fibonacci(int n) throws InterruptedException 
    { 
		long[] resul = new long[n+2];
		resul[0]= 0;
		resul[1] =1;
  
        int counter = 0; 
        ExecutorService thread = Executors.newFixedThreadPool(Runtime.getRuntime().availableProcessors());
        
        // Iterate till counter is N 
        for(int i = 2 ; i <=  n; i++) { 
  
             
            thread.execute(new FibonnaciIterative(resul,i));
          
            counter = counter + 1; 
        } 
        thread.shutdown();
        thread.awaitTermination(10, TimeUnit.SECONDS);
        return resul[n];
    }

	@Override
	public void run() {
		result[i]= result[i-1]+ result[i-2];
         
	}
}

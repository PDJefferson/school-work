package Learning;

import java.util.ArrayList;
import java.util.Collection;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.TimeUnit;

public class Fibonnacci implements Callable<Integer> {
	private int num1;
	private int num2;
	
	public Fibonnacci(int num1, int num2) {
		this.num1 = num1;
		this.num2 = num2;
	}
	public static void main(String[] args) throws InterruptedException, ExecutionException {
		// TODO Auto-generated method stub
	
		fib(10);
	}
	
	public static void fib(int n) throws InterruptedException, ExecutionException {
		   int num1 = 0, num2 = 1;
		   int result1;
		   
	        int counter = 0;
	        Callable<Integer> result = new Fibonnacci(num1, num2);
	        ExecutorService threads = Executors.newFixedThreadPool(Runtime.getRuntime().availableProcessors());
	        ArrayList<Future<Integer>> tasks = new ArrayList<Future<Integer>>(); 
	        
	        // Iterate till counter is N
	        while (counter < n) {
	        
	        	
			Future<Integer> future = threads.submit(result);
	        tasks.add(future);	
	        
	         counter = counter + 1;
	        }
	        
	        for(Future<Integer> f : tasks) {
	        	System.out.print(f.get() + " ");
	        }
	         
	        threads.shutdown();
	        threads.awaitTermination(10, TimeUnit.SECONDS);
	}

	@Override
	public Integer call() throws Exception {
		 int num3 = num2 + num1;
         num1 = num2;
         num2 = num3;
         return num1;
	}

	

	
	

}



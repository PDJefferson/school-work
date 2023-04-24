package Learning;

import java.util.ArrayList;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.TimeUnit;

public class RequestedProblem {

	
	public static void main(String[] args) throws InterruptedException, ExecutionException {
		// TODO Auto-generated method stub
		System.out.println(tryProblem(3));
	}
	public static int tryProblem(int n) throws InterruptedException, ExecutionException {
		int sum=0;
		
		ExecutorService thread = Executors.newFixedThreadPool(Runtime.getRuntime().availableProcessors());
		ArrayList<Callable<Integer>> tasks = new ArrayList<Callable<Integer>>();
		for(int i = 1; i <= n ; i++ ) {
			int iterator = i;
			//System.out.println(i);
			tasks.add(()-> iterator);
		}	
			for(Future<Integer> c : thread.invokeAll(tasks)) {
				sum += c.get();
				System.out.println(sum);
			}
			
		
		thread.shutdown();
		thread.awaitTermination(100, TimeUnit.SECONDS);
		return sum;
	}
	
	

}


package Learning;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.TimeUnit;
import java.util.stream.IntStream;

public class QuestionFour implements Callable<ArrayList<Integer>>{
	private int start;
	private int end;
	private ArrayList<Integer> result;
	public QuestionFour(int start, int end, ArrayList<Integer> result) {
		this.start= start;
		this.end = end;
		this.result = result;
	}
    static IntStream getPrimes1(int start, int end) {
        return IntStream.rangeClosed(start, end).filter(n -> isPrime(n));
    }
//	  public static ArrayList<Integer> getPrimes(int start, int end) throws InterruptedException, ExecutionException {
//		  
//		   ExecutorService threads= Executors.newFixedThreadPool(Runtime.getRuntime().availableProcessors());
//	        ArrayList <Future<String>> tasks = new ArrayList<Future<String>>();
//	        ArrayList<Integer> result = new ArrayList<Integer>();
//			Callable <ArrayList<Integer>> values =  new QuestionFour(start,end, result);
//			  	
//			 
//		  for(Future<Integer> f: threads.invokeAll(tasks)) {
//			  if(isPrime(f.get())) {
//				  prime.add(f.get());
//			  }
//		  } 
//			threads.shutdown();
//			threads.awaitTermination(10, TimeUnit.SECONDS);
//			  
//		  
//		return prime;
//	    }
	  
	  
	 public static boolean isPrime(long x) {
	       
		 
		 if (x < 3 || x % 2 == 0)
	            return x == 2;
	 
	        long max = (long) Math.sqrt(x);
	        for (long n = 3; n <= max; n += 2) {
	            if (x % n == 0) {
	                return false;
	            }
	        }
	        return true;
	    }
	 
	    public static void main(String[] args) throws InterruptedException, ExecutionException {
	       int n=1000;
	       ArrayList<Integer> result = new ArrayList<Integer>();
	       long startTime = System.nanoTime();
	    //   result = getPrimes(0,n);
	       long endTime = System.nanoTime();
	       printArray( result );
	       long duration = (endTime - startTime);
	       System.out.println("dURATION PARALLEL TAKES \n " + duration +"\n");
	       long startTime1 = System.nanoTime();
	       getPrimes1(0, 1000).forEach(p -> System.out.printf("%d, ", p));
	       long endTime1 = System.nanoTime();
	       long duration1 = (endTime1- startTime1);
	       System.out.println("\n" + duration1);
	       
	    		
	    }
	    public static void printArray(ArrayList<Integer> num) {
	    	for(int i= 0; i < num.size();i++) {
	    		System.out.print(num.get(i) + " ");
	    	}
	    }
		@Override
		public ArrayList<Integer> call() throws Exception {
			// TODO Auto-generated method stub
			return null;
		}

	
}


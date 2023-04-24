package Learning;

import java.util.ArrayList;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.TimeUnit;
import java.util.stream.IntStream;

public class RN implements Callable<String[]> {
	public static int count=0; 
	private Numeral[] values;
	 private long[] n;
	 private StringBuilder  buf;
	 
	private String[] rs;
	 
	 enum Numeral {
        I(1), IV(4), V(5), IX(9), X(10), XL(40), L(50), XC(90), C(100), CD(400), D(500), CM(900), M(1000);
        int weight;
 
        Numeral(int weight) {
            this.weight = weight;
        }
    };
 
    public RN(Numeral[] values, long[] n, StringBuilder buf) {
		this.values = values;
		this.n = n;
		this.buf =buf;
    }

	public static String[] roman(long[] n) throws InterruptedException, ExecutionException {
		for(int i =0;i< n.length;i++) {
        if( n[i] <= 0) {
            throw new IllegalArgumentException();
        }
		}
        String[] rr = new String[n.length];
        StringBuilder buf = new StringBuilder();
        final Numeral[] values = Numeral.values();
        ExecutorService threads = Executors.newFixedThreadPool(Runtime.getRuntime().availableProcessors());
        ArrayList <Future<String[]>> tasks = new ArrayList<Future<String[]>>();
        
        
        
        	Callable <String[]> result = new RN(values,n,buf);
        	Future<String[]> future = threads.submit(result);
	        tasks.add(future);	
        
        for(Future<String[]> f : tasks) {
        	rr = f.get();
        }
        threads.shutdown();
        threads.awaitTermination(10, TimeUnit.SECONDS);
        
        return rr;
    }
 
    public static void test(long n) throws InterruptedException, ExecutionException {
       // System.out.println(n + " = " + roman(n));
    }
 
    public static void main(String[] args)throws IllegalArgumentException, InterruptedException, ExecutionException{
    	long[] num = {210,213123,12343,2134};
    	String[] n =roman(num);
    	IntStream.range(0, num.length).forEach(i ->  System.out.print(n[i]+ " "));
    }

	@Override
	public String[] call() throws Exception {
		System.out.println(Thread.currentThread());
		rs = new String[n.length];
		for(int i= 0; i< n.length; i++) {
		for (int s = values.length - 1; s >= 0; s--) {   	
		while (n[i] >= values[s].weight) {
           buf.append(values[s]);
            n[i] -= values[s].weight;
        }	
	}
		rs[i] = buf.toString();
		buf.delete(0, buf.length());
		}
		return rs;
	}
 
}
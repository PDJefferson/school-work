package Learning;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class IdMatrixE implements Runnable{ 
	  int[][] result; 
	  int i; 
	  int n;
  
  public IdMatrixE(int[][] result, int i,int n){ 
	  this.result=result; 
	  this.i =i; 
	  this.n =n; 
	  }
  
  
  public static void main(String[] args) throws InterruptedException {
  
  int[][] s = identitityMatrix(7);
  printarray(s);
  
  }
 
	 
	
	public static void printarray(int[][] n) {
		for(int i=0; i < n.length; i++) {
			for(int j =0 ; j < n.length; j++) {
				System.out.printf("%4d", n[i][j]);
			}
			System.out.println();
		}
	}
	public static int[][] identitityMatrix(int n) throws InterruptedException{
		int[][] result = new int[n][n];
		ExecutorService thread = Executors.newFixedThreadPool(Runtime.getRuntime().availableProcessors());

		for (int i = 0 ; i < n; i++) {
			 thread.execute(new IdMatrixE(result, i,n));
		}
		thread.shutdown();
		thread.awaitTermination(10, TimeUnit.SECONDS);
		return result;
	}
	@Override
	public void run() {
		this.result[i] =new int[n];
		this.result[i][i]=  1;
	}

}

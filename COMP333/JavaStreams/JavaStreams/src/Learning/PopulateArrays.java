package Learning;

import java.util.Random;
import java.util.stream.IntStream;

public class PopulateArrays implements Runnable {
	int[] result;
	int i;
	
	public PopulateArrays(int[] result, int i) {
		this.result  = result;
		this.i = i;
	} 
	public static void main(String[] args) throws InterruptedException {
		int[] result =populateArray(5);
		printArray(result);
	}
	
	public static void printArray(int[] r ) {
		IntStream.range(0, r.length).forEach(i -> System.out.print(r[i] + "  "));
	}
	
	public static int[] populateArray(int n) throws InterruptedException {
		int[] result = new int[n];
		for(int i = 0; i < n ; i++) {
			new Thread(new PopulateArrays(result,i)).start();
		}
		Thread.sleep(1);
		return result;
	}
		
	@Override
	public void run() {
		// TODO Auto-generated method stub
		result[i]= new Random().nextInt(100);
	}

}

package Learning;

import java.util.stream.IntStream;

public class Problem1 implements Runnable{
	private int[] array; 
	private int i;
	private int[ ] answ;
	
	public  Problem1(int[] array, int i, int[] answ) {
		this.array= array;
		this.i =i;
		this.answ =answ;
	}
	
	
	public static void main(String[] args) throws InterruptedException {
		
		printArray();

	}
	public static void printArray() throws InterruptedException {
		int temp[]  = {1,2,4,6,8,10,12,14,18,19,21,24,26};
		int array[]= prob02(temp);
		
		
		IntStream.range(0,array.length).forEach(x -> System.out.print("value at " + x + " = " + array[x] + "\n"));
	}
	
	
	public static int[] prob02(int[] array) throws InterruptedException {
		int[] ans = new int[array.length];
		
		for(int i =0 ; i < array.length; i++) {
			for(int j =i ; j< array.length; j++) {
				new Thread(new Problem1(array, i, ans)).start();
				
			}
			Thread.sleep(1000);
		}
		
		
		return ans;
	}
	
	

	@Override
	public void run() {
		// TODO Auto-generated method stub
		answ[i] += array[i];  
	}

}

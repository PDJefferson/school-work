package Learning;

import java.util.stream.IntStream;

public class RunQuestion2 {
	public static void main(String[] args) throws InterruptedException {
	 int[] val =Question2.question(100);
	 printArray(val);
	 
	}
	public static void printArray(int[] array) {
		IntStream.range(0,array.length).forEach(x -> System.out.print("value at " + x + " = " + array[x] + "\n"));
	}
}

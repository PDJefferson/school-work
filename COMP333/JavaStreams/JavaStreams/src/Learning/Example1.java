package Learning;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;
import java.util.stream.IntStream;
import java.util.stream.LongStream;

public class Example1 {
	public static void main(String[] args) {
			
//		int[] array2 =  evenRandom(500);
//		printArray(array2);
//		int[] array = question(100);
//			printArray(array);
//		int[] t = {1,2,4,6,8,10,12,14,18,19,21,24,26};
//		int r[];
//		long[] test = {1231231,213123,123123};
//		r = prob02(t);
//		printArray(r);
//		int[] n=  new int[100];
//		for(int i=0;i < n.length; i++) {
//			n[i]=i;
//		}
//		System.out.println(questionSet1(n, n.length));
//		
//		System.out.println(question(n, n.length));
//		long ln = question1(test); 
//		long sn = question2(test);
//		
//		System.out.println("ln" + ln);
//		System.out.println("sn" + sn);
//		
//		//int [] s = prob4();
//		//printArray(s);
		int[][] sand =intRand2DArray(10, 10);
		for(int i=0; i < sand.length; i++) {
			for(int j =0 ; j < sand.length; j++) {
				System.out.printf("%4d", sand[i][j]);
			}
			System.out.println();
		}
	}
	
	public static int[] prob1(int n) {
		return IntStream.range(0, 5).map(x->1).toArray();
	}
	
	public static int[] prob2(int[] array) {
		return IntStream.range(0, array.length)
				.map(i -> IntStream.range(i , array.length).map(x -> array[i]).reduce(0,(a,b) -> a+b))
				.toArray();
		
		
	}
	public static int[] prob02(int[] array) {
		int[] ans = new int[array.length];
		
		for(int i =0 ; i < array.length; i++) {
			for(int j =i ; j< array.length; j++) {
				ans[i] += array[i];
			}
		}
		
		
		return ans;
	}
	
	public static void printArray(int[] array) {
		IntStream.range(0,array.length).forEach(x -> System.out.print("value at " + x + " = " + array[x] + "\n"));
	}
	
	
	public static String converter(byte[][] array) {
		return Arrays.stream(array).map(x -> Arrays.toString(x) + "\n").reduce("", (a,b) ->a+b );
	}
	
	public static int[] prob4() {
	return IntStream.range(0,200).map(x -> x = new Random().nextInt(500)).filter(e -> e % 2 == 0).toArray();
	}
	
	public static int questionSet1(int[] n, int x) {
	 ArrayList<Integer> holder = new ArrayList<Integer>();
	 int sum =0;
	 int count= 0;
	 for(int i =0 ; i< n.length; i++) {
		   if((n[i]%2)==0) {
			  
				   holder.add(((n[i]/x)%2));
				   sum += 7 + holder.get(count++);
			
		   }
	   }
	 
	 
	   return sum;
	}
	public static int  question(int[] in, int n)
	{
	return IntStream.range(0, n).parallel().map(i
	            -> in[i]).filter(i -> i%2==0).map(i ->
	                  (i/n)%2).reduce(7, (a,b) -> a+b);
	}
	
	public static void printNum(int n , int x) {
		System.out.println(n+x);
	}
	static boolean prime(long a){ //you can use this method on your solution
		   if(a == 2){
		      return true;
		   }else if(a <= 1 || a % 2 == 0){
		      return false;
		   }
		   long max = (long)Math.sqrt(a);
		   for(long n= 3; n <= max; n+= 2){
		      if(a % n == 0){ return false; }
		   }
		   return true;
		}
	
		static long question1 (long[] in){
		    long result = (long)(Math.random() * 1000000);
		    for (long l : in)
		    {
		      if (l%2== 0 && prime(l)) result /= l;
		    }    
		    return result;
		}
		
		static long question2 (long[] in){
			long result = (long)(Math.random() * 1000000);
			return LongStream.range(0, in.length).map(i -> in[ (int) i]).filter(l -> l%2==0 && prime(l))
					.reduce(result ,(a,b)-> a/b);
		}
		public static int[] question(int n)
		{
		    return IntStream.range(0, n).parallel().map(x -> n).toArray();
		}
		public static int[] evenRandom(int n)
		{
		    return new Random().ints().parallel().filter(i-> i%2==0).limit(n).toArray();
		}
		
		 static int[][] intRand2DArray(int row, int col) 
		 { 
		     return IntStream.range(0, row).mapToObj(x  
		          -> new Random().ints(0, 10).limit(col).toArray()
		        ) .toArray(int[][]::new);  
		 }
	
}

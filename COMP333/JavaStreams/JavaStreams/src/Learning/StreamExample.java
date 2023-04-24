package Learning;
import java.util.OptionalDouble;
import java.util.stream.DoubleStream;
import java.util.stream.IntStream;
import java.util.stream.Stream;
public class StreamExample {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(implementEquation(10));
		System.out.println(implementEquation2(10));
		System.out.println(implementQuestion1(10));
	}
	
	public static double implementEquation(int n) {
		return IntStream.range(1,n+1).mapToDouble(x -> x/Math.pow(n, x)).reduce(0,(a, b)-> a+b);
	}
	
	public static double implementEquation2(int n) {
		return IntStream.range(1, n+1).mapToDouble(i -> ((3.0/i)+(i/21.0))).reduce(0, (a,b)-> a+b);
	}
	
	public static int implementQuestion1(int n) {
		return (int) IntStream.range(1, n+1).mapToDouble(i ->  6 + Math.pow(i, 2)).reduce(0, (a,b)-> a+b);
	}

}

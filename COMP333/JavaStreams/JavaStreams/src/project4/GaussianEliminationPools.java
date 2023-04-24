package project4;

	import java.util.ArrayList;
	import java.util.List;
	import java.util.Locale;
import java.util.Random;
import java.util.concurrent.Callable;
	import java.util.concurrent.ExecutionException;
	import java.util.concurrent.ExecutorService;
	import java.util.concurrent.Executors;
	import java.util.concurrent.Future;
	import java.util.concurrent.ScheduledExecutorService;
	import java.util.concurrent.TimeUnit;

	import java.util.Locale;

	public class GaussianEliminationPools {
	    public static double solve(double[][] a, double[][] b) {
	        if (a == null || b == null || a.length == 0 || b.length == 0) {
	            throw new IllegalArgumentException("Invalid dimensions");
	        }

	        int n = b.length, p = b[0].length;
	        if (a.length != n || a[0].length != n) {
	            throw new IllegalArgumentException("Invalid dimensions");
	        }

	        double det = 1.0;
	        int counter= 1;
	        for (int i = 0; i < n - 1; i++) {
	        	 
	        	int k = i;
	            for (int j = i + 1; j < n; j++) {
	                if (Math.abs(a[j][i]) > Math.abs(a[k][i])) {
	                    k = j;
	                }
	            }

	            if (k != i) {
	                det = -det;

	                for (int j = i; j < n; j++) {
	                    double s = a[i][j];
	                    a[i][j] = a[k][j];
	                    a[k][j] = s;
	                }

	                for (int j = 0; j < p; j++) {
	                    double s = b[i][j];
	                    b[i][j] = b[k][j];
	                    b[k][j] = s;
	                }
	            }

	            for (int j = i + 1; j < n; j++) {
	                double s = a[j][i] / a[i][i];
	                for (k = i + 1; k < n; k++) {
	                    a[j][k] -= s * a[i][k];
	                }

	                for (k = 0; k < p; k++) {
	                    b[j][k] -= s * b[i][k];
	                }
	            }
	            counter++;
	            System.out.println("det "+ det);
	        }
	        
	        for (int i = n - 1; i >= 0; i--) {
	            for (int j = i + 1; j < n; j++) {
	                double s = a[i][j];
	                for (int k = 0; k < p; k++) {
	                    b[i][k] -= s * b[j][k];
	                }
	            }
	            double s = a[i][i];
	            det *= s;
	            for (int k = 0; k < p; k++) {
	                b[i][k] /= s;
	            }
	       System.out.println("det in next loop " + det);
	        }
	       
	     
	        return det;
	    }

	    public static void main(String[] args) {
	      
	        double[][] a = new double[][] { 
	        	{ 4.0, 1.0, 0.0, 0.0, 0.0 }, 
	        	{ 1.0, 4.0, 1.0, 0.0, 0.0 },
	        	{ 0.0, 1.0, 4.0, 1.0, 0.0 }, 
	        	{ 0.0, 0.0, 1.0, 4.0, 1.0 }, 
	        	{ 0.0, 0.0, 0.0, 1.0, 4.0 } 
	        	};
	        double[][] b = new double[][] { 
	 	        	{ 1.0 / 2.0 }, 
	 	        	{ 2.0 / 3.0 }, 
	 	        	{ 3.0 / 4.0 }, 
	 	        	{ 4.0 / 5.0 }, 
	 	        	{ 5.0 / 6.0 } 
	 	        	};
	        int size =100;
	        double [][]matrix = new double[size][size];
	        
	        for(int i=0;i<size;i++){
                for(int j=0;j<size;j++){
                    if(i<j){
                        matrix[i][j] =0;
                    }
                    else{
                        matrix[i][j] = 45;
                    }
                    
                    
                }
            }

	            
	        
	        double [][]whatever = new double[size][1];

	        for(int i=0;i<size;i++){
	            whatever[i][0] = (double) i / (double) i+1;
	        }
	       

	        double[] x = { 39.0 / 400.0, 11.0 / 100.0, 31.0 / 240.0, 37.0 / 300.0, 71.0 / 400.0 };
	        
	        long startTime = System.nanoTime();
	        System.out.println("det: " + solve(matrix, whatever));
	        long endTime = System.nanoTime();
	        for (int i = 0; i < 5; i++) {
	            System.out.printf(Locale.US, "%12.8f %12.4e\n", b[i][0], b[i][0] - x[i]);
	        }

	        // int n = 100;
	        // double[][]a = new double[n][n];
	        // double[][]b = new double[n][n];

	        // for(int i = 0 ; i< n; i++){
	        // for(int j = 0 ; j< n; j++){
	        // if(i==j){
	        // a[i][j] = 100.0;
	        // b[i][j] = 100.0;

	        // }
	        // else {
	        // a[i][j] = 0.0;
	        // b[i][j] = 0.0;

	        // }
	        // }
	        // }

	        // System.out.println("det: " + solve(a, b));

	        // for (int i = 0; i < 5; i++) {
	        // System.out.printf(Locale.US, "%12.8f\n", b[i][0]);
	        // }

	        

	        long duration = (endTime - startTime);

	        System.out.println(duration + " milliseconds (not parallel)");
	    }
	}


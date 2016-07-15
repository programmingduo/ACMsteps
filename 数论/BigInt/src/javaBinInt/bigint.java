package javaBinInt;

	import java.io.*;  
	import java.util.*;  
	import java.math.*;  
	public class bigint {  
	      
	    public static void main(String[] args) {  
	        Scanner in = new Scanner(System.in);  
	        BigInteger mod = BigInteger.valueOf(1);  
	        for(int i = 1; i <= 100; i++)  
	            mod = mod.multiply(BigInteger.valueOf(10));  
	        while(in.hasNext())  
	        {  
	            int n = in.nextInt();  
	            BigInteger ans = BigInteger.valueOf(1);  
	            BigInteger ret = BigInteger.valueOf(1);  
	            for(int i = 1; i+i <= n; i++)  
	            {  
	                  
	                ans = ans.multiply(BigInteger.valueOf(n-2*i+2));  
	                ans = ans.multiply(BigInteger.valueOf(n-2*i+1));  
	                ans = ans.divide(BigInteger.valueOf(i));  
	                ans = ans.divide(BigInteger.valueOf(i+1));  
	                ret = ret.add(ans);  
	                  
	            }  
	            ret = ret.mod(mod);  
	            System.out.println(ret);  
	              
	        }  
	          
	    }  
	}  


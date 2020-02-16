import java.util.*;
import java.util.Scanner;
public class kth_smallest_element { 
    static int minimum(int a, int b){
        if(a<b)
            return a;
        return b;
    }
    static int findkthsmallest(int[] A, int AStart, int[] B, int BStart, int k){
        int ALen = A.length-AStart;
        int BLen = B.length-BStart;
    
        if(ALen > BLen)
            return findkthsmallest(B, BStart, A, AStart, k);
        if(ALen==0)
            return B[BStart+k-1];
        if(k==1)
            return minimum(A[AStart], B[BStart]);
        
        int pa = minimum(k/2, ALen), pb = k-pa;
        if(A[AStart+pa-1]<B[BStart+pb-1])
            return findkthsmallest(A, AStart+pa, B, BStart, k-pa);
        else if(A[AStart+pa-1]>B[BStart+pb-1])
            return findkthsmallest(A, AStart, B, BStart+pb, k-pb);
        else
            return A[AStart+pa-1];
    }

     public static void main(String[] str){
        int x,y,k,i;
        Scanner input = new Scanner(System.in);

        System.out.println("enter length of 1st array");
        x = input.nextInt();
        int[] A = new int[x];

        System.out.println("enter elements of 1st array");
        for(i=0; i<x; i++)
            A[i] = input.nextInt();

        System.out.println("enter length of 2nd array");
        y = input.nextInt();
        int[] B = new int[y];

        System.out.println("enter elements of 2nd array");
        for(i=0; i<x; i++)
            B[i] = input.nextInt();
    
        System.out.println("enter k");
        k = input.nextInt();

        System.out.println(findkthsmallest(A,0,B,0,k));
    }
}
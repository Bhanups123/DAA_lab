import java.util.*;
import java.lang.Math;
public class Solution { 

    static int FindKthSmallest(int[] A, int AStart, int[] B, int BStart, int k){
        int ALen = A.length-AStart;
        int BLen = B.length-BStart;
    
        if(ALen > BLen)
            return FindKthSmallest(B, BStart, A, AStart, k);
        if(ALen==0)
            return B[BStart+k-1];
        if(k==1)
            return Math.min(A[AStart], B[BStart]);
        
        int pa = Math.min(k/2, ALen), pb = k-pa;
        if(A[AStart+pa-1]<B[BStart+pb-1])
            return FindKthSmallest(A, AStart+pa, B, BStart, k-pa);
        else if(A[AStart+pa-1]>B[BStart+pb-1])
            return FindKthSmallest(A, AStart, B, BStart+pb, k-pb);
        else
            return A[AStart+pa-1];
    }

     public static void main(String[] str){
        int[] A={1,2,5,6,7,8};
        int[] B={3,4,9,10,12,31};
        System.out.println(FindKthSmallest(A,0,B,0,6));
    }
}
import java.util.Scanner;

class banker{
	static boolean anyLeft(boolean process_finish[]){
		for(boolean p:process_finish){
			if( p == false )
				return true;
		}
		return false;
	}
	static boolean feasibleNow(int i,int m, int need[][], int available[]){
		for(int j=0; j<m; j++){
			if(need[i][j]>available[j]){
				return false;
			}
		}
		return true;
	}
	static void safetyAlgo(int n, int m, int allocation[][], int max[][], int need[][], int available[]){
		boolean process_finish[] = new boolean[n];
		int i, j, k=0;
		int pro_seq[] = new int[n];

		while(anyLeft(process_finish)){
			for(i=0; i<n; i++){

				if(feasibleNow(i, m, need, available) && process_finish[i] == false){
					//pro_seq[k] = i;
					//k++;
					System.out.print(i + " ");
					process_finish[i] = true;

					for(j=0; j<m; j++){
						available[j] += allocation[i][j];
					}
				//	for(j=0; j<m; j++){
				//		System.out.print(available[j] + " ");
				//	}
				//	System.out.println();
				}
			}
		}
	//	for(i=0; i<n; i++){
	//		System.out.print(pro_seq[i]);
	//	}
	}
	public static void main(String...str){

		Scanner inp = new Scanner(System.in);
		int n,m,i,j;

		System.out.println("NO. OF PROCESS");
		n = inp.nextInt();

		System.out.println("enter no of resources");
		m = inp.nextInt();

		int allocation[][] = new int[n][m];
		int max[][] = new int[n][m];
		for(i=0; i<n; i++){
			System.out.println("Process P" + i);
			System.out.println();

			for(j=0; j<m; j++){
				System.out.print("allocation R"+ j);
				allocation[i][j] = inp.nextInt();
			}

			for(j=0; j<m; j++){
				System.out.print("max R"+ j);
				max[i][j] = inp.nextInt();
			}
		}

		int available[] = new int[m];
		for(i=0; i<m; i++){
			System.out.println("available resource of R" + i);
			available[i] = inp.nextInt();
		}		
		int need[][] = new int[n][m];

		for(i=0; i<n; i++){
			for(j=0; j<m; j++){
				need[i][j] = max[i][j] - allocation[i][j];
			}
		}   
		safetyAlgo(n, m, allocation, max, need, available);

		System.out.println("\nneed matrix");
		for(i=0; i<n; i++){
			for(j=0; j<m; j++){
				System.out.print(need[i][j] +" ");
			}
			System.out.println();
		}
	}	
}
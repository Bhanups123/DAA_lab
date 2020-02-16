import java.util.*;

class process{
	int arrival_time;
	int burst_time, burst_time_new;
	String process_id;
	int waiting_time;
	int turn_around_time;
	int completion_time;

	process(String id, int a, int b){
		process_id = id;
		arrival_time = a;
		burst_time = burst_time_new = b;
	}
}
class shortest_job_first{
	static void sort(process[] p, int n){
		int i, j;
		process t;
		for(i= 0; i<n-1; i++ ){
			for(j = 0; j<n-i-1; j++ ){
				if(p[j].arrival_time>p[j+1].arrival_time){
					t = p[j];
					p[j] = p[j+1];
					p[j+1] = t;				
				}
			}
		}
	}
	static int shortest_job(process[] p, int no_process){
		int z = 0;
		for(int i=1; i<no_process; i++){
			if(p[z].burst_time_new>p[i].burst_time_new )
				z = i;;
		}
		return z;
	}
	static int completionTime(process[] p, int n){
		int sum = 0;
		for(int i=0; i<n; i++){
			if(p[i].burst_time_new == 2020)
				sum+= p[i].burst_time - 0;
			else
				sum+= p[i].burst_time - p[i].burst_time_new; 
		}
		return sum;
	}
	public static void main(String... str){
		int n,t,i;
		int arrival_time;
		int burst_time;
		String process_id;

		Scanner s  = new Scanner(System.in);

		System.out.println("enter no of processes");
		n = s.nextInt();

		process[] p = new process[n];

		System.out.println("p a_t b_t");
		for(i=0; i<n; i++){
			process_id = s.next();
			arrival_time = s.nextInt();
			burst_time = s.nextInt();
			p[i] = new process(process_id, arrival_time, burst_time);
		}
		sort(p, n);
		// for(process a:p){
		// 	System.out.println(a.process_id + " " + a.arrival_time + " " + a.burst_time);
		// }

		System.out.println();
		int z,r=0,q=0,prev_z;
		//p[0].burst_time_new -= p[1].arrival_time;
		for(i=0; i<n-1; i++ ){
			z = shortest_job(p, i+1);
			p[z].burst_time_new -= p[i+1].arrival_time-p[i].arrival_time;
			prev_z = z;
			if(p[z].burst_time_new<0){
				q-= p[z].burst_time_new;
				p[z].burst_time_new=0;
			}
			if(p[z].burst_time_new==0){
				p[z].completion_time = r + completionTime(p, n);
				p[z].burst_time_new = 2020;
			}
			r = q;
		System.out.print(p[z].process_id+ " ");
		}
		z = shortest_job(p, n);
		while(p[z].burst_time_new!=2020){
			p[z].burst_time_new =0;
			p[z].completion_time = r + completionTime(p, n);
			p[z].burst_time_new = 2020;
			System.out.print(p[z].process_id+" ");
			z = shortest_job(p, n);
		}
		for(process a:p){
			a.turn_around_time = a.completion_time - a.arrival_time;
			a.waiting_time = a.turn_around_time - a.burst_time;
		}
		System.out.println("Preemtive scheduling");
		System.out.println("process waiting time turn around time");
		for(process a:p){
			System.out.println(a.process_id + "\t" + a.waiting_time + "\t" + a.turn_around_time);
		}
		int average_wt = 0, average_tat = 0;
		for(process a:p){
			average_wt += a.waiting_time;
			average_tat += a.turn_around_time;
		}
		//System.out.println("gantt chart:");

		System.out.println("average waiting time: "+ average_wt/(float)n);
		System.out.println("average turn around time: "+ average_tat/(float)n);

		//System.out.println("Non Preemtive scheduling");

	}
}
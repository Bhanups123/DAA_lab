
import java.util.Scanner;

class graph{
	linked_list list[];
	
	linked_list[] create_graph(int node_count){
		list = new linked_list[node_count];
		
		for(int node_index=0; node_index<node_count ; node_index++ )
		{
			System.out.println("Vertex:"+(node_index+ 1));
			list[node_index] = new linked_list();
			list[node_index] = linked_list.create_list(list[node_index]);
		}
		return list;
	}
	void print_graph(int node_count){
		System.out.println("Given Graph:");
		
		for(int node_index=0; node_index<node_count ; node_index++ )
		{
			System.out.print("Vertex("+(node_index+ 1)+")");
			linked_list.print_list(list[node_index]);
		}
	}
	public static void main(String str[]){
		linked_list list[];
		graph new_graph = new graph();
		
		System.out.println("enter no. of vertex");
		Scanner input = new Scanner(System.in);
		int node_c = input.nextInt();
		
		list = new_graph.create_graph(node_c);
		new_graph.print_graph(node_c);
	}
}
	
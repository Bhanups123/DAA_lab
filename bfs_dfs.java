import java.util.Arrays;
class bfs_dfs{
	linked_list list_dfs = new linked_list();
	int node_count;
	boolean visited[];
	
	bfs_dfs(int node_count){
		this.node_count = node_count;
		visited = new boolean[node_count];
		Arrays.fill(visited,false);
	}
	void depth_first_search(linked_list[] list, int vertex){
		if(list[vertex].next!=null && visited[vertex]!=true)
		{
			visited[vertex] = true;
			linked_list.insert_node(list_dfs ,vertex);
			depth_first_search(list , list[vertex].next.data);
		}
		else{
			linked_list.pop(list_dfs);
			depth_first_search(list , 
		}

		
		
		
		
		
		
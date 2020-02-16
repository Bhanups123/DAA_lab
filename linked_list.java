import java.util.Scanner;
class linked_list{
	node head;						//add last
	
	public static class node{		//public -> protected
		int data;
		node next;
		
		node(int data_input){
			data = data_input;		//modify
			next = null;		//
		}
	}
	public static linked_list insert_node(linked_list list ,int data){
		node newnode = new node(data);
		
		if(list.head == null ){
			list.head = newnode;
		}
		else{
			node cur = list.head;
			while(cur.next != null){
				cur = cur.next;
			}
			cur.next = newnode;
		}
		return list;
	}
	public static linked_list create_list(linked_list list){
		int data = 0;
		Scanner input = new Scanner(System.in);
		while(data!= -1){
			System.out.println("Enter vertex to add an edge(or press -1 to stop)");		
			data = input.nextInt();
			if(data!=-1){
				node newnode = new node(data);
		
				if(list.head == null ){
					list.head = newnode;
				}
				else{
					node cur = list.head;
					while(cur.next != null){
						cur = cur.next;
					}
					cur.next = newnode;
				}
			}
		}
		return list;
	}
	/*public static void pop(linked_list l_list){
		System.out.println(linked_list.head.data+" ");
		l_list.head = l_list.head.next;
	}*/
	public static void print_list(linked_list list){
		node cur = list.head;
		if(cur ==null)
			System.out.print(" -> " + null);
		else
		while(cur!= null ){
			System.out.print(" -> " + cur.data);
			cur = cur.next;
		}
		System.out.println("");
	}
	/*public static void main(String str[]){
		linked_list list = new linked_list();
		list = create_list(list);
		
		/*list = insert_node(list , 1);
		list = insert_node(list , 2);
		list = insert_node(list , 3);
		list = insert_node(list , 4);
		
		
		print_list(list);
	}*/
}
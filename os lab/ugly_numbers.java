import java.util.Scanner;
class ugly_numbers{
	int nth_ugly_number(int nth_position){
		int i, x, index_ugly = 1, count;
		outerloop:
		for( i=2 ; index_ugly!= nth_position ; i++ )
		{
			count = 0;
			for( x=2 ; x<=i ;x++ )
			{
				if( i%x == 0){
					if(x==2 || x==3 || x==5){
						count++;
					}
					else{
						i++;
						continue outerloop;
					}
				}
			}
			if( count >0 ){
				//System.out.println(count);
				index_ugly ++;
			}
		}
		return i-1;
	}
	public static void main(String... str)
	{
		ugly_numbers ugly_numbers_obj = new ugly_numbers();
		System.out.println("enter position of ugly no. to be found");
		Scanner input = new Scanner(System.in);
		System.out.println(ugly_numbers_obj.nth_ugly_number(input.nextInt()));
	}
}

				
#include<iostream>
 
using namespace std;
int main()
{
    int n,dim,x,y;
    cout<<"Enter number of matrices\n";
    cin>>n;
 	n++;
    int Dimension[n];
 
    cout<<"Enter dimensions \n";
 
    for(dim=0;dim<n;dim++)
        cin>>Dimension[dim];
    
	int matrix_mult[n][n], s[n-1][n-1];
    int i, j, k, matrix_set, min_mult;
 
    for (i=1; i<n; i++)
    for(j=1; j<n;j++)
        matrix_mult[i][j] = 0;    
    for (matrix_set=2; matrix_set<n; matrix_set++)
    {
        for (i=1; i<n-matrix_set+1; i++)
        {
            j = i+matrix_set-1;
            matrix_mult[i][j] = 100000;  
 
            for (k=i; k<=j-1; k++)
            {
                min_mult = matrix_mult[i][k] + matrix_mult[k+1][j] + Dimension[i-1]*Dimension[k]*Dimension[j];
                if (min_mult < matrix_mult[i][j]){
                    matrix_mult[i][j] = min_mult;
                    for(x=1;x<n;x++){
                    for(y=1;y<n;y++)
                    {
						cout<<matrix_mult[x][y]<<"\t";
					}
						cout<<"\n";
                   
                }	 
            }
        }
    }
}

    cout<<"Minimum number of multiplications is "<<matrix_mult[1][n-1]<<endl;
	
	for(i=1;i<n;i++)
	{
		for(j=1;j<n;j++)
		{
			cout<<matrix_mult[i][j]<<"\t";
		}
		cout<<"\n";
	}
	
    return 0;
}

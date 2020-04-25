#include<iostream>
#include<vector>

using namespace std; 
  
struct Coordinate 
{ 
    int x, y; 
}; 
int alignment(Coordinate A, Coordinate B, Coordinate R) 
{ 
    int res = (B.y - A.y) * (R.x - B.x) - 
              (B.x - A.x) * (R.y - B.y); 
  
    if (res == 0) return 0;   
    return (res > 0)? 1: 2; 
} 
  
void convexHull(Coordinate coordinates[], int n) 
{ 
    if (n < 3) return; 
  
    vector<Coordinate> convHull; 
  
    int l = 0; 
    for (int i = 1; i < n; i++) 
        if (coordinates[i].x < coordinates[l].x) 
            l = i; 
            
    int A = l, B; 
    do
    { 
        convHull.push_back(coordinates[A]); 
        B = (A+1)%n; 
        for (int i = 0; i < n; i++) 
        { 
           if (alignment(coordinates[A], coordinates[i], coordinates[B]) == 2) 
               B = i; 
        } 
  
        A = B; 
  
    } while (A != l);   
  
  	cout<<"Points of convex hull are: "<<endl;
    for (int i = 0; i < convHull.size(); i++) 
        cout<< "(" << convHull[i].x << ", "<< convHull[i].y << ")\n"; 
}
  
int main() 
{ 

    int n;
    cout<<"Enter no. of points"<<endl;
    cin>>n;
    
    Coordinate coordinates[n];
    
    cout<<"Enter coordinates:"<<endl;
    for(int i=0; i<n; i++){
    	cin>>coordinates[i].x>>coordinates[i].y;
	}
	 
    convexHull(coordinates, n); 
    return 0; 
} 

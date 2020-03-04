#include <iostream>
#include <set>
using namespace std;

//bool is_constains(int *lru_col, int page, int capacity){
//	for(int x=0; x<lru_col; x++){
//		if(page == lru_col[x])
//			return true;
//	}
//	return false;
//}
int index(int *col, int x, int k){
	int i;
//	for(int u=0; u<k; u++){
//		cout<<"index"<<col[u]<<" ";
//	}
//	cout<<endl;
	for(i=0; i<k; i++){
		if(x==col[i])
			return i;
	}
	return i;
}
int which_ele(string str, int i, int k){
	set<int> s2;
	int x;
	for(x=i-1;  s2.size()!=k; x--){
		s2.insert( int(str[x]) );
	}
	return int(str[++x])-48;
}

int lru(int capacity, string str){
	int no_pages = str.length();
	
	int lru_table[capacity][no_pages];
	int frames[capacity];
	
	for(int j=0; j<capacity; j++){
		frames[j] = -1;
	}
	set<int> s1;
	int hits=0, wh_ele, wh_ind;
	int ele;
	
	for(int i=0; i<no_pages; i++){
		ele = int(str[i])-48;
		
			if(s1.size()<capacity){
				
				cout<<"Pages: ";
				for(int s=0; s<capacity; s++){
					if(frames[s]==-1)
						cout<<"_"<<"\t";
					else
						cout<<frames[s]<<"\t";
				}
				cout<<endl;
				
				if(s1.end() == s1.find(ele)){
					s1.insert(ele);
					wh_ind = index(frames, -1, capacity);
					frames[wh_ind] = ele;
				}
				else{
					hits++;
				}
			}
			else{
				cout<<"Pages: ";
				for(int s=0; s<capacity; s++)
					cout<<frames[s]<<"\t";
				cout<<endl;
				
				if(s1.end()== s1.find(ele)){
					wh_ele = which_ele(str, i, capacity);
					wh_ind = index(frames, wh_ele, capacity);
					
					frames[wh_ind] = ele;
					s1.erase(wh_ele);
					s1.insert(ele);
				}
				else{
					hits++;
				}
			}
		}
	return hits;
	
}

int main(){
	int capacity;
	string str;
	
	cout<<"enter no. of frames"<<endl;
	cin>>capacity;
	
	cout<<"enter string of pages"<<endl;
	cin>>str;
	
	int page_hits = lru(capacity, str);
	
	cout<<"total hits: "<<page_hits<<endl;
	cout<<"total faults: "<<str.length() - page_hits<<endl;
	
}

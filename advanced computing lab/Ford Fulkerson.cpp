#include<iostream>
#include<vector>
#include<set>
#include<stack>

using namespace std;

vector<vector<int>> graph(){
	int E, V, x, y;
	
	cout<<"enter no. of nodes"<<endl;
	cin>>V;
	
	vector<vector<int>> graph(V, vector<int>(V, 0));
	cout<<"enter no. of edges"<<endl;
	cin>>E;
	
	cout<<"enter edge i.e from, to, weight"<<endl;
		
	for(int i=0; i<E; i++){
		cin>>x>>y;
		cin>>graph[x][y];
	}
	
	return graph;
}
void dfs(vector<vector<int>> v, int s){
	set<int> S;
	stack<int> St;
	int buff;
	
	St.push(s);
	
	while(!St.empty()){
		buff = St.top();
		S.insert(buff);
		St.pop();
		
		for(int i=0; i<v.size(); i++){
			if(v[buff][i]>0 and S.find(i) == S.end()){
				St.push(i);
			}
		}
		
		cout<<buff<<" ";
	}
	
}
void print(vector<vector<int>> v){
	cout<<"Graph"<<endl;
	
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<v[i].size(); j++)
			cout<<v[i][j]<<" ";
			cout<<endl;
	}
}

int main(){
	vector<vector<int>> g;
	g = graph();
	print(g);
	dfs(g, 0);
}

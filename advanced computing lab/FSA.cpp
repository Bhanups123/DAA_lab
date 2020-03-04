#include <iostream>
#include <set>
#include <stdlib.h>
#include <fstream>
#include <iterator>
#include <stdio.h>
#define sigma 2

bool isaccept;
int n;
using namespace std;
struct unit{
	set<int> blocks;
};
int next_state(unit tt[][sigma], int ps, int pi, int count){
	auto it = tt[ps][pi].blocks.begin();
	
	while(count-->0){
		it++;
	}
	return *(it);
}
bool fsa(unit tt[][sigma], int present_state, int inp_index, string inp, set<int> final_states){

	if(inp_index==-1){
		if(final_states.find(present_state)!= final_states.end()){
			//cout<<" accepted"<<endl;
			cout<<present_state<<endl;
			isaccept = true;
			return true;
		}
		else{
			//cout<<" rejected"<<endl;
			cout<<endl;
			return false;
		}
	}
	int next_input = inp[inp_index++] - '0';
	if(inp_index==inp.length()){
		inp_index = -1;
	}
	
	cout<<present_state<<" ";
	int count = tt[present_state][next_input].blocks.size();
	int i=0;
	
	while(i<count){
		int n_state = next_state(tt, present_state, next_input, i);
		bool test = fsa(tt, n_state, inp_index, inp, final_states);
		i++;
	}
}
int main(){
	int Q;
	int q = 0;
	int F = 1;
	string inp;
	
	set<int> final_states;
	final_states.insert(1);
	
   fstream newfile;
   
   newfile.open("file.txt"); 
   if (newfile.is_open()){ 
      string tp;
      
      getline(newfile, tp);
      int Q = stoi(tp);
      
      getline(newfile, tp);
      int sigm_a = stoi(tp);
      
      getline(newfile, tp);
      int q = stoi(tp);
      
      getline(newfile, inp);
      
      newfile.close();
   }
	unit tt[Q][sigma];
	
	tt[0][0].blocks.insert(0);
	tt[0][1].blocks.insert(1);
//	tt[0][1].blocks.insert(0);
	tt[1][0].blocks.insert(0);
	tt[1][1].blocks.insert(0);
	tt[1][1].blocks.insert(1);
	
	bool answ = fsa(tt, 0, 0, inp, final_states);
	//cout<<answ<<endl;
	if(isaccept ==true){
		cout<<"accepted"<<endl;
	}
	else{
		cout<<"rejected"<<endl;
	}
	
}

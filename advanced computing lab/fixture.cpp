#include<iostream>
#include<Math.h>
#include<time.h>
using namespace std;

int sort_top(int i, int j, int* arr){
	int top[4];
	int max= arr[i], team = i;
	for(int x=i; x<j; x++){
		if(arr[x]>max){
			max=  arr[x];
			team = x;
		}
	}
}
int main(){
	int N = 16, i=0, j=0;
	int score[16] = {};
	int win;
	int x;
	
	srand(time(time_t()));
	for(i=0; i<8; i++){
		for(j=i+1; j<8; j++){
			x = rand();
			if(x%2==0)
				score[i]++;
			else
				score[j]++;
		}
	}
	for(i=0; i<8; i++){
		for(j=i+1; j<8; j++){		
			x = rand();
			if(x%2==0)
				score[i+8]++;
			else
				score[j+8]++;
		}
	}
	for(i=0; i<16; i++){
		if(i==8)
			cout<<"\t";
		cout<<score[i]<<" ";
	}
	int top1[4], top2[4];
	int max= 0, team = 20;
	
	for(int x=0; x<8; x++){
		if(score[x]>max){
			max=  score[x];
			team = x;
		}
	}
	top1[0] = team;
	max= 0;
	team = 20;
		for(int x=0; x<8; x++){
		if(score[x]>max and x!=top1[0]){
			max=  score[x];
			team = x;
		}
	}
	top1[1] = team;	
	max= 0;
	team = 20;
	for(int x=0; x<8; x++){
		if(score[x]>max and x!=top1[0] and x!=top1[1]){
			max=  score[x];
			team = x;
		}
	}
	top1[2] = team;	
	max= 0;
	team = 20;
	for(int x=0; x<8; x++){
		if(score[x]>max and x!=top1[0] and x!=top1[1] and x!=top1[2]){
			max=  score[x];
			team = x;
		}
	}
	top1[3] = team;
	max= 0;
	team = 20;
	
	for(int x=0; x<8; x++){
		if(score[x]>max){
			max=  score[x];
			team = x;
		}
	}
	
	max= 0;
	team = 20;
	
	for(int x=8; x<16; x++){
		if(score[x]>max){
			max=  score[x];
			team = x;
		}
	}
	top2[0] = team;
	max= 0;
	team = 20;
	for(int x=8; x<16; x++){
		if(score[x]>max and x!=top2[0]){
			max=  score[x];
			team = x;
		}
	}
	top2[1] = team;	
	max= 0;
	team = 20;
	for(int x=8; x<16; x++){
		if(score[x]>max and x!=top2[0] and x!=top2[1]){
			max=  score[x];
			team = x;
		}
	}
	top2[2] = team;	
	max= 0;
	team = 20;
	for(int x=8; x<16; x++){
		if(score[x]>max and x!=top2[0] and x!=top2[1] and x!=top2[2]){
			max=  score[x];
			team = x;
		}
	}
	top2[3] = team;
	
	cout<<endl;
	for(int p =0; p<4; p++){
		cout<<top1[p]<<" "<<top2[p]<<endl;
	}
	int w[4];
	
	for(int l=0; l<4; l++){
	if(rand()%2==0)
		w[l]= top1[l];
	else
		w[l] = top2[l];
	}
	cout<<endl;
	for(int g = 0;g<4; g++)
		cout<<w[g]<<endl;

	
	int w_z[2];
	for(int l=0; l<4; l++){
	if(rand()%2==0)
		w[l]= w[l];
	else
		w[l] = top2[l];
	}
		
	int won;
	for(int l=0; l<2; l++){
	if(rand()%2==0)
		won= top1[l];
	else
		won = top2[l];
	}
	

//	int z = winner(1,2);
//	int p = winner(1,2);
////	cout<<time(time_t());
}



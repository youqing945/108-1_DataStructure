#include <iostream>
#include <vector>
using namespace std;

void maxheap_sort(vector<int> &v, int row);
void sold_sort(vector<int> &v, int row);

int main(){
	int casenum;
	cin>>casenum;  //how many cases
	int caseans[casenum];

	for(int i=0; i<casenum; i++){
		int row, lining;
		cin>>row>>lining;
		vector<int> emptyv;
		for(int j=0; j<row; j++){
			int tmp;
			cin>>tmp;
			emptyv.push_back(tmp);
		}

		maxheap_sort(emptyv, row);

		//calculate
		int money = 0;
		for(int j=0; j<lining; j++){
			money = money + emptyv[0];
			emptyv[0]--;
			sold_sort(emptyv, row);
		}

		//record and clean
		caseans[i] = money;
		emptyv.clear();

	}

	for(int i=0; i<casenum; i++){
		cout<<caseans[i]<<endl;
	}

	return 0;
}

//sort the vector
void maxheap_sort(vector<int> &v, int row){
	//start from the last layer
	for(int i=row-1; i>=0; i--){
		if(2*i+2 < row){
			if(v[2*i+2] > v[i]){
				//switch content
				swap(v[2*i+2], v[i]);
			}
		}
		if(2*i+1 < row){
			if(v[2*i+1] > v[i]){
				//switch content
				swap(v[2*i+1], v[i]);
			}
		}
	}
}

void sold_sort(vector<int> &v, int row){
	int n = 0;
	while(1>0){
		int changed = -1;
		if(2*n+1 < row && changed == -1){
			if(v[n] < v[2*n+1]){
				//switch content
				swap(v[2*n+1], v[n]);
				changed = 2*n+1;
			}
		}
		if(2*n+2 < row && changed == -1){
			if(v[n] < v[2*n+2]){
				//switch content
				swap(v[2*n+2], v[n]);
				changed = 2*n+2;
			}
		}
		//
		if(changed != -1){
			n = changed;
		}
		else{
			break;
		}
	}
}


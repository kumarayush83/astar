#include <iostream>
#include <list>
#include <vector>

using namespace std;



struct node{
	vector<vector<int> > id;
	int g_val;
	//int h_val = 0;
};

list<node*> open_list;
list<node*> close_list;



list<node*> get_neighbour(node* b){
	list<node*> mylist;
	//node* n1 = new node();
	//n1->id = b->id;
	int pos1 =0;int pos2=0;int id1 , id2  ,id3, id4 = 0;
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			if(b->id[i][j] == -1){
				pos1 = i;
				pos2 = j;
			}
		}
	}

	if(pos1 == 1 && pos2 ==1){
		node* north = new node();
		north->id = b->id;
		node* west = new node();
		west->id = b->id;
		node* south = new node();
		south->id = b->id;
		node* east = new node();
		east->id = b->id;
		north->id[pos1][pos2] = north->id[pos1-1][pos2];
		north->id[pos1-1][pos2] = -1;
		west->id[pos1][pos2] = west->id[pos1][pos2-1];
		west->id[pos1][pos2-1] = -1;
		south->id[pos1][pos2] = south->id[pos1+1][pos2];
		south->id[pos1+1][pos2] = -1;
		east->id[pos1][pos2] = east->id[pos1][pos2+1];
		east->id[pos1][pos2+1] = -1;
		mylist.push_back(north);mylist.push_back(west);mylist.push_back(south);mylist.push_back(east);
	}

	if(pos1 == 0 && pos2 ==0){
		node* south = new node();
		south->id = b->id;
		node* east = new node();
		east->id = b->id;
		south->id[pos1][pos2] = south->id[pos1+1][pos2];
		south->id[pos1+1][pos2] = -1;
		east->id[pos1][pos2] = east->id[pos1][pos2+1];
		east->id[pos1][pos2+1] = -1;
		mylist.push_back(south);mylist.push_back(east);
	}
	if(pos1 == 2 && pos2 ==2){
		node* north = new node();
		north->id = b->id;
		node* west = new node();
		west->id = b->id;
		north->id[pos1][pos2] = north->id[pos1-1][pos2];
		north->id[pos1-1][pos2] = -1;
		west->id[pos1][pos2] = west->id[pos1][pos2-1];
		west->id[pos1][pos2-1] = -1;
		mylist.push_back(north);mylist.push_back(west);
	}
	if(pos1 == 0 && pos2 ==1){
		node* west = new node();
		west->id = b->id;
		node* south = new node();
		south->id = b->id;
		node* east = new node();
		east->id = b->id;
		west->id[pos1][pos2] = west->id[pos1][pos2-1];
		west->id[pos1][pos2-1] = -1;
		south->id[pos1][pos2] = south->id[pos1+1][pos2];
		south->id[pos1+1][pos2] = -1;
		west->id[pos1][pos2] = west->id[pos1][pos2+1];
		west->id[pos1][pos2+1] = -1;
		mylist.push_back(west);mylist.push_back(south);mylist.push_back(east);;
	}
	if(pos1 == 0 && pos2 ==2){
		node* west = new node();
		west->id = b->id;
		node* south = new node();
		south->id = b->id;
		west->id[pos1][pos2] = west->id[pos1][pos2-1];
		west->id[pos1][pos2-1] = -1;
		south->id[pos1][pos2] = south->id[pos1+1][pos2];
		south->id[pos1+1][pos2] = -1;
		mylist.push_back(west);mylist.push_back(south);
		
	}
	if(pos1 == 1 && pos2 ==0){
		node* north = new node();
		north->id = b->id;
		node* south = new node();
		south->id = b->id;
		node* east = new node();
		east->id = b->id;
		north->id[pos1][pos2] = north->id[pos1-1][pos2];
		north->id[pos1-1][pos2] = -1;
		south->id[pos1][pos2] = south->id[pos1+1][pos2];
		south->id[pos1+1][pos2] = -1;
		east->id[pos1][pos2] = east->id[pos1][pos2+1];
		east->id[pos1][pos2+1] = -1;
		mylist.push_back(north);mylist.push_back(south);mylist.push_back(east);
	}
	if(pos1 == 2 && pos2 ==0){
		node* north = new node();
		north->id = b->id;
		node* east = new node();
		east->id = b->id;
		north->id[pos1][pos2] = north->id[pos1-1][pos2];
		north->id[pos1-1][pos2] = -1;
		east->id[pos1][pos2] = east->id[pos1][pos2+1];
		east->id[pos1][pos2+1] = -1;
		mylist.push_back(north);mylist.push_back(east);
	}
	
	if(pos1 == 1 && pos2 ==2){
		node* north = new node();
		north->id = b->id;
		node* west = new node();
		west->id = b->id;
		node* south = new node();
		south->id = b->id;
		north->id[pos1][pos2] = north->id[pos1-1][pos2];
		north->id[pos1-1][pos2] = -1;
		west->id[pos1][pos2] = west->id[pos1][pos2-1];
		west->id[pos1][pos2-1] = -1;
		south->id[pos1][pos2] = south->id[pos1+1][pos2];
		south->id[pos1+1][pos2] = -1;
		mylist.push_back(north);mylist.push_back(west);mylist.push_back(south);
	}
	
	if(pos1 == 2 && pos2 ==1){
		node* north = new node();
		north->id = b->id;
		node* west = new node();
		west->id = b->id;
		node* east = new node();
		east->id = b->id;
		north->id[pos1][pos2] = north->id[pos1-1][pos2];
		north->id[pos1-1][pos2] = -1;
		west->id[pos1][pos2] = west->id[pos1][pos2-1];
		west->id[pos1][pos2-1] = -1;
		east->id[pos1][pos2] = east->id[pos1][pos2+1];
		east->id[pos1][pos2+1] = -1;
		mylist.push_back(north);mylist.push_back(west);mylist.push_back(east);
	}

	return mylist;

}







int main(){
	return 0;
}

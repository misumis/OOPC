
#include <iostream>
#ifndef MAP_TEMPLATE_H_
#define MAP_TEMPLATE_H_
using namespace std;
//n-name, v-value
template <class N, class V> 

class map_template{
private:
	struct node{
		node * next;
		N name;
		V value;
		node(N name, V value, node* next){
			this->name = name;
			this->value = value;
			this->next = next;
		}
		node(N name,V value){
			this->name = name;
			this->value = value;
			this->next = NULL;
		}
		~node(){}
	};
	node* head;
	void clear(){
		while(head){
			node * t = head -> next;
			delete head;
			head = t;
		}
	}
public:
	map_template(){
		head = NULL;
	}
	~map_template(){
		clear();
	}
	map_template(const map_template& m){
		node * t = m.head;
		head = NULL;
		while(t){
			node * tmp = new node((t->name), (t->value), head);
			this->head = tmp;
			t = t->next;
		}
	}
	void Add(N name,V value){
		node * tmp = new node(name, value, head);
		this->head = tmp;
	}
	V* Find(N name){
		node * t = head;
		while(t){
			if ((t->name) == name){
				return &(t->value);
			}
			t = t->next;
		}
		return NULL;
	}
	map_template& operator=(const map_template& m){
		if(&m == this)
		{
			return *this;
		}
		node * t = m.head;
		clear();
		while(t){
			node * tmp = new node((t->name), (t->value), head);
			this->head = tmp;
			t= t->next;
		}
		return *this;
	}
	friend ostream& operator << (ostream&o, map_template& m){
		node * t = m.head;
		while(t){
			o << (t->name) << " : " << (t->value) << endl;
			t = t->next;
		}
		return o;
	}
};



#endif 

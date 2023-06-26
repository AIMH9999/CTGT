#include <stdio.h>

struct NODE{
	int data;
	int stt;
	NODE *Next;
};

struct LIST{
	NODE *Head = NULL;
	NODE *Tail = NULL;
};

NODE *createnode(int s){
	int x;
	printf("Nhap gia tri:");
	scanf("%d", &x);
	NODE *p = new NODE();
	p->data = x;
	p->stt = s;
	p->Next = NULL;	
}

void addtail(LIST &l, NODE *p){
	if(l.Head==NULL){
		l.Head = p;
		l.Tail = p;
	}
	else{
		l.Tail->Next = p;
		l.Tail = p;
	}
}
void addposition(NODE *p, NODE *q){
	q->Next = p->Next;
	p->Next = q;
}

void deletehead(LIST &l){
	NODE *p = new NODE();
	p = l.Head;
	l.Head = l.Head->Next;
    p->Next = NULL;
    delete p;
}

int main(){
	LIST l;
	int i=1, n, position, a;
	printf("Nhap so phan tu:");
	scanf("%d", &n);
	while(i<=n){
		NODE *p = createnode(i);
		addtail(l, p);
		i++;		
	}
	for(NODE *p = l.Head;p!=NULL;p=p->Next){
		printf("[%d]=%d, ", p->stt, p->data);
	}
	printf("\nNhap vi tri muon chen:");
	scanf("%d", &position);
	for(NODE *p = l.Head;p!=NULL;p=p->Next){
		if(position == p->stt + 1){
			NODE *q = createnode(position);
			addposition(p, q);
			a = q->data;
		}
		if(p->stt >= position && p->data != a){
			p->stt = p->stt + 1;
		}
		
	}
	for(NODE *p = l.Head;p!=NULL;p=p->Next){
		printf("[%d]=%d, ", p->stt, p->data);
	}
	printf("\n");
	deletehead(l);
	for(NODE *p = l.Head;p!=NULL;p=p->Next){
		printf("[%d]=%d, ", p->stt, p->data);
	}
}
# include<iostream>
using namespace std;
void wait(){
   while(1)
	   ;
}
void error(){
   cout<<"error"<<endl;
   exit(1);
}
typedef struct LNode{
	int info;
	LNode *next;
}LNode,*LList;
void init(LList &L){
    L=new LNode;
	L->next=NULL;
}
void insert_pre(LList &L,LNode *p,LNode *q){
    LNode *s;
	s=L;
	while(s&&s->next!=p)s=s->next;
	if(!s)error();
	s->next=q;
	q->next=p;
}
void insert_pos(LList &L,LNode *p,LNode *q){
   LNode *s;
   s=L;
   while(s&&s!=p)s=s->next;
   if(!s)error();
   p->next=q;
   q->next=s;
}
void insert_last(LList &L,int x){
   LNode *s,*p;
   LNode *q=new LNode;
   q->info=x;
   s=L;
   while(s->next)s=s->next;
   if(!s)error();
   p=s->next;
   s->next=q;
   q->next=p;
}
int delete_node(LList &L,LNode *p){
   LNode *q;
   q=L;
   while(q->next&&q->next!=p)q=q->next;
   if(!q->next)error();
   q->next=p->next;
   int x;
   x=p->info;
   delete p;
   return x;
}
void show(LList &L){
   LNode *q;
   q=L->next;
   while(q->next){
	   cout<<q->info<<" ";
       q=q->next;
   }
}
LNode* locate(LList &L,int x,int i){
   LNode *q;
   q=L;
   while(q->next&&q->info!=x)q=q->next;
   if(!q->next)error();
   return q;
}
LNode* locate(LList &L,int k){
   LNode *q;
   q=L;
   int i=1;
   while(q->next&&i!=k){
	   q=q->next;
       ++i;
   }
   if(!q->next)error();
   return q;
}
int main(){
   LList l;
   init(l);
   int i=0;
   for(;i!=5;++i)
     insert_last(l,i);
   show(l);
   wait();
}

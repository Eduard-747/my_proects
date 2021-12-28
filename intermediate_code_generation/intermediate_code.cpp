struct E
{
	int c ; 
};
struct A;
struct A_vtable 
{
int(*v)(A*);
void(*v_function)(A*,int,int);
}Atable;
struct A
{
	int l ; 
	int x ; 
	A_vtable* v_ptr ;
struct B
{
	int b ; 
};
struct C
{
	int c ; 
};
};
	int a; 
struct D;
struct D_vtable 
{
void(*ese_virtuaL)(D*);
}Dtable;
struct D
{
	A subObj ;
	int d ; 
	D_vtable* v_ptr ;
};
void _E ( E * that ) { } 
void _E ( E * that , int c ) { } 
void foo ( E * that , int i , int l ) { } 
void set_b ( A::B * that , int x1 ) { E obj2 ; _E(&obj2,8); that->b = x1 ; } 
void set_c ( A::C * that , int x2 ) { E obj3 ; that->c = x2 ; } 
void _A ( A * that ) { E obj1 ; _E(&obj1,5); foo(&obj1,9,747) ; that->l = 444 ; } 
void _A ( A * that , int y ) { that->l = 444 ; } 
void _A ( A * that , const A & o ) { that->l = 444 ; } 
void set_x ( A * that , int x ) { that -> x = x ; } 
void foo ( ) { long kk ; } 
int v ( int j ) { return 333 ; } 
void v_function ( int a , int v ) { } 
void ese_virtuaL ( D * that ) { int l ; } 
int main ( ) { A obj4 ; A * pobj = new A ( ) ; pobj->v_ptr = (A_vtable*)&Dtable ; set_x(&obj4,3) ; } 
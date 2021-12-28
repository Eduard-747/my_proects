class E
{
public:
    E() {

    }
    E(int c) {

    }
    void foo(int i,int l) {

    }
    int  c ;
} ;
class A
{
public:
    int l ;
    A() 
    {
        E obj1(5);
        obj1.foo(9,747) ;
        l = 444 ;
    }
    A(int y) 
    {
        l = 444 ;
    }
    A(const A& o) 
    {
        l = 444 ;
    }
    void set_x (int x) {
        this->x = x ;
    }
    static void foo() 
    {
        long kk ;
    }
    static int a ;
public:   
    class B {
    public:
        void set_b (int x1) {
            E obj2(8) ;
            b = x1 ;
        }
        int b ;
    } ;

    class C {
    public:
       void set_c ( int x2 ) {
           E obj3 ;
            c = x2 ;
        }
        int c;
    } ;
    virtual int v(int j) {
        return 333 ;
    }
    virtual void v_function(int a,int v) 
    {
        
    }
    int x;
} ;

class D : public A
{
public:
    virtual void ese_virtuaL(int v ){
        int l ;
    }
    int d ;
    
} ;
int  main()
{
    A obj4 ;
    A * pobj = new A() ;
    obj4.set_x(3) ;
    pobj->set_x(747) ;
    pobj->v(2) ;
}
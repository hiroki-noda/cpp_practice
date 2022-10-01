#include <cstdio>

class Class1
{
    private:
    friend void func1(Class1&);
    friend class ClassFriend;
    int num;
    public:
    void print();
};

void Class1::print()
{
    printf("%02d\n", num);
    fflush(stdout);
}

void func1(Class1& c)
{
    c.num = 123;
    c.print();
}

class ClassFriend
{
    public:
    static void func2(Class1& c) 
    {
        c.num = 456;
        c.print();
    }
};

int main()
{
    Class1 c;
    func1(c);
    ClassFriend::func2(c);
}
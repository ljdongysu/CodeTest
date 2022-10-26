#include <iostream>

using namespace std;
struct Object
{
    enum ClassID
    {
        UNKNOWN = 0, PERSON, ESCALATOR, HANDRAILS, PERSON_DUMMY
    };
};
int main()
{


    return 0;
int * ip_a;
int * ip_b;

std::cout<<"line: "<<10<<std::endl;
ip_a = (int*)malloc( sizeof (int) * 5 );std::cout<<"line: "<<11<<std::endl;
for( int j = 0; j < 5; j++ )
{
   cout<<ip_a[j]<<" ";
}
for( int i = 0; i < 5; i++ )
{
   cin>>ip_a[i];
}
std::cout<<"line: "<<16<<std::endl;
for( int j = 0; j < 5; j++ )
{
   cout<<ip_a[j]<<" ";
}

ip_a = (int *) realloc(ip_a, sizeof(int)*10);
std::cout<<"line: "<<16<<std::endl;
for( int j = 0; j < 10; j++ )
{
   cout<<ip_a[j]<<" ";
}

std::cout<<"line: "<<21<<std::endl;
ip_b = ( int* )calloc( 5, sizeof(int) );
for( int j = 0; j < 5; j++ )
{
   cout<<ip_b[j]<<" ";
}
std::cout<<"line: "<<28<<std::endl;
printf("end\n");
return 0;
}


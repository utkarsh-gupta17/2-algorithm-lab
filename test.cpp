#include <bits/stdc++.h>
using namespace std;
class movie{
    int x;
    int y;
    char category;
    public:
    movie(int a,int b,char d){
        this->x=a;
        this->y=b;
        this->category=d;
    }
};
int main(){
    movie m1(100,25,'a');
    movie m2(20,90,'c');
    movie m3(95,15,'a');
    movie m4(25,110,'c');
}
#include<bits/stdc++.h>
using namespace std;

void qfun(float a, float b, float c){
    float m = ((pow(b,2))-4*a*c);
    // cout<<m<<endl;
    if(m>=0){
        float x1 = ((-b)+sqrt(m))/(2*a);
        float x2 = ((-b)-sqrt(m))/(2*a);
        cout<<" Possible roots are : "<<x1<<" and "<<x2<<endl;
    }
    else{
        cout<<"No real roots are possible "<<endl;
    }
}

int main(){
    // ax^2 + bx + c=0
    float a,b,c;
    cin>>a>>b>>c;
    qfun(a,b,c);
    return 0;
}

class Solution {
public:
    int romanToInt(string s) {
        int n = size(s);
        int ans=0;
        for(int i = 0; i< n ;i ++){
            
            if(s[i]=='I'){
                if(s[i+1]=='V'){
                    ans-=1;
                }
                else if(s[i+1]=='X'){
                    ans-=1;
                }
                else{
                    ans+=1;
                }
            }
            if(s[i]=='V'){
                ans+=5;
            }
            if(s[i]=='X'){
                if(s[i+1]=='L'){
                    ans-=10;
                }
                else if(s[i+1]=='C'){
                    ans-=10;
                }
                else{
                    ans+=10;
                }
            }
            if(s[i]=='L'){
                ans+=50;
            }
            if(s[i]=='C'){
                if(s[i+1]=='D'){
                   ans-=100; 
                }
                else if(s[i+1]=='M'){
                    ans-=100;
                }
                else{
                    ans+=100;
                }
            }
            if(s[i]=='D'){
                ans+=500;
            }
            if(s[i]=='M'){
                ans+=1000;
            }
        }
        return ans;
    }
};

vector<int> Solution::maxset(vector<int> &A) {
    int n= A.size();
    vector<int> ans;
    vector<int> temp;
    long long int sum=0, maxsum=0;
    for(int i=0; i<n; i++){
        if(A[i]>=0){
            temp.push_back(A[i]);
            sum+=A[i];
            if(sum>maxsum){
                ans=temp;
                maxsum=sum;
            }
            else if(maxsum==sum){
                if(temp.size()>ans.size()){
                    ans=temp;
                }
            }
        }
        else{
            temp.clear();
            sum=0;
        }
    }
    return ans;
}
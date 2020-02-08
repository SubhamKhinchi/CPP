vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long int n=A.size(); 
    long long int missing,repeating;
    long long int sum=(n*(n+1))/2;
    long long int sumsq = (n*(n+1)*(2*n+1))/6;
    
    for(int i=0; i<n; i++){
        sum-=(long long int)A[i];
        sumsq-=(long long int)A[i]*(long long int)A[i];
    }
    missing= (sum+sumsq/sum)/2;
    repeating = missing -sum;
    vector<int> ans;
    ans.push_back(repeating);
    ans.push_back(missing);
    return ans;
}
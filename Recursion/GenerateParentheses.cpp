class Solution {
public:
    void f(int opening, int closing, int n,vector<string> &res, string ans){
        if(opening == n){
            if(closing == n){
                res.push_back(ans);
                return;
            }
            while(closing<n){
                ans = ans + ")";
                closing++;
            }
            res.push_back(ans);
            return;
        }
        if(opening>= closing){
            f(opening+1, closing, n, res,ans+"(");
            f(opening,closing+1,n,res,ans +")");
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string ans = "";
        f(0,0,n,res,ans);
        cout<<res.size();
        return res;
    }
};

class Solution {
public:
    void fun(int ind, int n, string digits, unordered_map<int, string> &m, vector<string> &res, string &ds){
        if(ind == n){
            res.push_back(ds);
            return;
        }
        string val = m[digits[ind]-'0'];
        for(int i=0;i<val.size();i++){
            ds = ds + val[i];
            fun(ind+1,n,digits,m,res,ds);
            ds.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<int, string> m;        
        vector<string> res;
        string ds = "";
        int n = digits.size();
        if(n<1) return res;
        m[1] = {""};
        m[2] = {"abc"};
        m[3] = {"def"};
        m[4] = {"ghi"};
        m[5] = {"jkl"};
        m[6] = {"mno"};
        m[7] = {"pqrs"};
        m[8] = {"tuv"};
        m[9] = {"wxyz"};
        fun(0,n,digits,m,res,ds);
        return res;

    }
};

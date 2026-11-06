class Solution {
public:
    vector<string> ans;
    
    vector<string> addOperators(string s, int target) {
        helper(s,target, 0, "", 0, 0);
        return ans;
    }
    void helper(string s, int target,int i, const string& path, long eval, long residual) {
        // bc
        if(i==s.length()){
            if(eval==target){
                ans.push_back(path);
                return;
            }
        } 
        string currStr;
        long num=0;
        // backtracking loop
        for(int j=i;j<s.length();j++){
            // handle 0
            if(j>i && s[i]=='0') return;
            currStr+= s[j]; 
            num= num*10 + s[j]- '0';
            if(i==0){
                helper(s,target, j+1,path+ currStr,num, num);
            }
            else{
                helper(s,target,j+1,path + "+" + currStr, eval + num, num);
                helper(s,target,j+1,path + "-" + currStr, eval - num, -num);
                helper(s,target,j+1,path + "*" + currStr, eval -residual + residual*num , residual*num);


            }
        }
        
        
    }
};

// class Solution {
// public:
//     vector<string> ans;
//     vector<string> addOperators(string num, int target) {
//         helper(num, target, 0, "", 0, 0);
//         return ans;
//     }
//     void helper(string s, int target, int i, string path, long eval, long prev)
//     {
//         if(i == s.size())
//         {
//             if(eval == target)
//             {
//                 ans.push_back(path);
//             }
//             return;
//         }
//         for(int j = i; j < s.size(); j++)
//         {
//             //handel '0' 
//             if(j > i && s[i] == '0') return;
//             string currStr = s.substr(i, j-i+1);
//             long number = stol(currStr);
//             if(i == 0)
//             {
//                 helper(s, target, j + 1, path + currStr, number, number);
//             }
//             else
//             {
//                 helper(s, target, j + 1, path + "+" + currStr, eval+number, number);
//                 helper(s, target, j + 1, path + "-" + currStr, eval-number, -number);
//                 helper(s, target, j + 1, path + "*" + currStr, eval-prev + prev*number, prev*number);
//             }
//         }
//     }
// };
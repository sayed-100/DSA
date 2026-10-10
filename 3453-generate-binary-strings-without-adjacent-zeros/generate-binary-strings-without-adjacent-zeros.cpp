class Solution {
private:
    void Generate_BinaryStrings_Without_AdjacentZeros(string &s, int last, vector<string> &ans, int n )
    {
        //Base Case
        if(s.size()==n)
        {
            ans.push_back(s);
            return;
        }
        //explore if 1 pick 
        s.push_back('1');
        Generate_BinaryStrings_Without_AdjacentZeros(s,1,ans,n);
        //undo
        s.pop_back();
        //explore if 0 pick
        if(last != 0)
        {
            s.push_back('0');
            Generate_BinaryStrings_Without_AdjacentZeros(s,0,ans,n);
            //undo
            s.pop_back();
        }
    }
public:
    vector<string> validStrings(int n){
        string s ="";
        vector<string> ans;
        Generate_BinaryStrings_Without_AdjacentZeros(s,-1,ans,n);
        return ans;
    }
};
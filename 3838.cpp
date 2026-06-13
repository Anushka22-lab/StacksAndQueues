class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        unordered_map<int,char>mp;
        int res=0;
        char ch;
        int w;
       
        for(int i=0;i<words.size();i++){
            int res=0;
            for(int j=0;j<words[i].size();j++){
               ch=words[i][j];
               res+=weights[ch-'a'];
               
            }
            w=res%26;
            ans+='z'-w;}
        return ans;
    }
};
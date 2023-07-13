//Recursion
T.C:-O(n*(2^(n-1)))
S.C:-O(n*(2^(n-1)))
#include <bits/stdc++.h> 
void generate(string &s,string &t,unordered_map<string,bool>& mp,int ind,vector<string>& ans){
    if(ind==s.length()){
        ans.push_back(t);
        return;
    }

    for(int i=ind;i<s.length();i++){
        int sz=t.length();
        if(mp[s.substr(ind,i-ind+1)]){
            t.append(s.substr(ind,i-ind+1));
            t.push_back(' ');
            generate(s,t,mp,i+1,ans);
            int size=t.length();
            /*t=t.substr(0,size-(i-ind+2));*/
            while(size!=sz){
                t.pop_back();
                size--;
            }
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    unordered_map<string,bool>mp;
    for(auto &it:dictionary) mp[it]=true;
    vector<string>ans;
    string t;
    generate(s,t,mp,0,ans);
    return ans;
}

class Solution {
public:
    bool isSubFolder(string& str1, string& str2){
        if(str2.size()<=str1.size()) return false;
        int i=1;
        while(i<str1.size()){
            if(str1[i]!=str2[i]) return false;
            i++;
        }
        if(str2[i]=='/') return true;
        else return false;
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string> res;
        for(int i=0;i<folder.size();i++){
            if(res.empty() || (!isSubFolder(res.back(), folder[i]))) res.push_back(folder[i]);
        }
        return res;
    }
};
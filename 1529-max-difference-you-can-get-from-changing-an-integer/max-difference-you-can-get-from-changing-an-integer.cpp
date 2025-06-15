class Solution {
public:
    int maxDiff(int num) {
        string s1 = to_string(num);
        int i=0;
        while(i<s1.size() && s1[i]=='9') i++;
        char x;
        if(i<s1.size()) x=s1[i];
        else x=0;
        for(i;i<s1.size();i++){
            if(s1[i]==x) s1[i]='9';
        }
        int a = stoi(s1);

        string s2 = to_string(num);
        if(s2[0]!='1'){
            char y=s2[0];
            for(int k=0;k<s2.size();k++)
            {
                if(s2[k]==y) s2[k]='1';
            }
            int b = stoi(s2);
            return a-b;
        }
        int j=1;
        while(j<s2.size() && (s2[j]=='0' || s2[j]=='1'))j++;
        char y = s2[j];
        for(j;j<s2.size();j++){
            if(s2[j]==y) s2[j]='0';
        }
        int b = stoi(s2);
        return a-b;
    }
};
class Solution {
public:
    string intToRoman(int num) {
        map<int,string,greater<int>> m{
            {1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},{100,"C"},{90,"XC"},{50,"L"},{40,"XL"},{10,"X"},{9,"IX"},{5,"V"},{4,"IV"},{1,"I"}
        };
        string result;
        for(auto x:m){
            while(num>=x.first){
                result+=x.second;
                num-=x.first;
            }
        }
        return result;
    }
};
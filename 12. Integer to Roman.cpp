## https://leetcode.com/problems/integer-to-roman/
class Solution {
public:
    string repeat(string s,int count){
        string response = "";
        while(count--){
            response += s;
        }
        return response;
    }
    string intToRoman(int num) {
       map<int,string> roman = {{1,"I"},{5,"V"},{10,"X"},{50,"L"},{100,"C"},{500,"D"},{1000,"M"}};
       map<int,string> exceptions = {{4,"IV"},{9,"IX"},{40,"XL"},{90,"XC"},{400,"CD"},{900,"CM"}};
        string res = "";
        vector<int> divisors = {1000,100,10,1};
        int index = 0;
        while(num!=0){
            bool at = false;
            int quotient = num/divisors[index];
            if( quotient == 0){
                index++;
            }
            else{
                if(exceptions.find(quotient*divisors[index])==exceptions.end()){
                    if(roman.find(quotient*divisors[index])==roman.end()){
                        if(quotient > 5){
                            quotient -= 5;
                            res += roman[5*divisors[index]];
                            at = true;
                        }
                        else
                            res += repeat(roman[divisors[index]],quotient);   
                    }
                    else
                        res += roman[quotient*divisors[index]];
                }
                else{
                    res += exceptions[quotient*divisors[index]];
                }
                if(at)
                    num -= divisors[index] * 5;       
                else
                    num -= divisors[index] * quotient;
            }
        }
        return res;
    }
};
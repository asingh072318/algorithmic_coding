## https://leetcode.com/problems/reverse-words-in-a-string-iii/
class Solution {
public:
    string reverseString(string str){
        int i=0,j=str.size()-1;
        while(i<j){
            swap(str[i],str[j]);
            i++;
            j--;
        }
        return str;
    }
    string reverseWords(string s) {
        string newStr="",response="";
        int size = s.size();
        for(int i=0;i<=size;i++){
            if(i==size || s[i]==' '){
                response+=reverseString(newStr);
                if(i!=size)
                    response+=" ";
                newStr="";
            }
            else{
                newStr+=s[i];
            }
        }
        return response;
    }
};
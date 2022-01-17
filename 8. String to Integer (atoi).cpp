## https://leetcode.com/problems/string-to-integer-atoi/
class Solution {
public:
    bool checknumber(char s){
        return s>='0' && s<='9';
    }
    int myAtoi(string s) {
      int traverse=0;
      while(s[traverse]==' ')
          traverse++;
      bool positive = true;
      if(s[traverse]=='+')
          traverse++;
      else if(s[traverse]=='-'){
          positive=false;
          traverse++;
      }
      int end = traverse;
      while(checknumber(s[end]))
          end++;
      long long response = 0;
      while(traverse<end){
          response=response*10+(s[traverse]-'0');
          cout<<response<<endl;
          traverse++;
          if(response>=INT_MAX)
              break;
      }
      if(response >= pow(2,31) && positive)
          return 2147483647;
      if(!positive && response>pow(2,31))
          return -2147483648;
      if(!positive)
          return -1*response;
      return response;
    }
};
class Solution {
public:
    bool isValid(string s) {
         char openBracket = (char)40;
            char closeBracket = (char)41;
        stack <char> stk;
        if(s.length() == 1){
            return false;
        }
        for ( int i = 0 ; s[i] != '\0'; i++){ 
        char ch = s[i]; 
        if ( ch == '(' ||ch ==  '{' || ch == '[') { 
        stk.push (ch);
        }
        else if ( ch == closeBracket && ( stk.empty()||  stk.top() != openBracket )){ 
             return false ;
            }
         
        
        else if ( ch == '}' && (stk.empty() || stk.top() != '{' )){ 
             return false ;
            }
        
        else if ( ch == ']' &&( stk.empty() || stk.top() != '[' )){ 
             return false ;
            }
        else{
            stk.pop ();
        }
            
        }
            
            
     
        return stk.empty ();
    }
};
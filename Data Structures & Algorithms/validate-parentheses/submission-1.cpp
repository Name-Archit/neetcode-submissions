class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> valid;

        for(auto it: s){
            if(it == '[' || it == '{' || it == '(') valid.push(it);
            else{
                if(!valid.empty()){
                    char lastEle = valid.top();

                    if(it == ']'){
                        if( lastEle == '[') valid.pop();
                        else return 0;
                    }

                    if(it == '}'){
                        if(lastEle == '{') valid.pop();
                        else return 0;
                    }
                    if(it == ')'){
                        if(lastEle == '(') valid.pop();
                        else return 0;
                    }
                }
                else return 0;                
            }
        }

        if(valid.size() == 0) return 1;

        return 0;
    }
};

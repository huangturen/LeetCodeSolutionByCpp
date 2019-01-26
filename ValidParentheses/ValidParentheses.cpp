bool isValid(string s) {
        if (s.size()==0)return true;
        if (s.size() < 2) {
            return false;
        }
        map<char, char> mapping;
        mapping['}'] = '{';
        mapping[']'] = '[';
        mapping[')'] = '(';
        stack<char> stk;
        for (string::iterator iter = s.begin(); iter != s.end(); iter++) {
            if (mapping.find(*iter) != mapping.end()) {
                char top = stk.empty()? '#' : stk.top();
                if (!stk.empty()) {
                    stk.pop();
                }
                if (top != mapping[*iter]) {
                    return false;
                }
            }
            else{
                stk.push(*iter);
            }
        }
        return stk.empty();
    }

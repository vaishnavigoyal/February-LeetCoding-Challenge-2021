// Day 5
// Question : Simplify Path

class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
	vector<string> tokens;
	string ans,s;
	while(getline(ss,s,'/')){
		if(s=="." || s=="") continue;
		else if(s!="..") tokens.push_back(s);
		else if(!tokens.empty()) tokens.pop_back();
	}
	for(auto& ele:tokens) ans+="/"+ele;
	return tokens.empty()?"/":ans;
    }
};
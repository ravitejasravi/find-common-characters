class Solution {
public:
    vector<string> commonChars(vector<string>& words) {

        unordered_map<char, int> diff;
        vector<string> result;

        for(int i = 0; i < words[0].length(); i++) diff[words[0][i]]++;

        for(int i = 1; i < words.size(); i++) {

            unordered_map<char, int> inter;

            for(int j = 0; j < words[i].length(); j++) inter[words[i][j]]++;
                 
            for(auto k : diff) diff[k.first] = min(inter[k.first], k.second);
        
        }

        for(auto i = diff.begin(); i != diff.end(); i++) 
            if(i->second > 0) {
                string str(1,i->first);
                for(int j = 1; j <= i->second; j++) 
                    result.push_back(str);
            }

        return result;
    }
};
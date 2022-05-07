class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string>st;
        int ans=0;
        
        for(int i=0; i<emails.size(); i++){
           string temp;
            for(auto itr: emails[i]){
                if(itr=='.') continue;
                if(itr=='+' || itr=='@') break;
                temp+=itr;
            }
            temp+=emails[i].substr(emails[i].find('@'));
            cout<<temp<<endl;
            st.insert(temp);
        }
        return st.size();
    }
};
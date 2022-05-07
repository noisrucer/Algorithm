int solve(vector<vector<string>>& contacts) {
    unordered_set<string>st;
    int dup_cnt = 0;
    vector<string>temp;
    for(auto &contact: contacts){
        bool flag = false;
        for(auto &email: contact){
            if(st.count(email)) flag = true; 
            temp.push_back(email);
        }
        if(flag) dup_cnt++;
        for(auto &email: temp) st.insert(email);
        temp.clear();
    }
    return contacts.size() - dup_cnt;
}
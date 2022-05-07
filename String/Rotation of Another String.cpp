bool solve(string s1, string s2) {
    if(s1.length() != s2.length()) return false;
    s2 = s2 + s2;
    return s2.find(s1) != string::npos;
}

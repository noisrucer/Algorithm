int solve(int n) {
    string str = to_string(n);

    for(int i=0; i<str.length(); i++){
        if(str[i] - '0' < 3){
            str[i] = '3';
            break;
        }
    }


    return stoi(str);
}
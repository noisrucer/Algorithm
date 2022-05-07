int solve(string s) {
    int res = 0;
    int random = 0;
    for(char c: s){
        if(c=='L') res--;
        else if(c=='R') res++;
        else random++;
    }

    return res > 0 ? abs(res+random) : abs(res-random);
}
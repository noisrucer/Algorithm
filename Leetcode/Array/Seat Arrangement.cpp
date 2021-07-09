bool solve(int n, vector<int>& seats) {
    seats.push_back(0); seats.push_back(1);
    int len = seats.size();
    int temp=1, availableSeats = 0;
    for(int i=0; i<len; i++){
        if(seats[i]==1){
            availableSeats += (temp-1)/2;
            temp = 0;
        }else{
            temp++;
        }
    }
    cout<<availableSeats;
    return availableSeats >= n;
}
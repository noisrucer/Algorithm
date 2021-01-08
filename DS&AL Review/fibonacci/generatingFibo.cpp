
int main(){
    int n=100;
   
   int s = 0, e = 1;
    while (s+e <= n) {
        int temp = s + e;
        cout<<temp<<" ";
        s = e;
        e = temp;
        
    }
}
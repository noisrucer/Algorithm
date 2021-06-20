int solve(vector<int>& cells) {
    int n = cells.size();
    
   priority_queue<int>pq;
   for(auto &i: cells) pq.push(i);
   int x, y;

   while(pq.size()>1){
       x = pq.top(); pq.pop();
       y = pq.top(); pq.pop();

       if(x!=y) pq.push(floor((x+y)/3));
   }

   return pq.size()==1 ? pq.top() : -1;
}        
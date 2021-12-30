#include <iostream>
// #include <string>
using namespace std;

// 1. return할 자료형 
// 2. 함수이름
// 3. 인자(parameter)
// 4. 중괄호안에 있는 아무거나를 "실행"
// 5. return값 반환

void superLoyalCustomerThankyou(){
    cout<<"YOU're GOD!!!!      "; 
}
void loyalCustomerThankyou(){
    cout<<"You're fucking loyal customer!!!     ";
}

void normalThankyou(){
    cout<<"USER"<<", THANK YOU!!!!!!!!"<<endl;
}


void thankyou(int userID, int price){
    if(price > 300) superLoyalCustomerThankyou();
    else if(price > 200) loyalCustomerThankyou();
    else normalThankyou();
}

int main(){       
   int user_purchased_price[10] = {10, 30, 300, 40, 50, 2, 6, 3, 4, 6};
   
   for(int id=0; id<10; id++)
       if(user_purchased_price[id] >= 50)
           thankyou(id, user_purchased_price[id]);
}


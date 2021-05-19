<Question 2>
//Initialization 
T1 Bit 1 = 1 //Allow Entrance
T2 Bit 2 = 1 //Disallow Exit
n = 0


REPEAT: 
if(n==0) T2 Bit 2 = 1 // Disallow Exit if n==0
if(n==70) T1 Bit 2 = 1 //Disallow Exit if n==70

if(T1 Bit 3 == 1){  // If someone passes the entrance
  T1 Bit 3 = 0 // Reset to zero after reading
  T1 Bit 2 = 1 // Disallow Entrance
  T1 BIt 1 = 0 // Make Bit 1(which is Allow entrance) to avoid contradiction
  n++;
  display LED;
  if(n != 70) { //If not full
    T1 Bit 1 = 1 // Allow Antrance
    T1 Bit 2 = 0 // Make Bit 2(which is Disallow entrance) to avoid contradiction 
  }
}

//Same logic for exit
if(T2 Bit 3 == 1){ //If someone passes the exit
  T2 Bit 3 = 0 //reset to zero after reading
  T2 Bit 2 = 1
  T2 Bit 1 = 0
  n--;
  Display LED
  if(n!=0){
    T2 Bit  1 = 1
    T2 Bit 2 = 0
  }
}

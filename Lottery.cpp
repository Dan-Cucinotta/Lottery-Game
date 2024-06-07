/* This program asks the user if they would like to play the lottery game 
and will continue asking after each time played. It instructs the user to
input 5 unique integers between 1 and 40, then will compare them to the 
randomly generated numbers to calculate if the user won or lost and 
finally displaying the random numbers, user chosen numbers, how many
numbers were matched correctly and whether the user won or lost.
*/

// PROGRAMMER: Daniel Cucinotta

#include<iostream>
#include<cstdlib>
#include<ctime>


using namespace std;

void sort(int [], int SIZE);
void random(int [], int , int , int );
void user(int [], int);
int compare(int [], int [], int);

const int SIZE = 5;		
const int MIN = 1;
const int MAX = 40;
int correct;
bool play = true;

	int main(){

int randNum[SIZE];
int userNum[SIZE];

unsigned seed = time(0);
srand(seed);	
	
	// Do-while loop performing as a sentinel.
	do{
		
char game;
	
	cout << "\n\n\tWould you like to play the lottery game? ('Y' or 'N'): ";
	cin >> game;
	cout << "\n";
	
	// If-else statements to play or exit. 
	if(game == 'y' || game == 'Y') {
	   play == true;
	}
	else{
		cout << "\n\t\t\tThank you for playing, goodbye\n\n";
		play = false;
		exit(0);
	}
// Three function calls.
random(randNum, SIZE, MIN, MAX);
	
sort(randNum, SIZE);
	
user(userNum, SIZE);

// Assigning the return value of the function to the variable.	
correct = compare(userNum, randNum, SIZE);
	
	// If-else statements to display if the user won or lost.
	if(correct == 5) {
		cout << "\nYAY! YOU WIN! - YAY! YOU WIN! - YAY! YOU WIN!"
		" - YAY! YOU WIN! - YAY! YOU WIN!\n";
		cout << "\tYou guessed all 5 numbers correctly.";
	}
	else{
		cout << "\n\tSorry, you lose...\n";
		cout << "\tYou only guessed " << correct << " number(s) correctly.";
	}
    
    cout << "\n\nThe numbers you chose are --> ";
		
	for(int i = 0; i < SIZE; i++) {
	   
	cout << userNum[i] << " ";

	}	
		
	cout << "\n\nThe lottery numbers are --> ";

  	for(int i = 0; i < SIZE; i++) {
	    cout << randNum[i] << " "; 
	    
	}
		
	cout << "\n";			

	}
	while(play == true);
	
	return 0;
}
	
	
	

// Bubble sort function to sort the values in ascending order.	
void sort(int randNum[], int SIZE) {
bool flag;
int store;

	do {
flag = false;

        for(int i = 0; i < (SIZE - 1); i++) {
        	
        	// If statement to compare for the highest value and swap.
            if(randNum[i] > randNum[i + 1]) {
store = randNum[i];
randNum[i] = randNum[i + 1];
randNum[i + 1] = store;

flag = true;
		}
	}
}
while (flag);
}




/* 
This function uses a variable to temporarily store the 
randomly generated number in to check if the number is a 
duplicate entry, and assigns the value to the array element
if the number is distinct.
*/	
void random(int randNum[], int SIZE, int MIN, int MAX) {
	
	// For loop to assign the randomly generated numbers into the array elements.
	for(int i = 0; i < SIZE; i++) {
bool flag; 
int store; 
        
        // Do-while loop to continue while flag is not false.
    	do{    		
    
store = (rand() % (MAX - MIN + 1)) + MIN;
    
flag = true;
    		
    	   // For loop to iterate through the elements to compare if it is a 
		   // duplicate. 
    	   for (int j = 0; j < i; j++)
    	   		
    	   		// If statement to determine if the temporarily stored random number
    	   		// is a duplicate and sets the bool variable flag to false if it is.
        		if (store == randNum[j]) {
            	flag = false; 
           	    break; 
        }
    } 
	while (!flag); 

// Assigns the distinct number to the array element.	
randNum[i] = store; 
	}	

}

	
	

// This function validates and accepts the user's input.
void user(int userNum[], int SIZE) {

// For loop to iterate through the array elements.	
for(int i = 0; i < SIZE; i++) {
bool flag; 
int store; 
     
	cout << "Please input 5 distinct positive integers between 1 - 40 or -1 to quit:\n";
   		
   		// Do-while loop to continue while the bool variable flag is not false.
		do{
			
			// Do-while loop to validate the user's input.
    		do {
   		  cout << i + 1 << ") ";
		  cin >> store;
	}
	while(store < -1 || store > 40 || store == 0); 
		  
		  // If statement to exit if the sentinel (-1) is entered.	
		  if(store == -1) {
		  	cout << "\n\t\t\tThank you for playing, goodbye\n\n";
			exit(0);
		}
    		// If statement to validate if the temporary value is between 1-40.
  			if(store >= 1 && store <= 40) {
			   flag = true;
		}

    		// For loop to itearate through the elements to compare.
    		for (int j = 0; j < i; j++)
    			
    			// If statement to determine if there is a duplicate.
        		if (store == userNum[j]) {
            	flag = false;
           	    break; 
        }
    } 
	while (!flag); 

// Assigns the value to the array element.	
userNum[i] = store; 
	}
}



	
// This function compares and calculates how many numbers match.
int compare(int userNum[], int randNum[], int SIZE) {
int numbers = 0;
		
		// For loop to iterate through each element in the userNum array.
		for(int i = 0; i < SIZE; i++){
			
			// Nested for loop to iterate through each element in the randNum array.
			for(int j = 0; j < SIZE; j++) {	
				
				// If statement to compare values and if necessary 
				// increment the accumulator variable numbers.
				if(userNum[i] == randNum[j]) {
				   numbers++;
		}
	}	
}
// Returns the accumulated value to be assigned to the variable correct for comparison.
return numbers;
}



/*
@author: Slater Mead
@Project: 1D Cellular Automata
This program asks the user for a ruleset integer that is converted to binary,
and used as the cellular automata ruleset. Starting generation has one set
bit in the direct middle of the array, and using the ruleset 49 further generations
are calculated and displayed within the terminal.
*/

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

// This function converts the integer to a binary value and stores it within the
// ArrayRuleSet, filling zeros for values that do not reach 8 bits.
void convertRuleSetNumberToRuleSetArray(int NumberRuleSet, int ArrayRuleSet[8]){

    for (int i = 0; i < 8; i++) {
        ArrayRuleSet[i] = 0;
    }
    for(int index = 0; NumberRuleSet != 0 && index<8; NumberRuleSet /=2, index++){
        //If the binary value is even or fill zeroes for shorter value
        if(NumberRuleSet % 2 == 0 || NumberRuleSet == 0){
            ArrayRuleSet[index] = 0;
        } 
        else{
            ArrayRuleSet[index] = 1;
            NumberRuleSet -= 1;
        }
   }
   
}

// Prints a space for a 0 in the generation array,
// and prints a # for a 1.
void displayGeneration(int ArrToDraw[], int ArrLength){

    for(int i = 0; i < ArrLength; i++){

        if(ArrToDraw[i] == 0){
            cout << " ";
        }
        else{
            cout << "#";
        }
    }
    cout << endl;
}

//This function receives three int values (0 or 1) and converts the
//"binary" value into an integer
int convertNeighborhoodToIndex(int left, int mid, int right){
    return (4*left) + (2*mid) + (1*right);
}

/*This function computes the next generation of cell automata given
the CurrentGeneration, the RuleSet array, and the Generation Length.
Uses the values stored to the left and right (in current generation) 
to map the rule set with the correct value*/
void computeNextGeneration(int currentGeneration[], int NextGeneration[], int GenerationLength, int RuleSet[]){

    //Copies beginning and end of CurrentGeneration to NextGeneration
    NextGeneration[0] = currentGeneration[0];
    NextGeneration[GenerationLength-1] = currentGeneration[GenerationLength-1];

    for(int i = 1; i < GenerationLength-1; i++){
        //Converts neighboring values to a 3 digit binary value, converted to integer to map rule set
        NextGeneration[i] = RuleSet[convertNeighborhoodToIndex(currentGeneration[i-1], currentGeneration[i], currentGeneration[i+1])];
    }
}

/* Runs the entire Cellular Automata based on user's input ruleset,
invoking other functions/methods as needed */
int main(){
    //Initialize structures/vals
    int ArrRuleSet[8];

    //Receive user input rule set integer (0-255)
    cout << "Enter a rule set integer between (0-255): ";
    int intRuleSet;

    //Ensures valid input
    if(!(cin >> intRuleSet)){
        cout << "Invalid input: Please enter a numeric value";
        return 0;
    }

    if(intRuleSet < 0 || intRuleSet > 255){
        cout << "Invalid input: Enter a value between 0-255";
       return 0;
    }
    
    //Converts int RuleSet to binary (to be used as the cell rule set)
    convertRuleSetNumberToRuleSetArray(intRuleSet, ArrRuleSet);

    //Initializes & displays starting array
    int currentGeneration[64] = {0};
    currentGeneration[32] = 1;
    displayGeneration(currentGeneration, 64);

    //Creates & displays 49 further generations
    int NextGeneration[64] = {0};
    for(int i = 0; i < 49; i++){
        computeNextGeneration(currentGeneration, NextGeneration, 64, ArrRuleSet);
        displayGeneration(NextGeneration, 64);
        
        //Copies the newly created generation to "CurrentGeneration"
        for(int j = 0; j < 64; j++){
            currentGeneration[j] = NextGeneration[j];
        }
    }
}
// copy all of the values in source1 which are also found in source2 into destination
// return the number of elements copied into destination

int common_elements(int length, int source1[length], int source2[length], int destination[length]) {
    // PUT YOUR CODE HERE (you must change the next line!)
    int com_ele = 0;
    int count = 0;
    for (int i = 0; i < length; i++){
        for (int k = 0; k < length; k++){
            if (source1[i] == source2[k]){
                com_ele++;
                destination[count++] = source1[i];
                k = length;
            }
        }
    }            
    return com_ele;
}

// You may optionally add a main function to test your common_elements function.
// It will not be marked.
// Only your common_elements function will be marked.

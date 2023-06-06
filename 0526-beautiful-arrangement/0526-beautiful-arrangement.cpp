class Solution {
public:
    int count = 0;
    
    // Function to count the number of valid arrangements
    int countArrangement(int N) {
        vector<bool> visited(N + 1, false); 
        calculate(N, 1, visited);        
        return count;                        
    }
    
    void calculate(int N, int pos, vector<bool>& visited) {
        if (pos > N) {   // Base cace
            count++;             
        }
        for (int i = 1; i <= N; i++) {        // Loop over all possible numbers
            if (!visited[i] && (pos % i == 0 || i % pos == 0)) {  // Check if the number is valid
                visited[i] = true;           // Mark the number as visited
                calculate(N, pos + 1, visited);  // Generate the next permutation recursively
                visited[i] = false;          // Unmark the number as visited
            }
        }
    }
};
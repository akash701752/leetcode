class Solution {
public:
    int minSteps(int n) {
        if (n == 1)
            return 0;
        else
        {   
            int counter = 1 ; // current number of A`s
            int op_counter = 1; // final answer
            int last_copy = 1;

            while(counter < n) 
            {
                if( (counter != 1) && !((n - counter) % counter) )
                {
                    last_copy = counter;
                    op_counter ++; 
                }

                counter += last_copy;
                op_counter++; 
            }  

            return op_counter;
        }
    }
};

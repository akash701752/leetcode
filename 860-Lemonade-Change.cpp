class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;  // Count of $5 and $10 bills
        
        for (int i = 0; i< bills.size(); i++) {
            int bill = bills[i];
            if (bill == 5) {
                five++;  // No change needed, just collect the $5 bill
            } else if (bill == 10) {
                if (five == 0) return false;  // Need one $5 bill as change
                five--;
                ten++;
            } else {  // bill == 20
                if (ten > 0 && five > 0) {
                    ten--;  // Give one $10 bill
                    five--;  // Give one $5 bill
                } else if (five >= 3) {
                    five -= 3;  // Give three $5 bills
                } else {
                    return false;  // Not enough change
                }
            }
        }
        
        return true;
    }
};

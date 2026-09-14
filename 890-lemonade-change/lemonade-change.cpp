class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;

        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) {
                five++;
            } 
            else if (bills[i] == 10) {
                // Need to return one $5 bill
                if (five == 0) return false;
                five--;
                ten++;
            } 
            else { // Customer pays with $20 (need $15 change)
                // Greedy choice: prefer one $10 + one $5
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                } 
                // Fallback: three $5 bills
                else if (five >= 3) {
                    five -= 3;
                } 
                // Cannot make change
                else {
                    return false;
                }
            }
        }

        return true;
    }
};
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st; // This vector acts as our Stack

        for (int a : asteroids) {
            bool survived = true;

            // Collision loop: The stack isn't empty, the stack top is moving RIGHT (+), 
            // and the incoming asteroid 'a' is moving LEFT (-)
            while (!st.empty() && st.back() > 0 && a < 0) {
                
                // Compare the absolute sizes
                if (st.back() < abs(a)) {
                    // Stack top is smaller. It explodes.
                    st.pop_back();
                    // The while loop continues so the incoming asteroid can fight the next one!
                } 
                else if (st.back() == abs(a)) {
                    // They are equal size. Both explode.
                    st.pop_back();
                    survived = false;
                    break; // Stop fighting
                } 
                else {
                    // Stack top is larger. The incoming asteroid explodes.
                    survived = false;
                    break; // Stop fighting
                }
            }

            // If the incoming asteroid didn't explode during the fights, it joins the survivors
            if (survived) {
                st.push_back(a);
            }
        }

        return st;
    }
    
};
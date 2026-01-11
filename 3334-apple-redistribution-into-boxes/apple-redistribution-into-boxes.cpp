class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        // Step 1: Calculate total apples
        int totalApples = 0;
        for (int a : apple) {
            totalApples += a;
        }

        // Step 2: Sort capacities in descending order
        sort(capacity.begin(), capacity.end(), greater<int>());

        // Step 3: Use boxes until apples are covered
        int boxesUsed = 0;
        for (int cap : capacity) {
            if (totalApples <= 0) break;
            totalApples -= cap;
            boxesUsed++;
        }

        return boxesUsed;
    }
};

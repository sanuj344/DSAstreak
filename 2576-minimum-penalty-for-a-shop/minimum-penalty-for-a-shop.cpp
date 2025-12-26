class Solution {
public:
    int bestClosingTime(string customers) {
        int totalY = 0;
        for (char c : customers) {
            if (c == 'Y') totalY++;
        }

        int leftN = 0;
        int rightY = totalY;
        int minPenalty = rightY;
        int bestHour = 0;

        for (int i = 0; i < customers.size(); i++) {
            if (customers[i] == 'Y') {
                rightY--;
            } else {
                leftN++;
            }

            int penalty = leftN + rightY;

            if (penalty < minPenalty) {
                minPenalty = penalty;
                bestHour = i + 1;
            }
        }

        return bestHour;
    }
};

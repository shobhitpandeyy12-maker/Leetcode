class Solution {
    static constexpr int DY[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
public:
    int countDaysTogether(string aA, string lA, string aB, string lB) {
        int AA = days(aA);
        int LA = days(lA);

        int AB = days(aB);
        int LB = days(lB);

        return max(0, min(LA, LB) - max(AA, AB) + 1);
    }
    int days(string s){
        int count = 0;
        int M = stoi(s.substr(0,2));
        int D = stoi(s.substr(3, 5));

        for(int i = 0; i < M; ++i)
            count += DY[i];
        count -= DY[M - 1] - D;
        return count;
    }
};
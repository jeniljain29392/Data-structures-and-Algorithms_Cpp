class Solution {
private:
    int rectArea(int A, int B, int C, int D){
        if(A > C || B > D)
            return 0;
        else
            return (C - A)*(D - B);
    }
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area = rectArea(A, B, C, D) + rectArea(E, F, G, H);
        if(((A < G) || (E < C)) && ((B < H) || (F < D)))
            area -= rectArea(max(E, A), max(B, F), min(C, G), min(H, D));
        return area;
            
    }
};

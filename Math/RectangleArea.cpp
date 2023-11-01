class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int xoverlap = 0;
        int yoverlap = 0;
        int overlapArea = 0;
        xoverlap = min(ax2,bx2)-max(ax1,bx1);
        yoverlap = min(ay2,by2)-max(ay1,by1);

        if(xoverlap>0 && yoverlap>0)  overlapArea = xoverlap*yoverlap;

        int l1 = abs(ay2-ay1);
        int b1 = abs(ax2-ax1);

        int l2 = abs(by2-by1);
        int b2 = abs(bx2-bx1);

        int ans = (l1*b1) + (l2*b2) - overlapArea;
        return ans;


    }
};

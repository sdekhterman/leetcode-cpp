class Solution {
public:
    int reverse(int x) {
        int y = 0;
        int sign = 1;
        int topnumb = 0;
        int modBase = 0;
        int scale = 0;
        if(x < 0) {
            sign = -1;
            while(x < -pow(10,8)) {
                x +=  pow(10,8);
                topnumb++;
            }
        } else {
            while(x > pow(10,8)) {
                x -=  pow(10,8);
                topnumb++;
            }
        }

        for (int i = 1; (abs(x)*10) >= pow(10,i); i++){
            modBase = pow(10,i);
            scale   = pow(10, (i-1));

            y = 10*y + (abs(x) % modBase)/scale;
           
        }
        if (topnumb != 0) {
            for (int i = 1; (abs(topnumb)*10) > pow(10,i); i++){
                modBase = pow(10,i);
                scale = pow(10, i-1);

                if((i == 2) && (y > 214748364)){return 0;}
                y = 10*y + (abs(topnumb) % modBase)/scale;
            }
        }

        return sign * y;
    }
};

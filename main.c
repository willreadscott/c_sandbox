#include <stdio.h>

enum week{Mon = 5, Tue = 7, Wed = -1, Thur, Fri = 4, Sat, Sun};

int main() {
   enum week day;
    day = Sat;
    printf("%d\n",Mon);
    printf("%d\n",Tue);
    printf("%d\n",Wed);
    printf("%d\n",Thur);
    printf("%d\n",Fri);
    printf("%d\n",Sat);
    printf("%d\n",Sun);
    return 0;
}
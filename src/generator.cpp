#include <iostream>

int main(int argc, char* argv[]) 
{
    freopen(argv[1], "w", stdout);

    int cntadds = atoi(argv[2]);
    int cntexts = atoi(argv[3]);
    
    printf("%d %d %d\n", cntadds + cntexts, cntadds, cntexts);

    srand(static_cast<unsigned int>(time(NULL)));

    int balance = 0;
    while (cntadds + cntexts > 0) {
        int type = rand() % (cntadds + cntexts);
        if (type < cntadds || balance == 0) {
            printf("0 %d\n", (int)rand());
            cntadds--;
            balance++;
        } else {
            printf("1\n");
            cntexts--;
            balance--;
        }
    }
}


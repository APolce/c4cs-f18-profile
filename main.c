#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


#define LONG_TIME (0xffffffff/8)
#define noop (void)0

void branch1() {
    /*
    for (int i = 0; i < (LONG_TIME * 2); i++) {
        // Prevent the compiler from optimizing out empty loop
        noop;
    }
    */
    noop;
    return;
}
void branch2() {
    /*
    for (int i = 0; i < (LONG_TIME * 2); i++) {
        // Prevent the compiler from optimizing out empty loop
        noop;
    }
    */
    noop;
    return;
}
void branch3() {
    /*
    for (int i = 0; i < (LONG_TIME * 2); i++) {
        // Prevent the compiler from optimizing out empty loop
        noop;
    }
    */
    noop;
    return;
}
void branch4() {
    /*
    for (int i = 0; i < (LONG_TIME * 2); i++) {
        // Prevent the compiler from optimizing out empty loop
        noop;
    }
    */
    noop;
    return;
}
void branchAlways() {
    /*
    for (int i = 0; i < (LONG_TIME * 2); i++) {
        // Prevent the compiler from optimizing out empty loop
        noop;
    }
    */
    noop;
    return;
}
void branchNever() {
    /*
    for (int i = 0; i < (LONG_TIME * 2); i++) {
        // Prevent the compiler from optimizing out empty loop
        noop;
    }
    */    
    noop;
    return;
}

int main(int argc, char **argv) {
    argc = 5;
    if (argc != 5) {
        printf("Wrong number of args\n");
        exit(1);
    }
    printf("\n Inside main()\n");
    srand(time(NULL));


    double a = 40;
    double b = 20;
    double c = 10;
    double d = 90;
    /*
    double a = atoi(argv[1]);
    double b = atoi(argv[2]);
    double c = atoi(argv[3]);
    double d = atoi(argv[4]);
    */
    int random;
    /*
    a = a / 100;
    b = b / 100;
    c = c / 100;
    d = d / 100;
    */
    
    double always = 100;
    double never = 0;
    double i = 0;

    double count1 = 0;
    double count2 = 0;
    double count3 = 0;
    double count4 = 0;
    double countAlways = 0;
    double countNever = 0;
    int small_time = (((((((LONG_TIME / 2) / 2) / 2) / 2) / 2) / 2) / 2);
    printf(" %lf percent chance for branch A\n %lf percent chance for branch B\n %lf percent chance for branch C\n %lf percent chance for branch D\n", a, b, c, d);
    for (i = 0; i < small_time; i++) {
        random = rand() % 99 + 1;
        if (random <= a) {
            branch1();
            count1++;
        }
        if (random <= b) {
            branch2();
            count2++;
        }
        if (random <= c) {
            branch3();
            count3++;
        }
        if (random <= d) {
            branch4();
            count4++;
        }
        if (random < always) {
            branchAlways();
            countAlways++;
        }
        if (random < never) {
            branchNever();
            countNever++;
        }
    }

    printf("%d possible times branch could be taken\n", (int)i);
    double aPercent, bPercent, cPercent, dPercent, alwaysPercent, neverPercent;
    aPercent = (count1/i) * 100;
    bPercent = (count2/i) * 100;
    cPercent = (count3/i) * 100;
    dPercent = (count4/i) * 100;
    alwaysPercent = ((double)(countAlways/i)) * 100;
    neverPercent = ((double)(countNever/i)) * 100;
    printf("Branch A was taken %d times\n", (int)count1);
    printf("Branch A was taken %lf percent\n", aPercent);

    printf("Branch B was taken %d times\n", (int)count2);
    printf("Branch B was taken %lf percent\n", bPercent);

    printf("Branch C was taken %d times\n", (int)count3);
    printf("Branch C was taken %lf percent\n", cPercent);

    printf("Branch D was taken %d times\n", (int)count4);
    printf("Branch D was taken %lf percent\n", dPercent);

    printf("Branch Always was taken %d times\n", (int)countAlways);
    printf("Branch Always was taken %lf percent\n", alwaysPercent);

    printf("Branch Never was taken %d times\n", (int)countNever);
    printf("Branch Never was taken %lf percent\n", neverPercent);

    printf("\n Exiting \n");
    return 0;
}



/*
void child1(void) {
	printf("\n     Inside child1()\n");
	int i = 0;

	for( ; i < (LONG_TIME * 2); i++) {
		// Prevent the compiler from optimizing out empty loop
		asm("nop;");
	}

	return;
}

void child2(void) {
	int i = 0;

	for( ; i < 16; i++) {
		// Prevent the compiler from optimizing out empty loop
		asm("nop;");
	}

	return;
}

void parent(void) {
	printf("\n   Inside parent \n");
	int i = 0;

	for (i=0 ; i < (LONG_TIME); i++) {
		// Prevent the compiler from optimizing out empty loop
		asm("nop;");
	}
	child1();

	printf("\n     Starting child2() loop\n");
	for (i=0 ; i < (LONG_TIME/2); i++) {
		child2();
	}

	return;
}

static void no_children(void) {
	printf("\n   Inside no_children \n");
	int i = 0;

	for (i=0; i < (LONG_TIME * 5); i++) {
		// Prevent the compiler from optimizing out empty loop
		asm("nop;");
	}

	return;
}

int main(int argc, char **argv) {
	printf("\n Inside main()\n");
	int i = 0;

	parent();
	no_children();

	printf("\n Exiting \n");
	return 0;
}
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;

#define rad 10.0
#define hitlimit 1000000
#define debug 0

void generateshot (int *genp) {
	int x = rand() % 10 + 1;
	int y = rand() % 10 + 1;
	if (debug) {
		cout << "generated x= " << x << " generated y= << " <<  y << endl;
	}
	genp[0] = x;
	genp[1] = y;
	return;
}

int checkpincircle (int *cen, int *genp) {
	float dis = ((cen[0] - genp[0]) * (cen[0] - genp[0])) + ((cen[1] - genp[1]) * (cen[1] - genp[1]));
	dis = sqrt(dis);
	if (debug) {
		cout << "distance= " << dis << endl;
	}
	return (dis<=rad/2);
}

int main (int argc, char *argv[]) {
	srand (time(NULL));
	int shot = 0;
	int center[2] = {rad/2.0,rad/2.0};
	int hitp[2];
	int cir = 0;
	int sqr = 0;
	while (shot < hitlimit) {
		generateshot(hitp);
		if (checkpincircle(center,hitp)) {
			cir++;
		} else {
			sqr++;
		}
		shot++;
	}
	if (debug) {
		cout << "circle hits = " << cir << " square hits = " << sqr << endl;
	}
	float pie = ((float) cir / (float) hitlimit) * 4.0;
	cout << " Value of pie to be calcuated by "<< rad << " radius = " << pie << endl;
	return 0;
}

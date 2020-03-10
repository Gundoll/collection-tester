#include <stdio.h>
#include "queue.h"

bool (*testSet[])() = { \
	queueGradualValueTest, \
	queueGradualPtrTest \
};

int main(int argc, char* argv[]) {
	RetCode_t ret = RETCODE_OK;

	for(int i = 0; i < sizeof(testSet)/sizeof(void*); i++) {
		ret = testSet[i]();
		printf("========================================\n");
		printf(" Test result: %s\n", ret?"PASS":"FAIL");
		printf("========================================\n");
		printf("\n\n");
	}
	return 0;
}

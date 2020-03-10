#include "queue.h"
static int32_t queueCompare(void* lValue, void* rValue) {
	return *((long*)lValue) - *((long*)rValue);
}

bool queueGradualValueTest() {
	printf("Gundoll's collection tester: %s\n\n", __FUNCTION__);

	struct Context context = {queueCompare, CONTEXT_TYPE_VALUE, sizeof(int32_t)};
	struct GDQueue* queue = GDQueueCreate(4, 20, context);

	int32_t var[20] = {};
	int i = 0;
	for(i = 0; i < 20; i++) {
		if(i == 10) queue->dump(queue);
		var[i] = i+1;
		queue->push(queue, &var[i]);
	}
	queue->dump(queue);

	printf("\n");
	for(i = 0; i < 20; i++) {
		if(i > 0 && i % 8 == 0)
			printf("\n");

		int32_t value;
		queue->pop(queue, &value);
		printf("POP(%3d) ", value);
	}
	printf("\n\n");
	queue->dump(queue);

	GDQueueDestroy(queue);

	return true;
}

bool queueGradualPtrTest() {
	printf("Gundoll's collection tester: %s\n\n", __FUNCTION__);

	struct Context context = {queueCompare, CONTEXT_TYPE_POINTER, sizeof(int16_t*)};
	struct GDQueue* queue = GDQueueCreate(4, 20, context);

	queue->dump(queue);

	int16_t* var[20] = {};
	int i = 0;
	for(i = 0; i < 20; i++) {
		var[i] = (int16_t*)malloc(sizeof(int16_t));
		if(i == 10) queue->dump(queue);
		*var[i] = i+1;
		queue->push(queue, var[i]);
	}
	queue->dump(queue);

	printf("\n");
	for(i = 0; i < 20; i++) {
		if(i > 0 && i % 8 == 0)
			printf("\n");

		int16_t* ptr;
		queue->pop(queue, &ptr);
		printf("POP(%3d) ", *ptr);
		free(ptr);
	}
	printf("\n\n");
	queue->dump(queue);

	GDQueueDestroy(queue);

	return true;

}

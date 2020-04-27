
#define TAM_MAX_DATA 4096
#define SUMA 1

struct mensaje {
	int          messageType;
	unsigned int requestId;
	int          operationId;
	char         arguments[TAM_MAX_DATA];
};
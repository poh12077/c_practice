typedef struct NODE{
	void* header;
	char payload[10];
}NODE;

void makeFirstNode(NODE** entry);
void addAtTheEnd(NODE* entry);
void ask(NODE* entry);
void traversal(NODE* entry);
void clearReadBuffer(void);
void insertNode(NODE* entry);
void deleteNode(NODE** entry);


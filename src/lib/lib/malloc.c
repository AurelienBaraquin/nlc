typedef long intptr_t;
typedef long unsigned int size_t;

#define NULL ((void *)0)

int brk(void *addr);
void *sbrk(intptr_t increment);

typedef struct __attribute__((packed)) block_s {
    size_t size;
    char free : 1;
    struct block_s *next;
} block_t;

block_t *head = NULL;

void *malloc(size_t size) {
    if (size == 0)
        return NULL;

    if (head == NULL) {
        head = sbrk(sizeof(block_t));
        if (head == (void *)-1)
            return NULL;
        head->size = 0;
        head->free = 0;
        head->next = NULL;
    }

    block_t *current = head;
    while (current->next != NULL) {
        if (current->free && current->size >= size) {
            current->free = 0;
            return (void *)(current + 1);
        }
        current = current->next;
    }

    block_t *new_block = sbrk(sizeof(block_t) + size);
    if (new_block == (void *)-1)
        return NULL;
    new_block->size = size;
    new_block->free = 0;
    new_block->next = NULL;
    current->next = new_block;

    return (void *)(new_block + 1);
}

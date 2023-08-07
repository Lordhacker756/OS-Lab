#include <stdio.h>
#include <stdlib.h>

struct SegmentNode
{
    int seg;
    int base;
    int limit;
    struct SegmentNode *next;
};

struct SegmentNode *segment_table = NULL;

void insert(struct SegmentNode *head, int base, int limit, int seg)
{
    struct SegmentNode *new_node = (struct SegmentNode *)malloc(sizeof(struct SegmentNode));
    new_node->base = base;
    new_node->limit = limit;
    new_node->seg = seg;
    new_node->next = NULL;

    if (head == NULL)
    {
        segment_table = new_node;
    }
    else
    {
        while (head->next != NULL)
        {
            head = head->next;
        }
        head->next = new_node;
    }
}

int find(struct SegmentNode *head, int seg)
{
    while (head != NULL)
    {
        if (head->seg == seg)
        {
            return head->limit;
        }
        head = head->next;
    }
    return -1; // Return -1 if the segment is not found
}

int search(struct SegmentNode *head, int seg)
{
    while (head != NULL)
    {
        if (head->seg == seg)
        {
            return head->base;
        }
        head = head->next;
    }
    return -1; // Return -1 if the segment is not found
}

int main()
{
    int seg, offset, limit, base, c, s, physical;
    printf("Enter segment table:\n");
    printf("Enter -1 as the segment value for termination\n");

    do
    {
        printf("Enter segment number: ");
        scanf("%d", &seg);
        if (seg != -1)
        {
            printf("Enter base value: ");
            scanf("%d", &base);
            printf("Enter value for limit: ");
            scanf("%d", &limit);
            insert(segment_table, base, limit, seg);
        }
    } while (seg != -1);

    printf("Enter offset: ");
    scanf("%d", &offset);
    printf("Enter segmentation number: ");
    scanf("%d", &seg);
    c = find(segment_table, seg);
    s = search(segment_table, seg);

    if (c != -1 && offset < c)
    {
        physical = s + offset;
        printf("Address in physical memory: %d\n", physical);
    }
    else
    {
        printf("Error: Invalid segment or offset.\n");
    }
    return 0;
}

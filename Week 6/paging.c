#include <stdio.h>

/*
!Algorithm

?1. Ask the total memory and page size to calculate number of pages. rem_pages = total_pages
?2. Ask the number of processes, num_process
?3. Ask the number of pages that process requires, if pages_req[i] > rem_pages, break it otherwise reduce the remaining pages by req pages, then create page table
?4. Physical address = page_table[process_num][page_number]*page_size + offset;

*/

int main()
{
    int memory_size, page_size, num_pages, num_processes, remaining_pages, i, j, process_num, page_num, offset, physical_address;
    int pages_required[10], page_table[10][20];

    // Get memory size and page size from the user
    printf("Enter the memory size: ");
    scanf("%d", &memory_size);

    printf("Enter the page size: ");
    scanf("%d", &page_size);

    num_pages = memory_size / page_size;
    printf("The number of pages available in memory are: %d\n", num_pages);

    // Get the number of processes from the user
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    remaining_pages = num_pages;

    // Allocate pages to processes
    for (i = 1; i <= num_processes; i++)
    {
        printf("Enter the number of pages required for process P[%d]: ", i);
        scanf("%d", &pages_required[i]);

        if (pages_required[i] > remaining_pages)
        {
            printf("\nMemory is full. Cannot allocate more pages.");
            break;
        }

        remaining_pages -= pages_required[i];

        printf("Enter the page table for process P[%d]: ", i);
        for (j = 0; j < pages_required[i]; j++)
            scanf("%d", &page_table[i][j]);
    }

    // Get logical address to find physical address
    printf("\nEnter Logical Address to find Physical Address\n");
    printf("Enter the process number, page number, and offset: ");
    scanf("%d %d %d", &process_num, &page_num, &offset);

    if (process_num > num_processes || page_num >= pages_required[process_num] || offset >= page_size)
    {
        printf("\nInvalid Process or Page Number or Offset");
    }
    else
    {
        physical_address = page_table[process_num][page_num] * page_size + offset;
        printf("The Physical Address is: %d\n", physical_address);
    }

    return 0;
}

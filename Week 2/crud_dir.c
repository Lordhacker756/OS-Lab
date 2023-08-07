#include <stdio.h>
#include <fcntl.h>

main()
{
    char d[10];
    int c, op;
    DIR *e;
    struct dirent *sd;
    printf("\n**MENU**\n1.Create Directory\n2.Remove Directory\n3.Read Directory\nEnter your choice: ");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        printf("Enter name of directory: ");
        scanf("%s", &d);
        c = mkdir(d, 777);
        if (c == 1)
            printf("Directory not created");
        else
            printf("Directory created successfully\n");
        break;

    case 2:
        printf("Enter directory name: ");
        scanf("%s", &d);
        c = rmdir(d);
        if (c == 1)
            printf("Directory not removed");
        else
            printf("Directory removed successfully");
        break;

    case 3:
        printf("Enter director to open: ");
        scanf("%s", &d);
        e = opendir(d);
        if (e == NULL)
            printf("Directory doesn't exit!");
        else
        {
            printf("Directory exists\n");
            while ((sd = readdir(e)) != NULL)
            {
                printf("%s\t", sd->d_name);
            }
            closedir(e);
        }
        break;

    default:
        printf("Invalid choice!");
    }
}
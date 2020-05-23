#include <stdio.h>

struct point
{
    int x;
    int y;
    int z;
};

int main()
{
    int i;
    FILE *myfile;
    struct point p;

    // Writing to binary file
    myfile = fopen("point", "w");
    if (!myfile) {
        printf("Could not open file to write.");
        return 1;
    }

    for (i = 0; i < 10; i++)
    {
        p.x = (i + 1);
        p.y = (i + 1) * 10;
        p.z = (i + 1) * 100;
        fwrite(&p, sizeof(struct point), 1, myfile);
    }
    fclose(myfile);

    // Reading from binary file
    myfile = fopen("point", "r");
    if (!myfile) {
        printf("Could not open file to write.");
        return 1;
    }

    for (i = 0; i < 10; i++)
    {
        fread(&p, sizeof(struct point), 1, myfile);
        printf("%d %d %d\n", p.x, p.y, p.z);
    }
    fclose(myfile);

    return 0;
}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct box
    {
        int length;
        int height;
        int width;
    };
    
void formula(struct box aBox, struct box bBox);
int main()
{
    struct box box1;
    struct box box2;

    printf("Enter 1st box's all dimentions\n");
    printf("Height: ");
    scanf("%d", &box1.height);
    printf("Width: ");
    scanf("%d", &box1.width);
    printf("Length: ");
    scanf("%d", &box1.length);

    printf("\nEnter 2nd box's all dimentions\n");
    printf("Height: ");
    scanf("%d", &box2.height);
    printf("Width: ");
    scanf("%d", &box2.width);
    printf("Length: ");
    scanf("%d", &box2.length);

    formula(box1, box2);
}
void formula(struct box aBox, struct box bBox)
{
    int nLength,nWidth, nHeight;
    nLength = aBox.length + bBox.length;
    nWidth = aBox.width + bBox.width;
    nHeight = aBox.height + bBox.height;

    printf("\n\n");
    
    printf("The length of new box :  %d\n", nLength);
    printf("The width of new box :  %d\n", nWidth);
    printf("The height of new box :  %d\n", nHeight);
    
}
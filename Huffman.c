#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int f = 0;
int f1 = 0;
char inp_name[10];
char out_name[10];
char alphabet[27] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

struct htnode *newnode(char x);
struct node1
{
    char data;
    struct node1 *left;
    struct node1 *right;
};
//
struct node1 *newnode1()
{
    struct node1 *t;
    t = (struct node1 *)malloc(sizeof(struct node1));
    t->data = '\0';
    t->left = NULL;
    t->right = NULL;
    return t;
}

struct node1 *root1;

struct htnode
{
    char data;
    struct htnode *left;
    struct htnode *right;
} *root = NULL;
//
struct node
{
    int data;
    struct node *next;
    struct htnode *down;
} *first, *last = NULL;
//
int getL(char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

void merge(int arr[], int l, int m, int r, char ind[])
{
    int n2 = r - m;
    int n1 = m - l + 1;
    int i, k, j;

    int L[n1];
    int R[n2];
    char il[n1];
    char ir[n2];

    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
        ir[j] = ind[m + 1 + j];
    }

    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
        il[i] = ind[l + i];
    }

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            ind[k] = il[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            ind[k] = ir[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        ind[k] = il[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        ind[k] = ir[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r, char ind[])
{
    if (l < r)
    {
        int m = (l + r) / 2;

        mergeSort(arr, l, m, ind);
        mergeSort(arr, m + 1, r, ind);

        merge(arr, l, m, r, ind);
    }
}

void getFrequency(char str[], int freq[])
{
    int i = 0;

    while (str[i] != '\0')
    {
        freq[str[i] - 'a']++;

        i++;
    }
}

void create(struct node *p, int freq[], char arr[], int n)
{
    struct node *t;
    p->data = freq[n];
    p->next = NULL;
    p->down = newnode(arr[n]);
    last = p;
    for (int i = n + 1; i < 26; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = freq[i];
        t->next = NULL;
        t->down = newnode(arr[i]);
        last->next = t;
        last = t;
    }
}

struct htnode *newnode(char x)
{
    struct htnode *t;
    t = (struct htnode *)malloc(sizeof(struct htnode));
    t->data = x;
    t->left = NULL;
    t->right = NULL;
    return t;
}

int count(struct node *p)
{
    int count = 0;
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}

struct htnode *dequeue()
{
    struct node *x;
    struct htnode *t;
    if (first == NULL)
        printf("Queue is Empty\n");
    else
    {
        t = first->down;
        first = first->next;
    }
    return t;
}

void insert(struct node *p, struct htnode *x1, struct htnode *x2, int y1, int y2)
{
    struct node *t;
    int x = y1 + y2;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    t->down = newnode('\0');
    t->down->left = x1;
    t->down->right = x2;
    // t->next = NULL;
    if (p == NULL)
    {
        first = t;
        first->next = NULL;
        return;
    }

    if (p->data >= x)
    {
        t->next = first;
        first = t;
        return;
    }

    if (p->data < x && count(first) == 1)
    {
        first->next = t;
        t->next = NULL;
        return;
    }

    while (p != NULL)
    {
        if ((p->next)->data >= x)
        {
            t->next = p->next;
            p->next = t;
            break;
        }
        p = p->next;
    }
}

void display(struct htnode *p, int x, int y)
{
    if (p != NULL)
    {
        if (p->data == '\0')
        {
            display(p->left, x + 1, y);
            display(p->right, x, y + 1);
        }
        else
        {
            printf("%c %d %d \n", p->data, x, y);
        }
    }
}

void printArr(char arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%c", arr[i]);

    printf("\n");
}

int isLeaf(struct htnode *t)
{
    return !(t->left) && !(t->right);
}

char codes[26][200];

void printCodes(FILE *ptr, struct htnode *t, char arr[], int top)
{
    if (t->left)
    {
        arr[top] = '0';
        printCodes(ptr, t->left, arr, top + 1);
    }

    if (t->right)
    {
        arr[top] = '1';
        printCodes(ptr, t->right, arr, top + 1);
    }

    if (isLeaf(t))
    {
        // printf("%c: ", t->data);
        arr[top + 1] = '\0';
        arr[top] = '\n';
        fputc(t->data, ptr);
        // printArr(arr, top);
        int i;
        for (i = 0; i < 26; i++)
        {
            if (alphabet[i] == t->data)
            {
                f1 = i;
                break;
            }
        }
        f1 = i;

        for (int i = 0; i < getL(arr) - 1; i++)
        {
            codes[f1][i] = arr[i];
        }
        // f1++;
        fputs(arr, ptr);
        // fputc('\n', ptr);
    }
}

void huffmanCodes(char arr[], int freq[], FILE *ptr)
{
    if (count(first) > 1)
    {
        int y1 = first->data;
        struct htnode *x1 = dequeue();
        int y2 = first->data;
        struct htnode *x2 = dequeue();

        insert(first, x1, x2, y1, y2);
        huffmanCodes(arr, freq, ptr);
    }
    else
    {
        root = first->down;
        // display(root, 0, 0);
        char arr[200];
        int top = 0;
        // FILE *ptr = fopen("out.txt", "w");

        printCodes(ptr, root, arr, top);
    }
}

void compress()
{

    FILE *str = fopen(inp_name, "r");
    FILE *ptr = fopen(out_name, "w");

    char text[100000];
    fscanf(str, "%s", text);
    // printf("%s", text);
    int freq[27] = {0};
    freq[26] = '\0';
    alphabet[26] = '\0';
    getFrequency(text, freq);
    mergeSort(freq, 0, 25, alphabet);

    int i = 0;
    for (i = 0; i < 26; i++)
    {
        if (freq[i] > 0)
        {
            break;
        }
    }
    f = i;
    f1 = f;
    create(first, freq, alphabet, f);
    huffmanCodes(alphabet, freq, ptr);
    fclose(str);
    fscanf(str, "%s", text);
    for (int i = 0; i < getL(text); i++)
    {
        for (int j = f; j < 26; j++)
        {
            if (text[i] == alphabet[j])
            {
                fprintf(ptr, "%s", codes[j]);
            }
        }
    }
    fclose(ptr);
}

void buildTree(char str[])
{
    int x = getL(str);
    struct node1 *p;
    p = root1;
    for (int i = 1; i < x; i++)
    {
        // printf("%d", 0);
        if (str[i] == '1')
        {
            if (p->right == NULL)
            {
                p->right = newnode1();
            }
            p = p->right;
        }
        else if (str[i] == '0')
        {
            if (p->left == NULL)
            {
                p->left = newnode1();
            }
            p = p->left;
        }
    }
    p->data = str[0];
}

void decode1(char str[])
{
    int x = getL(str);
    struct node1 *p;
    p = root1;
    // printf("%d", x);
    FILE *deco = fopen("res.txt", "w");

    for (int i = 0; i < x; i++)
    {
        if (p->data == '\0')
        {
            if (str[i] == '1')
            {
                p = p->right;
            }
            else if (str[i] == '0')
            {
                p = p->left;
            }
        }
        else
        {
            // printf("%c", p->data);
            fputc(p->data, deco);

            p = root1;
            i--;
        }
    }
}

void decode()
{
    FILE *str = fopen(out_name, "r");
    char text[100000];
    root1 = newnode1();
    for (int i = 0; i < (26 - f - 1); i++)
    {
        fscanf(str, "%s", text);
        // printf("%s\n", text);
        buildTree(text);
    }
    fscanf(str, "%s", text);
    decode1(text);
}

int main()
{
    root = newnode('\0');
    first = (struct node *)malloc(sizeof(struct node));
    last = (struct node *)malloc(sizeof(struct node));

    int mode;
    printf("Enter the name of input file: ");
    scanf("%s", inp_name);
    printf("Enter the name of output file: ");
    scanf("%s", out_name);
    printf("Enter the mode: ");
    scanf("%d", &mode);
    if (mode == 0)
    {
        compress();
    }
    else if (mode == 1)
    {
        decode();
    }

    return 0;
}
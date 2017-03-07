#include<bits/stdc++.h>
using namespace std;
FILE *fp1,*fp2;

void create()
{
    char ar[100];
    cout<<"Enter the file name(without spaces)\n";
    cin>>ar;
    fp2=fopen(ar,"r");
    char choice='Y';
    if(fp2!=NULL)
    {
        cout<<"File with same name already exist. Do u wanna replace it  Y or N\n";
        cin>>choice;
        if(choice=='N'||choice=='n')
        {
            fclose(fp2);
            create();
            return;
        }
    }
    cout<<"Now start writing and terminate using the keyword ~\n";
    fp1=fopen(ar,"w");
    char c=getchar();
    while(1)
    {
        char c=getchar();
        if(c=='~')
            break;
        fputc(c,fp1);
    }
    fclose(fp1);
    return;
}
void display()
{
    char ar[100];
    cout<<"Enter the name of the file to be displayed\n";
    cin>>ar;
    fp1=fopen(ar,"r");
    if(fp1==NULL)
    {
        cout<<"File not found. Enter the correct filename along with extension\n";
        fclose(fp1);
        display();
        return;
    }
    while(!feof(fp1))
    {
        char c=fgetc(fp1);
        putchar(c);
    }
    fclose(fp1);
    return;
}
void append()
{
    cout<<"Enter the name of the file to be appended\n";
    char ar[100];
    cin>>ar;
    fp1=fopen(ar,"r");
    if(fp1==NULL)
    {
        cout<<"File not found. Enter the correct filename along with extension\n";
        fclose(fp1);
        append();
        return;
    }
    cout<<"File opened\nStart appending and terminate using ~\n";
    while(!feof(fp1))
    {
        char c=fgetc(fp1);
        putchar(c);
    }
    fclose(fp1);
    fp1=fopen(ar,"a");
    while(1)
    {
        char c=getchar();
        if(c=='~')
            break;
        fputc(c,fp1);
    }
    fclose(fp1);
}
void del()
{
    char ar[100];
    cout<<"Enter the file to be deleted\n";
    cin>>ar;
    fp1=fopen(ar,"r");
    if(fp1==NULL)
    {
        cout<<"File not found. Enter the correct filename along with extension\n";
        fclose(fp1);
        del();
        return;
    }
    fclose(fp1);
    if(remove(ar)==0)
        cout<<"File removed successfully\n";
    else
        cout<<"Error. File not removed\n";
}
int main()
{
    // To implement text editor
    printf("Enter ur choice\n1.Create File\n2.Display\n3.Append\n4.Delete\n5.Close\n");
    int choice;
    cin>>choice;
    switch(choice)
    {
    case 1:
    {
        create();
        break;
    }
    case 2:
    {
        display();
        break;
    }
    case 3:
    {
        append();
        break;
    }
    case 4:
    {
        del();
        break;
    }
    case 5:
    {
        exit(0);
    }
    }
}

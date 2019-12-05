 #include<stdio.h>
 #include<iostream>
 #include<stdlib.h>
 #include<string.h>
#include<fstream>
 using namespace std;
 
 struct Node
 {
    int level;
    char key[50];
   Node *left, *right;

    Node(){
      level = -1;
      left = NULL;
      right = NULL;
    }
};

 int w = 32;
 struct Node * top = NULL;

char *addDot(char *ip)
{
  int s=0,i=0;
  int length=strlen(ip);
 char ipfinal[50];
while(s < 15)
{
  ipfinal[s]=ip[i];
  s++;
  i++;
  if(i%3 == 0)
  {
    ipfinal[s]='.';
    s++;
  }
}
  ipfinal[s]='\0';
  strcpy(ip,ipfinal);
 return(ip);
}


void reverse(char str[], int length)
{
    int start = 0;
    int end = length -1;
    while (start < end)
    {
        swap(*(str+start), *(str+end));
        start++;
        end--;
    }
}

char* itoa(int num, char* str, int base)
{
    int i = 0;
    bool isNegative = false;
   
    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }  
   
    if (num < 0 && base == 10)
    {
        isNegative = true;
        num = -num;
    }    
   
    while (num != 0)
    {
        int rem = num % base;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/base;
    }
   
    if (isNegative)
        str[i++] = '-';
 
    str[i] = '\0';
     
    reverse(str, i);
 
    return str;
}


char *toDecimal(char *ip)
{
int s=0;
  int length=strlen(ip);
   printf("length:%d\n",length);
   length=length/8;
 char ipfinal[50]={'\0'};
  char iptemp1[length][10];
  int i,k=-1,j=0;
  int b,a;
  int z=0;
  for(i=0;ip[i]!='\0';)
  {
    s=0;
    j=0;
    k++;
   while(s<8 && ip[i] != '\0')
      {
              iptemp1[k][j]=ip[i];
              i++;
              j++;
              s++;
    }
  iptemp1[k][j]='\0';
  }

 int sum[3]={0};
int mul;
char one[]={"1"};
for(i=0;i<length;i++)
{
  mul=256;
  for(j=0;j<8;j++)
  {
    char ch[1]={iptemp1[i][j]};
    mul=mul/2;
     if((strncmp(ch,one,3)==0))
    {
      sum[i]=sum[i]+mul;
    }
  }
}
  int temp,digit;
  char buff[50];
      temp=sum[a];
      int fin=100;
      while(fin>0)
        {
          digit=temp/fin;
         itoa(digit,buff,10);
         strcat(ipfinal,buff);
          temp=temp%fin;
          fin=fin/10;
        }for(a=0;a<length;a++)
    {
        temp=sum[a];
      int fin=100;
      while(fin>0)
        {
          digit=temp/fin;
          itoa(digit,buff,10);
           strcat(ipfinal,buff);
          temp=temp%fin;
          fin=fin/10;
        }
    }
 strcpy(ip,ipfinal);
 return(ip);
}



 char * toBinary(char * ip)
{
int s=0;
 int length=strlen(ip);
 length=length/3;
char ipfinal[50];
char iptemp1[length][10];
int i,k=-1,j=0;
int b[10],a[10];
for(i=0;ip[i]!='\0';){
s=0;
j=0;
k++;
while(s<3&&ip[i]!='\0'){
            iptemp1[k][j]=ip[i];
            i++;
            j++;
            s++;
}
}
 int ipint[4];
  for(i=0;i<length;i++){
  ipint[i]=atoi(iptemp1[i]);
   }
  int bin[length][8];
  int z=0;
  for(int o=0;o<length;o++){
  int n=ipint[o];
  for( i=0; n>0; i++)    
      {    
         a[i]=n%2;    
         n= n/2;  
          }  
      for( k=0;k<8-i;k++)
       b[k]=0;  
      for(i=i-1 ;i>=0 ;i--)    
      {    
        b[k]=a[i];
         k++;  
      }
 for(int y=0;y<8;y++){
  ipfinal[z]=b[y]+'0';
   z++;
 }


  }
  ipfinal[z]='\0';
  strcpy(ip,ipfinal);
return ip;

  }

char *removedot(char *ip,char *str2){
  char iptt[20];
  int i=0;
    for(int j=0;ip[j]!='\0';j++){
      if(ip[j]!='.'){
          iptt[i]=ip[j];
          i++;
        }
    }
    iptt[i]='\0';
    strcpy(str2,iptt);
    return str2;

}

 
 struct Node * predecessor(char * ip,struct Node * root)
 { 
  int i =0;
  struct Node * curr = root;
  if(root->left || root->right)
 { while(ip[i]!= '\0' && curr->level != 32)
  {  if(ip[i] == '0')
       {if(curr->left)
        curr = curr->left;
        else if(curr->right)
          curr = curr->right;
        }
      else{
        if(curr->right)
       curr = curr->right;
     else if(curr->left)
        curr = curr->left;
      }
     i++;

  }
   if(strcmp(ip,curr->key)==0)
    {cout<<"\n same";
      return curr;///return curr
      }
      if(strcmp(curr->key,ip)>0)

  {    
       return curr->left;
     }
  


  
  else if(strcmp(curr->key,ip)<0)
  {
    return curr;
  }
}
else
  {
return NULL;
}

}

struct Node * successor(char * ip,struct Node * root)
 { 
  int i =0;
  struct Node * curr = root;
  if(root->left || root->right){
  while(ip[i]!= '\0' && curr->level != 32)
  {  if(ip[i] == '0')
      {if(curr->left)
       curr = curr->left;
       else
        curr = curr->right;
      }
      else
       {if(curr->right) 
       curr = curr->right;
       else
        curr = curr->left;
    }
     i++;

  }
  cout<<"\n ip:"<<ip;
  cout<<"\n curr->key"<<curr->key;
  if(strcmp(ip,curr->key)==0)
    {//cout<<"\n same";
      cout<<"\n suc is same";
      if(curr->right)
     { cout<<"\n suc is"<<curr->right->key;
      cout<<"\n";
      return curr->right;}
      else
        return NULL;
      }
  else if(strcmp(curr->key,ip)>0)
  {
    cout<<"\n >0";
    return curr;
    
    }
  else if (strcmp(curr->key,ip)<0)
  { 
    return curr->right;
  }}
  else
    return NULL;
}




 
 void insert(char *ip,struct Node * root)
 {     
        struct Node *node = new struct Node;
        strcpy(node->key,ip);
        node->level = w;
       struct Node *pre =predecessor(ip,root);
       if(pre!= NULL)
       {
         cout<<"\n pre->key"<<pre->key;
         if(strcmp(pre->key,ip)==0)
          {cout<<"\n they r the same!!!";
           
          }
   }

      else cout<<"\n not";
      struct Node *suc = successor(ip,root);
        if(pre != NULL)
        {
            if(pre->level != w)
            {
                std::cout << "Wierd level p " << pre->level << '\n';
                cout<<"\n  "<<pre->key;
            }
            node->right = pre->right;
            pre->right = node;
            node->left = pre;
        }
        else 
        {
         top = node;
         }
        if(suc != NULL)
        {
            if(suc->level != w)
            {
                std::cout << "Wierd level s" << suc->level << '\n';
            }
            node->left = suc->left;
            suc->left = node;
            node->right = suc;
        }

        
        int lvl = 1, prefix;
        struct Node *   curr = root;
           int i = 0;
        while(lvl != w)
    { 
     if(curr->left == NULL && ip[i]=='0')
     {  struct Node *temp = new struct Node;
        temp->level = lvl;
        char iptemp[50];
        int k;
        for( k =0;k<=i;k++)
        {iptemp[k] = ip[k];
         }
      iptemp[k] ='\0';
      strcpy(temp->key,iptemp);
      curr->left = temp;
     }
          
         if(curr->level!=31 && ip[i] =='0' && curr->left->level == 32)
     { struct Node *temp = new struct Node;
        temp->level = lvl;
        char iptemp[50];
        int k;
        for( k =0;k<=i;k++)
        {iptemp[k] = ip[k];
        }
      iptemp[k] ='\0';
      strcpy(temp->key,iptemp);
      curr->left = temp;
      } 
     if(curr->right == NULL && ip[i]=='1')
     {  struct Node *temp = new struct Node;
            temp->level = lvl;
        char iptemp[50];
        int k;
        for( k =0;k<=i;k++)
        {
          iptemp[k] = ip[k];
         }
      iptemp[k] ='\0';
      strcpy(temp->key,iptemp);
      curr->right = temp;
      }
          
         if(curr->level!=31 && ip[i] =='1' && curr->right->level == 32)
     { struct Node *temp = new struct Node;
        temp->level = lvl;
        char iptemp[50];
        int k;
        for( k =0;k<i;k++)
        {iptemp[k] = ip[k];
        }
      iptemp[k] ='\0';
      strcpy(temp->key,iptemp);
      curr->right = temp;
   
      } 
      if(ip[i]=='1')
      {
      curr = curr->right;
      
      }
    
      else 
      curr  = curr->left;
      i++;
      lvl++;  
    }
    if(ip[i]=='0')
      {
    curr->left=node;
    }
    else
    {
      curr->right=node;
    }
     lvl = 1;
    i = 0;
    curr = root;
    struct Node * temp;

      { if(ip[i]=='1')
        {
           curr=curr->right;
         }
        else
          { curr=curr->left;
          }
         i++;
      if(curr->right==NULL)
      { 
        temp =curr;
        
       while(temp->level!=32)
        { 
          if(temp->right)
            temp=temp->right;
          else 
            temp = temp->left;
          
        }
        curr->right = temp;
       
      }
     else if(curr->left == NULL)
      {  
        temp = curr;
       while(temp->level != 32)
       {
        if(temp->left){
          temp = temp ->left;
        }
        else  if(temp->right){
          temp = temp->right;
        }
       }
       curr->left = temp;
      }
  

    lvl++;
      }
 
  }
  void display()
  { 
    struct Node * curr = top;
    while(curr != NULL)
    {cout<<"\n "<<curr->key;
    curr = curr->right;
    }
    
  }
  void routeip(char *ip,struct Node * root){
    char ip1[50];
    removedot(ip,ip1);
    char ip2[50];
    strcpy(ip2,toBinary(ip1));
    char ip3[50];
    strcpy(ip3,predecessor(ip2,root)->key);
    cout<<"\n prede:"<<ip3;   
    char ip4[50];
    char ip5[50];
    cout<<"\n route the packet to "<<ip3;
  }

  struct Node * deletee(char *ip,struct Node *root)
  {  cout<<"\n \n pre "<<predecessor(ip,root)->key;
      cout<<"\n\n  ip"<<ip;
   if(strcmp(ip,predecessor(ip,root)->key)==0)
    {    
        root->left = NULL;
        root->right = NULL;
        root = NULL;
        top = NULL;
        ifstream obj1;
        obj1.open("ip2.txt");
        ofstream obj2;
        obj2.open("temp.txt");
        char tempip[50];
        string s;
        int n=0;
        while(getline(obj1,s))
        {   
           strcpy(tempip,s.c_str());
       if(strcmp(tempip,ip)!=0)
         {
          insert(tempip,root);
          obj2<<tempip<<'\n';

        }
        }
        obj1.close();
        obj2.close();
        remove("ip2.txt");
        rename("temp.txt","ip2.txt");
     }

     else
      cout<<"\n element not found";


return root;
  }
  
  int main()
  {
    struct Node* root= new struct Node;
    root->level = 0;
   fstream objt;
   char ipbin[35];
   int i=0;char c = '\0';
   objt.open("ip2.txt");
    ipbin[0]='\0';
    i=0;
   string line;
   while(getline(objt,line)) 
   {
     strcpy(ipbin,line.c_str());
    
     cout<<"\n ipbin"<<ipbin;
    
    insert(ipbin,root);
    cout<<"\n back in main";
}
   objt.close();

   display();
   cout<<"\n\n\n";
   int n;
   do{
    cout<<"\nenter\n1.add ip\n2.route ip\n3.display all ip\n4.delete ip\n0.quit";
    cin>>n;
    switch(n){
      case 1 :{ char ipt[50];
               cout<<"\n enter the ip to be added";
               cin>>ipt;
                char ip1[50];
                ip1[0]='\0';
               removedot(ipt,ip1);
               char ip2[50];
               ip2[0]='\0';
                strcpy(ip2,toBinary(ip1));
                cout<<"\n ip2"<<ip2;
                int flag = 0;
                 insert(ip2,root);
                fstream obj;
                obj.open("ip2.txt",fstream::app);
                 obj<<ip2;
                 obj<<'\n';
                 obj.close();           
               break;}
      case 2 : {char iptemp[50];
               cout<<"\n enter ip";
               cin>>iptemp;
               routeip(iptemp,root);
               break;}
      case 3 : {display();
               break;
             }
      case 4 :  {char ip[50];
                cout<<"\n enter the ip to be deleted";
                cin>>ip;
                 char ip1[50];
                removedot(ip,ip1);
               char ip2[50];
                 strcpy(ip2,toBinary(ip1));
                 root = deletee(ip2,root);
              break;
            }
    }
  }while(n);
  }
  
  
  
  
  
        
        
        
    

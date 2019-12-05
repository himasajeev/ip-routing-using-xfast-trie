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

    // also used by leaf nodes to simulate linked list
    Node *left, *right;

    Node(){
      //cout<<"\ninside constructor";
      level = -1;
      left = NULL;
      right = NULL;
    }
};

//struct Node* root = new struct Node;

 int w = 32;
 struct Node * top = NULL;//pointer to left of linked list

char *addDot(char *ip)
{
  int s=0,i=0;
//  char ip[50];
//  scanf("%s",ip);
  int length=strlen(ip);
//  printf("length:%d\n",length);
  char ipfinal[50];
while(s < 15)
{
  ipfinal[s]=ip[i];
  cout<<"ok"<<endl;
  s++;
  i++;
  if(i%3 == 0)
  {
    ipfinal[s]='.';
    s++;
  }
//  cout<<s<<endl;
}
  ipfinal[s]='\0';
  strcpy(ip,ipfinal);
  //cout<<ip<<endl;

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
//char ip[50];
//scanf("%s",ip);
  int length=strlen(ip);
   printf("length:%d\n",length);
   length=length/8;
 char ipfinal[50]={'\0'};
  char iptemp1[length][10];
  int i,k=-1,j=0;
  int b,a;
  //cout<<"\nlength="<<length;
  int z=0;
  for(i=0;ip[i]!='\0';)
  {
    s=0;
    j=0;
    k++;
  //cout<<"\n"<<ip[i];
    while(s<8 && ip[i] != '\0')
      {
              iptemp1[k][j]=ip[i];
              i++;
              j++;
              s++;
    }
  iptemp1[k][j]='\0';
  cout<<iptemp1[k]<<endl;
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
    cout<<"iptemp"<<iptemp1[i][j]<<endl;
    cout<<"ch="<<ch<<endl;
    cout<<"one"<<one<<endl;
   
    if((strncmp(ch,one,3)==0))
    {
      sum[i]=sum[i]+mul;
    }
  }
  cout<<"sum : "<<sum[i]<<endl;
}
  int temp,digit;
  char buff[50];
  //char tempo;
  cout<<"inside\n";
      temp=sum[a];
      int fin=100;
      while(fin>0)
        {
          digit=temp/fin;
          cout<<digit<<endl;
          itoa(digit,buff,10);
          cout<<buff<<endl;
          strcat(ipfinal,buff);
         // cout<<"\nipfinal:"<<ipfinal;
        // z++;
          temp=temp%fin;
          fin=fin/10;
        }for(a=0;a<length;a++)
    {
      cout<<"inside\n";
      temp=sum[a];
      int fin=100;
      while(fin>0)
        {
          digit=temp/fin;
          cout<<digit<<endl;
          itoa(digit,buff,10);
          cout<<buff<<endl;
          strcat(ipfinal,buff);
         // cout<<"\nipfinal:"<<ipfinal;
        // z++;
          temp=temp%fin;
          fin=fin/10;
        }
    }
 //printf("outside.\n");
 //cout<<ipfinal;
 strcpy(ip,ipfinal);
 return(ip);
}



 char * toBinary(char * ip)
{
//char ip[20];
  
int s=0;
 int length=strlen(ip);
 length=length/3;
char ipfinal[50];
char iptemp1[length][10];
int i,k=-1,j=0;
int b[10],a[10];
//cout<<"\nlength="<<length;
for(i=0;ip[i]!='\0';){
s=0;
j=0;
k++;
//cout<<"\n"<<ip[i];
while(s<3&&ip[i]!='\0'){
            iptemp1[k][j]=ip[i];
            i++;
            j++;
            s++;
            //cout<<"\ni="<<i;
}
//iptemp1[k][j]='\0';
//cout<<iptemp1[k];
//cout<<"\n i= "<<i;
}
//cout<<"\n"<<iptemp1[0]<<"\n"<<iptemp1[1]<<"\n"<<iptemp1[2]<<"\n"<<iptemp1[3];
  int ipint[4];
  for(i=0;i<length;i++){
  ipint[i]=atoi(iptemp1[i]);
   }
  int bin[length][8];
 // length=length/3;
  int z=0;
  for(int o=0;o<length;o++){
  int n=ipint[o];
 // cout<<"\n\n"<<n;
  for( i=0; n>0; i++)    
      {    
         a[i]=n%2;    
         n= n/2;  
         //cout<<"a= "<<a[i];
      }  
      for( k=0;k<8-i;k++)
       b[k]=0;  
      for(i=i-1 ;i>=0 ;i--)    
      {    
        b[k]=a[i];
        //cout<<" "<<b[k];  
        k++;  
      }
 for(int y=0;y<8;y++){
 // cout<<"\n b= "<<b[y];
  ipfinal[z]=b[y]+'0';
  //cout<<"\n ip ="<<ipfinal[z];
  z++;
 }


  }
  ipfinal[z]='\0';
  strcpy(ip,ipfinal);
   cout<<"\n"<<ip;
return ip;

  }

char *removedot(char *ip,char *str2){
 // cout<<"\n inside removedot";
 
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
    cout<<"\n in removedot"<<str2<<"\n";
    return str2;

}

 
 struct Node * predecessor(char * ip,struct Node * root)
 { //cout<<"\n inside prede";
  int i =0;
  struct Node * curr = root;
  if(root->left || root->right)
 { while(ip[i]!= '\0' && curr->level != 32)
  {  if(ip[i] == '0')
       {if(curr->left)
        curr = curr->left;
        else if(curr->right)
          curr = curr->right;

       // cout<<"left";
       }
      else{
       // cout<<"right";
        if(curr->right)
       curr = curr->right;
     else if(curr->left)
        curr = curr->left;
      }
     i++;

  }

  ///cout<<"\n outside whule";
   //cout<<"\n curr key"<<curr->key;
   //cout<<"\n ip"<<ip;
  if(strcmp(ip,curr->key)==0)
    {cout<<"\n same";
      return curr;///return curr
      }
    //  cout<<"\n njn potgtiytg";
  //else 
    if(strcmp(curr->key,ip)>0)

  {//cout<<"\n inside >0";
   //cout<<"\n curr->key"<<curr->key;
   //cout<<"\n curr->left->key"<<curr->left->key;
     //while(curr && strcmp(curr->key ,ip)>0)
      //{ curr = curr->left;}
       
       return curr->left;
     }
  


  
  else if(strcmp(curr->key,ip)<0)
  {
    //cout<<"\n else";
    //hile(curr &&strcmp(curr->key,ip)<0)
     //curr = curr->right;  
    return curr;//
  }
}
else
  {cout<<"ttttt";
return NULL;
}
  //return NULL;

}

struct Node * successor(char * ip,struct Node * root)
 { //cout<<"\n inside suc"; 
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
  { //while(curr && strcmp(curr->key,ip)>0)
      //curr = curr->left;
    cout<<"\n >0";
    return curr;
    
    }
  else if (strcmp(curr->key,ip)<0)
  { //while(curr && strcmp(curr->key,ip)<0)
    //curr = curr->right;
    return curr->right;
  }}
  else
    return NULL;
}




 
 void insert(char *ip,struct Node * root)
 {      //flag = -1;
        //cout<<"\n inside insert";
        struct Node *node = new struct Node;
        strcpy(node->key,ip);
        node->level = w;
        //cout<<"\n node created";
   
        // update linked list
       struct Node *pre =predecessor(ip,root);
       if(pre!= NULL)
       { //cout<<"\n pre->key exists";
         cout<<"\n pre->key"<<pre->key;
         if(strcmp(pre->key,ip)==0)
          {cout<<"\n they r the same!!!";
           //flag++;
          }
   }

      else cout<<"\n not";
       //if(strcmp(pre->key,ip)==0)
       //{
        //cout<<"\n they r the same!!!";
       //}

        struct Node *suc = successor(ip,root);
     // if(strcmp(pre->key,ip)!=0)
       // { cout<<"\n inside case 1";
    //if(flag != 0)

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
        {//cout<<"/n inside else";
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
    { //cout<<"\n insidew while";
    
      //prefix = k >> (w - lvl);
     if(curr->left == NULL && ip[i]=='0')
     {  struct Node *temp = new struct Node;
        //cout<<"\n left null nd 0";
        temp->level = lvl;
        char iptemp[50];
        int k;
        for( k =0;k<=i;k++)
        {iptemp[k] = ip[k];
         }
      iptemp[k] ='\0';
      strcpy(temp->key,iptemp);
      curr->left = temp;
    //cout<<"\n"<<temp->key;
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
    //cout<<"\n"<<temp->key;
      
          
      } 
          
      /*  if(curr->level  == 31 && ip[i] =='0' && curr->left->level == 32)
    {   curr->left = node;
      } 
      */
     if(curr->right == NULL && ip[i]=='1')
     {  struct Node *temp = new struct Node;
      //cout<<"\n right null 1";
        temp->level = lvl;
        char iptemp[50];
        int k;
        for( k =0;k<=i;k++)
        {
          iptemp[k] = ip[k];
        //cout<<"\n ip[k]"<<ip[k];
         }
      iptemp[k] ='\0';
      //cout<<"\n"<<iptemp;
      strcpy(temp->key,iptemp);
      curr->right = temp;
      //cout<<"\n"<<iptemp;
      //cout<<"\n"<<temp->key;
      //cout<<"\n"<<curr->right->key;

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
      //cout<<"\n"<<temp->key;
      curr->right = temp;
      //cout<<"\n"<<temp->key;
      
          
      } 
          
       /* if(curr->level  == 31 && ip[i] =='1' && curr->right->level == 32)
    {   curr->right = node;
      }*/
      if(ip[i]=='1')
      {
      curr = curr->right;
      //cout<<" curr is ";
      }
    
      else 
      curr  = curr->left;
      i++;
      lvl++;  
  
      //cout<<"\n"<<i<<"th time";
          
    }
    if(ip[i]=='0')
      {//cout<<"\n"<<i<<" left";
    curr->left=node;
// cout<<"\n\n\n"<<curr->left->key<<"\n\n\n";
      
    }
    else
    {
      curr->right=node;
  //     cout<<"\n\n\n"<<curr->right->key<<"\n\n\n";
    // cout<<"\n"<<i<<" right";
    }
   


//doubly linked

    

      
     lvl = 1;
    i = 0;
    curr = root;
    struct Node * temp;

      { if(ip[i]=='1')
        {
           curr=curr->right;
           //cout<<"\n inside ip[i]=='1' "<<curr->key;
           //cout<<"\n\n1";
         }
        else
          { curr=curr->left;
            //cout<<"\n else "<<curr->key;
          }
         i++;
      if(curr->right==NULL)
      { //cout<<"\n inside if crr->right = NULL";
        
        temp =curr;
        
       while(temp->level!=32)
        { // cout<<"\n inside if  while";
          if(temp->right)
            temp=temp->right;
          else 
            temp = temp->left;
          
        }
        curr->right = temp;
       //if(curr->left)
       //{ //curr = curr->left;
        //cout<<curr->left->key;
       //}
     
      }
     else if(curr->left == NULL)
      {  //cout<<"\ninside else if";
        temp = curr;
       while(temp->level != 32)
       {
        //cout<<"\n inside while";
        if(temp->left){
         // cout<<" left";
          temp = temp ->left;
        }
        else  if(temp->right){
          // cout<<" right";
          temp = temp->right;
        }
      

       }
       curr->left = temp;
       //curr= curr->right;

      }
  

    lvl++;
    }

   // cout<<"\n\n curr level"<<curr->level;
   // cout<<"\n curr key"<<curr->key;

    if(curr->level == 32)
    {//cout<<"\n\n level 32";
   // cout<<"\n"<<curr->right->key;


    }
   
  }
  //else 
    //cout<<"\n Element already present";
  //return flag;
    //return 0;
 // }
  //else
  //{
    //cout<<"\n Element already present";
    //return -1;
 // }//
  
  void display()
  { //cout<<"\n nammal polichuu";
    struct Node * curr = top;
    while(curr != NULL)
    {cout<<"\n "<<curr->key;
     //cout<<"\n inside display";
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
    //strcpy(ip4,toDecimal(ip3));
    //cout<<"\n after toDecimal"<<ip4;

    
    char ip5[50];
    //strcpy(ip5,addDot(ip4));
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
        
       //struct Node * root = new struct Node;
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
  {//struct Node * root = (struct Node *)malloc(sizeof(struct Node));
    struct Node* root= new struct Node;
    root->level = 0;

  /* char i[40] ={"00000000000000000000000000000011"};
   cout<<"\n b4 insert";
    insert(i,root);
  cout<<"\n no fault";
    //display();
  
    //cout<<"\n after predecessor";
    strcpy(i,"11111111111111111111111111111111");
    insert(i,root);

    //display();

    strcpy(i,"000000000000000000000000000000001 ");
    insert(i,root);
     display();

    strcpy(i,"00000000000000000000000000000001");
    
    if(predecessor(i,root));
    //  cout<<predecessor(i,root)->key;
    else 
      cout<<"null";

   /* strcpy(i,"11111111111111111111111111111111");
    
    if(predecessor(i,root))
      cout<<predecessor(i,root)->key;
    else 
      cout<<"null";
   */
    


   fstream objt;
   char ipbin[35];
   int i=0;char c = '\0';
   objt.open("ip2.txt");
   //while(!objt.eof())
   //{
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
    /*ipbin[0]='\0';
    i=0;
   

    do
    {   objt>>c;
      if(c!= '%')
       {ipbin[i]=c;

       cout<<"\n c"<<c;
       i++;}
     

     
    }while( c!='%');
   
    //if(c = '%' && !obj.eof())
    //obj>>c;
    ipbin[i]='\0';
     cout<<"\n ipbin"<<ipbin;
    //cout<<"\n\n\n ipbin"<<ipbin<<"\n\n\n";
    insert(ipbin,root);
    cout<<"\n back in main";
*/





   //}
   objt.close();

   display();
   cout<<"\n\n\n";
  /* cout<<"\ntop :"<<top->key;
   if(!(top->left || top->right))
   cout<<" \ntop  l nd r NULL";
 cout<<"\n top->right"<<top->right->key;
    cout<<"\n \n pre"<<predecessor(top->right->key,root)->key;
    if(!successor(top->key,root))
      cout<<"\n succ is null";
    cout<<"\n succ "<<successor(top->key,root)->key;
    if(!successor(top->right->key,root))
      cout<<"\n succ2 is null";

   cout<<" \n rlr"<<root->left->right->key;*/
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
                cout<<"\n ip1"<<ip1;
                cout<<"\n";
               char ip2[50];
               ip2[0]='\0';
                strcpy(ip2,toBinary(ip1));
                cout<<"\n ip2"<<ip2;
                int flag = 0;
                 insert(ip2,root);
                //if(flag!=0)
               //{ 
                fstream obj;
                obj.open("ip2.txt",fstream::app);
                 obj<<ip2;
                 obj<<'\n';
                 obj.close();
                 //}
               
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
  
  
  
  
  
        
        
        
    

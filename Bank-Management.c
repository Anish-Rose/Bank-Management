#include <stdio.h>

//Default Info    accNo = 123  pin = 123 //

   //----------Transactions Var-------//
  int userPin , pinChances=5 , userSelection , continueTransactions=1 , mainDash;
  float deposit , withdraw , balance;
  //----------Existing Acc-------//
  int exAccNo ;
  //----------Login var-------//
  int loginAccNo,  loginPin;
    //----------create account var-------//
    char name[20] = "dummy";
    char email[25] = "dummy@gmail.com";
    char address[50] = "4/95e Chennai";
    int accNo=123 , pin=123 , year=2022 , month=06, date=23 ;

int main(){
   system("color A");

   //----------------Login--------------//
     mainScreen();
   //---------------Logic------------

   switch(mainDash){
   case 1 :
       login();
       break;

   case 2 :
       createAccount();
       break;

    default :
      printf("Invalid Option");
      break;

   }
}

//--------------------------------------------------Functions--------------------------------------------------//
int mainScreen(){
   printf("\n\nWelcome to State bank of india \n\n");
   printf("1) Login \n\n");
   printf("2) Create an account ");
   printf("\n\nChoose : ");
   scanf("%d" , &mainDash);
}
//-----------Account Login----------//
int login(){
    system("cls");
     printf("\nWelcome to Login Screen\n\n");

while(accNo != loginAccNo || pin != loginPin){
    system("cls");
    printf("\nWelcome to Login Screen\n\n");
    printf("Enter your account no : ");
    scanf("%d" , &loginAccNo);

    printf("Enter your pin : ");
    scanf("%d" , &loginPin);

    if(accNo == loginAccNo && pin == loginPin){
        printf("\n\nWELCOME USER\n\n");
        mainDashBoard();
    }
    else{
        printf("\n\n---------Invalid Account Number or password---------\n\n");
        Beep(500,600);
    }
}

}
//-----------Account Create----------//
int createAccount(){

     system("cls");
     FILE *fp;

     printf("\n\nWelcome to Create Account Screen\n\n");

     printf("Enter your name : ");
     scanf("%s" , &name);

     printf("Enter your email : ");
     scanf("%s" , &email);

     printf("Enter your address : ");
     scanf("%s" , &address);

     printf("Enter Current Date : D/M/Y : ");
     scanf("%d/%d/%d" , &date , &month , &year);

    printf("Enter your new account no : ");
    scanf("%d" , &accNo);

    printf("Enter your new pin : ");
    scanf("%d" , &pin);

    fp = fopen("userDetails.txt" , "a");
    fprintf(fp,"Name : %s\nEmail : %s\nAddress : %s\nCurrent Date : %d/%d/%d\nAcc No : %d\nPin : %d\n------------\n", name, email , address , date,month,year , accNo , pin);

    int goback;
    printf("\n\nAccount Created Go to login screen 1[yes] : ");
    scanf("%d" , &goback);
    goback == 1 ? login() : printf("");
    goback--;

}
//-----------Main Dashboard----------//
int mainDashBoard(){
    while(continueTransactions != 0 ){

    dashBoard();
    //--------------Transactions---------------//
    switch(userSelection){
    case 1 :
    checkBalance();
    break;

    case 2 :
     amountWithdraw();
     break;

    case 3 : {
       amountDeposit();
        break;
     }
    case 4 : {
        existingAccount();
        break;
     }
    case 5 : {
        deletAccount();
        break;
     }
    case 6 : {
        accountHolders();
        break;
     }
    case 7 : {
        mainScreen();
        break;
     }
    default :
        printf("Invalid Selection");
        Beep(600,500);
        break;
   }
    printf("\n\nDo you need to continue Transactions 1(Yes) 0(No) : ");
    scanf("%d" , &continueTransactions);
 }
   printf("\n\n\t\t\t\t------------------------Thanks For Using State Bank of India ATM------------------------\n\n\t\t\t\t");
   return 0;
}
//-----------Dashboard----------//
int dashBoard(){
   system("cls");
   time_t now;
   time(&now);
   printf("%s \n" , ctime(&now));
   printf("Welcome To State Bank of India  \n\n");
   printf("1)Check Balance \n\n");
   printf("2)Withdraw Amount\n\n");
   printf("3)Deposit Amount \n\n");
   printf("4)Check Details of Existing Accounts \n\n");
   printf("5)Delete Existing Account \n\n");
   printf("6)View all account holders \n\n");
   printf("Choose : ");
   scanf("%d" , &userSelection);
}
//-----------Check Pin----------//
int checkPin(){
         //----------Checking For userpin----------//
      while(userPin != pin){
       printf("\nEnter your pin : ");
       scanf("%d" , &userPin);
       if(userPin != pin){
        pinChances--;
        Beep(600,500);
        printf("Invalid Pin Please try again \n");
       }
       if(pinChances <= 0){
        printf("\n--------------------Wrong Pin entered more than 5 times---------------------\n\n\n\n");
        Beep(600,500);
        exit(0);
       }
    }
}
//-----------Check balance----------//
int checkBalance(){
    printf("\n\n------------Checking Balance------------\n\n");
    printf("BALANCE = %.2f" , balance);
}
//-----------Amount Withdraw----------//
int amountWithdraw(){
    printf("\n\n-----------You Choose To Withdraw Money------------\n\n");
     printf("Enter a Amount to withdraw : ");
     scanf("%f" , &withdraw);

     if(withdraw > balance){
        printf("You dont have enough money to withdraw");
        Beep(600,500);
     }
     else if(withdraw < 100){
        printf("Withdraw Amount Too Low (Min Withdraw Amount = 100) \n\n");
        Beep(600,500);
     }
     else{
        balance = balance - withdraw;
        printf("You Withdraw = %.2f \n\n" , withdraw);
        printf("Your New Balance = %.2f" , balance);
     }
}
//-----------Amount Deposit----------//
int amountDeposit(){
     printf("\n\n-----------You Choose To Deposit Money------------\n\n");
        printf("Your Current Balance is: %.2f\n\n", balance);
        printf("Enter a Amount to Deposit : ");
        scanf("%f" , &deposit);

        if(deposit < 100){
            printf("Deposit Amount Too Low (Min Deposit Amount = 100) \n\n");
            Beep(600,500);
        }
        else {
            balance += deposit ;
            printf("You Deposited = %.2f \n\n" , deposit);
            printf("Your New Balance = %.2f" , balance);
        }
}

int existingAccount(){
    system("cls");
    system("color A");
    printf("Welcome To State bank of india\n\n");

    printf("Enter Your Account Number : ");
    scanf("%d" , &exAccNo);

        if(exAccNo == accNo){
            printf("\nName : %s\n\n" , name);
            printf("Email : %s\n\n" , email);
            printf("Address : %s\n\n" , address);
            printf("Account Created : %d/%d/%d\n\n" , date,month,year);
            printf("Account No : %d\n\n" , accNo);
        }
        else{
            printf("CANT FIND THE USER \n");
    }
}

int accountHolders(){
    printf("---------------------------------------------------\n");
    printf("Acc.No \t\t Name \t\t Address \t\t Account Created \n\n");
    printf("%d \t\t %s \t\t %s \t\t %d/%d/%d" , accNo , name , address , date,month,year);
}

int deletAccount(){
    printf("---------------------------------------------------\n");
    printf("Enter acc no to delete the profile : ");
    scanf("%d" , &exAccNo);
    if(exAccNo == accNo){
         accNo=NULL;
         memset(&name[0], 0, sizeof(name));
         memset(&email[0], 0, sizeof(email));
         memset(&address[0], 0, sizeof(address));;
        date= NULL;
        month =NULL;
        year = NULL;
    }
    if(accNo == NULL){
        printf("Account Deleted");
    }
}

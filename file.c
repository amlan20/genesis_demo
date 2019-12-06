#include<stdio.h>

#define MAX_SIZE 20
//const int max_size=20;

#define NO_YEARS  4
#define MAX_NAME_LEN 20
#define MAX_SCORE 4000

typedef enum {
  ETC=301,
  EEE=302,
  CSE           //303
}Discipline;

typedef enum {
  FCD,
  FC,
  SC,
  ORD,
  FAIL
}Grade;



typedef struct {
  unsigned int rollno;  //ideally has to be string type
  char name[MAX_NAME_LEN];
  Discipline branch;
  double scores[NO_YEARS];      //NO_SEMS
  unsigned int age;
  unsigned int rank;
}Student;


void display(const Student* ptr);
double grandTotal(const Student* ptr);
//void displayAll(const Student[],int);
void displayAll(const Student*,int);
void readSingle(Student*);
void readAll(Student*, int);


int main() {
   Student sarr[MAX_SIZE] = {
    { 1001, "Anant", ETC, {800, 900,700,750}, 20, 100 },
    { 1002, "Vinay", EEE, {850, 920,760,720}, 21, 150 },
   /* { .rollno = 1003, .name  ="Uddhav", .branch = CSE,
                        .age=20 } ,
    [3] = { 1005, "Aamir", ETC }*/
   };

   //printf("size=%d\n", sizeof(unsigned int*));
   printf("size=%d\n", sizeof(Student));

   readAll(sarr,5);
   display(&sarr[0]);
   displayAll(sarr, 5);

   Student* pres=findStudentByRollno(sarr,5, 1003);
   display(pres);
   //grandTotal(pres);
   //findGrade(pres);

   filterByBranch(sarr,5, ETC);

   return 0;
}
//void displayAll(const Student parr[], int n) {
void displayAll(const Student* parr,int n) {
   //printf("sizeof parr:%d\n", sizeof(parr));
   //for(int i=0;i<n;i++)
   //   display(&parr[i]);  // parr+i
   const Student *pcur=parr;
   for(int i=0;i<n;i++) {
     display(pcur);     //display(pcur++);
     pcur++;
   }
   //You may print details using parr/pcur in same
   //function, but another clean function is preferred
}
void display(const Student* ptr) {
  printf("Rollno=%u, Name=%s, Branch code=%d,           Grand total=%u,Age=%u,Rank=%u\n",
    ptr->rollno, ptr->name, ptr->branch,
    grandTotal(ptr), ptr->age, ptr->rank);
}
double grandTotal(const Student *ptr) {
  double sum=0;
  for(int j=0;j<NO_YEARS;j++)
    sum+=ptr->scores[j];
  return sum;
}
Grade findGrade(const Student *ptr) {

  double total = grandTotal(ptr);
  double avg = total / MAX_SCORE * 100;  //percentage
  if(avg >= 70.0)
    return FCD;
  else if(avg >= 60.0)
    return FC;
  //TODO: rest of the function
}
void readSingle(Student *ptr) {
  scanf("%d%s%d%d", &ptr->rollno, ptr->name,
                    &ptr->age, &ptr->rank);
  //TODO: ptr->branch
  for(int j=0;j<NO_YEARS;j++)
    ptr->scores[j]=rand()%1000;
}
void readAll(Student* parr, int n) {
  /*for(int i=0;i<n;i++)
      readSingle(&parr[i]);       //readSingle(parr+i) */
  Student *pcur = parr;
  for(int i=0;i<n;i++)
     readSingle(pcur++);
}

Student* findStudentByRollno(const Student* parr,int n,int keyRollno) {
   /*for(int i=0;i<n;i++)
     if(parr[i].rollno == keyRollno)
        return &parr[i];
        //or simply print, display(&parr[i])
        //but prefer return than print*/
   const Student *pcur=parr;    //parr,&parr[0]
   for(int i=0;i<n;i++) {
     if(pcur->rollno==keyRollno)
        return pcur;    //display(pcur)
     pcur++;
   }

   return NULL;
}
void filterByBranch(const Student* parr,int n,
                                Branch key) {
   const Student *pcur=parr;
   for(int i=0;i<n;i++) {
     if(pcur->branch==key)
        display(pcur);
     pcur++;
   }
}
double findMaxGrandTotal(const Student* parr,int n) {
  int maxTotal = 0;
  const Student *pcur=parr;       //Student *pmax=NULL;
  for(int i=0;i<n;i++) {
    if(grandTotal(pcur) >= maxTotal)
      maxTotal=grandTotal(pcur);  //pmax=pcur
    pcur++;
  }
  return maxTotal;
}
//TODO: min/avg grandTotal
//TODO: min/max/avg age
int countStudentsByGrade(const Student* parr,int n, Grade key) {
  int count=0;
  const Student *pcur=parr;       //Student *pmax=NULL;
  for(int i=0;i<n;i++) {
    if(findGrade(pcur)==key)
      count++;
  return count;
}
//TODO: count by rank range










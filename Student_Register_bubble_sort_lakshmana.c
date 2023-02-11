// student reg no marks input
// user choice to sort name or regno or marks
// using struct
// bubble sort

#include <stdio.h>

struct Register{
	char name[20];
	int reg_no, marks;
};

void input(struct Register student[], int n)
{
	for (int i=0; i<n; i++)
	{
		printf("Enter the Name of the Student: ");
		fflush(stdin);
		scanf("%s", student[i].name);
		printf("Enter the Reg. No. of the Student: ");
		scanf("%d", &student[i].reg_no);
		printf("Enter the Marks of the Student: ");
		scanf("%d", &student[i].marks);
		fflush(stdin);
	}
}

void output(struct Register student[], int n)
{
	printf("The details of the students are: \n");
	for (int i=0; i<n; i++)
	{
		//printf("The Reg. No. of the Student is ");
		printf("%d\t", student[i].reg_no);
		//printf("The Name of the Student is ");
		printf("%s\t", student[i].name);
		//printf("The Marks of the Student is ");
		printf("%d\t", student[i].marks);
		printf("\n");
	}
}

int main()
{
	int n;
	printf("Enter the number of students: ");
	scanf("%d", &n);
	struct Register student[n];
	input(&student, n);
	char name[10];
	
	output(student, n);
	return 0;
}
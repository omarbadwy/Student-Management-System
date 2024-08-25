/*
 ============================================================================
 Name        : C_Project_OmarBadwy.c
 Author      : Eng Omar Badwy
 Description : Student Management System.
 Data        : 10 - 8 - 2024
 ============================================================================
 */
/**********************************************
 *                                            *
 * C Project ----> Student Management System. *
 * By Omar Mohamed Suliman Mohamed.           *
 *                                            *
 *********************************************/
// Including Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Define a structure to store student data
struct student
{
	// Student ID
	int id;
	// Student Name
	char name [50];
	// Student Age
	int age;
	// Student GPA
	float gpa;
};
// Define a structure to represent a node in a linked list
struct node
{
	// Student data
	struct student data;
	// pointer to next node (Student)
	struct node *next;
};
struct node *head = NULL;
/*****************************************
 * Functions Prototyping / declarations. *
 *****************************************/
// function to create or add a new node
struct node * add_new_node(const struct student *ptr);
// Case 1
void addStudent(const struct student *const ptr);
// Case 2
void displayStudents(void);
// Case 3
void searchStudentByID(int id);
// Case 4
void updateStudent(int id);
// Case 5
float calculateAverageGPA(void);
// Case 6
void searchHighestGPA(void);
// Case 7
void deleteStudent(int id);
// Function to ask if the user wants to continue.
void ContinueMoreTask(void);
//****************************************************************************//
//                          #LOGIN SYSTEM#                                   //
//**************************************************************************//
/******************
 * Main Function  *
 ******************/
int main(void)
{
	int choice;
	// Massages display on console text
	printf("\n\t\t Hello My Friend \t\t\n");
	printf("\tWelcome To Student Management System \t\n");
	// Scanf problem's solution in Eclipse
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	// While Loop
	while (1)
	{
		// Print Menu to perform any task
		printf("*======================================================*");
		printf("\nChoose an action:\n");
		printf("1. Add a new Student.\n");
		printf("2. Display All Students.\n");
		printf("3. Search for a Student by ID.\n");
		printf("4. Update Student Information.\n");
		printf("5. Calculate Average GPA.\n");
		printf("6. Find Student with Highest GPA.\n");
		printf("7. Delete a Student by ID.\n");
		printf("8. Exit.\n");
		printf("Enter Choice : ");
		scanf("%d", &choice);
		printf("*======================================================*\n");
		//Switch Statement
		switch (choice)
		{
		//****************************************************************************//
		//                          #Add a new Student#                              //
		//**************************************************************************//
		case 1:
		{
			// Print massage "Add a new Student".
			printf("\t\tAdd a new Student\t\t\n");
			struct student NewStudent;
			// Input student ID
			printf("Enter Student ID: ");
			if (scanf("%d", &NewStudent.id) != 1 || NewStudent.id <= 0){
				printf("Invalid ID Input.\n");
				// Clear the input buffer
				while (getchar() != '\n');
				break;
			}
			// Input student Name
			printf("Enter Student Name: ");
			if (scanf("%49s", NewStudent.name) != 1){
				printf("Invalid Name Input.\n");
				// Clear the Input Buffer
				while (getchar() != '\n');
				break;
			}
			// Input student Age
			printf("Enter Student Age: ");
			if (scanf("%d", &NewStudent.age) != 1 || NewStudent.age <= 0){
				printf("Invalid Age Input.\n");
				// Clear the Input Buffer
				while (getchar() != '\n');
				break;
			}
			// Input student GPA
			printf("Enter student GPA: ");
			if (scanf("%f", &NewStudent.gpa) != 1 || NewStudent.gpa < 0.0 || NewStudent.gpa > 4.0){
				printf("Invalid GPA Input.\n");
				// Clear the Input Buffer
				while (getchar() != '\n');
				break;
			}
			// Calling Function in case 1 and add the student to the linked list
			addStudent(&NewStudent);
			// Calling Function and ask if the user wants to continue.
			ContinueMoreTask();
			break;
		}
		//****************************************************************************//
		//                        #Display All Students#                             //
		//**************************************************************************//
		case 2:
		{
			// Print massage "Display All Students"Print massage ".
			printf("\t\tDisplay All Students\t\t\n");
			// Calling Function in case 2 and display students in linked list
			displayStudents();
			// Calling Function and ask if the user wants to continue.
			ContinueMoreTask();
			break;
		}
		//****************************************************************************//
		//                   #Search for a Student by ID#                            //
		//**************************************************************************//
		case 3:
		{
			// Print massage "Search for a Student by ID".
			printf("\t\tSearch for a Student by ID\t\t\n");
			int id;
			printf("Enter ID: ");
			if (scanf("%d", &id) != 1){
				printf("Invalid ID Input.\n");
				// Clear the Input Buffer
				while (getchar() != '\n');
				break;
			}
			// Calling Function in case 3 and Search for a Student by ID in linked list
			searchStudentByID(id);
			// Calling Function and ask if the user wants to continue.
			ContinueMoreTask();
			break;
		}
		//****************************************************************************//
		//                    #Update Student Information#                           //
		//**************************************************************************//
		case 4:
		{
			//Print massage "Update Student Information".
			printf("\t\tUpdate Student Information\t\t\n");
			int id;
			printf("Enter ID: ");
			if (scanf("%d", &id) != 1){
				printf("Invalid ID Input.\n");
				// Clear the Input Buffer
				while (getchar() != '\n');
				break;
			}
			// Calling Function in case 4 and Update Student Information in linked list
			updateStudent(id);
			// Calling Function and ask if the user wants to continue.
			ContinueMoreTask();
			break;
		}
		//****************************************************************************//
		//                       #Calculate Average GPA#                             //
		//**************************************************************************//
		case 5:
			// Print massage "Calculate Average GPA".
			printf("\t\tCalculate Average GPA\t\t\n");
			// Calculate average GPA
			printf("Calculate average GPA:\n");
			// Calling Function in case 5 and Calculate Average GPA
			float average_GPA = calculateAverageGPA();
			printf("Average GPA: %.2f\n", average_GPA);
			// Calling Function and ask if the user wants to continue.
			ContinueMoreTask();
			break;
			//****************************************************************************//
			//                  #Find Student with Highest GPA#                          //
			//**************************************************************************//
		case 6:
			// Print massage "Find Student with Highest GPA".
			printf("\t\tFind Student with Highest GPA\t\t\n");
			// Calling Function in case 6 and Find Student with Highest GPA from linked list
			searchHighestGPA();
			// Calling Function and ask if the user wants to continue.
			ContinueMoreTask();
			break;
			//****************************************************************************//
			//                       #Delete a Student by ID#                            //
			//**************************************************************************//
		case 7:
			// Print massage "Delete a Student by ID".
			printf("\t\tDelete a Student by ID\t\t\n");
			int id;
			printf("Enter ID: ");
			if (scanf("%d", &id) != 1){
				printf("Invalid ID input.\n");
				// Clear the Input Buffer
				while (getchar() != '\n');
				break;
			}
			// Calling Function in case 6 and Delete a Student by ID from linked list
			deleteStudent(id);
			// Calling Function and ask if the user wants to continue.
			ContinueMoreTask();
			break;
			//****************************************************************************//
			//                         #Exit from Program#                               //
			//**************************************************************************//
		case 8:
			// Exit from Program.
			printf("Thank you for using our services.\n");
			printf("*======================================================*\n");
			exit(0);
			break;
		default:
			printf("Invalid choice.\n");
		}
	}
}
/******************************
 *  Functions Implementation  *
 ******************************/
// Function to create or add a new node with given student data.
struct node * add_new_node(const struct student *ptr)
{
	// Memory allocated using malloc()
	struct node *link = (struct node *)malloc(sizeof(struct node));
	// Check if memory allocation error
	if(link == NULL){
		printf("Sorry!!\n");
		printf("Unable to allocate Memory \n");
		return NULL;
	}
	link->data = *ptr;
	link->next = NULL;
	return link;
}
// Case 1 --> Function to add a new student to the linked list
void addStudent(const struct student *const ptr)
{
	/*******************************
	 * if the linked list is empty  *
	 * this means --> head == NULL  *
	 *******************************/
	if(ptr == NULL){
		printf("Invalid Student Data\n");
		return;
	}
	struct node *link= add_new_node(ptr);
	// Check if the linked list is empty to add a new student
	if (link == NULL){
		return;
	}
	// check if the linked list is empty.
	if (head == NULL){
		head = link;
		printf("The Student has been added Successfully\n");
		return;
	}
	// Pass the list to check for duplicate ID and add the end.
	struct node *current = head;
	while (current->next != NULL){
		if(current->data.id == link->data.id){
			// Check the last node for duplicate ID
			printf("Error!!!\n");
			printf("This ID is already Existing\n");
			free(link);
			return;
		}
		current = current->next;
	}
	if(current->data.id == link->data.id){
		printf("Error!!!\n");
		printf("This ID is already Existing\n");
		free(link);
		return;
	}
	// add the new node at the end of the list
	current->next = link;
	printf("The Student has been added Successfully\n");
}
// Case 2 --> Function to display the details of all students
void displayStudents(void)
{
	// check if the linked list is empty.
	if (head == NULL){
		printf("There are No Students Here!\n");
		return;
	}
	// pass the list to print students's data
	struct node* current = head;
	while (current != NULL){
		printf("[ID: %d, Name: %s, Age: %d, GPA: %.2f]\n",current->data.id, current->data.name, current->data.age, current->data.gpa);
		current = current->next;
	}
}
// Case 3 --> Function to search for a student by their ID and display their details if found.
void searchStudentByID(int id)
{
	// check if the linked list is empty.
	if (head == NULL){
		printf("There are No Students Here!\n");
		return;
	}
	struct node * current = head;
	while (current != NULL){
		if ((current->data.id) == id){
			printf("Student Found: [ID: %d, Name: %s, Age: %d, GPA: %.2f]\n",current->data.id, current->data.name, current->data.age, current->data.gpa);
			return;
		}
		current = current->next;
	}
	printf("Student with ID : %d is NOT Found\n", id);
}
// Case 4 --> Function updates the details of a student with the given ID
void updateStudent(int id)
{
	// check if the linked list is empty.
	if (head == NULL){
		printf("There are No Students Here!\n");
		return;
	}
	struct node * current = head;
	while(current != NULL){
		// check if id is exist
		if(current->data.id == id){
			struct student Update_student_data;
			//Check if id ia exist
			Update_student_data.id = id;
			printf("Enter Student's New Name: ");
			scanf("%49s",Update_student_data.name);
			printf("Enter Student's New Age: ");
			scanf("%d", &Update_student_data.age);
			printf("Enter Student's New GPA: ");
			scanf("%f", &Update_student_data.gpa);
			current->data = Update_student_data;
			printf("Student data has been updated successfully.\n");
			return;
		}
		current = current->next;
	}
	printf("Student with ID : %d is NOT Found\n", id);
}
// Case 6 --> Function calculates and returns ethe average GPA of all students.
float calculateAverageGPA(void)
{
	// check if the linked list is empty.
	if (head == NULL){
		printf("There are No Students Here!\n");
		return 0.0;
	}
	float sum = 0.0;
	int counter = 0;
	struct node *current = head;
	while (current != NULL){
		sum += current->data.gpa;
		current = current->next;
		counter++;
	}
	if (counter == 0){
		printf("There are No Students Here!\n");
		return 0.0;
	}
	return sum / counter;
}
// Case 5 --> Function to find and display the student with the highest GPA
void searchHighestGPA(void)
{
	// check if the linked list is empty.
	if (head == NULL){
		printf("There are No Students Here!\n");
		return;
	}
	struct node * current = head;
	struct node * max = head;
	while (current != NULL){
		if (current->data.gpa > max->data.gpa){
			max = current;
		}
		current = current->next;
	}
	if (max != NULL){
		printf("Student with Highest GPA: [Name: %s, ID: %d, Age: %d, GPA: %.2f]\n", max->data.name, max->data.id, max->data.age, max->data.gpa);
	}
	else{
		printf("Sorry!!\n");
		printf("Error in Finding Student with Highest GPA\n");
	}
}
// Case 7 --> Function to delete a student from the linked list by their ID
void deleteStudent(int id)
{
	// check if the linked list is empty.
	if (head == NULL){
		printf("There are No Students Here!\n");
		return;
	}
	struct node * current = head;
	struct node *prev = NULL;
	if ((current != NULL) && (current->data.id == id)){
		// Move the head to the next node
		head = current->next;
		// Free the memory of the old head
		free(current);
		printf("Student with ID : %d is Deleted.\n", id);
		return;
	}
	while ((current != NULL) && (current->data.id != id)){
		prev = current;
		current = current->next;
	}
	if (current == NULL){
		printf("Student with ID : %d is NOT Found\n", id);
		//return;
	}
	prev->next = current->next;
	// Free the memory of the deleted node
	free(current);
	printf("Student with ID : %d is Deleted.\n", id);
}
// Function to ask if the user wants to continue.
void ContinueMoreTask(void)
{
	// Ask if the user wants to continue.
	int i = 0;
	char Continue_More_Task [] = {'Y', 'y','N', 'n', '\0'};
	printf("\nDo you want to continue (Yes/No)? \n");
	scanf("%4s", Continue_More_Task);
	if ((Continue_More_Task [i] == 'N') || (Continue_More_Task [i] == 'n') || (Continue_More_Task [i] == 'Y') || (Continue_More_Task [i] == 'y')){
		if ((Continue_More_Task [i] == 'N') || (Continue_More_Task [i] == 'n')){
			printf("Thank you for using our services.\n");
			printf("*======================================================*\n");
			exit(0);
		}
	}else{
		printf("Invalid choice.\n");
		ContinueMoreTask();
	}
}
/************************************************ "Thank You" ************************************************/
